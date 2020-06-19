#include<iostream>
using namespace std;

int n;
int arr[10000];

int FindPivotElement(int s, int e, int key) {
	
	if(s>e) return -1;

	int mid = (s+e)/2;
	if(arr[mid] == key) return mid;

	if(arr[mid] >= arr[s]) {
		if(key >= arr[s] && key <= arr[mid]) {
			return FindPivotElement(s, mid - 1, key);
		} else {
			return FindPivotElement(mid + 1, e, key);
		}
	} else {
		if(key >= arr[mid] && key <= arr[e]) {
			return FindPivotElement(mid + 1, e, key);
		} else {
			return FindPivotElement(s, mid - 1, key);
		}
	}
}

int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	int key;
	cin>>key;

	cout<<FindPivotElement(0, n - 1, key);

	return 0;
}