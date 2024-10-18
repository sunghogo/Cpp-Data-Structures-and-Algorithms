#include <iostream>
#include <memory>

using namespace std;

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

class Node : public I_Printable {
    private:
        int value;
        Node* next;
    public:
        Node(int value) : value {value}, next {nullptr} {}
        Node() : Node {0} {};

        int get_value() const { return value; }
        Node *get_next() const { return next; }
        void set_value(int value) { this->value = value; }
        void set_next(Node *next) {  this->next = next; }

        virtual void print(std::ostream &os) const override { os << value; }
};

class LinkedList: public I_Printable {
    private:
        Node *head;
        Node *tail;
        int length;
    public:
        LinkedList() : head {nullptr}, tail {nullptr}, length {0} {};
        LinkedList(int value) : head {new Node {value}}, tail {head}, length {1} {}
        ~LinkedList() { 
            while (head) {
                Node *node = head;
                head = head->get_next();
                delete node;
            }
        }
        Node *get_head() const {return head;}
        Node *get_tail() const {return tail;}
        int get_length() const {return length;}

        virtual void print(std::ostream &os) const override { 
            os << "[Length: " << length << "| Head: " << (head ? (*head) : Node{})  << "| Tail: " << (tail ? (*tail) : Node{}) << "| List: ";
            Node *next = head;
            while (next) {
                os << (*next);
                next = next->get_next();
                if (next) os << " -> ";
            }
            os << "]";
         }
    
        void append(int value) {
            Node *node = new Node {value};
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
                Node *pre = head;
                Node *temp = head;
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

        void prepend(int value) {
            Node *node = new Node {value};
            if (length == 0) head = tail = node;
            else {
                node->set_next(head);
                head = node;
            }
            length++;
        }

        void deleteFirst() {
            if (length == 0) return;
            Node *node = head;
            if (length == 1) head = tail = nullptr;
            else {
                head = head->get_next();
                delete node;
            }
            length--;
        }
        
        void insert(int index, int value) {}        
};

int main() {
    unique_ptr<LinkedList> LL {new LinkedList{}};

    std::cout << *LL << std::endl;
    
    LL->prepend(1);
    LL->append(2);
    LL->append(3);

    std::cout << *LL << std::endl;

    LL->deleteFirst();
    std::cout << *LL << std::endl;

    LL->deleteLast();
    std::cout << *LL << std::endl;

    LL->deleteLast();
    std::cout << *LL << std::endl;
}