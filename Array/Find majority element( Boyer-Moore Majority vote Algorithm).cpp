/*

Given an integer array of size `n`, return the element which appears more than `n/2` times. Assume that the input always contain the majority element.

Input : [2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2]
Output: 2

Input : [1, 3, 1, 1]
Output: 1

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int findMajorityElement(vector<int> &nums)
	{
	   int m; // stores the majority elemet
	   int count = 0; // initialize count variable
	   
	   
	   // loop through the array
	   for(int i=0; i<nums.size(); i++){
	   	   
	   	   // If count equals to zero
	   	   if(count == 0){
	   	   	
	   	   	m = nums[i]; // store current element in m 
	   	   	
	   	   	count = 1; // and change count to 1;
	   	   	
	   	   }else{
	   	   	
	   	   	if(nums[i] == m){   // if curr element equals m, increment count, else                                   //    decrement count
	   	   		count++;
	   	   	}else{
	   	   		count--;
	   	   	}
	   	   }
	   }
	   
	   return m;   // return m
	}
};
