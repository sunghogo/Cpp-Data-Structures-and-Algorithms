#include <iostream>
#include <memory>
#include "linked_lists/linked_list.h"

int main() {
  auto singly_linked_list = std::make_unique<SinglyLinkedList<int>>();

  std::cout << *singly_linked_list << std::endl;

  singly_linked_list->Append(2);
  singly_linked_list->Append(3);
  singly_linked_list->Prepend(1);
  singly_linked_list->Prepend(0);
  std::cout << *singly_linked_list << std::endl;

  std::cout << *(singly_linked_list->Get(2)) << std::endl;

  singly_linked_list->Set(3, 4);
  std::cout << *singly_linked_list << std::endl;

  singly_linked_list->Insert(3, 3);
  std::cout << *singly_linked_list << std::endl;

  singly_linked_list->Reverse();
  std::cout << *singly_linked_list << std::endl;

  singly_linked_list->DeleteNode(2);
  std::cout << *singly_linked_list << std::endl;

  singly_linked_list->DeleteFirst();
  std::cout << *singly_linked_list << std::endl;

  singly_linked_list->DeleteLast();
  std::cout << *singly_linked_list << std::endl;

  singly_linked_list->DeleteFirst();
  std::cout << *singly_linked_list << std::endl;

  singly_linked_list->DeleteLast();
  std::cout << *singly_linked_list << std::endl;

  return 0;
}
