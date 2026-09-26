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

    ll n,m,k ;
    cin >> n >> m >> k ;

    vll a(n);
    rep(i , 0 , n) cin >> a[i];
    vll b(m);
    rep(i , 0 , m) cin >> b[i];

    // I'll check for round 1 and round 2 separately
    // Since it's best to just swap max and min continously
    // Like going back and forth with the same
    // This is also because the gain on swapping mini and maxi isn't the same with any other pair of elements

    // Round 1 

    sort(all(a));
    sort(all(b));
    
    if(a[0] < b[m-1]){
        swap(a[0],b[m-1]);
    }

    if(k==1){
        println(sum(a));
        return;
    }

    // Round 2 

    sort(all(a));
    sort(all(b));

    if(a[n-1] > b[0]){
        swap(a[n-1],b[0]);
    }

    // If we are on 2nd round, that means this back and forth thing will happen from now

    k -= 2 ;
    k = k%2 ;

    if(k==0){
        println(sum(a));
        return;
    }

    // Possible round 3 

    if(k == 1){

    sort(all(a));
    sort(all(b));

    if(a[0] < b[m-1]){
        swap(a[0], b[m-1]);
    }

    println(sum(a));
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

