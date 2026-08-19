#include<iostream>
using namespace std;


class Student{
float  *marks;
int size;
public:
Student (int s){
size = s;
marks  = new float[size];
}
void setMarks(){
    for (int i =0;i<size;i++){
        cout<<"Enter Marks of Sub  "<<i+1<<":";
        cin>>marks[i];
    }
}
float Average(){
    float sum =0;
    for(int i =0;i<size;i++){
        sum += marks[i];
    }
    return sum/size;
}
~Student(){
    delete []marks;
} 
};
int main(){
    int size;
    cout<<"Enter Number of Subs: ";
    cin>>size;
    Student s(size);
    s.setMarks();
    cout<<"Average: "<<s.Average()<<endl;
}