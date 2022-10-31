#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> SpiralTraversal(vector<vector<int>> matrix,int r,int c)
        {
            vector<int> vect;
            int top=0,right=c-1,bottom=r-1,left=0;
            while(left<=right && top<=bottom)
            {
                for(int i=left;i<=right;i++)
                    vect.push_back(matrix[top][i]);
                top++;
                for(int i=top;i<=bottom;i++)
                    vect.push_back(matrix[i][right]);
                right--;
                if(top<=bottom)
                {
                    for(int i=right;i>=left;i--)
                        vect.push_back(matrix[bottom][i]);
                    bottom--;
                }
                if(left<=right)
                {
                    for(int i=bottom;i>=top;i--)
                        vect.push_back(matrix[i][left]);
                    left++;    
                }
            }
            return vect;
        }
};
int main()
{
    int r,c;
    cin>>r>>c;
    vector<vector<int>> matrix(r);
    for(int i=0;i<r;i++)
    {
        matrix[i].assign(c,0);
        for(int j=0;j<c;j++)
            cin>>matrix[i][j];
    }
    Solution obj;
    vector<int> result=obj.SpiralTraversal(matrix,r,c);  
        for(int j=0;j<result.size();j++)
            cout<<result[j]<<" ";
        cout<<endl;
return 0;
}
