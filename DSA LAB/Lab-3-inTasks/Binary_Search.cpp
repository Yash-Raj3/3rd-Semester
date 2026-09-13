#include<iostream>
using namespace std;


int binary_search(int *arr,int n,int target){
	int left =0,right= n-1;
	while(left<=right){
	 int	mid = left + (right-left)/2;
		if(arr[mid]==target){
			return mid;
		}
		else if(arr[mid]<target){
			left =  mid+1;
		}
		else{
			right = mid -1;
		}
		
		
	}
	return -1;
}
int* EnterArray(int *arr,int n){
	arr = new int[n];
	cout<<"Enter Sorted Array\n";
	for(int i=0;i<n;i++){
		cout<<"Enter Element "<<i<<": ";
		cin>>arr[i];
	}
	
	return arr;
}
int main(){
	int n,target;
	cout<<"Enter Size of Array: ";
	cin>>n;
	int *arr = EnterArray(arr,n);
	cout<<"Enter Target Element: ";
	cin>>target;
	int idx = binary_search(arr,n,target);
	cout<<"Target Element Index: "<<idx;
	
	
	
	
	
	delete [] arr;
}
