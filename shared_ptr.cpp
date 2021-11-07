#include <memory>
#include <chrono>
#include <iostream>

int main() {
  size_t kTimes = 2e7;
  auto start = std::chrono::high_resolution_clock::now();
  for (size_t i = 0; i < kTimes; i++) {
    auto s = std::make_shared<int>(10);
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::cout << "make_shared using " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microsecs" << std::endl;
  
  start = std::chrono::high_resolution_clock::now();
  for (size_t i = 0; i < kTimes; i++) {
    auto s = std::shared_ptr<int>(new int(10));
  }
  end = std::chrono::high_resolution_clock::now();
  std::cout << "new using " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microsecs" << std::endl;

  return 0;
}