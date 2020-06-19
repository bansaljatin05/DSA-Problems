#include<iostream>
#include<algorithm>
using namespace std;
int n;
int arr[100005];

bool BinarySearch(int key, int s, int e) {
	
	while(s <= e) {
		int mid = (s+e)/2;
		if(arr[mid] == key) return true;
		if(arr[mid] < key) s = mid + 1;
		else e = mid - 1;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int k;
	cin>>n>>k;
	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	int ans = 0;
	sort(arr, arr + n);
	for(int i = 0; i < n; i++) {
		if(BinarySearch(arr[i] + k, 0, n)) ans++;
	}
	cout<<ans;
	return 0;
}