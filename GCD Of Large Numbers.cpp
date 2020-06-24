#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int modOperation(string a, int b) {
	int number = 0;
	for(int i = 0; i < a.length(); i++) {
		number*=10;
		number%=b;
		number += (a[i] - '0')%b;
		number%=b;
	}
	return number;
}
int GCD(int a, int b) {
	if(a<b) return GCD(b, a);
	if(b==0) return a;
	return GCD(b, a%b);
}
int main() {
	string a;
	int b;
	cin>>a>>b;
	cout<<GCD(b, modOperation(a, b))<<endl;
}
