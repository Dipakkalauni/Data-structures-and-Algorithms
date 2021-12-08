#include<bits/stdc++.h>
using namespace std;

/*

Given an integer array, rearrange it such that every second element becomes greater than its left and right elements.

• Assume that no duplicate elements are present in the input array.
• The solution should perform single traveral of the array.
• In case the multiple rearrangement exists, the solution can return any one of them.

Input : [1, 2, 3, 4, 5, 6, 7]
Output: [1, 3, 2, 5, 4, 7, 6] or [1, 5, 2, 6, 3, 7, 4], or any other valid combination..

Input : [6, 9, 2, 5, 1, 4]
Output: [6, 9, 2, 5, 1, 4] or [1, 5, 2, 6, 4, 9], or any other valid combination..

*/

class Solution
{
public:
	void rearrange(vector<int> &nums)
	{
		// loop through the array beginning from second elements and increment the index by 2
	   for(int i=1; i<nums.size(); i=i+2){
	   	
	   	// compare the curr element with previous element and if it is less 
	   	// than the previous element swap both
	   	  if(nums[i] < nums[i-1] && i>0){
	   	  	swap(nums[i], nums[i-1]);
	   	  }
	   	  
	   	  // compare the curr element with the next element and if it is less 
	   	  // than the previous element swap both
	   	  if(nums[i] < nums[i+1] && i < nums.size()-1){
	   	  	swap(nums[i], nums[i+1]);
	   	  }
	   }
	}
};
