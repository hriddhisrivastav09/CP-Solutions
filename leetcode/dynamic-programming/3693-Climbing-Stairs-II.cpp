using ll = int ;

class Solution {
public:

    int climbStairs(int n, vector<int>& costs) {
        vector<ll>dp(n+1 , INT_MAX/2);
        dp[0] = 0 ;

        for(ll i = 1 ; i <= n ; i++){
            ll cost = costs[i-1];

            for(ll j = max(0,i-3) ; j < i ; j++){
                ll jump = i - j ;

                ll tot = cost + dp[j] + jump*jump ;

                dp[i] = min(dp[i] , tot);
            }
        }

        return dp[n];
    }
};