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
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

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
        
        // We will use this method to test prepend on an empty list
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            tail = nullptr;
            length = 0;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

        void deleteLast() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                Node* pre = head;
                while(temp->next) {
                    pre = temp;
                    temp = temp->next;
                }
                tail = pre;
                tail->next = nullptr;
            }
            delete temp;
            length--;            
        }

        //   +=====================================================+
        //   |                 WRITE YOUR CODE HERE                |
        //   | Description:                                        |
        //   | - Write code to prepend 'value' to the list         |
        //   | - Return type: void                                 |
        //   |                                                     |
        //   | Tips:                                               |
        //   | - Consider edge cases like empty lists              |
        //   | - Remember to update the head and length            |
        //   | - Check output from Test.cpp in "User logs"         |
        //   +=====================================================+
        void prepend(int value) {
            Node *node = new Node(value);
            if (length == 0) head = tail = node;
            else {
                node->next = head;
                head = node;
            }
            length++;
        }

};

int main() {
    LinkedList LL {1};
    LL.makeEmpty();
    LL.printList();
    std::cout << "length: " << LL.getLength() << std::endl;
    
    LL.prepend(1);
    LL.printList();
    std::cout << "length: " << LL.getLength() << std::endl;

    LL.prepend(2);
    LL.printList();
    std::cout << "length: " << LL.getLength() << std::endl;

    LL.prepend(3);
    LL.printList();
    std::cout << "length: " << LL.getLength() << std::endl;
}

