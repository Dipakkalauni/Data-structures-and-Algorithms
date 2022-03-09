/*

Given an integer array, inplace sort it without using any inbuilt functions.

Input : [6, 3, 4, 8, 2, 9]
Output: [2, 3, 4, 6, 8, 9]

Input : [9, -3, 5, -2, -8, -6]
Output: [-8, -6, -3, -2, 5, 9]

*/

#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    //partition logic of quicksort to find pivot point
    // and sort elements less than pivot to the left side of the the pivot
    // and sort elements more than pivot to the right side of the pivot
    int partition(vector<int> &nums, int start, int end){  
    	
    	int pivot = nums[end];    //Pick the rightmost element as a pivot from the array
    	
    	int pIndex = start;
    	
    	//if the element <= pivot, swap the element with the element at pIndex and increase pIndex
    	for(int i=start; i < end; i++){
    		
    		if(nums[i] <= pivot){
    			
    			swap(nums[i], nums[pIndex]);
    			
    			pIndex++;
    		}
    	}
    	
    	swap(nums[pIndex], nums[end]);  //swap element at pIndex and end
    	
    	return pIndex;           //return pIndex
    }
   
     //Quicksort routine
    void quicksort(vector<int> &nums, int start, int end){
    	
    	if(start >= end){  //base condition
    		return;
    	}
    	
    	//rearrange elements across pivot
    	int pivot = partition(nums, start, end);
    	
    	//recurr subarrays that contains elements less than piovt and greater than pivot
    	quicksort(nums, start, pivot - 1);
    	quicksort(nums, pivot + 1, end);
    }
    
	void sort(vector<int> &nums)
	{
		int n = nums.size();    // stores the size of the array   
		
		if(n <= 1){         //if size of an array <= 1, return
			return;
		}
		
	    quicksort(nums, 0, n-1);  //calling the mergesort function
		
	}
};