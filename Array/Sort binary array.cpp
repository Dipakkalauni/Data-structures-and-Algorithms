/*

Input : [1, 0, 1, 0, 1, 0, 0, 1]
Output: [0, 0, 0, 0, 1, 1, 1, 1]

Input : [1, 1]
Output: [1, 1]

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	void sortArray(vector<int> &nums)
	{
		
		int j = 0;
		
		// Loop through the array
		// if the curr element is 0, insert 0 in jth position and increase j.
		// In this way, we can simultaneously count zero and insert 0 at next available jth position
		
		for(int i = 0; i < nums.size(); i++){
			
			if(nums[i] == 0){
				
				nums[j] = 0;
                
				j++;
			}
		}
		
		// print 1 in all the remaining positions
		for(int i = j; i < nums.size(); i++){
			
			nums[i] = 1;
		}
	}
};
