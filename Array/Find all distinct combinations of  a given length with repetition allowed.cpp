/*

Given an integer array, find all distinct combinations of a given length `k`, where the repetition of elements is allowed.

Input : [1, 2, 3], k = 2
Output: {[1, 1], [1, 2], [1, 3], [2, 2], [2, 3], [3, 3]}

Input : [1, 1, 1], k = 2
Output: {[1, 1]}

Input : [1, 2], k = 0
Output: {[]}

Input : [], k = 1
Output: {}

The solution should consider only distinct combinations. For example, either [1, 1, 2] or [1, 2, 1] or [2, 1, 1] should be considered for the below input. Same goes for [1, 2, 2] or [2, 1, 2] or [2, 2, 1].

Input : [1, 2, 1], k = 3
Output: {[1, 1, 1], [1, 1, 2], [1, 2, 2], [2, 2, 2]}

*/

class Solution
{
public:
    void combo(set<vector<int>> &combinations, vector<int> &nums, vector<int> &ans, int k, int j){
    	
    	
    	if(ans.size() == k){
    		
    		combinations.insert(ans);
    		return;
    	}
    	
    	for(int i = j; i < nums.size(); i++){
    		
    		ans.push_back(nums[i]);
    		combo(combinations, nums, ans, k, i);
    		ans.pop_back();
    	}
    	
    	
    }
    
    
	set<vector<int>> findCombinations(vector<int> &nums, int k)
	{
		set<vector<int>> combinations;
          
         vector<int> ans; 
          
		combo(combinations, nums, ans, k, 0);
		
		return combinations;
	}
};