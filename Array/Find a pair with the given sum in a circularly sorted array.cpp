/*

Given a circularly sorted integer array, find a pair with a given sum. Assume there are no duplicates in the array, and the rotation is in an anti-clockwise direction around an unknown pivot.

• The solution can return pair in any order.

Input : nums[] = [10, 12, 15, 3, 6, 8, 9], target = 18
Output: (3, 15) or (15, 3)

Input : nums[] = [5, 8, 3, 2, 4], target = 12
Output: (4, 8) or (8, 4)

• If no pair with the given sum exists, the solution should return the pair (-1, -1).

Input : nums[] = [9, 15, 2, 3, 7], target = 20
Output: (-1, -1)

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	pair<int,int> findPair(vector<int> const &nums, int target)
	{
		int n = nums.size();  //size of the array
		
		pair<int, int> p = {-1, -1};   // stores the pair with sum == target
		
		
		if(n <= 1){    // if size of array <= 1, return
			return p;
		}
		
		int start = 0;   // points to the smallest element of the array i.e. starting element
		int end = n-1;   // points to the larget element of the array i.e. ending element
		
		for(int i=1; i<n; i++){  // traverse through the array and find starting and ending point of the array
			
			if(nums[i] < nums[i-1]){
				start = i;
				end = i-1;
				break;
			}
		}
		
		while( start != end){     // loop while start != end
			
			if(nums[start] + nums[end] == target){ // if sum of start and end element == target, return
				
				p.first = nums[start];
				p.second = nums[end];
				return p;
			}
			else if(nums[start] + nums[end] > target){ // else if sum > target, decrease end
				
			   end = (end -1 + n) % n;
			}else if(nums[start] + nums[end] < target){  // else if sum < target, increase start
				
				start = (start + 1) % n;
			}
		}
		
		return {-1, -1}; 
	}
};