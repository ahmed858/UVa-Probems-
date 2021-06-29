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
void fast(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);
}
int w, n,ans=0;
int city[MAX][MAX];


bool valid(int x, int j) {
	return  city[x][j] && x <= w && j <= n;
}
int solve(int i = 1, int j = 1) {
	if (!valid(i, j))
		return 0;
	if (i == w && j == n )
		return 1;
	int a = solve(i, j + 1);
	int b = solve(i + 1, j);
	
	return a + b;
}
int memo[MAX][MAX];
int memo_solve(int i, int j) {
	if (!valid(i, j))
		return 0;
	int& ans = memo[i][j];
	if (ans != -1)
		return ans;
	if (i == w && j == n)
		return ans=1;
	

	int a = solve(i, j + 1);
	int b = solve(i + 1, j);
	
	return ans=a + b;
}
int main()
{
    fast();
	int t=1;
	cin >> t;
	while (t--)
	{
		memset(city, 1, sizeof city);
		memset(memo, -1, sizeof memo);
		cin >> w >> n;
		cin.ignore();
		for (int i = 1; i <= w; i++)
		{
			int f = 0 , j;
			string s;
			getline(cin, s);
			stringstream ss(s);
			while (ss >> j) {

				if(f)city[i][j] = 0;
				f = 1;
			}
		}
		cout << memo_solve(1, 1) << endl;
		if (t)cout << endl;
	}
}
