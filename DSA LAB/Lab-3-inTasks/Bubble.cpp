#include<iostream>
using namespace std;
// pushes Maximum to the last by adjacent swaps
//13 46 24 52 20 9 
void bubble_sort(int *arr,int n){
	for(int i=0;i<n-1;i++){
		for(int j =0;j<n-i-1;j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
}

void print(int *arr,int n){
	for (int i = 0; i < n; i++)
{
    cout << arr[i] << " ";
}
cout << endl;

	
	
}
void EnterArray(int *arr,int n){
	for(int i=0;i<n;i++){
		cout<<"Enter Element "<<i<<" :";
		cin>>arr[i];
	}
}

int main()
{
    int n;
	cout<<"Enter Array Size: ";
	cin>>n;
	
    int *arr = new int[n];
	EnterArray(arr,n);
	print(arr,n);
	bubble_sort(arr,n);
	cout<<"Sorted Array"<<endl;
	print(arr,n);


}

