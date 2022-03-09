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
		int n = nums.size();    // stores the size of the array   
		
		for(int i=n-1; i>0; i--){
			
		   for(int j=0; j<i; j++){
		   	
		   	  if(nums[j] > nums[j+1]){
		   	  	
		   	  	swap(nums[j], nums[j+1]);
		   	  }
		   }
		}
		
	}
};
