class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [x](const int& a, const int& b){
            return (abs(a-x) == abs(b-x)) ? a < b : (abs(a-x) < abs(b-x));
        });
        
        vector<int> ans(arr.begin(), arr.begin()+k);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
