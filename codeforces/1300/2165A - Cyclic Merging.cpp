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

// Sieve of Eratosthenes
vll sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (ll i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    vll primes;

    rep(i, 2, n + 1) {
        if (is_prime[i])
            primes.pb(i);
    }

    return primes;
}

ll binary_search(vll &a, ll x) {
    ll l = 0, r = sz(a) - 1;

    while (l <= r) {
        ll mid = l + (r - l) / 2;

        if (a[mid] == x)
            return mid;

        if (a[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

// Get all divisors
vll get_divisors(ll n) {
    vll divisors;

    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.pb(i);

            if (i != n / i)
                divisors.pb(n / i);
        }
    }

    sort(all(divisors));

    return divisors;
}


// Prime Factorization
vpll factorization(ll n) {
    vpll factors;

    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ll cnt = 0;

            while (n % i == 0) {
                n /= i;
                ++cnt;
            }

            factors.pb({i, cnt});
        }
    }

    if (n > 1)
        factors.pb({n, 1});

    return factors;
}

void solve(){

    ll n ;
    cin >> n ;

    vll a(n);
    rep(i , 0 , n) cin >> a[i];

    if(n == 2){
        println(mx(a));
        return;
    }

    ll sumi = 0 ;

    rep(i,0,n-1){
        sumi += max(a[i],a[i+1]);
    }

    println(sumi + max(a[0],a[n-1]) - mx(a));





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
