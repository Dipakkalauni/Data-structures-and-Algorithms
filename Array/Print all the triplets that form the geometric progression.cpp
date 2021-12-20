#include<bits/stdc++.h>
using namespace std;


/*

Given a sorted array of distinct positive integers, return all triplets that forms a geometric progression with an integral common ratio. A geometric progression is a sequence of numbers where each term after the first is found by multiplying the previous one by a fixed, non-zero number called the common ratio.

Input : [1, 2, 6, 10, 18, 54]
Output: {[2, 6, 18], [6, 18, 54]}

Input : [2, 8, 10, 15, 16, 30, 32, 64]
Output: {[2, 8, 32], [8, 16, 32], [16, 32, 64]}

Input : [1, 2, 6, 18, 36, 54]
Output: {[2, 6, 18], [1, 6, 36], [6, 18, 54]}

Input : [1, 2, 4, 16]
Output: {[1, 2, 4], [1, 4, 16]}

Input : [1, 2, 3, 6, 18, 22]
Output: {[2, 6, 18]}

*/

class Solution
{
public:
	set<vector<int>> findTriplets(vector<int> const &nums)
	{
		set<vector<int>> triplets;  //stores all triplets that form arithmetic progression
         
         int n = nums.size();       //stores size of the array
         
	       for(int i=1; i<n-1; i++){    //traverse the array from second to second-last element
			                        //consider each element the middle element of arithmetic progression
		      int j = i-1;          //To find the remaining two element of progression, start from
		      int k = i+1;            // 'i-1'th and 'i+1'th element
		        
		      while(j >= 0 && k < n){ // and loop through left side and the right side of the ith element
		     
		    if(nums[j]*nums[k] == nums[i]*nums[i]){// check if jth and kth element's product == square                                                       // of ith   element
		          vector<int> v;                    
		          v.push_back(nums[j]);           // if this condition holds true, we found the 
		    	  v.push_back(nums[i]);          //remaining two elements and insert those into set
		    	  v.push_back(nums[k]);
		    	  
		         	triplets.insert(v);
		    	k++;
		    	j--;
		    }else if(nums[j]*nums[k] < nums[i]*nums[i]){
		   	          k++;                            // if jth and kth element's product < square of ith                                                      // element
		        	                                 // increase the kth element
		     }else{	
		    	
		        j--;                              // else decrease the jth element
		                                    
		    }	
		    
		 }
		    
		}

		return triplets;
	}
};