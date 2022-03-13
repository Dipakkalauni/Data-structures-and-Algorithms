/*

Given an array of positive and negative integers, segregate them without changing the relative order of elements. The output should contain all positive numbers follow negative numbers while maintaining the same relative ordering.

Input : [9, -3, 5, -2, -8, -6, 1, 3]
Output: [-3, -2, -8, -6, 9, 5, 1, 3]

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums, vector<int> &aux, int start, int mid, int end){
    	
    	 int k = start;
    	 
    	 for(int i=start; i<=mid; i++){
    	 	if(nums[i] < 0){
    	 		aux[k] = nums[i];
    	 		k++;
    	 	}
    	 }
    	 
    	 for(int i=mid+1; i<=end; i++){
    	 	if(nums[i] < 0){
    	 		aux[k] = nums[i];
    	 		k++;
    	 	}
    	 }
    	 
    	 for(int i=start; i<=mid; i++){
    	 	if(nums[i] >= 0){
    	 		aux[k] = nums[i];
    	 		k++;
    	 	}
    	 	
    	 }
    	 
    	 for(int i=mid+1; i<=end; i++){
    	 	if(nums[i] >= 0){
    	 		aux[k] = nums[i];
    	 		k++;
    	 	}
    	 }
    	 
    	 for(int i=start; i<=end; i++){
    	 	
    	 	nums[i] = aux[i];
    	 }
    	
    }

    
    void mergesort(vector<int> &nums, vector<int> &aux, int start, int end){
    	
    	if(end <= start){
    		return;
    	}
    	
    	int mid = start + (end - start)/2;
    	
    	mergesort(nums, aux, start, mid);
    	mergesort(nums, aux, mid+1, end);
    	
    	merge(nums, aux, start, mid, end);
    }


	void rearrange(vector<int> &nums)
	{     
		int n = nums.size();
		
		vector<int> aux(n);
		mergesort(nums, aux, 0, n-1);
	}
};
