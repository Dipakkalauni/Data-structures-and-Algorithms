/*

Given an integer array, partition it into two contiguous subarrays having the same sum of elements and return the index that points to the starting of the second subarray. Return -1 if no partition is possible.

Input : [6, -4, -3, 2, 3]
Output: 2
Explanation: The subarrays [6, -4] and [-3, 2, 3] have equal sum of 2. The second subarray starts from index 2.

Input : [6, -5, 2, -4, 1]
Output: -1
Explanation: No equal sum partition possible.

In case multiple solutions is possible, return the index of the first occurrence. For example,

Input : [1, -1, 1, -1, 1, -1]
Output: 0

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int findPartitionIndex(vector<int> const &nums)
	{
		int n = nums.size();    // size of the array
		int total_sum = 0;       // stores the total_sum of the elements in the array
		
		if(n <= 1){           // if length of the array is less than and equal to 1, return -1
			return -1;
		}
		
		for(int i=0; i<n; i++){     // traverse the array and find the total_sum of the array elements
			
			total_sum += nums[i];
			
		}
		 
		 int left_sum = 0;         //stores the sum up to the current index
		 
		 if(left_sum == total_sum){  // if the total_sum is zero, return the first index
		 	return 0;
		 }
		 
		for(int i=0; i<n; i++){  // again traverse the array to find the partition index 
			
			left_sum += nums[i]; // add the current element to the left_sum
			
		if(left_sum == total_sum - left_sum){  //if the left_sum == to the sum of the remaining half of the array
				return i+1;                    // return i+1
			}
		}
		
		
		return -1;                            // at last, return -1
	}
};