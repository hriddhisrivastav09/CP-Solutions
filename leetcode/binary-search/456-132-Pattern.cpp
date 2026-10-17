class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size() ;
        int last = INT_MIN;
        stack <int> st ;
        for(int i = n-1 ; i >= 0 ; i--){
            if(nums[i] < last){
                return true ;
            }
            while(!st.empty() && st.top() < nums[i]){
                last = st.top();
                st.pop();
            }
            st.push(nums[i]);
        } 
        return false ;
    }
};