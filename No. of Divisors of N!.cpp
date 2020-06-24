#include<bits/stdc++.h>
#define pb push_back
#define MOD 1000000007
#define MAX 50001
typedef long long ll;
using namespace std;

vector<int> v;

int sieve[MAX + 1]={0};
void primeSieve(int n) {
	for(int i = 3; i <= n; i+=2) {
		sieve[i] = 1;
	} 
	//Main Method 
	for(int i = 3; i <= n; i += 2) {
		if(sieve[i] == 1) {
			for(int j = i*i; j <= n; j += j + i) {
				sieve[j] = 0;
			}
		}
	}
	sieve[2] = 1;
	sieve[1] = 0;
	for(int i = 1; i <= MAX; i++) {
		if(sieve[i]) v.pb(sieve[i]);
	}
}
ll TotalDivisors(int n) {
	ll result = 0;
	for(int i = 0; v[i] <= n; i++) {
		ll count = 0;
		int k = v[i];
		while(n/k) {
			count = (count + (n/k))%MOD;
			k = k*v[i];	
		}
		result = (result + ((count+1)%MOD))%MOD;
	}
	return result;
}

int main(int argc, char const *argv[])
{

	primeSieve(MAX);
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		cout<<TotalDivisors(n)<<endl;
	}

	return 0;
}
