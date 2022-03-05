#include<bits/stdc++.h>
using namespace std;

/*

Given an array of distinct integers `nums`, shuffle it according to order specified by another array `pos`. For every index `i` in `nums`, the solution should update `nums[pos[i]] = nums[i]`.

Input:

nums[] = [1, 2, 3, 4, 5]
 pos[] = [3, 2, 4, 1, 0]

Output: [5, 4, 2, 1, 3]

*/

class Solution
{
public:
	void shuffle(vector<int> &nums, vector<int> &pos)
	{
		int n = nums.size();  //stores the length of the array
		vector<int> res(n);   //stores the nums[i] element at pos[i];
		
		for(int i=0; i<n; i++){   //loop through the array
			res[pos[i]] = nums[i];   //store the nums[i] element at pos[i] th position of the array
		}
		
		for(int i=0; i<n; i++){   //copy the res to nums
			nums[i] = res[i];
		}
	}
};