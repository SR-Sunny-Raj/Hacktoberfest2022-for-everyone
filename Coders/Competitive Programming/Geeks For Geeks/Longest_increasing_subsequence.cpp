/* A Memoization Java Program for LIS Implementation */
//Problem : https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

import java.util.Arrays;
import java.lang.*;
class LIS {

/* To make use of recursive calls, this function must
	return two things: 1) Length of LIS ending with element
	arr[n-1]. We use max_ending_here for this purpose 2)
	Overall maximum as the LIS may end with an element
	before arr[n-1] max_ref is used this purpose.
	The value of LIS of full array of size n is stored in
	*max_ref which is our final result */
static int f(int idx, int prev_idx, int n, int a[],
			int[][] dp)
{
	if (idx == n) {
	return 0;
	}

	if (dp[idx][prev_idx + 1] != -1) {
	return dp[idx][prev_idx + 1];
	}

	int notTake = 0 + f(idx + 1, prev_idx, n, a, dp);
	int take = Integer.MIN_VALUE;
	if (prev_idx == -1 || a[idx] > a[prev_idx]) {
	take = 1 + f(idx + 1, idx, n, a, dp);
	}

	return dp[idx][prev_idx + 1] = Math.max(take, notTake);
}

// The wrapper function for _lis()
static int lis(int arr[], int n)
{

	// The function _lis() stores its result in max
	int dp[][] = new int[n+1][n+1];
	for (int row[] : dp)
	Arrays.fill(row, -1);

	return f(0, -1, n, arr, dp);


}

// driver program to test above functions
public static void main(String args[])
{
	int a[] = { 3, 10, 2, 1, 20 };
	int n = a.length;
	System.out.println("Length of lis is " + lis(a, n)
					+ "\n");
}
}

