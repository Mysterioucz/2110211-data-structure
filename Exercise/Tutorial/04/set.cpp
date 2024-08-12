#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    // Set : Fast look up, Fast erase, Slow insert, iterator start from minimum to maximum
    set<int> s = {4,1,3,2,1,1,3,4};
    set<string> s1 = {"c","a","a","z","x"};
    vector<int> v1 = {3,1,2};
    vector<int> v2 = {5,7,1};
    set<vector<int>> s2 = {v1,v2};

    cout << "Size of s is " << s.size() << endl;

    s.insert(10);
    s.insert(5);
    s.erase(3); // delete value 3 from set

    cout << "Member of set is : ";
    for(auto &it : s)cout << it << " ";
    cout << endl;

    // Set iterator

    // cannot do s.begin() + x is not as fast as vector
    cout << *(s.begin()) << endl; // this is work
    // cout << *(s.begin() + 2) << endl; // this is not
    // We can't compare set iterator เพราะ Set เก็บข้อมูลแบบโครงสร้างแปลกๆ ไม่ใช่เส้นตรง
    // สามารถใช้ it++, it-- ได้ในการไปข้างหน้าและย้อนกลับ


    return 0;
}