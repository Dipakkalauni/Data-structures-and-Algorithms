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

    int partition(vector<int> &a, int start, int end){
    	
    	int pivot = a[start];
    	int i = start-1;
    	int j = end+1;
    	
    	while(1){
    		
    		do {
            i++;
        } while (a[i] < pivot);
 
        do {
            j--;
        } while (a[j] > pivot);
 
        if (i >= j) {
            return j;
        }
 
        swap(a[i], a[j]);
    	}
    }
    
    void quicksort(vector<int> &nums, int start, int end){
    	
    	if(start >= end){
    		return;
    	}
    	
    	int pivot = partition(nums, start, end);
    	
    	quicksort(nums, start, pivot);
    	
    	quicksort(nums, pivot+1, end);
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