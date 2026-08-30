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
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int idx_max = 0 ;
        int idx_min = 0 ;

        ll mini = mn(nums);
        ll maxi = mx(nums);

        while(nums[idx_max]!=maxi && idx_max < n){
            idx_max++;
        }
        while(nums[idx_min]!=mini && idx_min < n){
            idx_min++;
        }

        ll l_mini = idx_min+1;
        ll r_mini = n - idx_min;

        ll l_maxi = idx_max+1;
        ll r_maxi = n - idx_max;

        ll ans = n ;

        ans = min(ans,max(l_maxi,l_mini));
        ans = min(ans,max(r_maxi,r_mini));

        if(idx_min > idx_max){
            ans = min(ans, r_mini+l_maxi);
        }
        else{
            ans = min(ans,r_maxi+l_mini);
        }

        return ans;


    }
};