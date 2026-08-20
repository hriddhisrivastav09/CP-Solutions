class Solution {
public:
    bool isPalindrome(int x) {

        if(x < 0){
            return false ;
        }

        int copy = x ;
        long long a = 0 ;

        while(copy > 0){
            a = (a * 10) + (copy%10) ;
            copy /= 10 ;
        }

        if(a == x){
            return true ;
        }

        return false ;

        


    }
};