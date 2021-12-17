/*

Given an unsorted integer array, find a triplet with a given sum `k` in it.

Input : [4, -1, 1, 2, -1], k = 0
Output: [-1, 2, -1]

Input : [4, 5, 4, -1, 3], k = 10
Output: []
Explanation: No triplet exists with sum 10.

If the input contains several triplets with sum `k`, the solution can return any one of them.

Input : nums[] = [2, 7, 4, 0, 9, 5, 1, 3], k = 6
Output: [0, 1, 5] or [0, 2, 4] or [1, 2, 3]

Note: The solution can return the triplet in any order, not necessarily as they appear in the array.

*/
#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:

  
	vector<int> findTriplets(vector<int> &nums, int k)
	{
	   int n = nums.size();        //Stores the length of the array
	   vector<int> ans;            // stores the required triplet
	   
	    for(int i=0; i<n-2; i++){  // loop through the each element
	    	
	    	int sum = k - nums[i]; // calculate sum which is required sum - current element
	    	unordered_set<int> s;  // now we will find a pair from remaining element whose sum = sum;
	    	
	    	for(int j = i+1; j<n; j++){ //loop through remaining elements greater than index i
	    		
	    		if(s.find(sum - nums[j]) == s.end()){  //if sum-nums[j] is not in the set, insert it
	    			
	    			s.insert(nums[j]);
	    			
	    		}else{                                // else we found of our required pair and 
	    			ans.push_back(nums[i]);          // insert the pair and nums[i] into vector 
	    			ans.push_back(nums[j]);           // and return the pair
	    			ans.push_back(sum - nums[j]);
	    			return ans;
	    		}
	    	}
	    }
	}
};