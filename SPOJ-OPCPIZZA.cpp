#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int n, m, t;

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
	cin>>t;
	while(t--) {
		cin>>n>>m;
		for(int i = 0; i < n; i++) {
			cin>>arr[i];
		}
		sort(arr, arr + n);
		int ans = 0;
		for(int i = 0; i < n; i++) {
			if(BinarySearch(m - arr[i], i + 1, n - 1)) ans++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}