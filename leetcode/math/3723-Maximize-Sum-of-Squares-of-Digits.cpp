class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s = "" ;
        int temp = 0 ;
        
        for(int i = 0 ; i < num ; i++){
            int diff = sum - temp ;
            int a = min(diff,9);
            temp += a ;
            s += to_string(a);
        }

        if(temp < sum){
            return "" ;
        }

        return s ;
    }
};