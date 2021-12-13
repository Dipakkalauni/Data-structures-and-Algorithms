/*

Given an integer array, find a contiguous subarray within it that has the maximum sum.

Input : [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: [4, -1, 2, 1]

Input : [-7, -3, -2, -4]
Output: [-2]

In case multiple subarrays exists with the largest sum, the solution can return any one of them.

Input : [-2, 2, -1, 2, 1, 6, -10, 6, 4, -8]
Output: [2, -1, 2, 1, 6] or [6, 4] or [2, -1, 2, 1, 6, -10, 6, 4]

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> findMaxSumSubarray(vector<int> const &nums)
	{
	    	vector<int> ans;
		
		   int n = nums.size();   //Stores length of the array
		
		   if(n == 0 || n==1){     // if length of the array is less than and equal to one 
		    	return nums;         // return the array
		    }
		  
		  int curr_sum = nums[0];   //Stores maximum sum of subarray ending at the current index
		  int max_sum = nums[0];   // Stores maximum sum of subarray found so far
		
	   	  int index = 0;           // Stores starting index of the maximum sum subarray
		                         // ending at current index
		                         
	  	  int ind_start = 0;       //Stores starting index of the maximum sum subarray found so far
		  int ind_end = 0;         // Stores ending index of the maximum sum subarray found so far
		
		  for(int i=1; i<n; i++){   //Loop through the array
			
		    curr_sum += nums[i];  //add current element to the curr_sum
			 
			 if(nums[i] > curr_sum){ // if current element > curr_sum
			 	                     //then update the maximum sum subarray ending at current index
			 	 curr_sum = nums[i];  // and store current index in "index" variable
			 	 index = i;
			 }
			 
			 if(max_sum < curr_sum){ // if the curr_sum > max_sum
			 	                     // update the max_sum 
			 	max_sum = curr_sum;  // and store the starting index and ending index
			 	ind_start = index;   // of the maximum sum subarray found so far
			 	ind_end = i;
			 	
			 }
		}
		
		for(int i = ind_start; i<= ind_end; i++){  // push back the maximum sum subarray into the vector
			                                       // using the starting and ending index
			ans.push_back(nums[i]);
		}
		
		return ans;                             // return the vector
	}
};