#include <iostream>
#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define endl '\n'
#define sz(x) x.size()
#define vi vector<int>
#define vl vector<ll>
#define clr(x) memset(x,-1,sizeof x);

void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#if online_judge
    freopen( in.txt, r,stdin);
#endif
}
const int N=1e4+1,MOD=1e9+7;
int n,k;
int arr[N];;
int dp[N][100];

bool  solve(int i ,int  mod) {
	if(i==n)return !mod;

	int &ans =dp[i][mod];
	if(~ans)return ans;
	ans=solve(i+1,((mod-arr[i])+k)%k);
	ans|=solve(i+1,((mod+arr[i])+k)%k);
	return ans;
}
int main()
{
    fast();
	int t=1;
	cin >> t;
	while (t--) {
	cin>>n>>k;
	for(int i=0;i<n;i++){
        cin>>arr[i];
	}
	clr(dp);
	int ans = solve(1,((arr[0])+k)%k);

	if(ans)cout<<"Divisible";
	else cout<<"Not divisible";
	cout<<endl;
	}
}


/*
 * don't be lazy in thinking ya
 * Think twice, code once
 * Think of different approaches to tackle a problem: write them down.
 * Think of different views of the problem. don't look from only one side.
 * don't get stuck in one approach.
 * common mistakes: over_flow
 *                  - out_of_bound index
 *                  -infinite loop
 *                  -corner cases
 *                  -double counting.
//	READ ALL PROBLEMS
//	Solve on paper first
//	If there's an equation, transform it into an easy one
//	Use binary search
//	Always think of patterns (LCM, GCD)
//	Be careful of unsigned
//	Think of a solution that gets TLE and optimize it
//	Reverse Thinking
//	Monotonic stack/dequeue
//	EV is computed using probabilities or number of ways
//	E(X + Y) = E(X) + E(Y)
//	E(X * Y) = E(X) * E(Y)
//	Try not to use doubles
//	Don't do DP in graphs on anything rather than DAGs
//	Don't use the fucking "double"

 */

