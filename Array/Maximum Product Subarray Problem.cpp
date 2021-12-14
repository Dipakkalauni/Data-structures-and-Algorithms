/*

Given an integer array, find the contiguous subarray that has the maximum product of its elements. The solution should return the maximum product of elements among all possible subarrays.

Input : [-6, 4, -5, 8, -10, 0, 8]
Output: 1600
Explanation: The maximum product subarray is [4, -5, 8, -10] which has product 1600.

Input : [40, 0, -20, -10]
Output: 200
Explanation: The maximum product subarray is [-20, -10] which has product 200.

Input : [10]
Output: 10

Input : []
Output: 0

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int findMaxProduct(vector<int> const &nums)
	{
		
		if(nums.size() == 0){     // if the size of array is zero , return zero
			return 0;
		}
		
	   int curr_max = nums[0];    // store sthe maximum product of subarray ending at current index
	   
	   int curr_min = nums[0];     // store the  minimum product of subarray end at current index
	   
	   int max_so_far = nums[0];    // Stores the maximum subarray found so far
	   
	   for(int i = 1; i < nums.size(); i++){   // Loop through the subarray
	   	     
	   	     int temp = max({nums[i], curr_min * nums[i], curr_max * nums[i]});
	   	     
	   	     curr_min = min({nums[i], curr_min * nums[i], curr_max*nums[i]});
	   	  
	   	  	 curr_max = temp;
	   	
	   	  	 max_so_far = max(max_so_far, curr_max);
	   	  }
		
		return max_so_far;
	}
};