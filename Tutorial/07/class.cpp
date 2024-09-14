#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    Student(float score){
        gpax = score;
    }
    void setFullname(string name, string surname) // integrated method
    {
        this->name = name;
        this->surname = surname;
    }
    string getFullname(){
        return "[" + name + " " + surname + "]";
    }

    void changeName(string name,string surname);
private:
    string name,surname;
    float gpax;
};

void Student::changeName(string name,string surname){ // Implement method of class Student from outside the class
    this->name = name;
    this->surname = surname;
}

int main(){
    Student a(9.00);
    Student b(2.00);
    a.setFullname("Chatrin","Yoonchalard");
    cout << a.getFullname() << endl;
    cout << b.getFullname() << endl;
    return 0;
}