class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ;
        vector <int> prefixMax(n) ;
        vector <int> suffixMax(n) ;

        int big_back = height[0] ;
        int big_fwd = height[n-1] ;

        for(int i = 0 ; i < n ; i++){
            big_back = max(big_back,height[i]);
            prefixMax[i] = big_back ;
        }
        for(int i = n-1 ; i >= 0 ; i--){
            big_fwd = max(big_fwd,height[i]);
            suffixMax[i] = big_fwd ;
        }

        int total = 0 ;

        for(int i = 0 ; i < n ; i++){
            if(height[i] < prefixMax[i] && height[i] < suffixMax[i]){
                total += min(prefixMax[i] , suffixMax[i]) - height[i];
            }
        }

        return total ;
    }
};