#include "queue.h"
#include "student.h"
#include <iostream>
using namespace std;

void print(CP::queue<int> q){
  CP::queue<int> temp(q);
  cout << "Queue: ";
  while(!temp.empty()){
    cout << temp.front() << " ";
    temp.pop();
  }
  cout << endl;
}

int main() {
  CP::queue<int> q;
  char c;
  scanf("%c", &c);
  while (c != 'q') {
    if (c == 'u') {
      // add data
      int v;
      scanf("%d", &v);
      q.push(v);
    } else if (c == 'o') {
      q.pop();
    } else if (c == 'p') {
      print(q);
    } else if (c == 'm') {
      q.reverse();
    } else if(c == 'b'){
      cout << q.back() << endl;;
    }
    scanf("%c", &c);
  }
}