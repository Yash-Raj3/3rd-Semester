#define HEADER1_H
#ifndef HEADER1_H
#include<string>
#include<iostream>
using namespace std;

class Employee{	
	int id;
		string name;
public:
		
Employee(int i, string n){
	name = n;
	id = i;
}

void display(){
	cout<<"Name: "<<name<<" ID: "<<id<<endl;
}
	
};
#endif