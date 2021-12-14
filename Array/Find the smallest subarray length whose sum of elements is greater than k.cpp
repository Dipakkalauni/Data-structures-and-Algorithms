/*

Given an array of positive integers and a positive integer k, find the smallest contiguous subarray length whose sum of elements is greater than k.

Input : [1, 2, 3, 4, 5, 6, 7, 8], k = 7
Output: 1
Explanation: The smallest subarray with sum > 20 is [8]

Input : [1, 2, 3, 4, 5, 6, 7, 8], k = 20
Output: 3
Explanation: The smallest subarray with sum > 20 is [6, 7, 8]

Input : [1, 2, 3, 4, 5, 6, 7, 8], k = 21
Output: 4
Explanation: The smallest subarray with sum > 20 is [5, 6, 7, 8]

Input : [1, 2, 3, 4, 5, 6, 7, 8], k = 40
Output: 0
Explanation: No subarray exists

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int findSmallestSubarray(vector<int> const &nums, int k)
	{
		
		 int sum = 0;   // stores sum of the current subarray ending at index "i"
		 int left = 0;  // stores left end of the subarray
		 
		 int len = INT_MAX;  // stores the minimum length of the subarray having sum > k
		 
	   for(int i=0; i<nums.size(); i++){   // Loop through the array
		 	
		 	sum += nums[i];                // add current element to sum
		 	
		 		while(sum > k){            // if sum is greater than k, remove the elements from the 
		 			                       // left index of the subarray till the sum <= k
		 			len = min(len, i - left + 1);       
		 			sum -= nums[left];
		 			left++;
		 		}
		 	
		 }
		 
		 
		 if(len == INT_MAX){       // return length of the smallest subarry 
		 	                       // if the sum of all the elements in array is less or equal to k
		 	return 0;              // return zero
		 }
		 return len;
	}
};