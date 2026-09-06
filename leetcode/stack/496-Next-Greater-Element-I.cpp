class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack <int> st ;
        vector<int>suffix(nums2.size());
        int n = nums2.size();

        for(int i = n-1 ; i>=0 ; i--){
            int temp = nums2[i];
            while(!st.empty() && st.top() <= temp){
                st.pop();
            }
            if(st.empty()){
                suffix[i] = -1 ;
                st.push(temp);
            }
            else{
                suffix[i] = st.top();
                st.push(temp);
            }
        }

        unordered_map<int,int>posi;

        for(int i = 0 ; i < n ; i++){
            posi[nums2[i]] = i ;
        }

        vector<int>ans;

        for(int i = 0 ; i < nums1.size() ; i++){
            int p = posi[nums1[i]];
            ans.push_back(suffix[p]);
        }
        return ans ;
    }
};