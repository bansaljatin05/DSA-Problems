#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int arr2[100005];
int n, m;

int BinarySearch(int key, int s, int e) {
	int ans = -1;
	while(s <= e) {
		int mid = (s+e)/2;

		if(arr[mid] == key) return ans = mid;
		if(arr[mid] > key) {
			e = mid - 1;
			ans = mid;
		} else {
			s = mid + 1;
		}
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	cin>>n;
	cin>>arr[0];
	for(int i = 1; i < n; i ++) {
		cin>>arr[i];
		arr[i] += arr[i - 1];
	}
	cin>>m;
	for(int i = 0; i < m; i++) {
		cin>>arr2[i];
	}

	for(int i = 0; i < m; i++) {
		cout<<BinarySearch(arr2[i], 0, n) + 1<<endl;
	}
	return 0;
}