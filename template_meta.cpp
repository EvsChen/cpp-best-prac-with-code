template <int n> 
struct Fib {
  const static int val = Fib<n - 1>::val + Fib<n - 2>::val;
};

template<>
struct Fib<1> {
  const static int val = 1;
};

template<>
struct Fib<2> {
  const static int val = 1;
};

constexpr int fib(int n) {
    if (n == 1 || n == 2) return 1;
    return fib(n - 1) + fib(n - 2);
    return 0;
}

int main() {
  int arr[Fib<10>::val];
  int arr2[fib(10)];
  return 0;
}