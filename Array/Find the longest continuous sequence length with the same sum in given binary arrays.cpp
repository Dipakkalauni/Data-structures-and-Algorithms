/*

Given two binary arrays, `X` and `Y`, find the length of the longest continuous sequence that starts and ends at the same index in both arrays and have the same sum. In other words, find `max(j-i+1)` for every `j >= i`, where the sum of subarray `X[i, j]` is equal to the sum of subarray `Y[i, j]`.

Input:

X[]: [0, 0, 1, 1, 1, 1]
Y[]: [0, 1, 1, 0, 1, 0]

Output: 5
Explanation: The length of the longest continuous sequence with the same sum is 5 as

X[0, 4]: [0, 0, 1, 1, 1]	(sum = 3)
Y[0, 4]: [0, 1, 1, 0, 1]	(sum = 3)

*/

#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
	int findMaxSubarrayLength(vector<int> const &X, vector<int> const &Y)
	{
		int sum_x = 0;    // stores the sum upto the current index in array X
		int sum_y = 0;    // stores the sum upto the current index in array Y
		
		int diff;         // stores the difference between sum_x and sum_y at any current index
		int maximum = 0;  // stores the maximum length of the required subarray
	
		 
		  unordered_map<int, int> map;  // To store the diff and look for the repeating diff
		  map.insert({0, -1});        //To handle the condition when sum start from 0th index
		  
		for(int i=0; i<X.size(); i++){   //Loop through the array
			
			 sum_x += X[i];        //add the element at current index "i" in both arrays X and Y to sum_y and sum_x
			 sum_y += Y[i];
			 
			 diff = sum_x - sum_y;  // find the difference between sum_x and sum_y i.e. sum till the current index i
			 
			 if(map.find(diff) == map.end()){  // if the diff is not in the map, insert it. 
			 	
			 	  map.insert({diff, i});
			 	  
			 }else{                            // else store the max(maximum, i - map[diff]) in the "maximum" 
			 	
			 	 maximum = max(i - map[diff] , maximum);
			 }
		}
		
		return maximum;         // return the maximum
	}
};