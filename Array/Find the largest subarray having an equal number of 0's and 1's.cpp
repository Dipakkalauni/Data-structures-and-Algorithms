/*

Given a binary array containing 0’s and 1’s, find the largest contiguous subarray with equal numbers of 0’s and 1’s.

Input : [0, 0, 1, 0, 1, 0, 0]
Output: [0, 1, 0, 1] or [1, 0, 1, 0]

Input : [0, 0, 0, 0]
Output: []

Note: Since an input can contain several largest subarrays with equal numbers of 0’s and 1’s, the code should return any one of them.

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
     
    
     
	vector<int> findLargestSubarray(vector<int> const &nums)
	{
		vector<int> largestSubarray;

	    int num_zero = 0;
	    int num_one = 0;
	    
	    // Count the number of 0's and 1's
	    
	    for(int i = 0; i < nums.size(); i++){
	    	if(nums[i] == 0){
	    		num_zero++;
	    	}else{
	    		num_one++;
	    	}
	    }
	      
	      // if count of 0's is greater the count of 1's, the max_size while be zero;
	       // else 1.
	       // if both are equal, then max_size = -1;
	       
	    int max_size = maximum(num_zero, num_one);
	      
	      // Now use two pointer approach to find the equal number of num_zero and num_one
	      
	    int i = 0;
	    int j = nums.size()-1;
	    
	     while(max_size != -1 && i<j){
	     	if(max_size == 0){
	     		if(nums[i]==0){
	     			i++;
	     			num_zero--;
	     		}else if(nums[j]==0){
	     			j--;
	     			num_zero--;
	     		}else{
	     			i++;
	     			num_one--;
	     		}
	     	}else if(max_size == 1){
	     		if(nums[i]==1){
	     			i++;
	     			num_one--;
	     		}else if(nums[j]==1){
	     			j--;
	     			num_one--;
	     		}else{
	     			i++;
	     			num_zero--;
	     		}
	     	}
	     	
	     	max_size = maximum(num_zero, num_one);
	     }
	     
	    
	     if(i<j){
	     	while(i <= j){
	     		largestSubarray.push_back(nums[i]);
	     		i++;
	     	}
	     }

		return largestSubarray;
	}
	
	// function to compare num_zero and num_one
	
	 int maximum(int num_zero, int num_one){
     	  if(num_zero < num_one){
     	  	return 1;
     	  }else if(num_zero > num_one){
     	  	return 0;
     	  }else{
     	  	return -1;
     	  }
     }
};
