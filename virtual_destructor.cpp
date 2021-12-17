#include <iostream>

class Base {};
class BaseV {
public:
  virtual ~BaseV() {}
};

class Derived : public Base {
  ~Derived() {
    std::cout << "Derived destructor" << std::endl;
  }
};

class DerivedV : public BaseV {
  ~DerivedV() {
    std::cout << "DerivedV destructor" << std::endl;
  }
};

int main() {
  Base* p = new Derived();
  BaseV* p1 = new DerivedV();
  delete p;
  delete p1;
  return 0;
}