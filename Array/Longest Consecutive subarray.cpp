/*

Given an integer array, find the length of the longest subsequence formed by the consecutive integers. The subsequence should contain all distinct values, and the character set should be consecutive, irrespective of its order.

Input : [2, 0, 6, 1, 5, 3, 7]
Output: 4
Explanation: The longest subsequence formed by the consecutive integers is [2, 0, 1, 3]. It has distinct values and length 4.

Input : [1, 4, 4, 0, 2, 3]
Output: 5
Explanation: The longest subsequence formed by the consecutive integers is [1, 4, 4, 0, 2, 3]. The distinct subsequence is [1, 4, 0, 2, 3] having length 5.

Input : [2, 4, 6, 3, 7, 4, 8, 1]
Output: 4
Explanation: The longest subsequence formed by the consecutive integers is [2, 4, 3, 4, 1]. The distinct subsequence is [2, 4, 3, 1] having length 4.

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int findMaxLenSubseq(vector<int> &nums)
	{
		int len = 0;     //stores the length of maximum subsequence formed by consecutive array
		unordered_set<int> map(nums.begin(), nums.end());  //set which contains the elements of an array
		 
		for(int i=0; i<nums.size(); i++){   //loop through the array
			
			if(map.find(nums[i]-1) == map.end()){  // if curr_ele - 1 is not present in the set, start the                                                             // subsequence from given element
				
				int length = 1;                    //and check if the consecutive elements are present
				                                   // in the set  or not.1 if the 
				                                   
				while(map.find(nums[i] + length) != map.end()){
					length++;
				}
				
				len = max(len, length);
			}
			
		}
		return len;
	}
};