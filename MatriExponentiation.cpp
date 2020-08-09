#include<iostream>
using namespace std;

void multiply(int A[2][2], int M[2][2]) {

	int fvalue = A[0][0] * M[0][0] + A[0][1] * M[1][0];
	int svalue = A[0][0] * M[0][1] + A[0][1] * M[1][1];
	int tvalue = A[1][0] * M[0][0] + A[1][1] * M[1][0];
	int lvalue = A[1][0] * M[0][1] + A[1][1] * M[1][1];

	A[0][0] = fvalue;
	A[0][1] = svalue;
	A[1][0] = tvalue;
	A[1][1] = lvalue;
}

void power(int arr[2][2], int n) {
	if(n == 1 || n == 0) {
		return;
	}

	power(arr, n/2);
	multiply(arr, arr);

	if(n % 2 != 0) {
		int M[2][2] = {{1, 1}, {1, 0}};
		multiply(arr, M);
	}
}

int fib(int n) {
	int arr[2][2] = {{1, 1}, {1, 0}};

	if(n == 0) return 0;

	power(arr, n - 1);
	return arr[0][0];
}

int main(int argc, char const *argv[])
{
	cout<<fib(8)<<endl;
	return 0;
}