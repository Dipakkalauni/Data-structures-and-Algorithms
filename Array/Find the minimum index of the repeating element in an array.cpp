/*

Given an integer array, find the minimum index of a repeating element in linear time and doing just a single traversal of the array.

Input : [5, 6, 3, 4, 3, 6, 4]
Output: 1
Explanation: The minimum index of the repeating element is 1

Input : [1, 2, 3, 4, 5, 6]
Output: -1
Explanation: Input doesn't contain any repeating element

*/
#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
	int findMinIndex(vector<int> const &nums)
	{
	   int n = nums.size();         //stores the length of the array
	   
	   unordered_map<int, int> map;   // map to find out the the repeated element
	    
	    int min_index = INT_MAX;     // stores the minimum repeating index;
	    
	   for(int i=0; i<n; i++){    //traverse through the array
	   	
	   	   if(map.find(nums[i]) == map.end()){   //if the current element is not found in the map, insert it
	   	   	
	   	   	  map.insert({nums[i], i});
	   	   }else{                            //else compare the index with the min_index
	   	   	
	   	   	 if(map[nums[i]] < min_index){
	   	   	 	
	   	   	 	 min_index = map[nums[i]];
	   	   	 }
	   	   }
	   }
	   
	   if(min_index == INT_MAX){             // if the array has all the distinct elements, return -1
	   	                                    // else return min_index
	   	  return -1;
	   }else{
	   	
	   	 return min_index;
	   }
	}
};
