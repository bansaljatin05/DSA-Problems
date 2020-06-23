#include<bits/stdc++.h>
using namespace std;

class Triplet {
public:
	int x;
	int y;
	int gcd;
};

Triplet ExtendedEuclid(int a, int b)  {//Extended GCD is values of x and y such that: "a*x + b*y = gcd(a, b)"
	
	if(b==0) {
		Triplet myAns;
		myAns.gcd = a;
		myAns.x = 1;
		myAns.y = 0;
	}

	Triplet smallAns = ExtendedEuclid(b, a%b);
	Triplet myAns;
	myAns.gcd = smallAns.gcd;
	myAns.x = smallAns.y;
	myAns.y = smallAns.x - (a/b)*smallAns.y;

}
int Euclid(int a, int b) {
	if(a<b) return Euclid(b, a);
	if(b==0) return a;
	return Euclid(b, a%b);
}

int main(int argc, char const *argv[])
{
	int a, b;
	cin>>a>>b;
	cout<<Euclid(a, b)<<endl;
	Triplet myTriplet = ExtendedEuclid(a, b);
	return 0;
}
