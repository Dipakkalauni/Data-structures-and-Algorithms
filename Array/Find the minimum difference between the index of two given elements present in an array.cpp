#include<bits/stdc++.h>
using namespace std;

/*

Given an integer array `nums` and two integers `x` and `y` present in it, find the minimum absolute difference between indices of `x` and `y` in a single traversal of the array.

Input : nums[] = [1, 3, 5, 4, 8, 2, 4, 3, 6, 5], x = 3, y = 2
Output: 2
Explanation: Element 3 is present at index 1 and 7, and element 2 is present at index 5. Their minimum absolute difference is min(abs(1-5), abs(7-5)) = 2

Input : nums[] = [1, 3, 5, 4, 8, 2, 4, 3, 6, 5], x = 2, y = 5
Output: 3
Explanation: Element 2 is present at index 5, and element 5 is present at index 2 and 9. Their minimum absolute difference is min(abs(5-2), abs(5-9)) = 3

Input : nums[] = [], x = 0, y = 1
Output: 0

*/

class Solution
{
public:
	int findDifference(vector<int> const &nums, int x, int y)
	{
		 int n = nums.size();    //Stores the length of the array
	      
	      if(nums.size() <= 1){   // is size of the array <= 1, return
	      	return 0;
	      }
	      
		  int ind_x = -1;         // Stores the last occurance of x
		  int ind_y = -1;         //Stores the last occurance of y
		  int absolute = INT_MAX;   //Stores the minimum absolute difference value so far
		  
		 for(int i=0; i<n; i++){   // Loop through the array
		 	
		 	if(nums[i] == x && (ind_x == -1 || ind_y == -1)){ //if current index element is x and either ind_x = -1
		 		                                               // or ind_y = -1, update ind_x
		 		ind_x = i;                                    // if ind_y is not equal to -1, find absolute value
		 		
		 		if(ind_y != -1){
		 			
		 			absolute = abs(ind_x- ind_y);
		 		}
		 		
		 	}else if(nums[i] == y && (ind_y == -1 || ind_x == -1)){// if the current index element is y and either 
		 		                                                  // ind_x = -1 or ind_y = -1, update ind_y
		 		ind_y = i;                                        //if ind_x is not equal to -1, find absolute value
		 		
		 		if(ind_x != -1){
		 			
		 			absolute = abs(ind_x- ind_y);
		 		}
		 	}else if(nums[i] == x){       // again if the current index element is x, find the minimum absolute and 
		 		                            // and update ind_x;
		 		  
		 	      if(absolute > abs(i - ind_y)){   
		 	      	  absolute = abs(i - ind_y);
		 	      	  
		 	      }
		 	      
		 	      ind_x = i;
		 	      
		 	}else if(nums[i] == y){     // again if the current index element is x, find the minimum absolute and 
		 		                            // and update ind_y
		 		                            
		 	      if(absolute > abs(i - ind_x)){
		 	      	  absolute = abs(i - ind_x);
		 	      	  
		 	      }
		 	      
		 	      ind_y = i;
		 	}
		 }
		 
		 if(absolute == INT_MAX){   // if the absolute value is still INT_MAX, return 0, else return absolute
		 	return 0;
		 }
		 return absolute;
	}
};
