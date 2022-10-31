class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int temp = nums[i] + nums[l] + nums[r];
                if (abs(ans - target) > abs(temp - target)) ans = temp;
                if (temp == target) break;
                if (temp > target) r--; 
                else l++;
            }
        }

        return ans;
    }
};
