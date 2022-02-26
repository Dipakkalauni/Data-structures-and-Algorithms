/*

Given an integer array, find an index that divides it into two non-empty contiguous subarrays having an equal sum.

Input : [-1, 6, 3, 1, -2, 3, 3]
Output: 2
Explanation: The element 3 at index 2 divides the array into two non-empty subarrays `[-1, 6]` and `[1, -2, 3, 3]` having the same sum.

• The solution should return -1 if no partition is possible.

Input : [6, -5, 2, -4, 1]
Output: -1
Explanation: No equal sum partition possible.

• In case multiple partitions is possible, return the index of the first partition.

Input : [-1, -2, 2, -3]
Output: 1
Explanation: The index 1 and 2 divides the array into two equal sum subarrays. The solution should return index 1.

Input : [4, 2, -3, 4, -1, 0, 4]
Output: 1
Explanation: The index 1 and 3 divides the array into two equal sum subarrays. The solution should return index 1.

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int findBreakPoint(vector<int> const &nums)
	{
		 int sum = 0;          //stores the total sum of the array
		 int n = nums.size();  //stores the total length of the array
		 
		for(int i=0; i<n; i++){ //traverse the array to find the sum of the array
			
			sum += nums[i];
		}
		 
		 int curr_sum = 0;      //stores the sum up to the curr_index
		 
		for(int i=0; i<n-2; i++){  //traverse the array up to the n-2
			
			curr_sum += nums[i];   //add current element to the curr_sum
			
			if(curr_sum == (sum - curr_sum - nums[i+1])){ //if the curr_sum == (sum - curr_sum = nums[i+1])
				
				return i+1;                                // return i+1
			}
		}
		
		return -1;             //return -1
	}
};