/*

Given an integer array, move all zeros present in it to the end. The solution should maintain the relative order of items in the array and should not use constant space.

Input : [6, 0, 8, 2, 3, 0, 4, 0, 1]
Output: [6, 8, 2, 3, 4, 1, 0, 0, 0]

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

  
	void rearrange(vector<int> &nums)
	{
	
	  int j = 0; //initialize j with zero

	  //loop through the array

	  for(int i=0; i<nums.size(); i++){
	  	 
		   // if the current element is not equal to zero 
		   // swap the current element with element at jth position
		   // and increment j.
	  	 if(nums[i] != 0){
	  	 	
	  	 	swap(nums[i], nums[j]);
	  	 	j++;
	  	 }
	  }
	}
};