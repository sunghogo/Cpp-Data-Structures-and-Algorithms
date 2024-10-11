#include <iostream>
#include <memory>

using namespace std;

class I_Printable {
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
public:
    virtual void print(std::ostream &os) const = 0;
    virtual ~I_Printable() = default;
};

std::ostream &operator<<(std::ostream &os, const I_Printable *obj) {
    obj->print(os);
    return os;
}

class Node : public I_Printable {
    private:
        int value;
        Node* next;
    public:
        Node(int value) : value {value}, next {nullptr} {}

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

        void print_head() const { cout << "head: " << head << endl; }
        void print_tail() const { cout << "tail: " << tail << endl; }
        void print_length() const { cout << "length: " << length << endl; }
        void print_list() const {
            Node *temp = head;
            while (temp) {
                cout << temp->get_value() << endl;
                temp = temp->get_next();
            }
        }

        virtual void print(std::ostream &os) const override { 
            os << "head: " << head << endl; 
            os  << "tail: " << tail << endl;
            os << "length: " << length << endl;
         }
    
        void append(int value) {
            Node *node = new Node {value};
            if (length <= 0) head = node, tail = node;
            else {
                tail->set_next(node);
                tail = node;
            }
            length ++;
        }
        void prepend(int value) {}
        void insert(int index, int value) {}        
};

int main() {
    unique_ptr<LinkedList> LL {new LinkedList{4}};

    cout << LL << endl;
    
    LL->append(5);

    LL->print_list();
}