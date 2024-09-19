#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <utility> // Include this for std::pair
#include <vector>
#include <stack>

using namespace std; // Add this line to bring std namespace into scope

int eval_postfix(vector<pair<int, int>> v)
{ // Remove std:: qualifiers
  // WRITE YOUR CODE HERE
  // DON"T FORGET TO RETURN THE RESULT
  stack<int> num;
  int o1;
  for (auto it : v)
  {
    if (it.first == 1)
    {
      num.push(it.second);
    }
    else
    { 
      o1 = num.top();
      num.pop();
      switch (it.second)
      {
      case 0:
        o1 += num.top();
        break;
      case 1:
        o1 = num.top() - o1;
        break;
      case 2:
      o1 = num.top() * o1;
        break;
      case 3:
      o1 = num.top() / o1;
        break;
      }
      num.pop();
      num.push(o1);
    }
  }
  return num.top();
}

#endif