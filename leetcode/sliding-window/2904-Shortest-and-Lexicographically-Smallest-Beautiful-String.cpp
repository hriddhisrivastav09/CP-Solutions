class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        vector<int>a;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '1'){
                a.push_back((i));
            }
        }

        if(a.size() < k){
            return "" ;
        }

        if(k==1){
            if(a.size() == 0){
                return "" ;
            }
            else {
                return "1" ;
            }
        }
       

        
        
        int last = a[k-1] ;
        int first = a[0] ;
        int diff = last - first;
        
        for(int i = 1 ; i <= a.size() - k ; i++){
            int curr_first = a[i] ;
            int curr_last = a[i+k-1] ;

            if(curr_last - curr_first < diff){
                last = curr_last ;
                first = curr_first ;
                diff = last - first ;
                continue ;
            }  

            else if(curr_last - curr_first == diff){
                

                string s_1 = s.substr(first, last - first + 1);
                string s_2 = s.substr(curr_first, curr_last - curr_first + 1);

                if(s_2 < s_1){
                    last = curr_last ;
                    first = curr_first ;
                }
            }
        }

        string ans = "" ;

        for(int j = first ; j <= last ; j++){
            ans += s[j] ;
        }

        return ans ;



        

        
    }
};