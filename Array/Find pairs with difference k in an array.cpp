/*

Given an unsorted integer array, find all pairs with a given difference `k` in it without using any extra space.

Input : nums = [1, 5, 2, 2, 2, 5, 5, 4], k = 3
Output: {(2, 5), (1, 4)}

Note:

• The solution should return the pair in sorted order. For instance, among pairs (5, 2) and (2, 5), only pair (2, 5) appeared in the output.

• Since the input can contain multiple pairs with a given difference, the solution should return a set containing all the distinct pairs. For instance, the pair (2, 5) appeared only once in the output.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	set<pair<int,int>> findPairs(vector<int> &nums, int k)
	{
		set<pair<int,int>> pairs;     // stores pairs whose difference is k

        sort(nums.begin(), nums.end());  // sort the vector
        
        if(nums.size() <= 1){  // if the length of the vector <= 1, return the pairs
        	
        	return pairs;
        }
        
        int i = 0;       // start from i = 0 and j = 0
        int j = 0;
        
        while(i < nums.size() && j < nums.size()){  //loop through the array while i and j < array size
        	
        	while(i < nums.size() && nums[i] == nums[i+1]){ //if current element is duplicate skip it
        		i++;
        	}
        	
        	while(j < nums.size() && nums[j] == nums[j+1]){
        		j++;
        	}
        	
        	if(nums[j] - nums[i] < k){   // if difference of nums[j] and nums[i] < k, increase j
        		
        		j++;
        		
        	}else if(nums[j] - nums[i] > k){  // if difference of nums[j] amd nums[i] > k, increase i
        		
        		i++;
        	}else{             // else if the difference of nums[i] and nums[j] == k
        		 
        		 int a = max(nums[i], nums[j]);       
        		  int b = min(nums[i], nums[j]);
        		
        		 pairs.insert({b, a});     // insert the pair into set in sorted order
        		 i++;                      // and increase i and j
        		 j++; 
        	}
        }
        
		return pairs;
	}
};