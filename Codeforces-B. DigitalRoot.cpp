#include<iostream>
#define ll long long
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	while(n--) {
		ll k, m;
		cin>>k>>m;
		cout<<(9*(k-1) + m)<<endl;
	}
	return 0;
}
