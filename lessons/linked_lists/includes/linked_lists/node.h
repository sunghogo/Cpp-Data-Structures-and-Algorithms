#ifndef LESSONS_LINKED_LISTS_INCLUDES_LINKED_LISTS_NODE_H_
#define LESSONS_LINKED_LISTS_INCLUDES_LINKED_LISTS_NODE_H_

#include <ostream>
#include <memory>
#include "printable_interface.h"

template <typename T>
class Node : public PrintableInterface {
 public:
  Node() : value_{}, next_{nullptr} {}

  explicit Node(const T& value) : value_{value}, next_{nullptr} {}

  ~Node() = default;

  T GetValue() const {
    return value_;
  }

  Node* GetNext() const {
    return next_.get();
  }

  std::shared_ptr<Node<T>> GetNextPointer() const {
    return next_;
  }

  void SetValue(const T& value) {
    value_ = value;
  }

  void SetNext(std::shared_ptr<Node<T>> next) {
    next_ = std::move(next);
  }

  std::shared_ptr<Node<T>> ReleaseNext() {
    return std::move(next_);
  }

  void Print(std::ostream& os) const override {
    os << value_;
  }

 private:
  T value_;
  std::shared_ptr<Node<T>> next_;
};

#endif
