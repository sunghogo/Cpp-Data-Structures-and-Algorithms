#ifndef LESSONS_LINKED_LISTS_INCLUDES_LINKED_LISTS_PRINTABLE_INTERFACE_H_
#define LESSONS_LINKED_LISTS_INCLUDES_LINKED_LISTS_PRINTABLE_INTERFACE_H_

#include <ostream>

class PrintableInterface {
  friend std::ostream& operator<<(std::ostream& os,
                                  const PrintableInterface& obj) {
    obj.Print(os);
    return os;
  }

 public:
  virtual void Print(std::ostream& os) const = 0;

  virtual ~PrintableInterface() = default;
};

#endif
