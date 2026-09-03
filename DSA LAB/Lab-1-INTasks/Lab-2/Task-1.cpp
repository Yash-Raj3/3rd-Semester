#include<iostream>
using namespace std;
int main(){
	int size;
	cout<<"Enter the size of Array: ";
	cin>>size;
	int *arr = new int[size];
	for(int i=0;i<size;i++){
		cout<<"Enter Element "<<i+1<<" :";
		cin>>arr[i];		
	}
	cout<<"Array: ";
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";		
	}
	int sum =0 ,min = arr[0] ,max = arr[0];
 
	for(int i=0;i<size;i++){
		sum += arr[i];
		if(arr[i]>max){
			max = arr[i];
		}		
		if(arr[i]<min){
			min =  arr[i];
		}
	}
	double avg = (double)sum/size;
	cout<<endl;
	cout<<"Sum: "<<sum<<", Average: "<<avg<<", Max: "<<max<<", Min: "<<min<<endl;
	
	delete []arr;
	
}


