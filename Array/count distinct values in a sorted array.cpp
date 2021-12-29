/*

Given an array of sorted integers that may contain several duplicate elements, count the total number of distinct absolute values in it.

Input : [-1, -1, 0, 1, 1, 1]
Output: 2
Explanation: There are 2 distinct absolutes in the array [0, 1]

Input : [-2, -1, 0, 1, 2, 3]
Output: 4
Explanation: There are 4 distinct absolutes in the array [0, 1, 2, 3]

Input : [-1, -1, -1, -1]
Output: 1
Explanation: There is only 1 distinct absolute in the array [1]

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int findDistinctCount(vector<int> const &nums)
	{
		int n = nums.size();   //stores the size of the array
		
		unordered_set<int> set;  //it is used to find the if a element is 
		                         //already present in the array or not
		                         
		int count = 0;          //stores the total number of distinct elements
		
		for(int i=0; i<n; i++){     //traverse the array
			
			//if the absolute value of a element is not present in the set, insert it, and increase the count
			if(set.find(abs(nums[i])) == set.end()){
				set.insert(abs(nums[i]));
				count++;
			}
		}
		
		return count;                  // and last return the count
	}
};