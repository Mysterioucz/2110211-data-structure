#include <iostream>
#include "stack.h"
#include "student.h"

template <typename T>
void test() {
  // input data
  int n, k;
  std::cin >> n >> k;

  CP::stack<T> a;

  for (int i = 1; i <= n; i++) {
    T x;
    std::cin >> x;
    a.push(x);
  }

  // call function
  std::vector<std::stack<T>> output;
  a.v_split(output, k);

  // check initial vector
  std::cout << a.size() << "\n";
  while (!a.empty()) {
    std::cout << a.top() << " ";
    a.pop();
  }
  std::cout << "\n";

  // check output
  for (int i = 0; i < output.size(); i++) {
    while (!output[i].empty()) {
      std::cout << output[i].top() << " ";
      output[i].pop();
    }
    std::cout << "/";
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int t;
  std::cin >> t;

  if (t == 1) test<int>();
  if (t == 2) test<std::string>();

  std::cout << "\nOK 8Fk7n2RqJhVtYp6LxXw5";
}