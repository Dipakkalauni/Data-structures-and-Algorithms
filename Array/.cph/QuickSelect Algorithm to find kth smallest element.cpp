
/*

Given an integer array, find k'th smallest element in the array where k is a positive integer less than or equal to the length of array.

Input : [7, 4, 6, 3, 9, 1], k = 3
Output: 4
Explanation: The 3rd smallest array element is 4

Input : [1, 5, 2, 2, 2, 5, 5, 4], k = 5
Output: 4
Explanation: The 5th smallest array element is 4

*/
#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
       // Partition Algorithm
    int partition(vector<int> &nums, int left, int right, int pIndex){
        
        int pivot = nums[pIndex];   //choose pIndex as a pivot point
        
        swap(nums[pIndex], nums[right]);  // swap pivot with the rightmost element of given subarray
        
        pIndex = left;                   // shift pIndex to point leftmost element of given subarray
        
        for(int i=left; i < right; i++){  // loop from left to right
        	
        	if(nums[i] <= pivot){            // if current element <= pivot
        		                             // swap current element and elemen at pIndex
        		swap(nums[i], nums[pIndex]);  //increase pIndex;
        		pIndex++;
        	}
        }
        
        swap(nums[pIndex], nums[right]);   // put pivot in its rightful place 
        
        return pIndex;                 // and return pIndex
    }
    
    int quickSelect(vector<int> &nums, int left, int right, int k){
    	
      if(left == right){     // if left == right, return nums[left]
      	
      	return nums[left];
      }
      
      int pIndex = left + rand() % (right - left + 1); //choose a random pIndex between right and left
      
      pIndex = partition(nums, left, right, pIndex); //find the real position of pIndex element 
                                                     // using partition Algorithm 
      if(k == pIndex){             //if pIndex and k are equal
      	return nums[k];           // return nums[k]
      }
      
      if(k < pIndex){        // if k < pIndex, repeat the quickSelect Algorithm for element from left to 
      	                        // pIndex-1
      	 return quickSelect(nums, left, pIndex-1, k);
      	 
      }else{          // if k > pIndex, repeat the quickSelect Algorithm for element from pIndex+1 to                            //right
      	return quickSelect(nums, pIndex+1, right, k);
      }
    }

    // Starting function
	int findKthSmallest(vector<int> &nums, int k)
	{
		return quickSelect(nums, 0, nums.size()-1, k-1);
	}
};