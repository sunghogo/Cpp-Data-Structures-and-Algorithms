#include <string>
#include "pointers_and_classes/cookies.h"

Cookie::Cookie(const std::string& color) : color_(color) {}

std::string Cookie::GetColor() const {
  return color_;
}

void Cookie::SetColor(const std::string& color) {
  color_ = color;
}
