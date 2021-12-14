/*

Given an integer array and a positive integer `k`, find the minimum sum contiguous subarray of size `k`.

Input : nums[] = [10, 4, 2, 5, 6, 3, 8, 1], k = 3
Output: [4, 2, 5]

Input : nums[] = [1, 4, 5, 3, 8], k = 6
Output: [1, 4, 5, 3, 8]

Note: Since an input can contain several minimum sum subarrays of size `k`, the solution can return any one of them.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> findMinSumSubarray(vector<int> const &nums, int k)
	{
		vector<int> minSumSubarray;
		
		if(nums.size()==0 || k ==0){
			return minSumSubarray;
		}
		
		if(k >= nums.size()){
			return nums;
		}

		 int min_sum = INT_MAX;    // Stores the min_sum found so far
		 int curr_sum = 0;         // stores current sum found so far
		 	   
		 int leftIndex = 0;       // Stores the leftmost index of the min sum subarray
		 int rightIndex = 0;      // Stores the rightmost index of the min sum subarray
		 int left = 0;            // stores left index of the current subarray
		 int i = 0;              // used to loop through the array
		 
		 for(i = 0; i < nums.size(); i++){   // Loop through the array
		 	
		 	curr_sum += nums[i];     // add the current index the the current sum
		 	
		 	if(i+1 >= k){            // if the size of the subarray is >= k.
		 		
		 		if(curr_sum < min_sum){   //check if the curr_sum of the subarray is less the min_sum found so far
		 			min_sum = curr_sum;  // if yes update the min_sum , leftIndex and rightIndex
		 			leftIndex = left;
		 			rightIndex = i;
		 		}
		 		
		 		curr_sum -= nums[left];  //remove the leftmost index from the subarray to maintain the k size                                                  //subarray
		 		left++;
		 	}
		 }
		 
		    
		 	    
		 for(int i = leftIndex; i <= rightIndex; i++){ // insert the min Subarray into the vector
		 	
		 	 minSumSubarray.push_back(nums[i]);
		 }
		 
	
		return minSumSubarray;
	}
};
