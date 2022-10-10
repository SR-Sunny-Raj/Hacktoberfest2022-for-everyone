#include<bits/stdc++.h>
using namespace std;

//this is an efficient implementation of this problem
//Time complexity: O(n^2) and constant aux space is required
class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { //this can be achieved in 2 steps
        // 1) taking transpose of matrix(interchanging the rows and columns)
         for(int i=0;i<n;i++)
        {
             for(int j=i+1;j<n;j++)
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        // 2)reversing the columns
        for(int i=0;i<n;i++)
        {
            int low=0,high=n-1;
            while(low<high)
            {   int temp=matrix[low][i];
                matrix[low][i]=matrix[high][i];
                matrix[high][i]=temp;
                low++,high--;
            }
        }
    } 
 
};

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> matrix(n);
    for(int i=0;i<n;i++)
    {
        matrix[i].assign(n,0);
        for(int j=0;j<n;j++)
            cin>>matrix[i][j];
    }
    Solution obj;
    obj.rotateby90(matrix,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
return 0;
}

