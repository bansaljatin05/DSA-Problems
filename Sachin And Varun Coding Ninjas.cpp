#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

class Triplet {
public: 
	ll x;
	ll y;
	ll gcd;
};

ll gcd(ll a, ll b) {
	if(a < b) return gcd(b, a);
	if(b == 0) {
		return a;
	}

	return(b, a%b);
}

Triplet ExtendedEuclid(ll a, ll b) {
	if(b == 0) {
		Triplet myAns;
		myAns.x = 1;
		myAns.y = 0;
		myAns.gcd = a;
		return myAns;
	}

	Triplet smallAns = ExtendedEuclid(b, a%b);
	Triplet myAns;
	myAns.gcd = smallAns.gcd;
	myAns.x = smallAns.y;
	myAns.y = smallAns.x - (a/b)*(smallAns.y);

	return myAns;
}

ll multiplicativeModuloInv(ll A, ll B) {
	Triplet ans = ExtendedEuclid(A, B);
	return (ans.x % B + B) % B;
}   

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--) {
		ll a, b, d;
		cin>>a>>b>>d;
		ll g = gcd(a, b);

		if(d % g) {
			cout<<0<<endl;
			cout<<"Fo"<<endl;
			continue;
		} 

		if(d == 0) {
			cout<<1<<endl;
			continue;
		}

		a /= g;
		b /= g;
		d /= g; 

		ll y1 = ((d%a) * multiplicativeModuloInv(b, a)) % a;
		ll firstValue = d/b;

		if(d < y1 * b) {
			cout<<0<<endl;
			cout<<"Yo"<<endl;
			continue;
		}

		ll n = (firstValue - y1) / a;
		cout<<n+1<<endl; 
	}
	
	return 0;
}

