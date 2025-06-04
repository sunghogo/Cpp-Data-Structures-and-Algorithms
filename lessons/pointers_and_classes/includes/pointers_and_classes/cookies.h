#ifndef COOKIES_H_
#define COOKIES_H_

#include <string>

class Cookie {
 public:
  Cookie(const std::string& color);
  std::string GetColor() const;
  void SetColor(const std::string& color);

 private:
  std::string color_;
};

#endif
