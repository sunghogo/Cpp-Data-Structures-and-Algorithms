#include <iostream>
#include <memory>


class I_Printable {
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
public:
    virtual void print(std::ostream &os) const = 0;
    virtual ~I_Printable() = default;
};

std::ostream &operator<<(std::ostream &os, const I_Printable &obj) {
    obj.print(os);
    return os;
}

template <typename T>
class Node : public I_Printable {
    private:
        T value;
        Node* next;
    public:
        Node(T value) : value {value}, next {nullptr} {}
        Node() : Node {0} {};

        int get_value() const { return value; }
        Node *get_next() const { return next; }
        void set_value(T value) { this->value = value; }
        void set_next(Node *next) {  this->next = next; }

        virtual void print(std::ostream &os) const override { os << value; }
};

template <typename T>
class LinkedList: public I_Printable {
    private:
        Node<T> *head;
        Node<T> *tail;
        int length;
    public:
        LinkedList() : head {nullptr}, tail {nullptr}, length {0} {};
        LinkedList(T value) : head {new Node<T> {value}}, tail {head}, length {1} {}
        ~LinkedList() { 
            while (head) {
                Node<T> *node = head;
                head = head->get_next();
                delete node;
            }
        }
        Node<T> *get_head() const {return head;}
        Node<T> *get_tail() const {return tail;}
        size_t get_length() const {return length;}

        virtual void print(std::ostream &os) const override { 
            os << "[Length: " << length << "| Head: " << (head ? (*head) : Node<T>{})  << "| Tail: " << (tail ? (*tail) : Node<T>{}) << "| List: ";
            Node<T> *next = head;
            while (next) {
                os << (*next);
                next = next->get_next();
                if (next) os << " -> ";
            }
            os << "]";
         }
    
        void append(T value) {
            Node<T> *node = new Node<T> {value};
            if (length <= 0) head = tail = node;
            else {
                tail->set_next(node);
                tail = node;
            }
            length ++;
        }

        void deleteLast() {
            if (length == 0) return;
            if (length == 1) {
                head = tail = nullptr; 
                length--;
            }
            else {
                Node<T> *pre = head;
                Node<T> *temp = head;
                while (temp->get_next()) {
                    pre = temp;
                    temp = temp->get_next();
                }
                tail = pre;
                tail->set_next(nullptr);
                length--;
                delete temp;
            }
        }

        void prepend(T value) {
            Node<T> *node = new Node<T> {value};
            if (length == 0) head = tail = node;
            else {
                node->set_next(head);
                head = node;
            }
            length++;
        }

        void deleteFirst() {
            if (length == 0) return;
            Node<T> *node = head;
            if (length == 1) head = tail = nullptr;
            else {
                head = head->get_next();
                delete node;
            }
            length--;
        }

        Node<T> *get(size_t index) {
            if (index < 0 || index >= length ) return nullptr;
            else {
                Node<T> *node = head;
                for (int i {0}; i < index; i++) {
                    node = node->get_next();
                }
                return node;
            }
        }

        bool set(size_t index, T value) {
            Node<T> *node = get(index);
            if (node) {
                node->set_value(value);
                return true;
            }
            return false;   
        }
        
        bool insert(size_t index, T value) {
            if (index == 0) prepend(value);
            else if (index == length) append(value);
            else {
                Node<T> *prev = get(index - 1);
                Node<T> *node = new Node<T> {value};
                if (prev) {
                    node->set_next(prev->get_next());
                    prev->set_next(node);
                    length++;
                } else {
                    return false;
                }
            }
            return true;
        }

        void deleteNode(size_t index) {
            if (index == 0) deleteFirst();
            else if (index == length) deleteLast();
            else {
                Node<T> *prev = get(index - 1);
                if (prev) {
                    Node<T> *node = prev->get_next();
                    prev->set_next(node->get_next());
                    length--;
                    delete node;
                }
            }
        }

        void reverse() {
            if (length <= 1) return;
            else {
                Node<T> *prev = head;
                head = tail;
                tail = prev;

                Node<T> *next = prev->get_next();
                tail->set_next(nullptr);
                while(next) {
                    Node<T> *temp = next->get_next();
                    next->set_next(prev);
                    prev = next;
                    next = temp;
                }
            }
        }
};

int main() {
    std::unique_ptr<LinkedList<int>> LL {new LinkedList<int>{}};

    std::cout << *LL << std::endl;
    
    LL->prepend(1);
    LL->append(2);
    LL->append(3);
    std::cout << *LL << std::endl;

    std::cout << *(LL->get(2)) << std::endl;

    LL->set(2, 4);
    std::cout << *LL << std::endl;

    LL->insert(2, 3);
    std::cout << *LL << std::endl;

    LL->reverse();
    std::cout << *LL << std::endl;

    LL->deleteNode(2);
    std::cout << *LL << std::endl;

    LL->deleteFirst();
    std::cout << *LL << std::endl;

    LL->deleteLast();
    std::cout << *LL << std::endl;

    LL->deleteLast();
    std::cout << *LL << std::endl;
}