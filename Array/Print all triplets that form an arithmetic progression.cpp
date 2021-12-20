/*

Given a sorted array of distinct positive integers, return all triplets that forms an arithmetic progression with an integral common difference. An arithmetic progression is a sequence of numbers such that the difference between the consecutive terms is constant.

Input : [5, 8, 9, 11, 12, 15]
Output: {[5, 8, 11], [9, 12, 15]}

Input : [1, 3, 5, 6, 8, 9, 15]
Output: {[1, 3, 5], [1, 5, 9], [3, 6, 9], [1, 8, 15], [3, 9, 15]}

*/
#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
	set<vector<int>> findTriplets(vector<int> const &nums)
	{
		set<vector<int>> triplets;  //stores all triplets that form arithmetic progression
         int n = nums.size();       //stores size of the array
         
		for(int i=1; i<n-1; i++){  //traverse the array from second to second-last element
			                       //consider each element the middle element of arithmetic progression
		    int j = i-1;    //To find the remaining two element of progression, start from
		    int k = i+1;    // 'i-1'th and 'i+1'th element
		                     // and loop through left side and the right side of the ith element
		    while(j >=0 && k < n){ 
		    	                               // check if jth and kth element's sum == 2*ith element
		    if((nums[j]+nums[k]) == 2*nums[i]){  // if this condition holds true, we found the 
		    	                                 //remaining two elements and insert those into set
		    	vector<int> v;                   
		    	v.push_back(nums[j]);
		    	v.push_back(nums[i]);
		    	v.push_back(nums[k]);
		    	triplets.insert(v);
		    	j--;
		    	k++;
		    	
		    }else if(nums[j] + nums[k] < 2*nums[i]){
		    	                // if jth and kth element's sum < 2*ith element
		    	k++;            // increase the kth element
		    	
		    }else{             // else decrease the jth element
		    	
		    	j--;
		    	
		    }
		}
		    
		    
		}

		return triplets;
	}
};