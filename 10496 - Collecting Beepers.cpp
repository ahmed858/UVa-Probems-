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
#define MAX					13
using namespace std;
const ll mod = 1e6 + 3;
const double EPS = 1e-10;
const double pi = 3.14159265358979323846;
const int Inf = 1e9;
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

int n, wanted;
int xCoor[MAX], yCoor[MAX];
int distances[MAX][MAX];
int memo[MAX][1 << 12];
bool isON( int idx, int mask) {

	return (1 << idx) & mask;
}
int bestCost(int pos, int mask) {
	mask |= (1 << pos);
	if (mask == wanted)
		return distances[pos][0];

	int& cost = memo[pos][mask];
	if (cost == -1) {
		cost = Inf;
		for (int idx = 1; idx < n; idx++) {
			if (!isON(idx, mask)) 
				cost = min(cost, bestCost(idx, mask) + distances[pos][idx]);
		}
	}
	return cost;
}
int main()
{
	fast();
	int t = 1;
	cin >> t;

	while (t--)
	{
		int r, c;
		cin >> r >> c;

		cin >> xCoor[0] >> yCoor[0];
		cin >> n;
		n++;
		for (int i = 1; i < n; i++) {
			cin >> xCoor[i] >> yCoor[i];

			for (int j = 0; j < i; j++)
				distances[i][j] = distances[j][i] =
				abs(xCoor[i] - xCoor[j]) + abs(yCoor[i] - yCoor[j]);
		}

		wanted = (1 << n) - 1;
		memset(memo, -1, sizeof memo);
		/*for (int i = 0; i < n; ++i)
			for (int j = 0; j < wanted; ++j)
				memo[i][j] = -1;*/
		cout << "The shortest path has length " << bestCost(0, 0) << '\n';
	}

}


