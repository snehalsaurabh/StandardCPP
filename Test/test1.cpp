//Remember, the path to becoming an expert is a marathon, not a sprint.
//Each problem you solve and each contest you participate in is a step towards your goal.
//Stay patient, keep learning, and maintain your determination. You've got this!
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define loop(i,j,n) for(int i=j;i<n;i++)
#define all(v) v.begin(),v.end()
#define yes cout<<"YES"<<'\n'
#define no cout<<"NO"<<'\n'
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << '\n';
#else
#define debug(x)
#endif
 
const int MOD = 1e9 + 7;
const int INF = 1e18;
 
vector <int> primeFactorization(int n){
    vector <int> factors;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            factors.pb(i);
            n/=i;
        }
    }
    if(n>1) factors.pb(n);
    return factors;
}
 
int bnExp(int a,int b){
    int ans = 1;
    while(b){
        if(b&1){
            ans = ans*a;
        }
        a = a*a;
        b=b>>1;
    }
    return ans;
}
 
int factorial(int n) {
    if (n == 0) return 1;
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result = (result * i);
    }
    return result;
}
 
 
int nCr(int n, int r) {
    if (r > n) return 0;
    r = min(r, n - r);
    int result = 1;
    for (int i = 0; i < r; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}
 
const int N = 1000001;
const int N1 = 101;
int dp[N1][N];
 
signed main() {
#ifndef ONLINE_JUDGE
freopen("Input.txt","r",stdin);
freopen("Output.txt","w",stdout);
freopen("Error.txt","w",stderr);
#endif
fastio;
memset(dp,0, sizeof(dp));
int n,x; cin >> n >> x;
vector <int> v(n);
for(auto &i : v)
    cin >> i;
for(int i=0;i<n;i++){
    dp[i][0] = 1;
}
for(int i= n-1;i>=0;i--){
    for(int j=1;j<=x;j++){
        int skipping = dp[i+1][j];
        int picking =0;
        if(v[i]<=j){
            picking = dp[i][j-v[i]];
        }
        dp[i][j] = (picking + skipping)%MOD;
    }
}
cout << dp[0][x] << '\n';
return 0;
}