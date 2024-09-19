#include <stdexcept>
#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include "vector.h"
#include "student.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

template <typename T>
void do_test() {
  int n,m,repeat;
  cin >> n >> repeat;
  CP::vector<CP::vector<T>> v(n);
  for (int i = 0;i < n;i++) {
    cin >> m;
    v[i].resize(m);
    for (int j = 0;j < m;j++) {
      cin >> v[i][j];
    }
  }


  while(repeat > 0) {
    for (int i = 0;i < n;i++) {
      for (int j = 0;j < n;j++) {
        bool b = v[i] < v[j];
        if (repeat == 1) {
          cout << b << "\n";
        }
      }
    }
    repeat--;
  }
}

int main() {
    std::ios_base::sync_with_stdio(false);std::cin.tie(0);
    int type;
    cin >> type;
    if (type == 1) {
      do_test<int>();
    } else {
      do_test<string>();
    }
}
