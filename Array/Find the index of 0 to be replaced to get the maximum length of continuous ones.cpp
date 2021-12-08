#include<bits/stdc++.h>
using namespace std;

/*

Given a binary array, find the index of 0 to be replaced with 1 to get the maximum length sequence of continuous ones. The solution should return the index of first occurence of 0, when multiple continuous sequence of maximum length is possible.

Input : [0, 0, 1, 0, 1, 1, 1, 0, 1, 1]
Output: 7
Explanation: Replace index 7 to get the continuous sequence of length 6 containing all 1’s.

Input : [0, 1, 1, 0, 0]
Output: 0
Explanation: Replace index 0 or 3 to get the continuous sequence of length 3 containing all 1’s. The solution should return the first occurence.

Input : [1, 1]
Output: -1
Explanation: Invalid Input (all 1’s)

*/

class Solution
{
public:
	int findIndexofZero(vector<int> const &nums)
	{
		// storee index of previous zero
	   int last_zero = -1;
	   
	    // stores continuous length of 1 before last_zero
	   int prev_len = 0;
	   
	   // stores maximum continuous length of 1 so far
	    int maxi = 0;
	    
	    // stores index of 0 after replacing which with 1 , we get mmaximum continuous length of 1
	    int index = 0;
	    
	    // stores curr continuous lenght of 1 from last_zero
	    int curr = 0;
	    
	    //stores sum of (prev_len and curr + 1)
	    int sum = 0;
	    
	    //loop through the array to find required value of all the above variable
	    
	   for(int i=0; i<nums.size(); i++){
	   	
	   	  if(nums[i]==0){
	   	  	 if(last_zero == -1){
	   	  	 	last_zero = i;
	   	  	 	prev_len = i;
	   	  	 	index = i;
	   	  	 
	   	  	 }else{
	   	  	 	 curr = i - last_zero - 1;
	   	  	 	  sum = prev_len + curr + 1;
	   	  	 	  
	   	  	 	 if(sum > maxi){
	   	  	 	 	maxi = sum;
	   	  	 	 	index = last_zero;
	   	  	 	 }
	   	  	 	 
	   	  	 	 prev_len = curr;
	   	  	 	 last_zero = i;
	   	  	 	 
	   	  	 	 
	   	  	 }
	   	  }
	   	  
	   }
	   
	   	  curr = nums.size() - last_zero -1;
	   	  sum = prev_len + curr +1;
	   	  
	   	  if(sum > maxi){
	   	  	maxi = sum;
	   	  	index = last_zero;
	   	  }
	   
	   
	   return index;
	}
};
