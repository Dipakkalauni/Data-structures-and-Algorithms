/*

Given an `M × N` integer matrix, find all paths that start at the first cell (0, 0) and ends at the last cell (M-1, N-1). You are allowed to move down, right, or diagonally (down-right), but not up or left.

Input:
[
	[1, 2, 3],
	[4, 5, 6],
	[7, 8, 9]
]

Output:

{
	[1, 4, 7, 8, 9],
	[1, 4, 5, 8, 9],
	[1, 4, 5, 6, 9],
	[1, 4, 5, 9],
	[1, 4, 8, 9],
	[1, 2, 5, 8, 9],
	[1, 2, 5, 6, 9],
	[1, 2, 5, 9],
	[1, 2, 3, 6, 9],
	[1, 2, 6, 9],
	[1, 5, 8, 9],
	[1, 5, 6, 9],
	[1, 5, 9]
}

*/

class Solution
{
public:
    bool isValid(int i, int j, vector<vector<int>> const &mat){
    	
    	if(i >= 0 && j >= 0 && i < mat.size() && j < mat[0].size()){
    		return true;
    	}
    	
    	return false;
    }
    
    void findPaths(set<vector<int>> &result, vector<vector<int>> const &mat, vector<int> &res, int i, int j){
    	
    	int N = mat.size();
    	int M = mat[0].size();
    	
    	res.push_back(mat[i][j]);
    	
    	if(i == N-1 && j == M-1){
    	   result.insert(res);
    	}
    	
    	if(isValid(i, j+1, mat)){
    		findPaths(result, mat, res, i, j+1);
    	}
    	
    	if(isValid(i+1, j, mat)){
    		findPaths(result, mat, res, i+1, j);
    	}
    	
    	if(isValid(i+1, j+1, mat)){
    		findPaths(result, mat, res, i+1, j+1);
    	}
    	
    	res.pop_back();
    }

    
	set<vector<int>> findAllPaths(vector<vector<int>> const &mat)
	{
	   set<vector<int>> result;
	   
	   if(mat.size() == 0){
	   	 return result;
	   }
	   
	   vector<int> res;
	   
	   findPaths(result, mat, res, 0, 0);
	}
};
