/*
Instructions: 
  Adopted from https://stackoverflow.com/questions/1759300/when-should-i-write-the-keyword-inline-for-a-function-method
  case 1:
    clang++ -std=c++14 ./inline1.cpp ./inline2.cpp -o inline
    output:
      inline111: fun() = 111, &fun = 0x107be6ac0
      inline222: fun() = 111, &fun = 0x107be6ac0
  case 2:
    clang++ -std=c++14 -O2 ./inline1.cpp ./inline2.cpp -o inline
    output:
      inline111: fun() = 111, &fun = 0x109e5b9f0
      inline222: fun() = 222, &fun = 0x109e5b9f0
*/

#include <iostream>

void bar();

inline int fun() {
  return 111;
}

int main() {
  std::cout << "inline111: fun() = " << fun() << ", &fun = " << (void*) &fun << std::endl;
  bar();
}