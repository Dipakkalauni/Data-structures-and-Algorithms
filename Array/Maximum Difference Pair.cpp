#include<bits/stdc++.h>
using namespace std;

  
  /*

Given an integer array, find the maximum difference between two elements in it such that the smaller element appears before the larger element. If no such pair exists, return any negative number.

Input : [2, 7, 9, 5, 1, 3, 5]
Output: 7
Explanation: The pair with the maximum difference is (2, 9).

Input : [5, 4, 3, 2, 1]
Output: -1 (or any other negative number)
Explanation: No pair with the maximum difference exists.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int findMaxDiff(vector<int> &nums)
	
	{
		
		
        int n = nums.size(); //Stores the size of the array
        
        int max_diff = INT_MIN; // stores the maximum difference between two elements
        
        if(n == 0){            // if n==0,  return max_diff
			return max_diff;
		}
		
		int mini = nums[0];  // stores the minimum element found so far
      	                     // and initialize it with first array element
      	
      	//Loop through the array
		for(int i = 1; i < n; i++){
			 
			 if(nums[i] <= mini){ // if the current element <= min
			 	                  // then min = current element
			 	mini = nums[i];
			 	
			 }else{       // else check if the difference between current element and                             // min is greater then the max_diff
			 	        
			    max_diff = max(max_diff, nums[i] - mini);
			 }
	
		}
		
		// return the max_diff
		return max_diff;
		
		
	}
};