#ifndef LESSONS_LINKED_LISTS_LEETCODE_INCLUDES_LINKED_LISTS_LEETCODE_NODE_H_
#define LESSONS_LINKED_LISTS_LEETCODE_INCLUDES_LINKED_LISTS_LEETCODE_NODE_H_

#include <memory>

class Node {
 public:
  int value;
  std::shared_ptr<Node> next;

  Node(int value) : value{value}, next{nullptr} {}
};

#endif
