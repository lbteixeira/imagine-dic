#include <string>
#include "hello.hpp"

namespace imagine {
  const std::string* sayHello(){
    std::string* msg = new std::string("LT code starters!");
    return msg;
  }
}
