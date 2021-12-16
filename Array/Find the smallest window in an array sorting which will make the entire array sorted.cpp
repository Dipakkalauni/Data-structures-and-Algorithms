/*

Given an integer array, find the smallest window sorting which will make the entire array sorted in increasing order. The solution should return a pair consisting of the starting and ending index of the smallest window.

Input : [1, 2, 3, 7, 5, 6, 4, 8]
Output: (3, 6)
Explanation: The array can be sorted from index 3 to 6 to get sorted version.

Input : [1, 3, 2, 7, 5, 6, 4, 8]
Output: (1, 6)
Explanation: The array can be sorted from index 1 to 6 to get sorted version.

If the array is already sorted, the solution should return pair (0, 0).

Input : [1, 2, 3, 4, 5]
Output: (0, 0)
Explanation: The array is already sorted.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	pair<int,int> findSmallestWindow(vector<int> const &nums)
	{
	    pair<int, int> p = {0,0};  // Stores the left and right indes of the 
	                               // smallest window and initialized with {0, 0}
	     int i = 0;               // Used to loop throught the array
	     
	     if(nums.size() == 0 || nums.size() == 1){ //if length of an array is 0 or 1
	     	return p;                               // return {0,0};
	     }
	     
	     int max_ele = INT_MIN;   //Stores the maximum element found so far
	     int right_index = 0;     // stores the rightmost index of smallest window
	     int left_index = 0;      //Stores the leftmost index of smallest window
	     
	     int flag = 0;         // used to check the disorder of elements is for the                                   // first time or not
	   
	      
	     while(i < nums.size()){  // loop through the entire array
	     	
	     	if(nums[i] > max_ele){  //if current element is greater then max_ele
	     		max_ele = nums[i];  // Update max_ele and 
	     	}
	     	
	     	if(flag == 0 && nums[i] < max_ele){// if the flag is zero and the current
	     		int j = i-1;                   // element is less than max_ele i.e.
	     		                              // we have found disorder for the first
	     		while(nums[i] < nums[j]){     // time. Therefore loop through the 
	     			left_index = j;          //previous element and check whether the
	     			j--;                   // current element is less than them or not.
	     		}                          // and store the previous element index 
	     		                           // in left_index
	     		right_index = i;      // store current element index in right_index
	     		flag = 1;             // and change the flag to 1
	     		
	     	}else if(flag == 1 && nums[i] < max_ele){
	     		//if the flag is 1 and the current element is less than max_ele
	     		// change the right_index to the current index
	     		
	     		right_index = i;
	     	}
	     	
	     	i++;
	     }
	    	
	    p = {left_index, right_index};  //insert the left_index and right_index 
	    return p;                        // into the pair and return the pair
	}
};