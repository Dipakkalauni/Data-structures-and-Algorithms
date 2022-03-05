#include<bits/stdc++.h>
using namespace std;

/*

Given an integer array, count the total number of strictly increasing contiguous subarrays in it.

Input: [1, 2, 4, 4, 5]
Output: 4
Explanation: The total number of strictly increasing subarrays are [1, 2], [1, 2, 4], [2, 4], [4, 5]

Input: [1, 3, 2]
Output: 1
Explanation: The total number of strictly increasing subarrays is [1, 3]

Input: [5, 4, 3, 2, 1]
Output: 0
Explanation: The total number of strictly increasing subarrays is 0

*/

class Solution
{
public:
	int getCount(vector<int> const &nums)
	{
	   int count = 0;         //stores the count of number of subarray
	   int n = nums.size();    //size of the array
	  
	   for(int i=0; i<n; i++){  //loop through the array
	   	 
	   	 for(int j=i+1; j<n; j++){  //loop from i+1 th element
	   	 	
	   	 	if(nums[j-1] >= nums[j]){ // the current element <= previous element, break
	   	 		break;                // else count++;
	   	 	}
	   	 	
	   	 	count++;
	   	 }
	   }
	   
	   return count;
	}
};