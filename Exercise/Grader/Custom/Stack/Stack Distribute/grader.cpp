#include <iostream>
#include <vector>
#include <string>
#include "stack.h"
#include "student.h"

using namespace std;

string convert_to_string(int p) {
  return to_string(p) + "a";
}

bool check_int(int n,int k,int repeat) {
  CP::stack<int> s;
  for (int i = n-1;i >= 0;i--) {
    s.push(i);
  }

  while (repeat--) {
    vector<vector<int>> x = s.distribute(k);

    //check
    int p = 0;
    int a = n/k;
    int b = n%k;
    for (int i = 0;i < k;i++) {
      int expect = a;
      if (i < b) expect++;
      for (int j = 0;j < expect;j++) {
        if (x[i][j] != p) {
          return false;
        }
        p++;
      }
    }
  }
  return true;
}

bool check_string(int n,int k,int repeat) {
  CP::stack<string> s;
  for (int i = n-1;i >= 0;i--) {
    s.push(convert_to_string(i));
  }

  while (repeat--) {
    vector<vector<string>> x = s.distribute(k);

    //check
    int p = 0;
    int a = n/k;
    int b = n%k;
    for (int i = 0;i < k;i++) {
      int expect = a;
      if (i < b) expect++;
      for (int j = 0;j < expect;j++) {
        string value = convert_to_string(p);
        if (x[i][j] != value) {
          return false;
        }
        p++;
      }
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);

  int type,n,a,b,c;
  cin >> n;
  while(n--) {
    cin >> type >> a >> b >> c;
    if (type == 0) {
      bool res = check_int(a,b,c);
      if (!res) {
        cout << "ERROR int" << endl;
        return 0;
      }
    } else {
      bool res = check_string(a,b,c);
      if (!res) {
        cout << "ERROR String" << endl;
        return 0;
      }
    }
  }
  cout << "OK!!!! a;lsdkj;alui4h;jalds;lkvjnzlxckjhbvzkhjsgahgdkfl" << endl;
}



