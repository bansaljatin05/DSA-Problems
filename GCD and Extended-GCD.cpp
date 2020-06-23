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

int ModuloMultiplicativeInverse(A, M) { //For A given A, M in (A.B)%M = 1 find the value of B in range[1, M-1]
	Triplet ans = ExtendedEuclid(A, M);
	return ans.x;
}

int main(int argc, char const *argv[])
{
	int a, b;
	cin>>a>>b;
	cout<<Euclid(a, b)<<endl;
	Triplet myTriplet = ExtendedEuclid(a, b);
	return 0;
}
