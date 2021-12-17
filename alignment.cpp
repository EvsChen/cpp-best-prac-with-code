#include <iostream>

// 1. struct is aligned as the biggest member of struct
// 2. paddings are added to make
//  a). field aligned
//  b). the whole struct aligned
// 3. #pragma push can force the object to align

struct x_ {
   char a; // size 1, alignment 1
   // 3 bytes padding for putting b on 4 bytes boundary
   int b; // size 4, alignment 4
   short c; // size 2, alignment 2
   char d; // size 1, alignment 1
   // 1 byte padding for putting x_ on 4 byte boundary
}; // size 12, alignment 4

struct y_
{
   char a;
   // 1 bytes for aligning c
   short c;
   char d;     // 1 byte
   // 3 bytes for aligning b
   int b;      // 4 bytes
}; // size 12, alignment 4

struct z_
{
   char a;     // 1 byte
   char d;     // 1 byte
   short c;    // 2 bytes
   int b;      // 4 bytes
}; // size 8, alignment 4

// https://docs.microsoft.com/en-us/cpp/preprocessor/pack?view=msvc-170
#pragma pack(push, 1)
struct w_ {
  char a;
  int b;
  short c;
  char d;
}; // size 8, alignment 1
#pragma pack(pop)


struct __attribute__ ((__packed__)) p_ {
  char a;
  int b;
  short c;
  char d;
}; // size 8, alignment 1

int main() {
  std::cout << "size:" << sizeof(x_) << " align:" << alignof(x_) << std::endl;
  std::cout << "size:" << sizeof(y_) << " align:" << alignof(y_) << std::endl;
  std::cout << "size:" << sizeof(z_) << " align:" << alignof(z_) << std::endl;
  std::cout << "size:" << sizeof(w_) << " align:" << alignof(w_) << std::endl;
  std::cout << "size:" << sizeof(p_) << " align:" << alignof(p_) << std::endl;
}