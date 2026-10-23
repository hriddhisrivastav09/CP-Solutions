using ll = long long ;

ll gcd(ll a, ll b) {
    while (b) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size() ;
        // I f*cking got spoiled by the hint!
        // Bit manipulation is the next one btw

        ll g = -1;

        for(ll i = 0 ; i < n ; i++){
            if(i!=nums[i]){
                g &= nums[i]; 
            }
        }

        return g==-1? 0 : g ;


    }
};