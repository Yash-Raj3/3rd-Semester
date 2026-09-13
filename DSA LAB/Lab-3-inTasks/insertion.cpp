#include<iostream>
using namespace std;
// 13 46 24 52 20 9 
void insertion_sort(int *arr,int n){
	
	for(int i=1;i<n;i++){
	
		int swapped =0;
		int j = i-1;
		while(j>=0 && arr[j] > arr[j+1]){
			int temp =  arr[j+1];
			arr[j+1] = arr[j];
			arr[j] = temp;
			j--;
			swapped =1;
		}
	if(swapped == 0){
		cout<<"Sorted"<<endl;
		break;
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
	cout<<"Before Insertion Sort\n";
	print(arr,n);
	insertion_sort(arr,n);
	cout<<"After Insertion Sort\n";

	print(arr,n);


}




