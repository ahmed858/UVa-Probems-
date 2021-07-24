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
const ll mod = 1e6;
const double EPS = 1e-10;
const double pi = 3.14159265358979323846;
const int Inf = 1e9;

int dx[]{ 1, 0, 0, -1, 1, 1, -1, -1 };
int dy[]{ 0, 1, -1, 0, 1, -1, 1, -1 };

//TK
int DX[] = { 1,1,-1,-1,2,2,-2,-2 };
int DY[] = { 2,-2,2,-2,1,-1,1,-1 };
void fast() {

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
}
int cnt[MAX], price[MAX],n;
int memo[MAX][MAX];
int solve1(int last_idx, int cur_idx) {//O(n*n*n)
	if (cur_idx == n)return 0;

	int& ret = memo[last_idx][cur_idx];
	if (~ret)return ret;
	int sum = 0;
	for (int i = last_idx; i <= cur_idx; i++)
		sum += cnt[i];
	sum += 10;
	ret = (sum * price[cur_idx]) + solve1(cur_idx + 1, cur_idx + 1);

	if (cur_idx != n - 1)
		ret = min(ret, solve1(last_idx, cur_idx + 1));
	return ret;
}
int prefix[MAX];
int solve2(int last_idx, int cur_idx) {// O(n*n)
	if (cur_idx == n)return 0;

	int& ret = memo[last_idx][cur_idx];
	if (~ret)return ret;
	int sum = 0;
	if (last_idx == 0)
		sum = prefix[cur_idx];
	else sum= prefix[cur_idx]- prefix[last_idx-1];

	sum += 10;
	ret = (sum * price[cur_idx]) + solve2(cur_idx + 1, cur_idx + 1);

	if (cur_idx != n - 1)
		ret = min(ret, solve2(last_idx, cur_idx + 1));
	return ret;

}
int solve3(int last_idx, int cur_idx, int prev_sum = 0) {// sum on the fly O(n*n)
	if (cur_idx == n)return 0;


	int& ret = memo[last_idx][cur_idx];
	if (~ret)return ret;

	ret = solve3(cur_idx + 1, cur_idx + 1, 0) 
		+ (prev_sum + cnt[cur_idx] + 10) * price[cur_idx];

	if (cur_idx != n - 1)
		ret = min(ret, solve3(last_idx, cur_idx+1, prev_sum + cnt[cur_idx]));
	return ret;
}
int new_memo[MAX];
int solve4(int last_idx) {
	if (last_idx == n)return 0;
	int& ret = new_memo[last_idx];
	if (~ret)return ret;
	ret = 1e9;
	int sum = 0;
	for (int cur_idx = last_idx; cur_idx < n; cur_idx++) {
		sum += cnt[cur_idx];
		ret = min(ret, (sum + 10) * price[cur_idx] + solve4(cur_idx + 1));
	}
	return ret;

}
int main() {
	fast();
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> cnt[i] >> price[i];

		memset(memo, -1, sizeof memo);
		cout<<solve1(0, 0);


		prefix[0] = cnt[0];
		for (int i = 1; i < n; i++)
			prefix[i] = prefix[i - 1] + cnt[i];
		cout << solve2(0, 0);


		cout << solve3(0, 0, 0);

		memset(new_memo, -1, sizeof new_memo);
		cout << solve4(0);


		cout << endl;
	}
}
/*
				COMMENT THE FILE FUNCTION !?!
*/
