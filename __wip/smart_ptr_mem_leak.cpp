#include <memory>

struct Chunk {
  char large[10000];
};

int func_that_throws() {
  throw std::exception();
  return 0;
}

// void func(std::shared_ptr<Chunk> ptr, int i) {}

// void func(int i, std::shared_ptr<Chunk> ptr) {}

// void func(int i, std::unique_ptr<Chunk> ptr) {}

void func(std::unique_ptr<Chunk> ptr, int i) {}

int main() {
  try {
    func(std::unique_ptr<Chunk>(new Chunk), func_that_throws());
    // func(func_that_throws(), std::unique_ptr<Chunk>(new Chunk));

  } catch (std::exception& e) {
    
  }
  return 0;
}