class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st ;
        int n = tokens.size();

        for(int i = 0 ; i < n ; i++){
            if(tokens[i] == "+" ||
               tokens[i] == "-" ||
               tokens[i] == "*" ||
               tokens[i] == "/" ){
                int a = (st.top()) ;
                st.pop();
                int b = (st.top());

                if(tokens[i] == "+"){
                    st.pop();
                    st.push(a+b);
                }
                else if(tokens[i] == "-"){
                    st.pop();
                    st.push(b-a);
                }
                else if(tokens[i] == "*"){
                    st.pop();
                    st.push(a*b);
                }
                else{
                    st.pop();
                    st.push(b/a);
                }
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};