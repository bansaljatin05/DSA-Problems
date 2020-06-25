#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int moduloExpo(int a, int b, int c) {
	if(b==0) return 1;
	if(b&1) return ((a%c)*(moduloExpo((a*a)%c, b/2, c)))%c;
	else return moduloExpo((a*a)%c, b/2, c);
} 

int main(int argc, char const *argv[])
{
	int a, b, c;
	cin>>a>>b>>c;
	cout<<moduloExpo(a, b, c)<<endl;
	return 0;
}