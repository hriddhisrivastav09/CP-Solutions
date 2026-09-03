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

    // ll a , b , c ;
    // cin >> a >> b >> c ;

    ll n ;
    cin >> n ;

    vll a(n);
    rep(i , 0 , n) cin >> a[i];

    if(n==1 || is_sorted(all(a))){
        println(-1)
        return;
    }

    ll mini = 1 ;
    ll maxi = n ;

    ll i = 0 ;
    ll j = n-1 ;

    bool found = false ;

    while(i < j){
        if(a[i] == mini){
            i++;
            mini++;
        }
        else if(a[i] == maxi){
            i++;
            maxi--;
        }
        else if(a[j] == mini){
            j--;
            mini++;
        }
        else if(a[j] == maxi){
            j--;
            maxi--;
        }
        else{
            found = true ;
            break;
        }
        
    }

    if(found){
        print(i+1);
        print(j+1);
    }
    else{
        print(-1);
    }
    nl;

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
