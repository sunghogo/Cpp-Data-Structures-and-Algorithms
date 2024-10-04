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
};

class LinkedList {
    private:
        Node *head;
        Node *tail;
        int length;
    public:
        LinkedList(int value) : head {new Node {value}}, tail {head}, length {1} {}
        Node *get_head() const {return head;}
        Node *get_tail() const {return tail;}
        int get_length() const {return length;}
        void append(int value) {}
        void prepend(int value) {}
        void insert(int index, int value) {}
        ~LinkedList() { 
            for (size_t i {0} ; i < length; i++) {
                Node *node = head;
                head = head->get_next();
                delete node;
            }
        }
};

int main() {
    unique_ptr<LinkedList> LL {new LinkedList{4}};
    cout << "head: " << LL->get_head()->get_value() << endl;
    cout << "tail: " << LL->get_tail()->get_value() << endl;
    cout << "length: " << LL->get_length() << endl;
}