#include <iostream>

inline int fun() {
  return 222;
}

void bar() {
  std::cout << "inline222: fun() = " << fun() << ", &fun = " << (void*) &fun << std::endl;
}