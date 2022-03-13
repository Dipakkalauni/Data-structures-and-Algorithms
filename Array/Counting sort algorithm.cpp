/*

Given a collection of `n` items, each of which has a non-negative integer key whose maximum value is at most `k`, effectively sort it using the counting sort algorithm.

Input : nums[] = [4, 2, 10, 10, 1, 4, 2, 1, 10], k = 10
Output: [1, 1, 2, 2, 4, 4, 10, 10, 10]

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
  
    	
	void sort(vector<int> &nums, int k)
	{
		int n = nums.size();    //size of the array
		
		vector<int> hash(k+1, 0);  // hash_table to store the fequency of elements in an array
		
		for(int i=0; i<n; i++){    // traverse the array and store the frequency occurance of elements in hash
			
			hash[nums[i]]++;
		}
		
			int index = 0;
       //traverse the hash and overwrite the nums in sorted order
		for(int i=0; i<k+1; i++){
			
			while(hash[i]){
				
				nums[index] = i;
				index++;
				hash[i]--;
			}
		}
		
		
	}
};