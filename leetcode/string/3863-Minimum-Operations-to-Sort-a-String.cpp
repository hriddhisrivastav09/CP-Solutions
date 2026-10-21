class Solution {
public:
    int minOperations(string s) {
        // My idea is that in any case, it will take at max 2 ops
        // Reason is simple. Except for first (or last), sort everything
        // Then, include that first (or last) element, and sort it till the posi
        // That's 2 ops

        // But then, it can take even 1 op, and that is when first element is smallest already,
        // or last element is the largest possible
        // In that case, we simply leave that element and sort everything at once

        // Then, there's only one case when its not possible
        // If the length of string is 2 and it's not sorted

        // It failed on a testcase of edc, which needed 3

        int n = s.length();

        if(n==2 && !is_sorted(s.begin(),s.end())){
            return -1;
        }

        if(is_sorted(s.begin(),s.end())){
            return 0;
        }

        char mx = *max_element(s.begin(),s.end());
        char mn = *min_element(s.begin(),s.end());

        if(s[0] == mn || s[n-1] == mx){
            return 1;
        }

        for(int i = 1 ; i < n-1 ; i++){
            if(s[i] == mx || s[i] == mn){
                return 2 ;
            }
        }

        return 3 ;
        
    }
};