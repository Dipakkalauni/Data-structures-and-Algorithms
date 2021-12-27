#include<bits/stdc++.h>
using namespace std;

/*

Given an integer array and a positive integer `k`, find the count of distinct elements in every contiguous subarray of size `k`.

Input : nums[] = [2, 1, 2, 3, 2, 1, 4, 5], k = 5
Output: [3, 3, 4, 5]
Explanation:

The count of distinct elements in subarray [2, 1, 2, 3, 2] is 3
The count of distinct elements in subarray [1, 2, 3, 2, 1] is 3
The count of distinct elements in subarray [2, 3, 2, 1, 4] is 4
The count of distinct elements in subarray [3, 2, 1, 4, 5] is 5


Input : nums[] = [1, 1, 2, 1, 3], k = 3
Output: [2, 2, 3]
Explanation:

The count of distinct elements in subarray [1, 1, 2] is 2
The count of distinct elements in subarray [1, 2, 1] is 2
The count of distinct elements in subarray [2, 1, 3] is 3

*/

class Solution
{
public:
	vector<int> findDistinctCount(vector<int> const &nums, int k)
	{
	   int n = nums.size();   //stores the length of the array
	   
	   vector<int> ans;      // stores the number of distinct elements in all of the subarray
	   
	   if(n == 0 || k > n){ //if n == 0 || k > n, then return 
	   	  return ans;
	   }
	   
	   unordered_map<int, int> map;  // used to store the elements in the subarray
	   
	   int i = 0;                    
	   int j = 0;
	   
	    while(i < k){               //traverse through the array while 'i' < k
	   	  	 if(map.find(nums[i]) == map.end()){ // if nums[i] is not found in the map, insert nums[i] and count
	   	  	 	 map[nums[i]] = 1;
	   	  	 }else{                       // else increase the count
	   	  	 	map[nums[i]]++;
	   	  	 }
	   	  	 
	   	  	 i++;
	   	  }
	   	  
	    ans.push_back(map.size());  //push_back the size of map to the ans
	   
	   while(i < n){             // again traverse through the remaining array
	   	 
	   	  map[nums[i]]++;       // add the ith element to the map
	   	  
	   	  map[nums[j]]--;       // decrease the count of the jth element in the array
	   	  
	   	  if(map[nums[j]] == 0){  //if the count is equal to 0, erase it from the map
	   	  	  map.erase(nums[j]);
	   	  }
	   	  
	   	  ans.push_back(map.size());      // push_back the size of map into the array
	   	  i++;                            // increase both i and j
	   	  j++;
	   }
	   
	   return ans;                  // return ans
	}
};