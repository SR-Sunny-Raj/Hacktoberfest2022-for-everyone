// leetcode 4. Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution 
{
public:
    double findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
    {
        int n1=A.size(),n2=B.size();
        if(n2<n1) return findMedianSortedArrays(B,A);
        int l=0,h=n1;
        while(l<=h){
            int c1=l+(h-l)/2;
            int c2=(n1+n2+1)/2-c1;
            int l1=(c1==0?INT_MIN:A[c1-1]);
            int l2=(c2==0?INT_MIN:B[c2-1]);
            int r1=(c1==n1?INT_MAX:A[c1]);
            int r2=(c2==n2?INT_MAX:B[c2]);
            if(l1<=r2&&l2<=r1){
                if((n1+n2)%2==0)
                    return ((max(l1,l2)+min(r1,r2))/2.0);
                else return max(l1,l2);
            }
            else if(l1>r2) h=c1-1;
            else l=c1+1;
        }
        return 0.0;
    }
};