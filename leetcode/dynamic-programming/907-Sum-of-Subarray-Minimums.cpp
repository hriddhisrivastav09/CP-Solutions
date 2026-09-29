class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack <int> nse ;
        stack <int> pse ;
        int n = arr.size() ;
        long long mod = 1e9 + 7 ;

        vector <int> nsev(n) ;
        vector <int> psev(n) ;

        for(int i = 0 ; i < n ; i++){
            while(!pse.empty() && arr[pse.top()] > arr[i]){
                pse.pop();
            }
            psev[i] = pse.empty() ? -1 : pse.top() ;
            pse.push(i);
        }

        for(int j = n-1 ; j >= 0 ; j--){
            while(!nse.empty() && arr[nse.top()] >= arr[j]){
                nse.pop();
            }

            nsev[j] = nse.empty() ? n : nse.top() ;
            nse.push(j);
        }

        long long ans = 0 ;

        for(int i = 0 ; i < n ; i++){
            long long c_left = i - psev[i] ;
            long long c_right = nsev[i] - i ;

            ans = (ans + (c_left * c_right * arr[i])%mod)%mod ;


        }

        return ans ;


    }
};