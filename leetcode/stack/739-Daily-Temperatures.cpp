class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <int> st ;
        int n = temperatures.size() ;
        stack <int> idx ;

        vector<int>ans(n,0);

        for(int i = n-1 ; i>=0 ; i--){
            int temp = temperatures[i];

            while(!st.empty() && st.top() <= temp){
                st.pop();
                idx.pop();
            }

            if(idx.empty()){
                ans[i] = 0 ;
            }
            else{
                ans[i] = idx.top() - i ;
            }

            st.push(temp);
            idx.push(i);

        }

        return ans ;
    }
};