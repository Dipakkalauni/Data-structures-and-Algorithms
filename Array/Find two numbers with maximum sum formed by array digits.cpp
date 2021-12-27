/*

Given an integer array between 0 and 9, generate a pair using all the array digits that has the maximum sum. The difference in the number of digits of the two numbers should be ± 1.

Input : [4, 6, 2, 7, 9, 8]
Output: (974, 862)

Input : [9, 2, 5, 6, 0, 4]
Output: (952, 640)

The solution can return pair in any order. If a pair cannot be formed, the solution should return the pair (0, 0).

*/


#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
	pair<int,int> constructMaxSumNumber(vector<int> &nums)
	{
		int n = nums.size();         //Stores the length of the array
		
	    if(n <= 1){               // if the length of the array is <=1, return {0, 0}
	    	
	    	return {0, 0};
	    }
	    
		sort(nums.begin(), nums.end(), greater<int>());  // sort the array in decreasing order
		
		int a = nums[0];              //stores the first number
		int b = nums[1];              //stores the second number
		
		for(int i=2; i<n; i++){     //traverse through the array
			
			if(i%2 == 0){            //if the index is even, add this element to the first number
				a = a*10 + nums[i];   // otherwise, add this element to the second number
			}else{
				
				b = b*10 + nums[i];
			}
		}
		
		return {a, b};            //return both the numbers
		
	}
};