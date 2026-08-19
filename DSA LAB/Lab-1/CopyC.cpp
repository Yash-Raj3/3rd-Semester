#include<iostream>
using namespace std;


class Student{
float  *marks;

public:
int size;
Student (int s){
size = s;
marks  = new float[size];
}
 Student (const Student &other){
    size = other.size;
    marks = new float [other.size];
    for (int i=0;i<size;i++ ){
        marks[i] = other.marks[i];
    }
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
void changeMark(){
   for(int i =0;i<size;i++){
     cin>>marks[i];
   }
}
~Student(){
    delete []marks;
} 
void avg(){
    cout<<"Average: "<<Average()<<endl;
}
};
int main(){
    int size;
    cout<<"Enter Number of Subs: ";
    cin>>size;
    Student s1(size);
    s1.setMarks();
    s1.avg();
    Student s2 =  s1;
    s2.avg();
    s1.changeMark();
    s1.avg();
    s2.avg();

}