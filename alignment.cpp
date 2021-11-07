#include <iostream>

struct x_ {
   char a;
   int b;
   short c;
   char d;
};

struct y_
{
   char a;
   short c;
   char d;     // 1 byte
   int b;      // 4 bytes
};

struct z_
{
   char a;     // 1 byte
   char d;     // 1 byte
   short c;    // 2 bytes
   int b;      // 4 bytes
};

#pragma pack(push, 1)
struct w_ {
   char a;
   int b;
   short c;
   char d;
};
#pragma pack(pop)

int main() {
  std::cout << sizeof(x_) << std::endl;
  std::cout << sizeof(y_) << std::endl;
  std::cout << sizeof(z_) << std::endl;
  std::cout << sizeof(w_) << std::endl;
}