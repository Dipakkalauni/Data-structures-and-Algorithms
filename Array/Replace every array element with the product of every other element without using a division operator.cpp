#include<bits/stdc++.h>
using namespace std;

 
 /*

Given an integer array, replace each element with the product of every other element without using the division operator.

Input : [1, 2, 3, 4, 5]
Output: [120, 60, 40, 30, 24]

Input : [5, 3, 4, 2, 6, 8]
Output: [1152, 1920, 1440, 2880, 960, 720]

*/

class Solution
{
public:
	void rearrange(vector<int> &nums)
	{  
		// stores size of an array
		int n = nums.size();
		
        // if n is equal to zero return
		if(n==0 ){
			return;
		}
      
      // declare left and right array to store
      // left subarray and right subarray product

	   vector<int> left(n);
	   vector<int> right(n);
	   
	    left[0] = 1; //initialize left with 1;
         // each index i stores left subarray product nums[0] * nums[1]*...* nums[i-1]
	  for(int i = 1; i < nums.size(); i++){
	  	 left[i] = left[i-1] * nums[i-1];
	  }
	  
	   right[n-1] = 1; 
       // each index i stores  right subarray product nums[i+1]*nums[i+2]*...*nums[n-1]
	  for(int i = n-2; i >= 0; i--){
	  	right[i] = right[i+1] * nums[i+1];
	  }
	  

	   for(int i=0; i<n; i++){
           // repalce every element with right subarray and left subarray product
	   	 nums[i] = left[i]*right[i];
	   }
	}
};



/*    Alternative Solution using recursion       */

 class Solution
{
	
public:

     int product(vector<int> &nums, int i, int left, int n){
    	
    	if(i == n){	  // if current index 'i' is equal to n return 1;
    	   return 1;	   
    	}
    	
    	  int curr = nums[i];    // stores the element at curent index
    	  

          // returns the product of right subarray 
    	  int right = product(nums, i+1, left * nums[i], n); 
    	  
    	   nums[i] = left*right; //replace the current index with the product
                                 // right and left subarray
    	   
    	   return curr*right; // return the product of right subarray and curr element
   	}
   	
	void rearrange(vector<int> &nums)
	{  
		int n = nums.size();
	   
	   product(nums, 0, 1, n);
	}
};