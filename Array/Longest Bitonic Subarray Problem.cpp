/*

The Longest Bitonic Subarray (LBS) problem is to find a contiguous subarray of a given sequence in which the subarray’s elements are first sorted in increasing order, then in decreasing order, and the subarray is as long as possible.

Input : [3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4]
Output: [4, 5, 9, 10, 8, 5, 3]

In case the multiple bitonic subarrays of maximum length exists, the solution can return any one of them.

Input : [-5, -1, 0, 2, 1, 6, 5, 4, 2]
Output: [-5, -1, 0, 2, 1] or [1, 6, 5, 4, 2]

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
     
	vector<int> findBitonicSubarray(vector<int> const &nums)
	{
	    int j = 0; // Stores the last index of the longest bitonic subarray

	    vector<int> ans; // stores the longest bitonic subarray

	    int max_len = 0; // stores the maximum length of the bitonic subarray

	    int len = 0; // stores the current length of the subarray

	    int flag = 0; // stores the state of the bitonic subarray
                      // if flag is equal to zero, then we are iterating over the array for the first time
                      // if flag is equal to one, the subarray is in increasing order
                      // if flag is equal to two , the subarry is in decreasig order

	      
	      if(nums.size() == 1){ //if length of array is one, return the given array
	        return nums;
	      	 
	      }

          // loop throughtthe array
	    for(int i=0; i<nums.size(); i++){
	    	
	    	if(flag == 0 ){  // if we are iterating over the array for the first time

	    		//if current element is less than the next
                // the subarray is in increasing order, so set flag = 1, and increase the length
	    		if(i < nums.size()-1 && nums[i] < nums[i+1]){
	    			len++;
	    			flag = 1;
	    			
	    		}else if(i < nums.size()-1 && nums[i] > nums[i+1]){
                    // if the current element is greater than the next
                    // the subarray is in decreasing order, so set flag = 2 and increase the length
	    			len++;
	    			flag = 2;
	    			
	    		}else if(nums[i] == nums[i+1]){
	    		 	// if current element and next element are equal than set len = 1
                     // and check if the current length of subarray is greater than max_len.
                     
                     len =1;

	    		 	if(len > max_len){
	    		 	 	max_len = len;
	    		 	 	j = i;
	    		 	 }
	    		 	 
	    		 	 
	    		 }

	    	}else if(flag == 1 ){ // if the subarray is in increasing order
	    		 
	    		if(i < nums.size()-1 && nums[i] < nums[i+1]){
                // if the curr element is less than next element, increase the length
	    			len++;
	
	    			
	    		}else if(i < nums.size()-1 && nums[i] > nums[i+1]){
                // if the curr element is greater than next element, now subarray is in decreasing order
                // increase the length and set flag = 2
	    			len++;
	    			flag = 2;

	    		}else if(i == nums.size()-1){
	    		  // if the index the last index of the array
                  // increase the length because if flag == 1, it does no matter if the last ele is greater 
                  // than the previous element.
                  // Then compare the len and max_len
	    			len++;

	    			if(max_len < len){
	    				max_len = len;
	    				j = i;
	    			}
	    		}else if(nums[i] == nums[i+1]){
	    		 	// if current and next element are equal
                    // compare len and max_len
                    // and then set len = 1 because the subarray discontinues if elements are equal
	    		 	if(len > max_len){
	    		 	 	max_len = len;
	    		 	 	j = i;
	    		 	 }
	    		 	 
	    		 	 len = 1;
	    		 }

	    	}else if(flag == 2){ // if the subarray is in decreasing order
	    		
	    		 if(i < nums.size()-1 && nums[i] > nums[i+1]){
                     // if subarray is decreasing i.e. curr element > next element
                     // increase the length
	    		 	len++;
	    		 	
	    		 }else if(i < nums.size()-1 && nums[i] < nums[i+1]){
                     // if the current element < next element
                     // increase the length and compare the length and max length
                     // the set len = 1 and flag = 1, because now the suarray is in increasing state
	    		 	len++;
	    		 	
	    		 	 if(len > max_len){
	    		 	 	max_len = len;
	    		 	 	j = i;
	    		 	 }
	    		 	 
	    		 	 len = 1;
	    		 	 flag = 1;
	    		 }else if(i==nums.size()-1){
	    		 // if the current index is the last index of the array

	    		 	if(nums[i] != nums[i-1]){// if the last element is not equal to the previous element
                                             // increase the length and compare len and max_len
	    		 		len++;
	    		 	 
	    		 	 if(len > max_len){
	    		 	 	max_len = len;
	    		 	 	j = i;
	    		 	 }
	    		 	}else{         // else ignore the last element and just compare len and max_len
	    		 		
	    		 		if(len > max_len){
	    		 	 	max_len = len;
	    		 	 	j = i;
	    		 	 }
	    		 	}
	    		 	 
	    		 }else if(nums[i] == nums[i+1]){ // if curr and next element are equal, compare len and max_len
	    		 	                             // the set len = 1 because the subarray is discontinued and we have to start over
	    		 	if(len > max_len){
	    		 	 	max_len = len;
	    		 	 	j = i;
	    		 	 }
	    		 	 
	    		 	 len = 1;
	    		 }
	    	}
	    }
	    
	    for(int i = j-max_len+1; i<=j; i++){ // insert the max_subarray in the vector
                                             // and then return the vector
	    	ans.push_back(nums[i]);
	    	
	    }
	    
	    return ans;
	}
};
