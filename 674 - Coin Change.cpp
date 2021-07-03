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
void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
// O(NV) DP solution
int V;
int coins[] = { 1,5,10,25,50 };
int memo[5][7489];
ll ways(int type, int value) {
	if (value == 0)return 1;
	if (type == 5 || value < 0)return 0;

	int& ret = memo[type][value];
	if (ret != -1)return ret;
	return ret = ways(type + 1, value) + ways(type, value - coins[type]);
}

int main()
{
	fast();
		
		memset(memo, -1, sizeof memo);
	while (scanf("%d", &V) != EOF)//UVa eeeeeeeeeeeeeeeeeeeeeeeeee
		cout << ways(0, V)<<endl;
	
}


