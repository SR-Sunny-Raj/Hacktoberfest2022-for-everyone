class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len=nums.size();
        if(3>len) return 0;
        int x=INT_MAX,y=INT_MAX;
        for(auto i:nums)
        {
            if(i<=x){
                x=i;
            }
            else if(i<=y)
            {
                y=i;
            }
            else{
                return true;
            }
        }
        return 0;
    }
};
