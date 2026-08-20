class Solution {
public:
    bool isPalindrome(int x) {

        if(x < 0){
            return false ;
        }

        int copy = x ;
        long long a = 0 ;

        while(copy > 0){
            int rem = copy%10 ;
            a = a + rem ;
            a = a * 10 ;
            copy = copy/10 ;
        }

        a /= 10 ;

        if(a == x){
            return true ;
        }

        return false ;

        


    }
};