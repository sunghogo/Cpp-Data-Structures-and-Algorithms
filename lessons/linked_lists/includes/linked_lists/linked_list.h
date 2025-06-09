#ifndef LESSONS_LINKED_LISTS_INCLUDES_LINKED_LISTS_LINKED_LIST_H_
#define LESSONS_LINKED_LISTS_INCLUDES_LINKED_LISTS_LINKED_LIST_H_

#include <iostream>
#include <memory>
#include "linked_lists/printable_interface.h"
#include "linked_lists/node.h"

template <typename T>
class SinglyLinkedList : public PrintableInterface {
 public:
  SinglyLinkedList() : head_{nullptr}, tail_{}, length_{0} {}

  explicit SinglyLinkedList(const T& value)
      : head_{std::make_shared<Node<T>>(value)}, tail_{head_}, length_{1} {}

  ~SinglyLinkedList() = default;

  Node<T>* GetHead() const {
    return (head_) ? head_.get() : nullptr;
  }

  Node<T>* GetTail() const {
    return !tail_.expired() ? tail_.lock().get() : nullptr;
  }

  size_t GetLength() const {
    return length_;
  }

  void SetHead(std::shared_ptr<Node<T>> head) {
    head_ = std::move(head);
  }

  void SetTail(const std::shared_ptr<Node<T>>& tail) {
    tail_ = tail;
  }

  std::shared_ptr<Node<T>> ReleaseHead() {
    return std::move(head_);
  }

  std::shared_ptr<Node<T>> ReleaseTail() {
    auto tail = tail_.lock();
    tail_.reset();
    return tail;
  }

  void Append(T value) {
    auto node = std::make_shared<Node<T>>(value);

    if (length_ == 0) {
      SetTail(node);
      SetHead(node);
    } else {
      GetTail()->SetNext(node);
      SetTail(node);
    }

    ++length_;
  }

  void DeleteLast() {
    if (length_ == 0) {
      return;
    }

    if (length_ == 1) {
      ReleaseHead();
      ReleaseTail();
      --length_;
      return;
    }

    auto current = head_;
    while (current->GetNextPointer() &&
           current->GetNextPointer()->GetNextPointer()) {
      current = current->GetNextPointer();
    }

    current->ReleaseNext();
    SetTail(current);
    --length_;
  }

  void Prepend(T value) {
    auto node = std::make_shared<Node<T>>(value);

    if (length_ == 0) {
      SetTail(node);
      SetHead(node);
    } else {
      auto old_head = ReleaseHead();
      node->SetNext(old_head);
      SetHead(node);
    }

    ++length_;
  }

  void DeleteFirst() {
    if (length_ == 0) {
      return;
    }

    if (length_ == 1) {
      ReleaseTail();
      ReleaseHead();
      --length_;
      return;
    }

    auto old_head = ReleaseHead();
    SetHead(old_head->ReleaseNext());
    --length_;
  }

  Node<T>* Get(size_t index) {
    if (index >= length_)
      return nullptr;
    else {
      Node<T>* node = GetHead();
      for (size_t i = 0; i < index; ++i) {
        node = node->GetNext();
      }
      return node;
    }
  }

  bool Set(size_t index, const T& value) {
    Node<T>* node = Get(index);
    if (node) {
      node->SetValue(value);
      return true;
    }
    return false;
  }

  bool Insert(size_t index, T value) {
    if (index == 0) {
      Prepend(value);
    } else if (index == length_) {
      Append(value);
    } else {
      Node<T>* prev = Get(index - 1);
      auto node = std::make_shared<Node<T>>(value);
      if (prev) {
        node->SetNext(prev->ReleaseNext());
        prev->SetNext(node);
        ++length_;
      } else {
        return false;
      }
    }
    return true;
  }

  bool DeleteNode(size_t index) {
    if (index == 0) {
      DeleteFirst();
      return true;

    } else if (index == length_ - 1) {
      DeleteLast();
      return true;

    } else {
      Node<T>* prev = Get(index - 1);
      if (prev) {
        auto node = prev->ReleaseNext();
        prev->SetNext(node->ReleaseNext());
        --length_;
      } else {
        return false;
      }
      return true;
    }
  }

  void Reverse() {
    if (length_ <= 1)
      return;
    else {
      auto old_head = ReleaseHead();
      auto prev = old_head;
      auto curr = prev->ReleaseNext();

      while (curr) {
        auto next = curr->ReleaseNext();
        curr->SetNext(prev);
        prev = curr;
        curr = std::move(next);
      }

      SetTail(old_head);
      SetHead(prev);
    }
  }

  void Print(std::ostream& os) const override {
    os << "[Length: " << length_;
    os << " | Head: ";
    if (head_) {
      os << *GetHead();
    } else {
      os << "";
    }
    os << " | Tail: ";
    if (tail_.lock()) {
      os << *GetTail();
    } else {
      os << "";
    }
    os << " | List: ";
    Node<T>* next = GetHead();
    while (next) {
      os << (*next);
      next = next->GetNext();
      if (next) os << " -> ";
    }
    os << "]";
  }

 private:
  std::shared_ptr<Node<T>> head_;
  std::weak_ptr<Node<T>> tail_;
  size_t length_;
};

#endif
