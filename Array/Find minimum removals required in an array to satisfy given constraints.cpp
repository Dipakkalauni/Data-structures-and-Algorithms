/*

Given an integer array, trim it such that its maximum element becomes less than twice the minimum, return the minimum number of removals required for the conversion.

Input : [4, 6, 1, 7, 5, 9, 2]
Output: 4
Explanation: The trimmed array is [7, 5, 9] where 9 < 2 × 5.

Input : [4, 2, 6, 4, 9]
Output: 3
Explanation: The trimmed array is [6, 4] where 6 < 2 × 4.

*/

#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
	int findMin(vector<int> &nums)
	{
		int n = nums.size();  //stores the size of the array
		
		int mini, maxi;  //stores the minimum and maximum element in the current subarray
	
		int max_count = 0;  //stores the maximum length of the subarray that satisfies the given constraints
		
		for(int i=0; i<n && n-i > max_count; i++){  // loop through each element in the array
			
			mini = maxi = nums[i];   // initialize mini and maxi by assigning current element to them
			
			for(int j = i; j<n; j++){  //consider current element as the starting point of subarray 
				                       // and find the maximum length subarray starting at current index
				mini = min(mini, nums[j]);  // update the min and max element
				maxi = max(maxi, nums[j]);
				
				if(maxi >= 2 * mini){  // if the min and the max element does not satisfies the constraints, break 
					break;
				}
				
				max_count = max(max_count, j-i+1); //update the max_count
			}
			
			
		}
		
		return n - max_count; // return the minimum number of removals
		
	}
};