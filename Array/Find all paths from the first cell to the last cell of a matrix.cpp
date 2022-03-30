/*

Given an `M × N` integer matrix, find all paths from the first cell to the last cell. You are only allowed to move down or to the right from the current cell.

Input:

[
	[1, 2, 3],
	[4, 5, 6],
	[7, 8, 9]
]

Output:

{
	[1, 2, 3, 6, 9],
	[1, 2, 5, 6, 9],
	[1, 2, 5, 8, 9],
	[1, 4, 5, 6, 9],
	[1, 4, 5, 8, 9],
	[1, 4, 7, 8, 9]
}

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
      //function return true if current cell is valid
     bool isValid(int i, int j, vector<vector<int>> const &mat){
     	
     	if(i >= 0 && i < mat.size() && j >= 0 && j < mat[0].size()){
     		
     		return true;
     	}
     	
     	return false;
     }
    
    void allPaths(set<vector<int>> &result, vector<vector<int>> const &mat, vector<int> &res, int i, int j){
    	
    	
    	int M = mat[0].size();
    	int N = mat.size();
    	
    	res.push_back(mat[i][j]);  //store the current cell into res
    	
    	if(i == N-1 && j == M-1){  //if the last cell is reached insert the path into result
    
    		result.insert(res);
    		
    	}
    	
    	
    	if(isValid(i, j+1, mat)){ //move right
    		allPaths(result, mat, res, i, j+1);
    	}
    	
    	if(isValid(i+1, j, mat)){ // move down
    		allPaths(result, mat, res, i+1, j);
    	}
    	
    	
    	res.pop_back();  //backtrack
    	
    }
	set<vector<int>> findAllPaths(vector<vector<int>> const &mat)
	{
	
		set<vector<int>> result;  //used to store all paths
		
		if(mat.size() == 0){  //if mat is empty
		
			return result;
		}
		
		vector<int> res;  //used to store unique path
		 
		allPaths(result, mat, res, 0, 0); 
		
		return result;
	}
};
