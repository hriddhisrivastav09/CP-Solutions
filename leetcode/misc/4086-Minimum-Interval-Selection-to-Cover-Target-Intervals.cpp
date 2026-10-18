class Solution {
public:
    int minSelection(vector<vector<int>>& availableIntervals, vector<vector<int>>& targetIntervals) {
        // Hahaha it's greedy, not escaping on my watch

        sort(availableIntervals.begin(),availableIntervals.end());
        sort(targetIntervals.begin(),targetIntervals.end());

        vector<vector<int>> merge ;

        for(auto& inter : targetIntervals){
            if(merge.empty() || inter[0] > merge.back()[1]){
                merge.push_back(inter);
            }
            else{
                merge.back()[1] = max(merge.back()[1],inter[1]);
            }
        }

        int n = availableIntervals.size();
        int j = 0 ;
        int ans = 0 ;

        int reach = 0 ;
        bool isReach = false ;

        for(auto& target : merge){
            int l = target[0];
            int r = target[1];

            if(isReach && reach >= r){
                continue ; // We don't need to do this one since it's already covered
            }

            if(!isReach || reach < l){
                int last_end = 0 ;
                bool found = false ;

                while(j < n && availableIntervals[j][0] <= l){
                    if(availableIntervals[j][1] >= l && (!found || availableIntervals[j][1] > last_end)){
                        last_end = availableIntervals[j][1];
                        found = true ;
                    }
                    j++;
                }

                if(!found){
                    return -1 ;
                }

                reach = last_end ;
                isReach = true ;
                ans++;
            }

            while(reach < r){
                int bestEnd = reach ;

                while(j < n && availableIntervals[j][0] <= reach){
                    if(availableIntervals[j][1] > reach){
                        bestEnd = max(availableIntervals[j][1],bestEnd);
                    }
                    j++;
                }

                if(bestEnd == reach){
                    return -1 ;
                }

                reach = bestEnd ;
                ans++;
            }
        }

        return ans ;
    }
};