#include <iostream>
#include <map>
using namespace std;

int main(){
    map<string,int> m; // Like Dictionary in Python
    // Key type of map must comparable ex.int,bool,float,string,double,char,.... (can be Pair if type of first and second are comparable)
    // Value type can be anything
    m["Chat"] = 10;
    m["Chad"] = 20;
    cout << "Size : " << m.size() << endl;

    //access unseen Key create a map with default value (0)
    cout << "m[\"xxx\"] = " << m["xxx"] << endl;
    //each element is a pair of Key Type and Mapped Type
    for (auto it = m.begin(); it != m.end();it++){ // Map iterator เรียงตาม Key จาก น้อยไปมาก
        cout << it->first << " is mapped to " << it->second << endl;
    }
    //this will create mapping "abc" to 0 first and then increase it
    m["abc"]++;
    cout << "now size = " << m.size() << endl;
    for (auto &x : m){
        cout << x.first << " is mapped to " << x.second << endl;
    }

    // Usage of find()

    //Check if map has this key
    if(m.find("Chat") != m.end()){
        cout << "Found" << endl;
    }else{
        cout << "Does not found" << endl;
    }
    // ในการเช็คว่ามี Key ใน Map ไหมไม่ใช้วิธีเช็คว่า Value ที่ Pair กับ Key นั้นเป็น Default value ไหม
    // เพราะ Key นั้นอาจมีอยู่และ Pair กับ Default valaue จริงๆ

    // Question
    // Q1: Both map and set has insert and erase method but what is the return value of both function of each data structure // Ans: Both Set & Map return number of deleted element
    // For set<int> can we do s.erase(20) // Ans: Yes we can
    // For map<string,bool> m, can we do m.erase("Somchai")?? // Ans: Yes, we can method erase of map can accept Key, Iterator, Range of iterator

    // Q2: If we wish to errase element from index 3 to index 4096 in a vector
    // is there any function we can easily use? // Ans: Yes,there is erase(v.begin()+3,v.begin()+4096)


    return 0;
}