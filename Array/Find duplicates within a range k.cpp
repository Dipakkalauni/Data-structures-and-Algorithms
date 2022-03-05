/*

Given an integer array and a positive number `k`, check whether the array contains any duplicate elements within the range `k`. If `k` is more than the array’s size, the solution should check for duplicates in the complete array.

Input: nums[] = [5, 6, 8, 2, 4, 6, 9], k = 4
Output: true
Explanation: Element 6 repeats at distance 4 which is <= k

Input: nums[] = [5, 6, 8, 2, 4, 6, 9], k = 2
Output: false
Explanation: Element 6 repeats at distance 4 which is > k

Input: nums[] = [1, 2, 3, 2, 1], k = 7
Output: true
Explanation: Element 1 and 2 repeats at distance 4 and 2, respectively which are both <= k

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	bool hasDuplicate(vector<int> const &nums, int k)
	{   
		int n = nums.size();        //stores the length of the array
		unordered_set<int> map;     //stores the element within the range k
		
	   for(int i=0; i<n; i++){      //loop through the array
	   	 
	   	 if(map.find(nums[i]) != map.end()){  //if current element is in the map, return true
	   	 	 return true;
	   	 }
	   	 
	   	 map.insert(nums[i]);    //insert the current element in the map
	   	 
	   	 if(i >= k){             //if i>=k erase the i-k th element from the map
	   	 	 map.erase(nums[i - k]);
	   	 }
	   }
		
		return false; 
	}
};