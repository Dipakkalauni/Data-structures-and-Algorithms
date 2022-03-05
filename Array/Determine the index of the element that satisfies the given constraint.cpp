/*

Given an integer array, determine the index of an element before which all elements are smaller and after which all are greater.

Input: [4, 2, 3, 5, 1, 6, 9, 7]
Output: 5
Explanation: All elements before index 5 are smaller, and all elements after index 5 are greater.

• In case multiple indices satisfies the problem constraints, the solution should return the minimum index.

Input: [1, 2, 3, 4, 5]
Output: 1
Explanation: Index 1, 2, and 3 satisfies the problem constraints. The solution should return the minimum index, i.e., 1.

• For invalid inputs, the solution should return -1.

Input: [] or [1] or [1, 2] or [5, 4, 3, 2, 1]
Output: -1

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int findIndex(vector<int> const &nums)
	{
	      int n = nums.size();  //stores the size of the array
	      
	      if(n <= 2){         //if size <= 2, return -1
	      	return -1;
	      }
	      
	      vector<int> left(n);  // stores the maximum element till the current index
	      left[0] = INT_MIN;   
	      
	     for(int i=1; i<n; i++){ //loop through the array and store the maximum element till index "i"
	     	
	     	left[i] = max(nums[i-1], left[i-1]);
	     }
	     
	       int mini = INT_MAX;      //stores the minimum element in right side of index "i"
	       int index = -1;          // stores the index which satitsfies the condition
	       
	     for(int i = n-2; i > 0; i--){  //loop the array from right to left
	     	
	     	 mini = min(mini, nums[i+1]);  //find minimum element up to the current index from right side
	     	 
	     	 if(nums[i] > left[i] && nums[i] < mini){ // if current element > max_ele to its left side 
	     	 	index = i;                            // and less the min_ele to its right side
	     	 }                                         // then store  the index in "i"
	     }
	     
	     return index;                           //return index
	     
	     
	}
};