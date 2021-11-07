#include <memory>


// Instructions:
// leaks -atExit -- ./why_weak_ptr

struct A;
struct B;

struct A {
  char data[100];
  std::shared_ptr<B> ptr;
};

struct B {
  char data[100];
  std::shared_ptr<A> ptr;
};

void func() {
  auto a_ptr = std::make_shared<A>();
  auto b_ptr = std::make_shared<B>();
  a_ptr->ptr = b_ptr;
  b_ptr->ptr = a_ptr;
}

int main() {
  func();
  return 0;
}


