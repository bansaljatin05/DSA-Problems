#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int arr[1000];
int n;

int Solution() {
	vector<int> v1;
	vector<int> v2;
	pair<vector<int>::iterator, vector<int>::iterator> p;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				v1.push_back(arr[i]*arr[j] + arr[k]);
				if(arr[i] != 0)//Condition for d != 0 ***Very important to remember****
				v2.push_back(arr[i]*(arr[j] + arr[k]));
			}
		}
	}
	int sum = 0;
	sort(v2.begin(), v2.end());
	for(int i = 0; i < v1.size(); i++) {
		p = equal_range(v2.begin(), v2.end(), v1[i]);
		sum += (p.second - p.first);
	}

	return sum;
}

int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}

	cout<<Solution();
	return 0;
}