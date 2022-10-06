//Problem Link -: https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:
void setZeroes(vector<vector<int>>& matrix) {
   set<int> arr, brr;
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                arr.insert(i);
                brr.insert(j);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr.count(i)!=0 || brr.count(j)!=0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    }
};
