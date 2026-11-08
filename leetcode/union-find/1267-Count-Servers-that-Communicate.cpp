using ll = int ;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        ll m = grid.size();
        ll n = grid[0].size();

        vector<ll> rows(m);
        vector<ll> cols(n);

        for(ll i = 0 ; i < m ; i++){
            for(ll j = 0 ; j < n ; j++){
                rows[i] += grid[i][j];
                cols[j] += grid[i][j];
            }
        }

        ll ans = 0 ;
        for(ll i = 0 ; i < m ; i++){
            for(ll j = 0 ; j < n ; j++){
                if(grid[i][j] == 1 && rows[i] + cols[j] > 2){
                    ans++;
                }
            }
        }


        return ans ;
    }
};