#ifndef LESSONS_LINKED_LISTS_EXERCISES_INCLUDES_LINKED_LISTS_EXERCISES_NODE_H_
#define LESSONS_LINKED_LISTS_EXERCISES_INCLUDES_LINKED_LISTS_EXERCISES_NODE_H_

#include <memory>

class Node {
 public:
  int value;
  std::shared_ptr<Node> next;

  Node(int value) : value{value}, next{nullptr} {}
};

#endif
