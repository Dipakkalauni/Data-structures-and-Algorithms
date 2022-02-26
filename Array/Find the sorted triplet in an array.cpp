#include<bits/stdc++.h>
using namespace std;

/*

Given an integer array `nums`, efficiently find a sorted triplet such that `nums[i] < nums[j] < nums[k]` where `i < j < k`.

Input : [7, 3, 4, 2, 6]
Output: (3, 4, 6)

• If the input contains several sorted triplets, the solution can return any one of them.

Input : [5, 4, 3, 7, 6, 1, 9]
Output: (5, 7, 9) or (4, 7, 9) or (3, 7, 9) or (5, 6, 9) or (4, 6, 9) or (3, 6, 9)

• If no triplet exists, return tuple (0, 0, 0).

Input : [5, 4, 3]
Output: (0, 0, 0)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	tuple<int, int, int> findSortedTriplet(vector<int> const &nums)
	{
	     int n = nums.size();     //stores the size of the array
	     int min_index = 0;       // stores the index of the minimum element
	     
	     tuple<int, int, int> tup;  //
		  
		  int low = -1;         // 
		  int mid = -1;         // 
		  
		  for(int i=1; i<n; i++){            //loop through the array from second element
		  	if(nums[i] <= nums[min_index]){   //if the curr_ele <= minimum element, 
		  	                                   // update the index of min_element
		  		min_index = i;
		  	}else if( mid == -1){            // if mid is not initialized,
		  		                             // initialize it to current index and low to min_index
		  		mid = i;
		  		low = min_index;
		  	}else if(nums[i] <= nums[mid]){  //if curr_ele <= mid element, update mid and low
		  		
		  		mid = i;
		  		low = min_index;
		  		
		  	}else{                //if the curr_ele > mid element, we have found our triplet
		  		                    // make a tuple and return it
		  		tup = make_tuple(nums[low], nums[mid], nums[i]);
		  		return tup;
		  	}
		  }
		  
		tup = make_tuple(0, 0, 0);  //if nothing is returned, return (0 0 0) tuple
		return tup;
		
	}
};