#include<bits/stdc++.h>
using namespace std;

/*

Given an unsorted integer array containing many duplicate elements, rearrange it such that the same element appears together and the relative order of the first occurrence of each element remains unchanged.

Input : [1, 2, 3, 1, 2, 1]
Output: [1, 1, 1, 2, 2, 3]

Input : [5, 4, 5, 5, 3, 1, 2, 2, 4]
Output: [5, 5, 5, 4, 4, 3, 1, 2, 2]

Input : [7, 0, 4, 2, 5, 0, 6, 4, 0, 5]
Output: [7, 0, 0, 0, 4, 4, 2, 5, 5, 6]

*/

class Solution
{
public:
	vector<int> sortArray(vector<int> const &nums)
	{
		unordered_map<int, int> m;       //map to store the elements and their frequency of occurance
		int n = nums.size();              //size of thevector
		vector<int> ans(n);                //stores the resulting vector
		
		for(int i=0; i<n; i++){         //loop through the array, count the frequency of elements and 
			                             // store that in map
				m[nums[i]]++; 
			
		}
		
		 int j = 0;                  //points to the starting index of the resulting vector
		for(int i=0; i<n; i++){    //loop through the array again
			
			if(m.find(nums[i]) != m.end()){ // if the current element is in the array
				                            // store the frequency of its occurance in k
				int k = m[nums[i]];        
				while(k--){                 // insert the current element in the resulting vector
					                         // k times
					ans[j] = nums[i];
					j++;
				}
				
				m.erase(nums[i]);           // delete the current element from the map
			}
		}
		
		return ans;                          // return thr resulting ans;
	}
};

