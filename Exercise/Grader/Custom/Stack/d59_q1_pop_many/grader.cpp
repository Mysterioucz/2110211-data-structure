#include <iostream>
#include <vector>
#include <stack>
#include "stack.h"
#include "student.h"
#include <fstream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  CP::stack<int> s;
  std::ofstream outputFile;
  outputFile.open("outputfile.txt", std::ios_base::app);
  char c;
  scanf("%c", &c);
  while (c != 'q') {
    if (c == 'a' || c == 'm' || c == 'r') {
      // add data
      int n;
      scanf("%d", &n);
      if (c == 'a') {
        s.push(n);
      } else if (c == 'm') {
        s.multi_pop(n);
      } else if (c == 'r') {
        auto s1 = s.remove_top(n);
        printf("remove_top Result: Size = %d Data =",(int)s.size());
        outputFile <<"remove_top Result: Size = " << (int)s.size() << " Data =";
        while (s1.empty() == false) {
          printf(" %d",s1.top()); s1.pop();
          outputFile << " " <<s1.top();
        }
        printf("\n");
        outputFile << "\n";
      }
    } else if (c == 'd') {
       s.pop();
    } else if (c == 'p') {
      s.print();
    }
    scanf("%c", &c);
    outputFile.close();
  }
  return 0;
}
