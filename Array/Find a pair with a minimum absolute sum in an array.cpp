/*

Given a sorted integer array, find a pair in it having an absolute minimum sum.

Input : [-6, -5, -3, 0, 2, 4, 9]
Output: (-5, 4)
Explanation: (-5, 4) = abs(-5 + 4) = abs(-1) = 1, which is minimum among all pairs.

• Each input can have multiple solutions. The output should match with either one of them.

Input : [-6, -2, 0, 1, 5]
Output: (-6, 5) or (-2, 1) or (0, 1)

• The solution can return pair in any order. If no pair exists, the solution should return the pair (-1, -1).

Input : [1]
Output: (-1, -1)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	pair<int,int> findPair(vector<int> const &nums)
	{
		int n = nums.size();          //Stores the size of the array
		
		if(n < 2){                    // if the size of array < 2, return {-1, -1}
			return {-1, -1};
		}
		
		int low = 0;                   // points to left end of the array
		int high = n-1;                // points to right end of the array
		
		int minimum = INT_MAX;          // stores the minimum absolute sum
		pair<int, int> p;              // stores the pair with minimum absolute sum
		
		while(low < high){             // traverse the array while low < high
			
			if(abs(nums[high] + nums[low]) < minimum){  //check if absolute sum < minimum
				                                        // if yes, update minimum and pair 'p'
				minimum = abs(nums[high] + nums[low]);
				p = {nums[low], nums[high]};
			}
			
			if((nums[low] + nums[high]) >= 0){        //if sum of high and low elements >= 0, decrease high
				high--;                               // else low
			}else{
				low++;
			}
		}
		
		return p;                                    // return p
	}
};
