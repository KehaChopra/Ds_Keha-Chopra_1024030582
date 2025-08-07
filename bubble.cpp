#include <iostream>
using namespace std;
int main(){
	int arr[7];
	cout<<"enter array to be sorted";
	for(int i=0;i<7;i++){
		cin>>arr[i];
	}
	for(int i=0;i<7;i++){
		for(int j=0;j<7-i-1;j++){
			if(arr[j]>arr[j+1]){
			int temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
			}
		
		}
	}
	cout<<"array in sorted order ";
	for(int i=0;i<7;i++){
		cout<<arr[i];
	}
	return 0;
}
