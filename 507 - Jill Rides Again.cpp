#include<bits/stdc++.h>

#define ll				    long long
#define all(v)			    v.begin(),v.end()
#define allr(v)			    v.rbegin(),v.rend()
#define YES				    cout << "YES\n";
#define NO				    cout << "NO\n";
#define endl			    "\n"
#define vi				    vector<int>
#define vl				    vector<ll>
#define wach(x)			    cerr<<(#x)<<" = ("<<(x)<<")"<<"\n"
#define RT(v)			    return cout<<v,0
#define sz(x)			    x.size()
#define pii					pair<int,int>
#define MAX					501
using namespace std;
const ll mod = 1e6 + 3;
const double EPS = 1e-10;
const double pi = 3.14159265358979323846;
void fast(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);
}
int  n;
vector < int>v;

void input() {
	cin >> n;
	v = vi(n);
	n--;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
}
pair<int,pii> kadaneAlgo() {
	int sum = 0, ans = INT_MIN, l = 1, ret_l, ret_r;
	for (int r = 1; r <= n; r++)//max end
	{
		sum += v[r];
		if (sum < 0) {
			l = r + 1;
			sum = 0;
		}

		if (sum > ans || (sum == ans && (ret_r - ret_l < r - l))) {
			ans = sum;
			ret_l = l;
			ret_r = r;
		}

	}
	return { ans,{ret_l,ret_r} };
}
int main()
{
	fast();
	int t = 1;
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		input();
		pair<int, pii> p = kadaneAlgo();
		wach(p.first);
		if (p.first <= 0) {
			cout << "Route " << i << " has no nice parts";
		}
		else cout << "The nicest part of route " << i << " is between stops " << p.second.first << " and " << p.second.second+1;
		cout << endl;
	}
	
}
