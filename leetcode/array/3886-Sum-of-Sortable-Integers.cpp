
class Solution {
public:
    bool check(vector<int>& nums, vector<int>& sorted, int k) {
        int n = nums.size();

        for (int l = 0; l < n; l += k) {
            int descent = 0;
            int pivot = 0;

            for (int j = 0; j < k; j++) {
                int nxt = (j + 1) % k;

                if (nums[l + j] > nums[l + nxt]) {
                    descent++;
                    pivot = nxt;
                }
            }

            if (descent > 1) {
                return false;
            }

            for (int j = 0; j < k; j++) {
                if (nums[l + (pivot + j) % k] != sorted[l + j]) {
                    return false;
                }
            }
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> factors;

        vector<int> copy = nums;
        sort(copy.begin(), copy.end());

        for (int i = 1; i <= n / i; i++) {
            if (n % i == 0) {
                factors.push_back(i);

                if (i != n / i) {
                    factors.push_back(n / i);
                }
            }
        }

        int ans = 0;

        for (int k : factors) {
            if (check(nums, copy, k)) {
                ans += k;
            }
        }

        return ans;
    }
};
