#include<iostream>
using namespace std;

class Employee{
int id;
string name;
public:
Employee (int i, string n){
id =i;
name = n;
}
string getName(){
    return name;
}
int getID(){
    return id;
}
virtual const void  display() =0;
}; 
class Manager : public Employee{
    public:

    Manager (int i , string name): Employee (i,name){}
   const void display(){
        cout<<"Name: "<<getName()<<" ID: "<<getID()<<endl;
    }

};


int main(){
Manager m1(10,"yash");
m1.display();



}