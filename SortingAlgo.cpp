#include<bits/stdc++.h>
using namespace std;
int arr[10000];
int n;

void selectionSort() {
	for(int i = 0; i < n - 1; i++) {
		int minIdx = i;
		for(int j = i; j < n; j++) {
			if(arr[j] < arr[minIdx]) minIdx = j;
		}
		swap(arr[i], arr[minIdx]);
	}
}

void bubbleSort() {
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < n-i; j++) {
			if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
		}
 	}
}

void insertionSort() {
	for(int i = 0; i < n; i++) {
		int j = i - 1;
		int curr = arr[i];
		while(j >= 0 && curr < arr[j]) {
			arr[j+1] = arr[j];
			j = j - 1; 
		}
		arr[j+1] = curr;
	}
}

int main(int argc, char const *argv[])
{
	cin>>n;

	for(int i = 0; i < n; i++) cin>>arr[i];
	insertionSort();

	for(int i = 0 ;i <  n; i ++) {
		cout<<arr[i]<<" ";
	}
	return 0;
}