/*

Given an integer array, find all maximum size contiguous subarrays having all distinct elements in them.

Input : [5, 2, 3, 5, 4, 3]
Output: {[5, 2, 3], [2, 3, 5, 4], [5, 4, 3]}

Input : [1, 2, 3, 3]
Output: {[1, 2, 3], [3]}

Input : [1, 2, 3, 4]
Output: {[1, 2, 3, 4]}

Note: Since an input can have multiple subarrays with all distinct elements, the solution should return a set containing all the distinct subarrays.

*/
#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
	set<vector<int>> findDistinctSubarrays(vector<int> const &nums)
	{
		set<vector<int>> subarrays;           //stores all the maximum size subarrays

	    int n = nums.size();                 //stores the length of the array
        unordered_set<int> ans;              // stores the current distinct subarrays
        
        if(n == 0){                       // if size of the array is 0, return 
        	
        	return subarrays;
        }
        
        int i = 0;
        int j = 0;
        
        while(i < n && j<n){  // traverse the array
        	
        	while(ans.find(nums[i]) == ans.end() && i<n){  //if the current element is not in the set 'ans'
        		                                           // i.e. it is the distinct element
        		ans.insert(nums[i]);                      // insert it into the set 'ans'
        		i++;                                      // increase index 'i'
        	}
        	
        	vector<int> v;                             //store the current subarray into the vector
        	for(int k = j; k < i; k++){                // and insert the vector into set 'subarrays'
        		
        		v.push_back(nums[k]);
        	}
        	
        	subarrays.insert(v);
        	
        	while(ans.find(nums[i]) != ans.end() && j < n){ //increase 'j' while the ith element is removed 
        		                                             // from the map or, move j to point to next
        		ans.erase(nums[j]);                          // distinct subarray
        		j++;
        	}
        }
        
		return subarrays;                               // return the subarrays
	}
};