#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll arr[1000006];
ll M, N;

bool possible(ll key) {
	ll required = 0;
	for(int i = 0; i < N; i ++) {
		if(arr[i] > key) {
			required += (arr[i] - key);
		}
	}
	if(required >= M) return true;
	return false;
}

ll BinarySearch(int s, int e) {
	
	ll ans = -1;

	while(s <= e) {
		int mid = (s + e)/2;

		if(possible(mid)) {
			ans = mid;
			s = mid + 1;
		} else {
			e = mid - 1;
		}

	}

	return ans;
}

int main(int argc, char const *argv[])
{

	cin>>N>>M;
	ll minm = INT_MAX;
	ll maxm = INT_MIN;
 	for(int i = 0; i <  N; i++) {
		cin>>arr[i];
		minm = min(arr[i], minm);
		maxm = max(arr[i], maxm);
	}	

	cout<<BinarySearch(minm, maxm);
	return 0;
}