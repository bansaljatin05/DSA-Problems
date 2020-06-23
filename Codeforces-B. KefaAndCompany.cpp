#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<utility>
#define ll long long int
using namespace std;
pair<ll, ll> p[100005];
ll n, d, m, s;

int main(int argc, char const *argv[])
{
	cin>>n>>d;
	cin>>m>>s;
	p[0] = make_pair(m, s);
	for(int i = 1; i < n; i++) {
		cin>>m>>s;
		p[i] = make_pair(m, s);
	}
	sort(p, p + n);

 	ll ans = INT_MIN;
 	ll right = 0, curr = 0;
	for(ll left = 0; left < n; left++) {
		while(right < n && abs(p[left].first - p[right].first) < d) {
			curr += p[right].second;
			right++;	
		}
		if(curr > ans) ans = curr;
		curr-=p[left].second;
	}
	cout<<ans<<endl;
	return 0;
}