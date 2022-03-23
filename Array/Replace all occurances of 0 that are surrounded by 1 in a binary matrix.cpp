/*

Given an `M × N` binary matrix, replace all occurrences of 0’s by 1’s, which are completely surrounded by 1’s from all sides (top, left, bottom, right, top-left, top-right, bottom-left, and bottom-right).

Input:

[
	[1, 1, 1, 1, 0, 0, 1, 1, 0, 1],
	[1, 0, 0, 1, 1, 0, 1, 1, 1, 1],
	[1, 0, 0, 1, 1, 1, 1, 1, 1, 1],
	[1, 1, 1, 1, 0, 0, 1, 1, 0, 1],
	[0, 0, 1, 1, 0, 0, 0, 1, 0, 1],
	[1, 0, 0, 1, 1, 0, 1, 1, 0, 0],
	[1, 1, 0, 1, 1, 1, 1, 1, 1, 1],
	[1, 1, 0, 1, 1, 0, 0, 1, 0, 1],
	[1, 1, 1, 0, 1, 0, 1, 0, 0, 1],
	[1, 1, 1, 0, 1, 1, 1, 1, 1, 1]
]

Output:

[
	[1, 1, 1, 1, 0, 0, 1, 1, 0, 1],
	[1, 1, 1, 1, 1, 0, 1, 1, 1, 1],
	[1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
	[1, 1, 1, 1, 1, 1, 1, 1, 0, 1],
	[0, 0, 1, 1, 1, 1, 1, 1, 0, 1],
	[1, 0, 0, 1, 1, 1, 1, 1, 0, 0],
	[1, 1, 0, 1, 1, 1, 1, 1, 1, 1],
	[1, 1, 0, 1, 1, 1, 1, 1, 1, 1],
	[1, 1, 1, 0, 1, 1, 1, 1, 1, 1],
	[1, 1, 1, 0, 1, 1, 1, 1, 1, 1]
]

*/

#include<bits/stdc++.h>
using namespace std;

 //these array shows all possible movements
  int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};
  
class Solution
{
public:
     //this function returns true if (x, y) and target is  valid   
    bool isSafe(vector<vector<int>> &mat, int x, int y, int target)
{
    int M = mat.size();
    int N = mat[0].size();
 
    return (x >= 0 && x < M && y >= 0 && y < N) &&
            mat[x][y] == target;
}    
        
    void dfs(vector<vector<int>> &mat, int x, int y, int replacement)
{
    int M = mat.size();
    int N = mat[0].size();
 
    // get the target value
    int target = mat[x][y];
 
    // replace current cell value with that of replacement
    mat[x][y] = replacement;
 
    // process all eight adjacent cells of the current cell and
    // recur for each valid cell
 
    for (int k = 0; k < 8; k++)
    {
        // if the adjacent cell at position `(x + row[k], y + col[k])` is
        // valid and has the same value as that of the current cell
 
        if (isSafe(mat, x + row[k], y + col[k], target)) {
            dfs(mat, x + row[k], y + col[k], replacement);
        }
    }
}
 
	void replaceZeros(vector<vector<int>> &mat)
	{
	   if(mat.size() == 0){ //base case
	   	 return;
	   }
	   
	   "M*N matrix"
	   int N = mat.size();
	   int M = mat[0].size();
	   
	   //traverse all cells in first and last row of matrix
	   for(int i=0; i<M; i++){
	   	  if(mat[0][i] == 0){
	   	  	  dfs(mat, 0, i, -1);
	   	  }
	   	  
	   	  if(mat[N-1][i] == 0){
	   	  	 dfs(mat, N-1, i, -1);
	   	  }
	   }
	   
	   
	   //traverse all cells in first and last column of matrix
	   for(int i=0; i < N; i++){
	   	  
	   	  if(mat[i][0] == 0){
	   	  	 dfs(mat, i, 0, -1);
	   	  }
	   	  
	   	 if(mat[i][M-1] == 0){
	   	 	 dfs(mat, i, M-1, -1);
	   	 } 
	   }
	   
	  //traverse the given matrix
	   for(int i=0; i<N; i++){
	   	
	    for(int j=0; j<M; j++){
	   		
	   		//replace every 0 with 1
	   		if(mat[i][j] == 0){
	   			
	   			mat[i][j] = 1;
	   			
	   		}
	   		//replace every -1 with 0
	   		if(mat[i][j] == -1){
	   			
	   			mat[i][j] = 0;
	   		}
	   		
	   	}
	   }
	}
};