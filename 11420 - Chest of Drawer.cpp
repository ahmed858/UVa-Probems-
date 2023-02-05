#include<set>
#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<sstream>
#include<string>
#include<map>
#include<unordered_map>
#include<queue>
#include<unordered_set>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;


#define all(x) x.begin(), x.end()
#define endl '\n'
#define sz(x) x.size()
#define clr(x,v)  memset(x,v,sizeof x);
typedef  long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void fast()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#if online_judge

#endif
}

const int N = 1e2 + 1;
int n, s;


ll dp[100][100][3];
ll solve(int idx, int cnt, int lock) {

	if (idx == 0)
		return cnt == s ;

	ll& ans = dp[idx][cnt][lock];
	if (~ans)return ans;

	ans = solve(idx - 1, cnt, 0);
	if (lock) {
		ans += solve(idx - 1, cnt + 1, 1);
	}
	else {
		ans += solve(idx - 1, cnt, 1);
	}
	return ans;
}
int main() {
	while (1)
	{
		cin >> n >> s;
		if (n == -1 && s == -1)break;
		clr(dp, -1);
		cout << solve(n, 0, 1) << endl;;

	}
}
