using ll = int ;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        ll n = nums.size() ;
        ll isDec = 0 ;
        ll isInc = 0 ;

        if(n<=1){
            return 0 ;
        }

        // Here's the observation. Firstly, it can be sorted if it's a sorted rotated array
        // Inc or Dec, doesn't matter since we can always rotate
        // First detect it
        // If it's inc, then we find the minimum distance for 0 to reach to any of the ends
        // If it's Dec, then for largest n-1 element we do the same

        for(ll i = 0 ; i < n ; i++){
            ll next = nums[(i+1)%n];

            if(nums[i] < next){
                isInc++;
            }
            if(nums[i] > next){
                isDec++;
            }
        }

        if(isDec == 1){
            ll zero = find(nums.begin(),nums.end(),0) - nums.begin();
            return min(zero , n - zero + 2) ;
        }
        if(isInc == 1){
            ll largest = find(nums.begin(),nums.end(),n-1) - nums.begin();
            return 1 + min(largest,n-largest);
        }

        return -1;

        

    
    }
};