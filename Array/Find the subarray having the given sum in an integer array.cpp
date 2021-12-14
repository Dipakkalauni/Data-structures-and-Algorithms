/*

Given an integer array, find a contiguous subarray having sum `k` in it where `k` is an integer.

Input : nums[] = [2, 6, 0, 9, 7, 3, 1, 4, 1, 10], k = 15
Output: [6, 0, 9]

Input : nums[] = [0, 5, -7, 1, -4, 7, 6, 1, 4, 1, 10], k = -3
Output: [1, -4]

Note: Since an input can contain several subarrays having sum `k`, the solution can return any one of them.

Input : nums[] = [0, 5, -7, 1, -4, 7, 6, 1, 4, 1, 10], k = 15
Output: [1, -4, 7, 6, 1, 4] or [4, 1, 10]

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> findSubarray(vector<int> const &nums, int k)
	{
		vector<int> subarray;     // array to store the subarray
        
        if(nums.size() == 0){      // if the size of subarray is zero, return
        	return subarray;
        }
        
	    unordered_map<int, int> m;  // unordered_map to store the sum of elements till index current index
	     m.insert({0, -1});         // initialize the map with {0, -1} to handle the case the 
	                                // when sum of the elements till current index is equal to k
	    int sum = 0;  
	    
	    for(int i=0; i < nums.size(); i++){  //loop through the array
	    	
	       sum += nums[i];                   // add the current index to the sum 
	       
	       if(m.find(sum - k) == m.end()){   // if the the (sum - target) is not in the map
	       	                                 // insert it in the map
	       	  m.insert({sum, i});
	       }else{                           // else we have found the subarray with sum equal to k
	       	  
	       	  for(int j = m[sum-k]+1; j <= i; j++){   // insert the subarray into vector and break
	       	  	
	       	  	 subarray.push_back(nums[j]);
	       	  }
	       	  
	       	  break;
	       }
	    	
	    }
		
		return subarray;                 // return the vector
	}
};
