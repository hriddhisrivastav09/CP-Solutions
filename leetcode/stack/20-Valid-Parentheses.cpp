class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2==1){
            return false ;
        }

        stack <char> st ;

        for(char x : s){
            if(x == '(' || x == '[' || x == '{'){
                st.push(x);
            }
            else{
                if(st.empty()){
                    return false ;
                }
                if(x == ')' && st.top() != '('){
                    return false ;
                }
                else if(x == ']' && st.top() != '['){
                    return false ;
                }
                else if(x == '}' && st.top() != '{'){
                    return false ;
                }
                st.pop();
            }
        }

        return st.empty() ;


    }
};