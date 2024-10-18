#include <iostream>

using namespace std;

class Node { 
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
}; 


class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Write the LinkedList constructor                   |
        //   | - Constructor takes an int value                     |
        //   | - Create a new node                                  |
        //   | - Initialize head, tail to the new node              |
        //   | - Length starts at 1                                 |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Use 'new' to allocate memory for the new node      |
        //   | - Make sure to set head and tail pointers            |
        //   | - Make sure to set length                            |
        //   | - Check output from Test.cpp in "User logs"          |
        //   +======================================================+
        LinkedList(int value) : head {new Node{value}}, tail {head}, length {1} {}

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        Node* getTail() {
            return tail; 
        }

        int getLength() {
            return length;
        }

};

int main() {
    LinkedList *LL = new LinkedList {1};
    cout << "head: " << LL->getHead()->value << endl;
    cout << "tail: " << LL->getTail()->value << endl;
    cout << "length: " << LL->getLength() << endl;
}