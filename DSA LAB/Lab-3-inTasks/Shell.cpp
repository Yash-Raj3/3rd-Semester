#include<iostream>
using namespace std;
// 13 46 24 52 20 9 
void shell_sort(int *arr,int n){
	for(int gap = n/2;gap >= 1;gap /= 2){
		for(int i = gap;i<n;i++){
			int j = i-gap;
			while(j>= 0 && arr[j] > arr[j+gap]){
				int temp =  arr[j];
				arr[j] =  arr[j+gap];
				arr[j+gap] = temp;
				j = j-gap;
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
	cout<<"Before shell Sort\n";
	print(arr,n);
	shell_sort(arr,n);
	cout<<"After shell Sort\n";

	print(arr,n);


}




