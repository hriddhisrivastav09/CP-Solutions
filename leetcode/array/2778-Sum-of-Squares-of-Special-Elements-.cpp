class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sumi = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(n%(i+1)==0){
                sumi += (nums[i]*nums[i]);
            }
        }
        return sumi ;
    }
};