#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int moduloExpo(int a, int b, int c) { //complexity -> o(log(n))
	if(b==0) return 1;
	if(b&1) return ((a%c)*(moduloExpo((a*a)%c, b/2, c)))%c;
	else return moduloExpo((a*a)%c, b/2, c);
} 
int moduloExpoIterative(int a, int b, int c) { // Complexity -> o(log(n))
	int ans = 1;
	while(b) {
		if(b&1) {
			ans = (ans*a)%c;
		}
		b/=2;
		a = (a*a)%c;
	}
	return ans%c;
}

int main(int argc, char const *argv[])
{
	int a, b, c;
	cin>>a>>b>>c;
	cout<<moduloExpoIterative(a, b, c)<<endl;
	return 0;
}