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

bool f(long long mid, vll &v){
    long long j = v.size() - 1;
    bool check = true;
    for (int k = mid - 1; k >= 0; k--, j--) {
        if (j - 1 < mid) return false;
        check &= ((v[k] < v[j]) && (v[k] < v[j-1])); 
    }
    return check;
}
void solve() {
    int n;
    cin>>n;
    vll v(n);
    for0(i,n){
        cin>>v[i];
    }
    sort(all(v));
    ll lo=1;
    ll hi=n;
    ll ans=0;
    while(lo<=hi){
        ll mid=(lo)+(hi-lo)/2;
        if(f(mid,v)){
           lo=mid+1;
           ans=mid;
        }
        else{
            hi=mid-1;
            
        }
    }
    vll result(n);
    ll i=ans-1;
    ll j=n-1;
    for(int k=0;k<n;k++){
        if(k%2==0 || i==-1){
          result[k]=v[j--];
        }  
        else{
            result[k]=v[i--];
        }
    }
    cout<<ans<<endl;
    for0(l,n){
        cout<<result[l]<<" ";
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;
    // cin>>t;
    // while(t--)
    solve();
    return 0;
}
