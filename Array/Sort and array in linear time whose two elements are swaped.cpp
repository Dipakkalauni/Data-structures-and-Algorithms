/*

Given an integer array where all its elements are sorted in increasing order except two swapped elements, sort it in linear time. Assume there are no duplicates in the array.

Input : [3, 8, 6, 7, 5, 9] or [3, 5, 6, 9, 8, 7] or [3, 5, 7, 6, 8, 9]
Output: [3, 5, 6, 7, 8, 9]

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	void sortArray(vector<int> &nums)
	{
	   
	   int n = nums.size();  //Stores the length of the array
	   
	   if(n <= 1){      // if the length of the array is less than or equal to 1, return
	   	
	   	return;
	   	
	   }
	    int ind_1 = -1;   //used to store the index of the two swapped elements
	    int ind_2 = -1;
	    
	   
	   for(int i = 1; i < n; i++){ // loop through the array
	   	 
	   	  if(nums[i] < nums[i-1]){  // if the current element < previous element
	   	  
	   	  	                        // if this is the first disordered element
	     	if(ind_1 == -1){       // use ind_1 to point to previous element
	   	  		                   // and use ind_2 to point to current element
	   	  		ind_1 = i-1;
	   	        ind_2 = i;
	   	        
	   	  	}else{              // else use ind_2 to point to current element
	   	  		
	   	  		ind_2 = i;
	   	  	}
	   	  
	   	  }
	   }
	   
	   swap(nums[ind_2], nums[ind_1]);  // swap the elements pointed by ind_1 and ind_2
	}
};