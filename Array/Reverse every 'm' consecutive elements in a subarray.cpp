/*

Given an integer array `nums` and non-negative integers i, j, and m, reverse every group of consecutive `m` elements in subarray `[i, j]`.

Input : nums[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], m = 3, i = 1, j = 7
Output: [1, 4, 3, 2, 7, 6, 5, 8, 9, 10]

Input : nums[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], m = 3, i = 1, j = 9
Output: [1, 4, 3, 2, 7, 6, 5, 10, 9, 8]

Input : nums[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], m = 3, i = 3, j = 5
Output: [1, 2, 3, 6, 5, 4, 7, 8, 9, 10]

Input : nums[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], m = 3, i = 3, j = 4
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

*/
#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:

    void reverse(vector<int> &nums, int l, int j){
    	
    	while(l < j){
    	   int temp = nums[l];
    	   nums[l] = nums[j];
    	   nums[j] = temp;
    	   
    		l++;
    		j--;
    	}
    }
    
	void reverseInGroup(vector<int> &nums, int m, int i, int j)
	{
		  
		  
		  if(m > j-i+1  || nums.size() <= 1){  // if (m > length of the subarray) or (array size <= 1), return
		  	
		  	return;
		  }
		  
		  if(m <= 1){ // if m is the less than or equal to 1, return
		  	return;
		  }
		  
		  
		for(int l = i; l <= j; l = l+m){  //loop through every mth subarray elements
			
		   if(l+m-1 <= j){  // if the next mth element <= end of the subarray,
		                      //reverse the elements from current index to next mth index
		   	  
		   	 reverse(nums, l, l+m-1);
		   }
		}
	}
};