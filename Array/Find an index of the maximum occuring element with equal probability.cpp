/*

Given a non-empty integer array, return the index of the maximum occurring element with an equal probability.

Input: nums[] = [4, 3, 6, 8, 4, 6, 2, 4, 5, 9, 7, 4]
Output: The solution should return any one of [0, 4, 7, 11] with equal probability.
Explanation: The maximum occurring element, 4, occurs at index 0, 4, 7, and 11.

If there are two maximum occurring elements in the array, the solution should consider the first occurring maximum element.

Input: nums[] = [4, 3, 6, 5, 2, 4, 1, 1]
Output: The solution should return any one of [0, 5] with equal probability.
Explanation: The maximum occurring elements are 4 and 1. Element 4 appears before element 1, at indices 0 and 5.

*/

#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
	int findIndex(vector<int> const &nums)
	{
		   int n = nums.size();
		   
		   unordered_map<int, int> map;
		   
		   for(int i=0; i<n; i++){
		   	   map[nums[i]]++;
		   }
		   
		   int max_occur = nums[0];
		   
		   for(int i=1; i<n; i++){
		   	
		   	if(map[nums[i]] > map[max_occur]){
		   		max_occur = nums[i];
		   	}
		   	
		   }
		   
		   srand(time(nullptr));
		   int random = (rand() % map[max_occur])+1;
		    
		   int i = 0;
		   while(random > 0 && i<n){
		   	 
		   	 if(nums[i] == max_occur){
		   	 	random--;
		   	 }
		   	 
		   	 i++;
		   }
		   
		   return i-1;
		   
	}
};