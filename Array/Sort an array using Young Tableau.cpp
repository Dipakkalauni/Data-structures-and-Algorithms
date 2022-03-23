/*

Given an integer array, inplace sort it using Young tableau. You are given a utility class YoungTableau with the following public member functions:

1. vector<vector<int>> construct(vector<int> &nums): Construct and return an `N × N` Young tableau from the list `nums`. Note that `N` is determined dynamically by taking ceil of the square root of `nums` length.

2. int extractMin(vector<vector<int>> &tableau): Extract the next minimum element from the Young tableau `tableau`.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void fixTableau(vector<vector<int>> &ans, int i, int j){
    	
    	int N = ans.size();
    	
    	int bottom = (i+1 < N) ? ans[i+1][j] : INT_MAX;
    	int right = (j+1 < N) ? ans[i][j+1] : INT_MAX;
    	
    	if(bottom == INT_MAX && right == INT_MAX){
    		return;
    	}
    	
    	if(bottom < right){
    		
    		swap(ans[i][j], ans[i+1][j]);
    		fixTableau(ans, i+1, j);
    		
    	}else{
    		
    		swap(ans[i][j], ans[i][j+1]);
    		fixTableau(ans, i, j+1);
    	}
    }
    int extractMin(vector<vector<int>> &ans){
    	
    	int num = ans[0][0];
    	
    	 ans[0][0] = INT_MAX;
    	 
    	 fixTableau(ans, 0, 0);
    	 
    	 return num;

    }
    
    void insert(vector<vector<int>> &ans, int i, int j){
    	
    	if(i == 0 && j == 0){
    		return;
    	}
    	
    	if(i == 0){
    
    			if(ans[i][j] < ans[i][j-1]){
    				
    				swap(ans[i][j], ans[i][j-1]);
    				insert(ans, i, j-1);
    			}
    			return;
    		}
    	
    	
    	if(j == 0){
    		
    			if(ans[i][j] < ans[i-1][j]){
    				
    				swap(ans[i][j], ans[i-1][j]);
    				insert(ans, i-1, j);
    			}
    			return;
    		}
    	
    	  if(ans[i][j] < ans[i-1][j]){
    	  	
    	  	  swap(ans[i][j], ans[i-1][j]);
    	  	  insert(ans, i-1, j);
    	  }
    	  
    	  
    	  if(ans[i][j] < ans[i][j-1]){
    	  	
    	  	swap(ans[i][j], ans[i][j-1]);
    	  	insert(ans, i, j-1);
    	  }
    	
    }
    
    vector<vector<int>> construct(vector<int> &nums){
    	
    	int N = (int) ceil(sqrt(nums.size()));
    	
    	vector<vector<int>> ans(N, vector<int>(N, INT_MAX));
    	
    	for(int i=0; i<nums.size(); i++){
    		
    		if(ans[N-1][N-1] != INT_MAX){
    			break;
    		}
    		
    		ans[N-1][N-1] = nums[i];
    		insert(ans, N-1, N-1);
    	}
    	
    	return ans;
    }
    
	void sort(vector<int> &nums)
	{
		if(nums.size() == 0){
			return;
		}
		
		vector<vector<int>> ans = construct(nums);
		
		for(int i=0; i<nums.size(); i++){
			 nums[i] = extractMin(ans);
		}
	}
};