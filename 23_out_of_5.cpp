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

using namespace std;
const ll mod = 1073741824;
const double EPS = 1e-10;
const double pi = 3.14159265358979323846;
void fast()
{
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}
vi v;
bool  solve(int i, int n)
{
	// base case
	if (i == 5) {
		return (n == 23);
	}
	// transition 
	return 
		solve(i + 1, n + v[i]) ||
		solve(i + 1, n - v[i]) ||
		solve(i + 1, n * v[i]);
}
int main()
{
	fast();
	while (true)
	{
		v = vi(5);
		int x = 0;
		for (int i = 0; i < 5; i++)
		{
			cin >> v[i];
			x += v[i];
		}
		if (!x)
			return 0;
		sort(all(v));
		bool valid = false;
		do {
			valid |= solve(1, v[0]);
		} while (next_permutation(all(v)));
		if (valid)
			cout << "Possible";
		else 
			cout << "Impossible";
		cout << endl;
	}
	return 0;
}
