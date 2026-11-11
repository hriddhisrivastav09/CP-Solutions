using ll = long long ;
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll total = 0 ;
        ll pairs = min(need1,need2);
        ll costPairs = pairs * min(costBoth, cost1 + cost2);
        ll rem1 = need1 - pairs ;
        ll rem2 = need2 - pairs ;
        ll costRem = rem1 * min(cost1,costBoth) + rem2*min(costBoth,cost2);
        return costPairs+costRem;
    }
};