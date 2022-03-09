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
       //function to merge two sorted subarrays using auxiliary array
    void merge(vector<int> &nums, vector<int> aux, int low, int mid, int high){
    	
    	int i=low;   //points to start of left subarray
    	int k = low;  // points to the start of auxiliary array
    	int j = mid+1;  //points to the start of right subarray
    	
    	while(i <= mid && j <= high){ //traverse while either of left or right subarray is traversed
    		
    		if(nums[i] < nums[j]){  //if ith element of first subarray < jth element of second subarray
    			aux[k] = nums[i];   // store ith element at kth position of auxiliary array
    			i++;                 // increase t
    		}else{             
    			aux[k] = nums[j];  //else, store jth element at kth position of auxiliary array
    			j++;                // increase j
    		} 
    		
    		k++;     //increase k
    	}
    	
    	while(i <= mid){      // if any of the subarray is not completely traversed, do it
    		aux[k] = nums[i];
    		i++;
    		k++;
    	}
    	
    	while(j <= high){
    		aux[k] = nums[j];
    		j++;
    		k++;
    	}
    	
    	for(int i=low; i<=high; i++){  //copy the auxiliary subarray into nums
    		
    		nums[i] = aux[i];
    	}
    }
    
    void mergesort(vector<int> &nums, vector<int> aux, int n){ //mergesort function
        
         for (int m = 1; m <= n-1; m = 2*m)
    {
       
        for (int i = 0; i < n-1; i += 2*m)
        {
            int from = i;
            int mid = min(i + m - 1, n-1);
            int to = min(i + 2*m - 1, n-1);
 
            merge(nums, aux, from, mid, to);
        }
        
    }
    	
    }
    
	void sort(vector<int> &nums)
	{
		int n = nums.size();    // stores the size of the array   
		
		if(n <= 1){         //if size of an array <= 1, return
			return;
		}
		
		vector<int> aux(n);    //auxiliary array 
	    mergesort(nums, aux, n);  //calling the mergesort function
		
	}
};