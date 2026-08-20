
using ll = int ;

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

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ll m = matrix.size();
        ll n = matrix[0].size();

        ll mini = matrix[0][0];
        ll maxi = matrix[m-1][n-1];

        if(target < mini || target > maxi){
            return false ;
        }

        if(target == mini || target == maxi){
            return true ;
        }

        ll low = 0 ;
        ll high = (m*n) - 1 ;

        while(low <= high){
            ll mid = low + (high-low)/2 ;

            ll r = mid/n ;
            ll c = mid%n ;

            ll e = matrix[r][c];
            if(e == target){
                return true ;
            }
            else if(e < target){
                low = mid+1 ;
            }
            else{
                high = mid - 1 ;
            }
        }

        return false ;
    }
};