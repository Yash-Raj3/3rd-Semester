#include<iostream>
using namespace std;


int interpolation_search(int *arr,int n,int target){
	int low =0,high= n-1;
	
	while(low<=high && target >= arr[low] && target <= arr[high]){
	 int probe = low + (high-low) * (target - arr[low])/(arr[high]-arr[low]);
		if(arr[probe]==target){
			return probe;
		}
		else if(arr[probe]<target){
			low =  probe+1;
		}
		else{
			high = probe -1;
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
	int idx = interpolation_search(arr,n,target);
	cout<<"Target Element Index: "<<idx;
	
	
	
	
	
	delete [] arr;
}
