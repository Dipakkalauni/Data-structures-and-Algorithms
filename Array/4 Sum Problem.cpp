/*

Given an unsorted integer array, find all quadruplets (i.e., four elements tuple) having a given sum.

Input : nums = [2, 7, 4, 0, 9, 5, 1, 3], target = 7
Output: {[0, 1, 2, 4]}

Since the input can contain multiple quadruplets that sum to a given target, the solution should return a set containing all the quadruplets.

Input : nums = [2, 7, 4, 0, 9, 5, 1, 3], target = 20
Output: {[0, 4, 7, 9], [1, 3, 7, 9], [2, 4, 5, 9]}

Note: The order of elements doesn't matter in a quadruplet, and any permutation is allowed in the output. For example, the output set can contain quadruplets [9, 1, 7, 3] and [9, 3, 7, 1], but system treats them the same.

*/
#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
	set<vector<int>> findQuadruplets(vector<int> &nums, int target)
	{
		set<vector<int>> quadruplets;      //stores all the quadruplets
         
        unordered_map<int, vector<pair<int, int>>> maps;  //stores a sum and a vector of pairs if indexes which has                                                            // a given sum
        
         int n = nums.size();    //stores the length of an element
          
	     for(int i=0; i<n-1; i++){  // loop through the array except the last element
	     	
	       for(int j = i+1; j<n; j++){  // for each "ith" element consider every element whose index > i
	       	
	       	  int sum = target - (nums[i] + nums[j]);  // calculate the remaining sum
	       	  
	       	  if(maps.find(sum) != maps.end()){     //if the remaining sum is found
	       	  	                                       // insert the vector of four elements whose sum is target
	       	  	 for(auto p : maps.find(sum)->second){  // into the quadruplets set.
	       	  	 	
	       	  	 	int x = p.first;
	       	  	 	int y = p.second;
	       	  	 	
	       	  	 	if((x != i && x!= j) && (y != i && y != j)){
	       	  	 		
	       	  	 		 vector<int> v;
	       	  	 		 
	       	  	 		 v.push_back(nums[x]);
	       	  	 		 v.push_back(nums[y]);
	       	  	 		 v.push_back(nums[i]);
	       	  	 		 v.push_back(nums[j]);
	       	  	 		 
	       	  	 		 quadruplets.insert(v);
	       	  	 	}
	       	  	 }
	       	  }
	       	  
	       	  maps[nums[i]+nums[j]].push_back({i, j});   // and insert the sum of ith and jth elements and i and j 
	       }                                             // indexes into map
	     }
	     
	     

		return quadruplets;
	}
};

