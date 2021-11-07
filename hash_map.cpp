#include <unordered_map>
#include <iostream>
#include <functional>

void check_prop(const std::unordered_map<int, int> &map) {
  std::cout << "bucket count " << map.bucket_count() << std::endl;
  std::cout << "max bucket count" << map.max_bucket_count() << std::endl;
  std::cout << "load factor " << map.load_factor() << std::endl;
  std::cout << "mac load factor " << map.max_load_factor() << std::endl;
}

int main() {
  for (int i = -10; i < 10; i++) {
    std::cout << "Hash for " << i << " is " << std::hash<int>()(i) << std::endl;
  }

  std::unordered_map<int, int> map;
  check_prop(map);
  map[0] = 1;
  check_prop(map);
  
  for (size_t i = 2; i < 100; i++) {
    map[i] = rand() % 200; 
  }
  check_prop(map);
  return 0;
}