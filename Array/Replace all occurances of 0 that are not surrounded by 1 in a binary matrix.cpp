/*

Given an `M × N` binary matrix, replace all occurrences of 0’s by 1’s, which are not completely surrounded by 1’s from all sides, i.e., top, left, bottom, right, top-left, top-right, bottom-left, and bottom-right.

Input:

[
	[1, 1, 1, 1, 0, 0, 1, 1, 0, 1],
	[1, 0, 0, 1, 1, 0, 1, 1, 1, 1],
	[1, 0, 0, 1, 1, 1, 1, 1, 1, 1],
	[1, 1, 1, 1, 0, 0, 1, 1, 0, 1],
	[1, 1, 1, 1, 0, 0, 0, 1, 0, 1],
	[1, 1, 0, 1, 1, 0, 1, 1, 0, 0],
	[1, 1, 0, 1, 1, 1, 1, 1, 1, 1],
	[1, 1, 0, 1, 1, 0, 0, 1, 0, 1],
	[1, 1, 1, 0, 1, 0, 1, 0, 0, 1],
	[1, 1, 1, 0, 1, 1, 1, 1, 1, 1]
]

Output:

[
	[1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
	[1, 0, 0, 1, 1, 1, 1, 1, 1, 1],
	[1, 0, 0, 1, 1, 1, 1, 1, 1, 1],
	[1, 1, 1, 1, 0, 0, 1, 1, 1, 1],
	[1, 1, 1, 1, 0, 0, 0, 1, 1, 1],
	[1, 1, 1, 1, 1, 0, 1, 1, 1, 1],
	[1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
	[1, 1, 1, 1, 1, 0, 0, 1, 0, 1],
	[1, 1, 1, 1, 1, 0, 1, 0, 0, 1],
	[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
]

*/

// these array show all possible eight movements
 int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
 int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};
 
class Solution
{
public:
     
     
     // check false if '(x, y)' is a vaild location
     bool isValid(int x, int y, int M, int N){
     	
     	 return (x >= 0 && x < M && y>=0 && y < N);
     }
     
    
    void dfs(vector<vector<int>> &mat, int i, int j){
    	
    	int M = mat.size();
    	int N = mat[0].size();
    	
    	mat[i][j] = 1; //repace the current cell by 1
    	
    	//recur for all valid location among eight possible movements
    	for(int k = 0; k < 8; k++){
    		
    		int x = i + row[k];
    		int y = j + col[k];
    		
    		if(isValid(x, y, M, N) && !mat[x][y]){
    			
    			dfs(mat, x, y);
    		}
    	}
    	
    	
    }
	void replaceZeros(vector<vector<int>> &mat)
	{
	   if(mat.size() == 0){  //base case
	   	return;
	   }
	   
	   int N = mat[0].size(); //
	   int M = mat.size();
	   
	   //check for every element on the first and last row
	   for(int i=0; i < mat[0].size(); i++){
	   	  
	   	  if(mat[0][i] == 0){
	   	  	
	   	  	  dfs(mat, 0, i);
	   	  }
	   	  
	   	  if(mat[M-1][i] == 0){
	   	  	
	   	  	 dfs(mat, M-1, i);
	   	  }
	   }
	   
	   //check for every element on the first and last column
	   for(int i=0; i<mat.size()-1; i++){
	   	
	   	   if(mat[i][0] == 0){
	   	   	
	   	   	  dfs(mat, i, 0);
	   	   }
	   	   
	   	   if(mat[i][N-1] == 0){
	   	   	
	   	   	  dfs(mat, i, N-1);
	   	   }
	   }
	   
	   
	}
};