/*

Given an integer array, find all distinct combinations of a given length `k`. The solution should return a set containing all the distinct combinations, while preserving the relative order of elements as they appear in the array.

Input : [2, 3, 4], k = 2
Output: {[2, 3], [2, 4], [3, 4]}

Input : [1, 2, 1], k = 2
Output: {[1, 2], [1, 1], [2, 1]}

Input : [1, 1, 1], k = 2
Output: {[1, 1]}

Input : [1, 2, 3], k = 4
Output: {}

Input : [1, 2], k = 0
Output: {[]}

*/
#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
   
   void Combinations(vector<int> const &nums, int i, int k, set<vector<int>> &subarrays, vector<int> &ans){
   	    
   	    if(nums.size()==0 || k > nums.size()){ // check if the input is invalid
   	    	return;
   	    }
   	    
   	    if(k == 0){                  // base case
   	    	subarrays.insert(ans);   // if k ==0 , insert the currently formed vector into set
   	    	return;                   // and return
   	    }
   	    
   	      
   	    for(int j = i; j < nums.size(); j++){  // Loop through the array
   	    	
   	    	ans.push_back(nums[j]);             //push the current element into the vector
   	    	                                    // and define the recursive step that will find all other 
   	    	Combinations(nums, j+1 , k-1, subarrays, ans);  //valid  Combinations
   	    	
   	    	ans.pop_back();                     // backtrack by poping back the current element 
   	    }
   	    
   }
    
	set<vector<int>> findCombinations(vector<int> const &nums, int k)
	{
		set<vector<int>> subarrays; // Stores the final set

	     vector<int> ans; // Stores each combination of size k
	     
	   Combinations(nums, 0, k, subarrays, ans);  // Find all the Combinations using recursion 
       
	   	return subarrays;
	}
};
