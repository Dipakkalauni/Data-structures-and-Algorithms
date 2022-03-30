/*

Given an unsorted integer array, find all triplets in it with sum less than or equal to a given number.

Input : nums[] = [2, 7, 4, 9, 5, 1, 3], target = 10
Output: {[1, 2, 3], [1, 2, 4], [1, 2, 5], [1, 2, 7], [1, 3, 4], [1, 3, 5], [1, 4, 5], [2, 3, 4], [2, 3, 5]}

Input : nums[] = [3, 5, 7, 3, 2, 1], target = 5
Output: {}

Since the input can have multiple triplets with sum less than or equal to the target, the solution should return a set containing all the distinct triplets in any order.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

    
	set<vector<int>> getTriplets(vector<int> &nums, int target)
	{
		set<vector<int>> subsets;
         
         if(nums.size() < 3){ //if nums has less than three elements return
         	
         	return subsets;
         }
         
         //sort the nums int ascending order
		sort(nums.begin(), nums.end());
		
		//check if triplet is formed by nums[i] and a pair from [i+1...n]
		for(int i = 0; i <= nums.size()-3; i++){
			
			int low = i+1; 
			int high = nums.size() - 1;
			
			 vector<int> ans(3);
			 
			  ans[0] = nums[i];
			 
			while(low < high){
				
				if(nums[i] + nums[low] + nums[high] > target){
					
					high--;
					
				} else{
					
					ans[1] = nums[low];
					
					for(int j = low + 1; j <= high; j++){
						
						ans[2] = nums[j];
						subsets.insert(ans);
					
					}
					
					low++;
				}
				
				
			}
		}

		return subsets;
	}
};
