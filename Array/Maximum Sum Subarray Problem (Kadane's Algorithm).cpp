/*

Given an integer array, find the maximum sum among all its subarrays.

Input : [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: 6
Explanation: The maximum sum subarray is [4, -1, 2, 1]

Input : [-7, -3, -2, -4]
Output: -2
Explanation: The maximum sum subarray is [-2]

Input : [-2, 2, -1, 2, 1, 6, -10, 6, 4, -8]
Output: 10
Explanation: The maximum sum subarray is [2, -1, 2, 1, 6] or [6, 4] or [2, -1, 2, 1, 6, -10, 6, 4]

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int findMaxSubarraySum(vector<int> const &nums)
	{
	    int n = nums.size();  // Stores the length of the array
	    
	    int max_sum = nums[0]; //Stores the maximum Sum found so far
	    
	    int curr_sum =  nums[0]; //Stores the maximum sum up to given index
	      
	    
	    for(int i=1; i<n; i++){  //Loop through the array
	    	
	    	 curr_sum += nums[i];                 //add current element to the curr_sum
	    	 
	         curr_sum = max(curr_sum, nums[i]);   // update curr_sum if current element > curr_sum
	         
	         max_sum = max(max_sum, curr_sum);     // update max_sum if curr_sum > max_sum
	    }
	    
	    return max_sum;                  // return max_sum found so far
	}
};