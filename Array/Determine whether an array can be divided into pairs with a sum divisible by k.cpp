/*

Given an integer array, determine whether it can be divided into pairs such that the sum of elements in each pair is divisible by a given positive integer `k`.

Input: nums[] = [3, 1, 2, 6, 9, 4], k = 5
Output: true
Explanation: Array can be divided into pairs {(3, 2), (1, 9), (4, 6)}, where the sum of elements in each pair is divisible by 5.

Input: nums[] = [2, 9, 4, 1, 3, 5], k = 6
Output: true
Explanation: Array can be divided into pairs {(2, 4), (9, 3), (1, 5)}, where the sum of elements in each pair is divisible by 6.

Input: nums[] = [3, 1, 2, 6, 9, 4], k = 6
Output: false
Explanation: Array cannot be divided into pairs where the sum of elements in each pair is divisible by 6.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	bool hasPairs(vector<int> const &nums, int k)
	{
	  int n = nums.size();    //stores the size of the array
	  
	  if(n % 2 != 0){     //if array has odd number of elements, return false
	  	 return false;
	  }
	  
	  unordered_map<int, int> map;  // map to store the pair of remainder and its frequency of occurance
	  
	  for(int i=0; i<n; i++){  // loop through the array and if remainder of curr_ele is negative , add k to it
	  	                         // and increase the frequency by 1
	  	if(nums[i] % k < 0){     // else update the frequency of rem by 1
	  		
	  	  map[nums[i]%k + k] += 1;
	  	}else{
	  		
	  	map[nums[i] % k] += 1;
	  	}
	  }
	  
	  for(auto const &ele : map){  // loop through the map
	  	
	  	int r = ele.first;        // store remainder and frequency in r and f
	  	int f = ele.second;
	  	
	  	
	  	if(r == 0 ){         //if rem is 0 and frequency is not even return false
	  		
	  		if(f % 2 != 0){
	  			
	  		return false;
	  		
	  		}
	  		
	  	}else if(f != map[k-r]){  //else if frequency of r != frequency of k-r, return false
	  		
	  		return false;
	  	}
	  }
	  
	  return true;     //else return true
	  
	  
	}
};