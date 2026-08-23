class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector <int> x ;
        vector <int> y ;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == 0){
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }

        for(int i = 0 ; i < x.size() ; i++){

            int a = x[i];
            int b = y[i];

            while(a >= 0){
                matrix[a][b] = 0 ;
                a--;
            }

            a = x[i];

            while(a < m){
                matrix[a][b] = 0 ;
                a++;
            }

            a = x[i];

            while(b < n){
                matrix[a][b] = 0 ;
                b++;
            }

            b = y[i];

            while(b >= 0){
                matrix[a][b] = 0 ;
                b--;
            }

        }

       
    }
};