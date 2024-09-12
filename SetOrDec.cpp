#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>
#include <set>
#include <limits>
#include <cstdlib>
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sz(a) int((a).size())

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
bool f(ll mid, vll v, ll k, ll sum){
    if(sum-mid <= k) return true;
    for(int i=v.size()-1;i>= max(1ll,(int)v.size()-mid);i--){
        sum-=v[i];
        ll opleft=(mid-(v.size()-i));
        ll tempsum=sum-v[0]+(v.size()-i+1)*(v[0]-opleft);
        if(tempsum<=k) return true;
    }
    return false;
}
void solve() {
   ll n,k;
   cin>>n>>k;
   vll v(n);
   ll sum=0;
   for0(i,n){
    cin>>v[i];
    sum+=v[i];
   }
   sort(all(v));
   ll lo=0;
   ll hi=1e10;
   ll ans=1e10;
   while(lo<=hi){
    ll mid=(lo)+(hi-lo)/2;
    if(f(mid,v,k,sum)){
        ans=mid;
        hi=mid-1;
    }
    else{
        lo=mid+1;
    }
   }
   cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}
