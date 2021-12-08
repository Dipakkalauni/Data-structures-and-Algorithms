/*

Given an integer array, find all contiguous subarrays with zero-sum.

Input : [4, 2, -3, -1, 0, 4]
Output: {[-3, -1, 0, 4], [0]}

Input : [3, 4, -7, 3, 1, 3, 1, -4, -2, -2]
Output: {[3, 4, -7], [4, -7, 3], [-7, 3, 1, 3], [3, 1, -4], [3, 1, 3, 1, -4, -2, -2], [3, 4, -7, 3, 1, 3, 1, -4, -2, -2]}

Input : [0, 0]
Output: {[0], [0, 0]}

Input : [1, 2, 3]
Output: {}

Note: Since an input can have multiple subarrays with zero-sum, the solution should return a set containing all the distinct subarrays.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	set<vector<int>> getAllZeroSumSubarrays(vector<int> const &nums)
	{
		set<vector<int>> subarrays;
        
        // multimap to store the  sum and the index up to which the we have calculated sum
	    multimap<int, int> m;
	    
	    // initializing the multimap to handle the sum = 0 condition
	    m.insert({0, -1});
	    
	    // variable to store the current sum
	    int sum = 0;
        
         // loop through the vector to find the current sum
         // if the sum is not found in the multimap, insert the sum into multimap
         // if the sum is found, then find all the subarray with same sum
         
        for(int i=0; i<nums.size(); i++){
        	sum += nums[i];
        	
        	if(m.find(sum)==m.end()){
        		m.insert({sum, i});
        	}else{
        		
        	 auto it = m.find(sum);
        	 
        	 while(it->first==sum && it != m.end()){
        	 	
        	 	vector<int> v;
        	 	
        	 	for(int j=(it->second)+1; j<=i; j++){
        	 		
        	 		v.push_back(nums[j]);
        	 	}
        	 	
        	 	subarrays.insert(v);
        	 	it++;
        	 }
        	 
        	 m.insert({sum, i});
        	 
        	}
        }
        
		return subarrays;
	}
};

