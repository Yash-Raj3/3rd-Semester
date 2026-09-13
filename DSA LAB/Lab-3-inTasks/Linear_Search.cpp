#include<iostream>
using namespace std;
int linear_Search(int *arr,int n,int target){
	
	for(int i=0;i<n;i++){
		if(arr[i] == target){
			return i;
			break;
		}
	}
	return -1;
	
	
}
int* EnterArray(int n){
	int *arr = new int [n];
	cout<<"Enter Unsorted Array\n";
	
	for(int i=0;i<n;i++){
		cout<<"Enter Element "<<i<<": ";
		cin>>arr[i];
	}
	return arr;
}
void print(int *arr,int n){
	cout<<"----Array----\n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
int n;
cout<<"Enter Size of Array: ";
cin>>n;
int *arr = EnterArray(n);	
int target;
cout<<"Enter Target Element: ";
cin>>target;
int idx = linear_Search(arr,n,target);
if(idx != -1){
	cout<<"Target "<<target<<" Element Index: "<<idx<<endl;
}else{
	cout<<"Not Found!"<<endl;
}
delete[] arr;
	
}
