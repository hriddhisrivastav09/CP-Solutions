class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size() ;
        int cnt = 0 ;
        int cnt_s = 0 ;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] == target){
                cnt++;
            }
            else if(nums[i] < target){
                cnt_s++;
            }
        }

        vector <int> ans ;

        int idx = cnt_s ;

        while(cnt > 0){
            ans.push_back(idx);
            idx++;
            cnt--;
        }

        return ans ;
    }
};