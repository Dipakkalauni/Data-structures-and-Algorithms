#include<bits/stdc++.h>
using namespace std;

/*

Given an integer array, right-rotate it by `k` positions, where `k` is a postive integer.

Input: nums[] = [1, 2, 3, 4, 5], k = 2
Output: [4, 5, 1, 2, 3]

Input: nums[] = [1, 2, 3, 4, 5, 6, 7], k = 3
Output: [5, 6, 7, 1, 2, 3, 4]

Input: nums[] = [1, 2, 3, 4, 5], k = 6
Output: [1, 2, 3, 4, 5]

*/

class Solution
{
public:

  
    void rev(vector<int> &nums, int start, int end){  //function to reverse the elements for index = start to 
    	                                              // index = end
    	while(start < end){
    		int temp = nums[start];
    		nums[start] = nums[end];
    		nums[end] = temp;
    		start++;
    		end--;
    	}
    }

	void rightRotate(vector<int> &nums, int k)
	{
		int n = nums.size();
		if(k<0 || k>=n){
			return;
		}
		rev(nums, 0, n-1);
		rev(nums, 0, k-1);
		rev(nums, k, n-1);
		
	}
};

