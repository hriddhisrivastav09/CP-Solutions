#include <bits/stdc++.h>

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;
using ll = long long ;

ll gcd(ll a, ll b) {
    while (b) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define mx(v) *max_element(all(v))
#define mn(v) *min_element(all(v))
#define sum(v) accumulate(all(v), 0LL)

#define rep(i, a, b) for(ll i = a; i < b; ++i)
#define rrep(i, a, b) for(ll i = a; i >= b; --i)

#define sz(x) ((ll)(x).size())
#define print(x) cout << x << " " ;
#define println(x) cout << x << '\n' ;
#define yes cout << "Yes" << '\n';
#define no cout << "No" << '\n';
#define nl cout << '\n';

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

void solve(){

    ll b ;

    ll n , m ;
    cin >> n >> m ;

    vll a(n);
    rep(i , 0 , n) cin >> a[i];

    cin >> b ;

    a[0] = min(a[0] , b - a[0]) ;

    if(n==1){
        yes;
        return;
    }

    rep(i,1,n){
        ll temp = b - a[i];

        if(a[i] < a[i-1] && temp < a[i-1]){
            no;
            return;
        }
        else{
            a[i] = min((a[i] < a[i-1] ? INF : a[i]) , (temp < a[i-1] ? INF : temp)) ;
        }
    }

    if(is_sorted(all(a))){
        yes ;
    }
    else{
        no;
    }



}


int main() {

    fast_io;

    ll t;
    cin >> t;
    while (t > 0) {
        solve() ;
        t--;
    }
    

    return 0;
}