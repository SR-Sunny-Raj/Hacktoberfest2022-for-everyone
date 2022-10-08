/* 
   Problem Link :- https://leetcode.com/problems/merge-intervals/
*/

class Solution {
  public:
    vector < vector < int >> merge(vector < vector < int >> & intervals) {
      vector < vector < int >> res;

      // If there are no intervals at all we can simply return empty result
      if (intervals.size() == 0) {
        return res;
      }

      // Sorting the intervals so as to get desired sorted output
      sort(intervals.begin(), intervals.end());

      /* Taking the initial interval as a comparing unit for merging the intervals.
         Here it is [1,3]
      */
      vector < int > tmp = intervals[0]; /* tmp=[1,3] */

      /* Looping through the intevals vector*/

      /* First interval :-  a=[1,3] -> 1 < 3 -> tmp[1]=max(3,3)=3 -> tmp=[1,3] */
      /* Second interval :- a=[2,6] -> 2 < 3 -> tmp[1]=max(6,3)=3 -> tmp=[1,6] */
      /* Third interval :- a=[8,10] -> 8 > 6 -> tmp=[1,6] -> res=[[1,6]] -> tmp=[8,10] */
      /* Fourth interval :- a=[15,18] -> 15 > 10 -> tmp=[8,10] -> res=[[1,6],[8,10]] -> tmp=[8,10] -> res=[[1,6],[8,10],[15,18]] */

      for (auto a: intervals) {
        if (a[0] <= tmp[1]) {
          /* Comparison if current interval's 0th element is less than comparator's 1st element */
          tmp[1] = max(a[1], tmp[1]); /* If above condition satisifed set comparator's 1st element as maximum of current interval's and comparator's 1st element */
        } else {
          res.push_back(tmp); /* If above condition does not match push comparator in result */
          tmp = a; /* Make current interval as new comparator */
        }
      }
      res.push_back(tmp); /* Push the remaining comparator value into result */
      return res; /* Return result */
    }
};