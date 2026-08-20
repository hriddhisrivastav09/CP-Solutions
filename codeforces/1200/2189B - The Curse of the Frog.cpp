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

    ll n , x ;
    cin >> n >> x ;

    vector<vector<ll>> matrix(n, vector<ll>(3));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }

    ll dist = 0 ;
    ll rolls = 0 ;

    for(auto it : matrix){
        if(it[1] > 1){
            dist += it[0] * (it[1] - 1) ;
        }
    }

    if(dist >= x){
        println(0)
        return;
    }

    ll rem = x - dist ;
    ll maxi = INT32_MIN;

    for(auto it : matrix){
        maxi = max(maxi , (it[0]*it[1]) - it[2]);
    }

    if(maxi <= 0){
        println(-1)
        return;
    }

    ll ans = (rem+maxi - 1)/maxi ;
    println(ans)




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
