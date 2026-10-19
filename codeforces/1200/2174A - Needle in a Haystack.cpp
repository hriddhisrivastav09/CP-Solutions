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

    string s;
    cin >> s;

    string t;
    cin >> t;

    vector <char> cpy ;

    unordered_map<char,ll>freq_s ;
    unordered_map<char,ll>freq_t ;
    
    for(char ch : s){
        freq_s[ch]++;
    }
    for(char ch : t){
        freq_t[ch]++;
    }

    for(auto it : freq_s){
        if(freq_t[it.first] < it.second){
            cout << "Impossible" << '\n' ;
            return;
        }
        else{
            freq_t[it.first] -= it.second;
        }
    }

    for(auto it : freq_t){
        while(it.second > 0){
            cpy.pb(it.first);
            it.second--;
        }
    }

    sort(all(cpy));

    string ans ;

    ll i = 0 , j = 0 ;


    while(i < s.length() && j < cpy.size()){
        if(s[i] < cpy[j] || s[i] == cpy[j]){
            ans += s[i];
            i++;
        }
        else if(s[i] > cpy[j]){
            ans += cpy[j];
            j++;
        }
    }

    while(i < s.length()){
        ans += s[i];
        i++;
    }

    while(j < cpy.size()){
        ans+=cpy[j];
        j++;
    }

    println(ans);


    

   
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
