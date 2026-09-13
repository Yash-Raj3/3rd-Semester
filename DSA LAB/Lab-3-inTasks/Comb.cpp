#include<iostream>
using namespace std;
// 13 46 24 52 20 9 
void comb_sort(int *arr,int n){
int gap =  n;
int swapped = 1;
while(gap!=1 || swapped == 1){
	gap = (gap*10)/13;
	if(gap < 1){
		gap=1;
	}
	swapped = 0;
	for(int i=0;i<n-gap;i++){
		if(arr[i] > arr[i+gap] ){
			int temp = arr[i];
			arr[i] = arr[i+gap];
			arr[i+gap] = temp;
			swapped = 1;
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
	cout<<"Before Comb Sort\n";
	print(arr,n);
	comb_sort(arr,n);
	cout<<"After Comb Sort\n";

	print(arr,n);


}




