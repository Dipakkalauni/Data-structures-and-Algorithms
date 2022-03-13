/*

Given two integer arrays, reorder elements of the first array by the order of elements defined by the second array.

The elements that are not present in the second array but present in the first array should be appended at the end in sorted order. The second array can contain some extra elements which are not part of the first array.

Input:

nums[] = [5, 8, 9, 3, 5, 7, 1, 3, 4, 9, 3, 5, 1, 8, 4]
 pos[] = [3, 5, 7, 2]

Output : [3, 3, 3, 5, 5, 5, 7, 1, 1, 4, 4, 8, 8, 9, 9]

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	void shuffle(vector<int> &nums, vector<int> &pos)
	{
		int n = nums.size();   //stores the size of the first array
		
		unordered_map<int, int> map; //map to store the elements and its frequency
		
		//store element and its frequency of occurance in map
		for(int i=0; i<n; i++){
			
			map[nums[i]]++;
		}
		
		
		int k = 0; //points to the starting index of first array
		//We overwrite the elements of first array based on order defined on second array
		for(int i=0; i<pos.size(); i++){
			
			while(map[pos[i]]--){
				nums[k] = pos[i];
				k++;
			}
			
			map.erase(pos[i]);
		}
		
		int i = k;
		//Now the remaining elements  present only on the first array is added to the end and then sorted
		for(auto ele: map){
			
			int val = ele.first;
			int freq = ele.second;
			
			while(freq--){
				nums[k] = val;
				k++;
			}
		}
		
		sort(nums.begin()+i, nums.begin()+k);
	}
};