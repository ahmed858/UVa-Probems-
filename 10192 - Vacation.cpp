#define _CRT_SECURE_NO_WARNINGS
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
#define MAX					1001
using namespace std;
const ll mod = 1e6 + 3;
const double EPS = 1e-10;
const double pi = 3.14159265358979323846;
bool valid(int i, int j) 
{
int n=0, m=0;
	return 
		i < n && i >= 0 &&
		j < m && j >= 0;
}
void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

string mummy, dady;
int memo[100][100];
int solve(int i, int j) {
	if (i == sz(mummy) || j == sz(dady))return 0;
	int& ret = memo[i][j];
	if (ret != -1)
		return ret;
	if (mummy[i] == dady[j])
		return ret = 1 + solve(i + 1, j + 1);
	int ch1 = solve(i + 1, j);
	int ch2 = solve(i, j + 1);
	return ret = max(ch1, ch2);
}
int main()
{
	fast();
	int t=1; 
	//cin >> t;

	while (getline(cin,mummy), mummy[0] != '#')
	{
		getline(cin, dady);
		memset(memo, -1, sizeof(memo));
		cout << "Case #" << t++ << ": you can visit at most " << solve(0, 0) << " cities.\n";
		
	}


}


