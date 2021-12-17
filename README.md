# C++ Best Practices with Code

This repo is a collection of code snippets that effectively demonstrate WHY some best practices are useful, not only in interviews.

Below is the list of best practices with their sample codes

- [shared_ptr.cpp](shared_ptr.cpp) : using `std::make_shared` over `new` 
- (TODO) [smart_ptr_mem_leak.cpp](smart_ptr_mem_leak.cpp): possible memory leak when using smart pointers with `new`
- [why_weak_ptr.cpp](why_weak_ptr.cpp): memory leak due to cyclic reference of `shared_ptr`
- [inline_func](inline_func): The meaning of `inline` function
  - This function will be defined in multiple translation units, don't worry about it. The linker needs to make sure all translation units **use a single instance** of the variable/function.
- [virtual_destructor](virtual_destructor.cpp): resource leak due to non-virtual destructor in base class: derived class destructor not called
- [alignment](alignment.cpp): how does `alignment` in a struct work and how does `pragma pack` work 