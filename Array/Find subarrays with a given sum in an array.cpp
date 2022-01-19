/*

Given an integer array, find all contiguous subarrays with a given sum `k`.

Input : nums[] = [3, 4, -7, 1, 3, 3, 1, -4], k = 7
Output: {[3, 4], [3, 4, -7, 1, 3, 3], [1, 3, 3], [3, 3, 1]}

Since the input can have multiple subarrays with sum `k`, the solution should return a set containing all the distinct subarrays.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	set<vector<int>> getAllSubarrays(vector<int> const &nums, int k)
	{
		set<vector<int>> subarrays;  //set of vectors to store all the subarrays having sum k;
        
        int sum_so_far = 0;        //stores the sum up to current index
        int n = nums.size();       //total size of the array
        
        unordered_map<int, vector<int>> map;   //map to store the sum_so_far and ending index of all subarrays whose
                                               // sum = sum_so_far;
          map[0].push_back(-1);                //to handle the case when subarray start from the start of the array                   
        for(int i=0; i<n; i++){             //traverse through the array
         
         sum_so_far += nums[i];            //add current element to sum_so_far
         
         auto itr = map.find(sum_so_far - k);//check if there exist a subarray with given sum k
         
         if(itr != map.end()){      // if yes, insert all the subarrays having the sum k and ending at index i
         	                        // int the set
         	for(int ele : map[itr->first]){
         		
         		vector<int> temp;
         		
         		for(int j = ele + 1; j <= i; j++){
         			
         			temp.push_back(nums[j]);
         		}
         		
         		subarrays.insert(temp);
         	}
         	
         }
         
         map[sum_so_far].push_back(i); //insert the  pair of sum_so_far and current index into the map
        	
        }
        
		return subarrays;          //return the set of the subarray having sum k
	}
};