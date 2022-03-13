/*

Given an integer array having distinct elements, find the surpasser count for each element in it. In other words, for each array element, find the total number of elements to its right, which are greater than it.

Input : [4, 6, 3, 9, 7, 10]
Output: [4, 3, 3, 1, 1, 0]

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

 void merge(vector<int> &nums, vector<int> aux, int start, int mid, int end,    unordered_map<int, int> &m){
   	
   	  int i = start; int j = mid+1; int k = start;
   	   
   	   int count = 0;
   	  while(i <= mid && j <= end){
   	  	
   	  	 if(nums[i] > nums[j]){
   	  	 	
   	  	 	m[nums[i]] += count;
   	  	 	aux[k] = nums[i];
   	  	 	i++;
   	  	 }else{
   	  	 	
   	  	 	aux[k] = nums[j];
   	  	 	count++;
   	  	 	j++;
   	  	 }
   	  	 
   	  	 k++;
   	  }
   	  
   	  while(i <= mid){
   	  	aux[k] = nums[i];
   	  	m[nums[i]] += count;
   	  	i++;
   	  	k++;
   	  }
   	  
   	  while(j <= end){
   	  	aux[k] = nums[j];
   	  	j++;
   	  	k++;
   	  }
   	  
   	 
   	  
   	  for(int i=start; i<=end; i++){
   	  	nums[i] = aux[i];
   	  }
   }

    void mergesort(vector<int> &nums, vector<int> aux, int start, int end, unordered_map<int, int> &m){
    	
    	if(end <= start){
    		return;
    	}
    	
    	int mid = start + (end - start)/2;
    	
    	mergesort(nums, aux, start, mid, m);
    	
    	mergesort(nums, aux, mid+1, end, m);
    	
    	merge(nums, aux, start, mid, end, m);
    }
    
	vector<int> findSurpasserCount(vector<int> &nums)
	{
		int n = nums.size();
		
		unordered_map<int, int> m;
		vector<int> arr(nums);
		vector<int> aux(n);
		
		mergesort(arr, aux, 0, n-1, m);
		
		for(int i=0; i<n; i++){
			
			aux[i] = m[nums[i]];
		}
		
		return aux;
	}
};