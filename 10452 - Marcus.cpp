/*

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
#define MAX					9
using namespace std;
const ll mod = 1e6;
const double EPS = 1e-10;
const double pi = 3.14159265358979323846;
const int Inf = 1e9;
void fast() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
int n, m, idx;
int Ex, Ey;
int Sx, Sy;
char grid[MAX][MAX];
string word = "IEHOVA#";
vector<string>ans;
bool valid(int i, int j)
{

	return
		i < n&& i >= 0 &&
		j < m&& j >= 0;
}
void solve(int i, int j) {
	if (!valid(i, j))
		return;
	if (grid[i][j] == '#')
		return;
	if (grid[i - 1][j] == word[idx]) {
		ans.push_back("forth");
		idx++;
		solve(i - 1, j);
	}
	else if (grid[i][j + 1] == word[idx]) {
		ans.push_back("right");
		idx++;
		solve(i, j + 1);

	}
	else if (grid[i][j - 1] == word[idx]) {
		ans.push_back("left");
		idx++;
		solve(i, j - 1);

	}

}
int main()
{
	fast();
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		idx = 0;
		ans = vector<string>();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> grid[i][j];
				if (grid[i][j] == '@')
					Sx = i,
					Sy = j;

			}
		solve(Sx, Sy);
		cout << ans[0];
		for (int i = 1; i < sz(ans); i++){
			cout << " " << ans[i];
}
		cout << endl;
	}
}


*/
// alittle bit cool solution

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
#define MAX					9
using namespace std;
const ll mod = 1e6;
const double EPS = 1e-10;
const double pi = 3.14159265358979323846;
const int Inf = 1e9;
void fast() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
int dx[] = { -1,0,0 };
int dy[] = { 0,1,-1 };
int n, m;
int Sx, Sy;
char grid[MAX][MAX];
string word = "IEHOVA#";
string dir[] = { "forth","right","left" };
vector<string>ans;
bool valid(int i, int j){
	return i < n&& i >= 0 &&j < m&& j >= 0;
}
void solve(int i, int j,int idx=0) {
	if (idx > sz(word))return;
	
	for (int k = 0; k < 3; k++) {
		int newX = i + dx[k];
		int newY = j + dy[k];
		if (valid(newX, newY) && grid[newX][newY] == word[idx]) {
			ans.push_back(dir[k]);
			solve(newX, newY, idx + 1);
		}
	}

}
int main()
{
	fast();
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		ans = vector<string>();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> grid[i][j];
				if (grid[i][j] == '@')
					Sx = i,
					Sy = j;

			}
		solve(Sx, Sy,0);
		cout << ans[0];
		for (int i = 1; i < sz(ans); i++) 
			cout << " " << ans[i];
		
		cout << endl;
	}
}




