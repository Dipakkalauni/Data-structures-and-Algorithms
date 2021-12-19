/*

Given an integer array, find the maximum product of its elements among all its subsets.

Input : [-6, 4, -5, 8, -10, 0, 8]
Output: 15360
Explanation: The subset with the maximum product of its elements is [-6, 4, 8, -10, 8]

Input : [4, -8, 0, 8]
Output: 32
Explanation: The subset with the maximum product of its elements is [4, 8]

Input : []
Output: 0

*/
#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
	int findMaxProduct(vector<int> const &nums)
	{
	  
	  if(nums.size() == 0){  // if the array length is 0, return 0.
	  	return 0;
	  }
	  
	  if(nums.size() == 1){  // if the array length is 1, return the element
	  	 
	  	 return nums[0];
	  }
	  
	  int product = 1;           // stores the maximum product of subset in the array
	  int neg_min = INT_MIN;     // stores the maximum negative number
	  int neg_len = 0;           // stores the number of negative elements
	  int pos_len = 0;           // stores the numberof positive elements
	  
	   for(int i=0; i<nums.size(); i++){  // loop through the array
	   	  
	   	  if(nums[i] > 0){                // if the current element is positive, than
	   	  	
	   	  	pos_len++;                    // increase the positive length and multiply product by current element
	   	  	product *= nums[i];
	   	  	
	   	  }else if(nums[i] < 0){        // else if the current element is negative, increase the neg_len
	   	  	    neg_len++;
	   	  	    
	   	  	 if(nums[i] > neg_min){    // and update the neg_min and multiply current element to the product
	   	  	 	neg_min = nums[i];
	   	  	 }
	   	  	 
	   	  	 product *= nums[i];   
	   	  }
	   }
	   
	   if(neg_len % 2 != 0){    // if neg_len is not even the remove the maximum negative number from product
	   	                         // by divinding the product by the neg_min
	   	   product = product/neg_min;
	   }
	   
	    if(neg_len==0 && pos_len == 0){  // handle the special cases and then return the product
	    	
	    	return 0;
	    }else if(pos_len == 0 && neg_len == 1){
	    	return 0;
	    }
	    
	    
	    return product;     
	}
};