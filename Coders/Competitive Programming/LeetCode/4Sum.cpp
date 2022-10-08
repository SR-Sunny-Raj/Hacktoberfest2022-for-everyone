// Problem link : https://leetcode.com/problems/4sum/

class Solution {
public:
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    vector<vector<int>>v;
    int n=nums.size();
    set<vector<int>>s;
    for(int i=0;i<n-3;i++)
    {
        for(int j=i+1;j<n-2;j++)
        {
            int k=target-(nums[i]+nums[j]);
            int p=j+1,q=n-1;
            while(p<q)
            {
               int sum=nums[p]+nums[q];
                if(sum==k)
                {
                    s.insert({nums[i],nums[j],nums[p],nums[q]});
                    p++;

                }
                else if(sum<k)
                {
                   p++;
                }
                else{
                    q--;
                }
            }
        }
    }
    for(auto it:s)
    {
        v.push_back(it);
    }
    return v;
}
};