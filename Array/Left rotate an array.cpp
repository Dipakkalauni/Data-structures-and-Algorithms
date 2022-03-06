#include<bits/stdc++.h>
using namespace std;

/*

Given an integer array, left-rotate it by `k` positions, where `k` is a postive integer.

Input: nums[] = [1, 2, 3, 4, 5], k = 2
Output: [3, 4, 5, 1, 2]

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
	void leftRotate(vector<int> &nums, int k)
	{
		int n = nums.size();    // stores the size of the array
		if(k < 0 || k >= n){    //if k < 0 or greater than n, return
			return;
		}
		rev(nums, 0, n-1);    //reverse the complete array
		rev(nums, 0, n-k-1);  // reverse the array till n-k elements
		rev(nums, n-k, n-1);   // reverse the rest of the elements
	}
};
