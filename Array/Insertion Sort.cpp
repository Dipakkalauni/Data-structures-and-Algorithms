/*

Given an integer array, inplace sort it without using any inbuilt functions.

Input : [6, 3, 4, 8, 2, 9]
Output: [2, 3, 4, 6, 8, 9]

Input : [9, -3, 5, -2, -8, -6]
Output: [-8, -6, -3, -2, 5, 9]

*/

#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
	void sort(vector<int> &nums)
	{
		int n = nums.size();  //size of an array
		
	     for(int i=1; i<n; i++){ //traverse the array from second element
	     	
	     	int j = i-1;  // point j to the i-1 the index
	     	
	     	while(j >= 0 && nums[j] > nums[j+1]){  //loop while j>=0 and j+1 th element < jth element
	     		
	     		  swap(nums[j], nums[j+1]);        // swap jth and j+1 th element
	     		  j--;                             // decrease jth element
	     	}
	     }
		
	}
};