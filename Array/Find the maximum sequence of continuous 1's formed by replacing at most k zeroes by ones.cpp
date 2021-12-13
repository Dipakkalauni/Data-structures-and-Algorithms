#include<bits/stdc++.h>
using namespace std;

/*

Given a binary array and a positive integer `k`, return the indices of the maximum sequence of continuous 1’s that can be formed by replacing at most `k` zeroes by ones.

• The solution should return a pair of the starting and the ending index of the maximum sequence.
• For invalid inputs, the solution should return pair (-1, -1).
• In case multiple sequence of continuous 1’s of maximum length exists, the solution can return any one of them.

Input : nums[] = [1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0], k = 0
Output: (6, 9)
Explanation: The longest sequence of continuous 1’s is formed by index 6 to 9.

Input : nums[] = [1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0], k = 1
Output: (3, 9)
Explanation: The longest sequence of continuous 1’s is formed by index 3 to 9 on replacing zero at index 5.

Input : nums[] = [1, 1, 1, 1, 1], k = 1
Output: (0, 4)

Input : nums[] = [1, 0, 1, 1, 0, 0, 1, 1, 0, 1], k = 1
Output: (0, 3) or (6, 9)

Input : nums[] = [], k = 1
Output: (-1, -1)

*/

class Solution
{
public:
   
	pair<int,int> findLongestSequence(vector<int> const &nums, int k)
	{
		pair<int, int> ans; // stores the left and right index of the maximum sequence
	
		 
		 
		    int count = 0;  // stores the current count of 0's
		    
		    int len =0;     // Stores the maximum len of the sequence found so far
		    int left = 0;   // Stores the left index 
		   
		    
		   for(int right = 0; right < nums.size(); right++){   //Loop through the array
		    	 
		    	if(nums[right] == 0){                        // if the current index is zero
		    		count++;                                 // increase the count
		    	}
		    	
		        while(count > k){                            // if the count is greater than k
		        	                                         // increase the left index till count <= k.
		        	if(nums[left] == 0){
		        		count--;
		        	}
		        	
		        	left++;
		        }
		    	
		    	if(right - left + 1 > len){             // if the current length of the sequence is > len
		    		len = right - left + 1;             // set len = current length
		    		
		    		ans = {left, right};                 // insert the left and the right index into the pair
		    		
		    	}                                  
		    	
		    }
		    
		    if(len == 0){                               // if the maximum length of the sequence is zero
		    	return {-1, -1};                         // return {-1. -1}
		    }
		
		return ans;                                       // else return pair
	}
};