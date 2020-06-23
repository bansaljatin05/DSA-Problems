#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int n;
int sieve[10000000] = {0};
void primeSieve() {
	for(int i = 3; i <= n; i+=2) {
		sieve[i] = 1;
	} 

	//Main Method 
	for(int i = 3; i <= n; i += 2) {
		if(sieve[i] == 1) {
			for(int j = i*i; j < n; j += j + i) {
				sieve[j] = 0;
			}
		}
	}
	sieve[2] = 1;
	sieve[1] = 0;
	for(int i = 1; i <= n; i++) {
		if(sieve[i]) cout<<i<<" ";
	}
}
 

int main(int argc, char const *argv[])
{
	
	cin>>n;
	primeSieve();
	return 0;
}