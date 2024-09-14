#include <iostream>
#include <string>
#include <queue>
using namespace std;

string operator*(string &lhs, const int &rhs){ // & : pass by reference (ต้องเป็น Object เท่านั้น)
    string result = "";
    for (int i=0 ; i < rhs; i++){
        result = result + lhs;
    } // lhs : Left Hand Side, rhs : Right Hand Side
    return result;
}
class Student{
public:
string name,surname;
float gpax;
    Student(float score,string a,string b){
        name = a;
        surname = b;
        gpax = score;
    }
    bool is1stHonor(){
        return gpax >= 3.6;
    }
    bool operator <(const Student &other) const { // Overloading operator "<" less-than
        return gpax < other.gpax;
    }

};

int main(){
    string a = "AbC ";
    cout << (a*9) << endl; // ปกติคุณ int & string ไม่ได้แต่เรา Custom ให้ทำได้
    Student s1(3.7,"Somchai","Eiei");
    Student s2(4.00,"Huh","Sapon");
    cout << (s1 < s2) << endl;
    priority_queue<Student> pq;
    pq.push(s1);
    pq.push(s2);
    cout << pq.top().name << endl;
    return 0;
}