#include <iostream>
#include <queue>
using namespace std;

int main(){
    // Priority queue is a queue with priority(ความสำคัญ)
    // Item with high priority is promoted to the front of the queue and no back of the queue
    // Priority is defined by having more value
    // // Comparison, bydefault is to use operator < , if A < B is true then B has higher priority
    // // We can have custom comparator
    // Have same interface as stack
    priority_queue<int> pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    cout << "Current size = " << pq.size() << " top is " << pq.top() << endl;
    pq.pop(); // 30 got popped
    pq.push(15);
    pq.pop(); // 20 got popped
    cout << "Current size = " << pq.size() << " top is " << pq.top() << endl;
    return 0;
}