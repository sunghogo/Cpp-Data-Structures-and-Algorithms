#include <iostream>
#include <memory>

using namespace std;

class Node {
    private:
        int value;
        Node* next;
    public:
        Node(int value) : value {value}, next {nullptr} {}
        int get_value() const { return value; }
        Node *get_next() const { return next; }
        void print(std::ostream &os) const { os << value; }
};

std::ostream &operator<<(std::ostream &os, const Node *obj) {
    obj->print(os);
    return os;
}

class LinkedList {
    private:
        Node *head;
        Node *tail;
        int length;
    public:
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

        void append(int value) {}
        void prepend(int value) {}
        void insert(int index, int value) {}        
};

int main() {
    unique_ptr<LinkedList> LL {new LinkedList{4}};
    
    LL->print_head();
    LL->print_tail();
    LL->print_length();    
    
    LL->print_list();
}