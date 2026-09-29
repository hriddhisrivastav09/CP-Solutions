class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> st ;
        int n = asteroids.size();

        for(int i = 0 ; i < n ; i++){
            if(asteroids[i] >= 0){
                st.push(asteroids[i]);
            }
            else{
                int temp = (-1) * asteroids[i] ;
                while(!st.empty() && st.top() >= 0 && st.top() < temp){
                    st.pop();
                }

                if(!st.empty() && st.top() >= 0){
                    int a = st.top();
                    st.pop();
                    if(a > temp){
                        st.push(a);
                    }
                }
                else{
                    st.push(-temp);
                }
            }
        }

        vector<int>ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};