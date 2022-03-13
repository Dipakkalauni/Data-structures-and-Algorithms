/*

Given an integer array, find the total number of inversions of it. If `(i < j)` and `(nums[i] > nums[j])`, then pair `(i, j)` is called an inversion of an array `nums`. The solution should provide count of all such pairs in the array.

Input : [1, 9, 6, 4, 5]
Output: 5
Explanation: There are 5 inversions in the array: (9, 6), (9, 4), (9, 5), (6, 4), (6, 5)

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    
    int Merge(vector<int> &nums, vector<int> &aux, int start, int mid, int end){
    	
    	int i = start;
    	int j = mid+1;
    	int k = start;
    	int inversion = 0;
    	
    	while(i <= mid && j <= end){
    		
    		if(nums[i] <= nums[j]){
    			
    			aux[k] = nums[i];
    			i++;
    			
    		}else{
    			
    			aux[k] = nums[j];
    			inversion += mid - i + 1;
    			j++;
    		}
    		
    		k++;
    	}
    	
    	while(i <= mid){
    		aux[k] = nums[i];
    		i++;
    		k++;
    	}
    	
    	while(j <= end){
    		aux[k] = nums[j];
    		j++;
    		k++;
    	}
    	
    	for(int i = start; i <= end; i++){
    		
    		nums[i] = aux[i];
    	}
    	
    	return inversion;
    }

    int mergesort(vector<int> &nums, vector<int>& aux, int start, int end){
    	
    	if(start >= end){
    		return 0;
    	}
    	
    	int mid = start + (end - start)/2;
    	int inversion = 0;
    	
    	inversion += mergesort(nums, aux, start, mid);
    	
    	inversion += mergesort(nums, aux, mid+1, end);
    	
    	inversion += Merge(nums, aux, start, mid, end);
    	
    	return inversion;
    }
    
	int findInversionCount(vector<int> &nums)
	{
		int n = nums.size();
		
		vector<int> aux(n);
		
	    return mergesort(nums, aux, 0, n-1);
	}
};