#include <iostream>
using namespace std;
// tC = O(n^2)
// gets the minimum and swap it with the ith element
void selection_sort(int *arr,int n){
	
	for(int i=0;i<n-1;i++){
	int min = i;
	for(int j=i+1;j<n;j++){
		if(arr[j]<arr[min]){
			min =j;
		}
	}
	int temp = arr[min];
	arr[min] = arr[i];
	arr[i] = temp;
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
	selection_sort(arr,n);
	cout<<"      Sorted Array    "<<endl;
	print(arr,n);


}

