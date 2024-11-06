#include <iostream>
#include <assert.h>
#include "list.h"
#include <string>
#include <fstream>
using namespace std;


int main() {
  ofstream out("output.txt");
  int n,k;
  CP::list<int> l;

  cin >> n;
  while (n--) {
    int a;
    cin >> a;
    l.push_back(a);
  }
  cin >> k;

  l.shift(k);

  //check result
  l.check();
  auto it = l.begin();
  while (it != l.end()) {
    out << *it << " ";
    it++;
  }
  out << endl;
  it = l.end(); it--;
  while (it != l.end()) {
    out << *it << " ";
    it--;
  }
  out << endl;
  out << "abradacadabra" << endl;

	return 0;
}
