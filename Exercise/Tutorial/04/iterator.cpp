#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> v){
    cout << "v contains : ";
    for(int &x : v){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    vector<int> v1 = {1,2,3};
    vector<float> v2 = {4,5,6,7.0,8.0};
    
    vector<int>::iterator it1 = v1.begin() + 3;
    vector<float>::iterator it2 = v2.end();

    //getting value at iterator using "*" operator
    cout << *it1 << endl;
    cout << *(it2-1) << endl;
    cout << *it1+2 << endl;

    //iterator arithmatics
    vector<int>::iterator it3 = it1 + 2;
    cout << "data at it3: " << *it3 << endl;
    cout << "different of it3,it1: " << (it3-it1) << endl;

    // This cannot be done
    // cout << (it2-it1) << endl; // getting an error because both are iterator from different data type

    auto it = v1.begin(); // Set data type of it to v1.begin() automatically

    it1 = min_element(v1.begin(),v1.end());
    it2 = max_element(v2.begin()+2,v2.end());

    cout << "Min element of v1 is : " << *it1 << endl;
    cout << "Max element of v2 is : " << *it2 << endl;

    // iterate all element

    for (auto &x : v1){ // &x is pass by element then x is a each element that in v1
        x++;
    }
    print_vector(v1);

    // iterator invalidation

    auto it4 = v1.begin();
    v1.resize(10);
    cout << "*it4 invalid value is : " << *it4 << endl; // it4 access memory that not useable because v1.resize(10) allocate new memory area 
    //then it's mean that it4 is now point to unallocated memory then we call it4 is invalidated iterator

    return 0;
}