#ifndef LESSONS_LINKED_LISTS_LEETCODE_INCLUDES_LINKED_LISTS_LEETCODE_LINKED_LIST_H_
#define LESSONS_LINKED_LISTS_LEETCODE_INCLUDES_LINKED_LISTS_LEETCODE_LINKED_LIST_H_

#include <iostream>
#include <memory>
#include "linked_lists_leetcode/node.h"

using namespace std;

class LinkedList {
 private:
  std::shared_ptr<Node> head;
  std::weak_ptr<Node> tail;
  size_t length;

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
  LinkedList(int value)
      : head{std::make_shared<Node>(value)}, tail{head}, length{1} {}

  ~LinkedList() {}

  void printList() {
    auto temp = head;
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
    return head.get();
  }

  Node* getTail() {
    return tail.lock().get();
  }

  size_t getLength() {
    return length;
  }

  // We will use this method to test append to an empty list
  void makeEmpty() {
    head.reset();
    tail.reset();
    length = 0;
  }

  //   +====================================================+
  //   |                 WRITE YOUR CODE HERE               |
  //   | Description:                                       |
  //   | - Write code to append 'value' to the list         |
  //   | - Return type: void                                |
  //   |                                                    |
  //   | Tips:                                              |
  //   | - Consider edge cases like empty lists             |
  //   | - Remember to update the length                    |
  //   | - Check output from Test.cpp in "User logs"        |
  //   +====================================================+
  void append(int value) {
    auto node = std::make_shared<Node>(value);
    if (length == 0)
      tail = head = node;
    else {
      tail.lock()->next = node;
      tail = node;
    }
    ++length;
  }

  //   +=====================================================+
  //   |                 WRITE YOUR CODE HERE                |
  //   | Description:                                        |
  //   | - Write code to delete the last element in the list |
  //   | - Return type: void                                 |
  //   |                                                     |
  //   | Tips:                                               |
  //   | - Consider edge cases like empty lists              |
  //   | - Remember to update the tail and length            |
  //   | - Check output from Test.cpp in "User logs"         |
  //   +=====================================================+
  void deleteLast() {
    if (!length) return;

    if (length == 1) {
      head.reset();
      tail.reset();
      length = 0;
      return;
    }

    auto prev = head;
    for (size_t i = 0; i < length - 2; i++) prev = prev->next;
    prev->next.reset();
    tail = prev;
    --length;
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
    auto node = std::make_shared<Node>(value);

    if (!length)
      tail = head = node;
    else {
      node->next = head;
      head = node;
    }
    ++length;
  }

  //   +======================================================+
  //   |                 WRITE YOUR CODE HERE                 |
  //   | Description:                                         |
  //   | - Write code to delete the first element in the list |
  //   | - Return type: void                                  |
  //   |                                                      |
  //   | Tips:                                                |
  //   | - Consider edge cases like empty lists               |
  //   | - Remember to update the head and length             |
  //   | - Check output from Test.cpp in "User logs"          |
  //   +======================================================+
  void deleteFirst() {
    if (!length)
      return;
    else if (length == 1)
      tail = head = nullptr;
    else
      head = head->next;
    --length;
  }

  //   +======================================================+
  //   |                 WRITE YOUR CODE HERE                 |
  //   | Description:                                         |
  //   | - Write code to get the node at the given index      |
  //   | - Return type: Node*                                 |
  //   |                                                      |
  //   | Tips:                                                |
  //   | - Check if the index is out of bounds                |
  //   | - Return nullptr if index is invalid                 |
  //   | - Use a loop to traverse to the required node        |
  //   | - Check output from Test.cpp in "User logs"          |
  //   +======================================================+
  Node* get(size_t index) {
    if (index >= length)
      return nullptr;
    else if (index == 0)
      return getHead();
    else if (index == length - 1)
      return getTail();
    else {
      auto current = head;
      for (size_t i = 0; i < index; i++) current = current->next;
      return current.get();
    }
  }

  //   +======================================================+
  //   |                 WRITE YOUR CODE HERE                 |
  //   | Description:                                         |
  //   | - Update the value of the node at the given index    |
  //   | - Return type: bool                                  |
  //   |                                                      |
  //   | Tips:                                                |
  //   | - Use the get function to find the node              |
  //   | - If node is found, update the value and return true |
  //   | - Otherwise, return false                            |
  //   | - Check output from Test.cpp in "User logs"          |
  //   +======================================================+
  bool set(int index, int value) {
    Node* node = get(index);
    if (node)
      node->value = value;
    else
      return false;
    return true;
  }

  //   +======================================================+
  //   |                 WRITE YOUR CODE HERE                 |
  //   | Description:                                         |
  //   | - Insert a node with given value at a specific index |
  //   | - Return type: bool                                  |
  //   |                                                      |
  //   | Tips:                                                |
  //   | - Use get function to find the node before index     |
  //   | - Special cases: index is 0 or equal to length       |
  //   | - If node is found, insert new node and return true  |
  //   | - Otherwise, return false                            |
  //   | - Check output from Test.cpp in "User logs"          |
  //   +======================================================+
  bool insert(size_t index, int value) {
    if (index > length || index < 0)
      return false;
    else if (!index)
      prepend(value);
    else if (index == length)
      append(value);
    else {
      auto prev = head;
      auto node = std::make_shared<Node>(value);
      for (size_t i = 0; i < index - 1; i++) prev = prev->next;
      node->next = prev->next;
      prev->next = node;
      ++length;
    }
    return true;
  }

  //   +======================================================+
  //   |                 WRITE YOUR CODE HERE                 |
  //   | Description:                                         |
  //   | - Delete a node at a specific index                  |
  //   | - Return type: void                                  |
  //   |                                                      |
  //   | Tips:                                                |
  //   | - Use get to find node before index                  |
  //   | - Special cases: index is 0 or equal to length - 1   |
  //   | - Delete node if found                               |
  //   | - Adjust 'next' pointers of adjacent nodes           |
  //   | - Reduce length by 1                                 |
  //   | - Check output from Test.cpp in "User logs"          |
  //   +======================================================+
  void deleteNode(size_t index) {
    if (index >= length)
      return;
    else if (!index)
      deleteFirst();
    else if (index == length - 1)
      deleteLast();
    else {
      auto prev = head;
      for (size_t i = 0; i < index - 1; i++) prev = prev->next;
      prev->next = prev->next->next;
      --length;
    }
  }

  //   +======================================================+
  //   |                 WRITE YOUR CODE HERE                 |
  //   | Description:                                         |
  //   | - Reverse the linked list                            |
  //   | - Return type: void                                  |
  //   |                                                      |
  //   | Tips:                                                |
  //   | - You'll need 3 pointers: before, temp, after        |
  //   | - Loop through all nodes                             |
  //   | - Update 'next' pointers to reverse direction        |
  //   | - Swap head and tail pointers                        |
  //   | - Check output from Test.cpp in "User logs"          |
  //   +======================================================+
  void reverse() {
    if (length <= 1) return;

    // Reverse head and tail
    auto old_head = head;
    head = tail.lock();
    tail = old_head;

    // Setup nodes current = tail, next = old_head->next
    std::shared_ptr<Node> prev = nullptr;
    auto current = tail.lock();

    // Iterate and reverse links
    for (size_t i = 0; i < length; i++) {
      auto next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
  }

  //   +======================================================+
  //   |                 WRITE YOUR CODE HERE                 |
  //   | Description:                                         |
  //   | - Find the middle node of the linked list            |
  //   | - Return type: Node*                                 |
  //   |                                                      |
  //   | Tips:                                                |
  //   | - Use two pointers: 'slow' and 'fast'                |
  //   | - 'slow' moves one step, 'fast' moves two            |
  //   | - When 'fast' reaches the end, 'slow' is at middle   |
  //   | - Return 'slow' as the middle node                   |
  //   +======================================================+
  Node* findMiddleNode() {
    Node* head = getHead();
    Node* tail = getTail();

    Node* slow = head;
    Node* fast = head;

    while (fast != tail && fast) {
      slow = slow->next.get();
      fast = fast->next->next.get();
    }
    return slow;
  }
};

#endif
