/*

Given an integer array with many duplicated elements, efficiently sort it in linear time.

Input : [4, 2, 40, 10, 10, 1, 4, 2, 1, 10, 40]
Output: [1, 1, 2, 2, 4, 4, 10, 10, 10, 40, 40]

Constraints:

• The input elements lie in the range [0, 1000].
• The relative order of equal elements doesn't matter.

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Partition routine using the dutch national falg algorithm
    pair<int, int> partition(vector<int> &nums, int start, int end){
    	
    	int pivot = nums[end];
    	int mid = start;
    	
    	while(mid <= end){
    		
    		if(nums[mid] < pivot){
    			
    			swap(nums[start], nums[mid]);
    			start++;
    			mid++;
    		}else if(nums[mid] > pivot){
    			
    			swap(nums[end], nums[mid]);
    				end--;
    			
    		}else{
    			mid++;
    		}
    			
    		
    	}
    	
    	return make_pair(start-1, mid);
    	
    }
    
     // Quicksort logic to sort the array
    void quicksort(vector<int> &nums, int start, int end){
    	
    	if(start >= end){ //base case
    		return;
    	}
    	
    	if(start - end == 1){ // if array has only two elements, manually sort the array
    		
    		if(nums[start] > nums[end]){
    			swap(nums[start], nums[end]);
    		}
    		
    		return;
    	}
    	
    	//rearrange elements across pivot using dutch national flag algorithm
    	pair<int, int> p = partition(nums, start, end);
    	
    	//recurring on subarray containing elements less than the pivot
    	quicksort(nums, start, p.first);
    	
    	//recurring on subarray containing elments more than the pivot
    	quicksort(nums, p.second, end);
    	
    }
    
	void sort(vector<int> &nums)
	{
		int n = nums.size();   // stores the size of an array
		
		quicksort(nums, 0, n-1);  // sorts the array
	}
};
