// Problem Link: https://leetcode.com/problems/combination-sum/description/

class Solution {
public:
    
    int target;
    int numCand;
    vector<vector<int>> result;

    void combinate(vector<int>& cand, vector<int>& cur, int i, int total){        
        if(total == target){
            result.push_back(cur);            
            return; 
        }
        if(i >= numCand || total > target){
            return;
        }
        
        int cur_cand = cand[i];
        cur.push_back(cur_cand);
        combinate(cand, cur, i, total + cur_cand);
        cur.pop_back();
        combinate(cand, cur, i+1, total);       
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target = target;
        this->numCand = candidates.size();
        vector<int> v;

        combinate(candidates, v, 0, 0);
        return result;      
    }
};