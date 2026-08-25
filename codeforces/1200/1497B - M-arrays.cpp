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

    ll n , m ;
    cin >> n >> m ;

    vll a(n);
    rep(i , 0 , n) cin >> a[i];

    rep(i,0,n){
        a[i] = a[i]%m ;
    }

    unordered_map<ll,ll>freq;
    for(ll x : a){
        freq[x]++;
    }

    ll cnt = 0 ;

    for(auto it : freq){
        ll first = it.first ;
        ll sec = (m - it.first) % m; ;

        ll freq_1 = freq[first];
        ll freq_2 = 0;
        auto it2 = freq.find(sec);
        if (it2 != freq.end()) {
            freq_2 = it2->second;
        }

        if(freq_1 == 0 || freq_2 == 0){
            ll maxi = max(freq_1,freq_2);
            cnt+=maxi ;
            it2 = freq.find(sec);
        if (it2 != freq.end()) {
            freq_2 = it2->second;
        }
            continue;
        }
        
        ll mini = min(freq_1,freq_2);
        
        freq_1 -= mini ;
        freq_2 -= mini ;

        

        cnt++;

        if(freq_1 > 0){
            cnt += (freq_1 - 1) ;
            freq_1 = 0 ;
        }
        else if(freq_2 > 0){
            cnt += (freq_2 - 1) ;
            freq_2 = 0 ;
        }

        freq[first] = 0;

        it2 = freq.find(sec);
        if (it2 != freq.end()) {
            it2->second = 0;
        }
    }

    println(cnt)

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
