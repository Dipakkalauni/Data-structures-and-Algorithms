/*

Given a circular integer array, find a contiguous subarray with the largest sum in it.

Input : [2, 1, -5, 4, -3, 1, -3, 4, -1]
Output: 6
Explanation: Subarray with the largest sum is [4, -1, 2, 1] with sum 6.

Input : [8, -7, -3, 5, 6, -2, 3, -4, 2]
Output: 18
Explanation: Subarray with the largest sum is [5, 6, -2, 3, -4, 2, 8] with sum 18.

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kadane(vector<int> &nums, int n){
    	
		int max_sum = nums[0];   // Stores maximum sum of subarray found so far
		int curr_sum = nums[0];  // Stores maximum sum of subarray ending at current index
		
		for(int i=1; i<n; i++){
			
			curr_sum += nums[i];
			
			curr_sum = max(curr_sum, nums[i]);
			
			max_sum = max(max_sum, curr_sum);
		}
		
		return max_sum;
    }
    
	int findMaxSubarray(vector<int> &nums)
	{
		int n = nums.size(); // Stores the length of the array
		
		if(n==0){        // if length of the array is zero, the sum is also zero
			
			return 0;
		}
		
		 int positive_max = kadane(nums, n); // Store the maximum subarray sum of original array found so far
		 
		  if(positive_max < 0){  //if the maximum sum < 0, that means all the element are negative in the array
		  	                       // return the maximum negative number
		  	 return positive_max;
		  }
		  
		  int total = 0;           // Stores the total sum of the subarray 
		  
		for(int i=0; i<n; i++){    // Loop through the array and add the current
		    
		    total += nums[i];         // element to the total and then
	    	nums[i] = -nums[i];          //Change the sign of all the element in the array
		
		}
		
		 // Since we have negated the array, the maximum sum that will be returned by the 
		 // kadane function is actually the minimum sum of the sequence in the original array
		 // Therefore we negate the sign of the sum received
		 
	   int negative_max = -1 * kadane(nums, n);  //Stores the maximum subarray sum of negated array
		 
		 // To find the maximum circular subarray sum, subtract the minimum sum stored in "negative_max"
		 // from the total sum of the array stored in the "total"
		 
		 // return the maximum of the positive_max and total - negative_max; 
		 return max(positive_max, total - negative_max); 
		 
	}
};