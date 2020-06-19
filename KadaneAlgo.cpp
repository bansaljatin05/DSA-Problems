#include<iostream>
using namespace std;

int arr[10000];
int n;

int KadaneAlgo() {
	int maxSum = 0;
	int currSum = 0;
	for(int i = 0; i < n; i++) {
		currSum += arr[i];
		if(currSum < 0) currSum = 0;
		maxSum = max(currSum, maxSum);
	}
	return maxSum;
}

int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}

	cout<<KadaneAlgo();


	return 0;
}