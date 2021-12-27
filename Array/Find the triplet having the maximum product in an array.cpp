/*

Given an integer array, find a triplet having the maximum product.

Input : [-4, 1, -8, 9, 6]
Output: [-4, -8, 9]

If the input contains several triplets with maximum product, the solution can return any one of them.

Input : [5, 2, -10, 4, 5, 1, -2]
Output: [5, 4, 5] or [5, -10, -2]

Note: The solution can return the triplet in any order, not necessarily as they appear in the array.

*/

#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
	vector<int> findTriplet(vector<int> &nums)
	{
		vector<int> triplet;   
		
		int n = nums.size();      //stores the length of the array
		
		if(n <= 2){              // if the length of the array <= 2, return
			return triplet;
		}

		sort(nums.begin(), nums.end()); //sort the array in increaseing order
		
		if(nums[0]*nums[1]*nums[n-1] >= nums[n-1]*nums[n-2]*nums[n-3]){
		  
		  // if this condition holds true, 	                      
			triplet.push_back(nums[0]);
			triplet.push_back(nums[1]);
			triplet.push_back(nums[n-1]);
			
		}else{ //else
		
			triplet.push_back(nums[n-1]);
			triplet.push_back(nums[n-2]);
			triplet.push_back(nums[n-3]);
		}

		return triplet;
	}
};
