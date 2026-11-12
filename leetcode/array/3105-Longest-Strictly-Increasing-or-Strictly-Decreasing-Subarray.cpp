using ll = long long ;
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        ll n = nums.size();
        ll inc = 1 ; 
        ll final_inc = 0 ;
        for(ll i = 1 ; i < n ; i++){
            final_inc = max(final_inc,inc);
            if(nums[i] > nums[i-1]){
                inc++;
            }
            else{
                
                inc = 1 ;
            }
        }
        final_inc = max(final_inc,inc);

        ll dec = 1 ;
        ll final_dec = 0 ; 

        for(ll i = 1 ; i < n ; i++){
            final_dec = max(final_dec,dec);
            if(nums[i] < nums[i-1]){
                dec++;
            }
            else{
                dec = 1 ;
            }
        }
            final_dec = max(final_dec,dec);


        return max(final_dec,final_inc);
    }
};