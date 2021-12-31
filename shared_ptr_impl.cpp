#include <memory>
#include <iostream>
#include <atomic>

template<typename T>
class sblock {
public:
  std::atomic<int> ref_cnt;
};

template<typename T>
class my_sptr {
public:
  my_sptr() {}

   // ctor by object ptr
  my_sptr(T* object) {
    block = new sblock<T>();
    obj_ptr = object;
    block->ref_cnt = 1;    
  }

   // copy constructor
  my_sptr(const my_sptr<T>& other) {
    block = other.block;
    obj_ptr = other.obj_ptr;
    block->ref_cnt++;
  }

   // move constructor
  my_sptr(my_sptr<T>&& other) {
    std::cout << "Move constructor called" << std::endl;
    block = other.block;
    obj_ptr = other.obj_ptr;
  }

  ~my_sptr() {
    block->ref_cnt--;
    if (block->ref_cnt == 0) {
      delete block;
      delete obj_ptr;
    }
  }

  my_sptr<T>& operator= (const my_sptr<T>& other) {
    block = other.block;
    obj_ptr = other.obj_ptr;
    block->ref_cnt++;    
  }

  T* operator->() {
    return obj_ptr;
  }

private:
  T* obj_ptr;
  sblock<T>* block;
};

template<typename T, class ...Args>
my_sptr<T> make_shared(Args&&... args) {
  
}

class Test {
public:
  Test() {
    std::cout << "Test constructor called" << std::endl;
  }
  ~Test() {
    std::cout << "Test destructor called" << std::endl;
  }
};

int test_func(my_sptr<Test>&& test_ptr) {
  return 1;
}

int test_func(std::shared_ptr<Test>&& test_ptr) {
  return 1;
}


int main() {
  auto ptr = my_sptr<Test>(new Test());
  auto ptr2 = std::shared_ptr<Test>(new Test());
  test_func(std::move(ptr));
  test_func(std::move(ptr2));
  std::cout << "Function returns" << std::endl;
  return 0;
}