#include<iostream>
using namespace std;
int arr[1000][1000];
int prefixMatrix[1000][1000] = {0};
int m, n;

int Ans() {
	int sum = 0;

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			int tl = (i+1)*(j+1);
			int br = (n-j)*(m-i);
			sum += arr[i][j]*tl*br;
		}
	}

	return sum;
}

int main() {
    cin>>m>>n;

    for(int i = 0; i < m; i++) {
    	for(int j = 0; j < n; j++) {
    		cin>>arr[i][j];
    	}
    }
    
    cout<<Ans()<<endl;
}