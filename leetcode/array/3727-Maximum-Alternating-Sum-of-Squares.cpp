class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size() ;
        vector <long long> sq ;
        for(int i = 0 ; i < n ; i++){
            sq.push_back(1LL * nums[i] * nums[i]);
        }
        sort(sq.begin(),sq.end());
        int i = 0 ; 
        int j = n-1;
        bool flip = false ;
        long long sumi = 0 ;
        while(i <= j){
            if(!flip){
                sumi += sq[j];
                j--;
            }
            else{
                sumi -= sq[i];
                i++;
            }
            flip = !flip;
        }
        return sumi ;
    }
};