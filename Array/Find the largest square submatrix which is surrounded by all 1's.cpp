/*

Given a binary matrix, find size of the largest square submatrix, which is surrounded by all 1’s.

Input:
[
	[1, 1, 1, 1, 1, 1],
	[1, 0, 1, 1, 0, 1],
	[0, 1, 1, 0, 0, 1],
	[1, 1, 1, 1, 1, 1],
	[1, 0, 0, 1, 0, 1],
	[1, 0, 1, 1, 0, 0],
	[1, 0, 1, 0, 1, 1],
	[1, 1, 1, 0, 1, 1]
]

Output: 4

Explanation: The size of the largest square submatrix in the following binary matrix is 4. The largest square submatrix is formed by cells (0, 2), (3, 2), (0, 5), and (3, 5).

*/

class Solution
{
public:
	int findLargestSquareSubMatrix(vector<vector<int>> const &mat)
	{
		if(mat.size() == 0){ //base case
			return 0;
		}
		
		// size of "M * N" matrix
		int N = mat.size();     
		int M = mat[0].size();
		
		// auxiliary matrices of size M x N
		int X[N][M] = {};
		int Y[N][M] = {};
		
		//update matrix X and Y with total number of continuous 1's 
		// ending at the cell (i, j)
		for(int i=0; i<N; i++){
			
		   for(int j = 0; j<M; j++){
		   	
		   	    if(mat[i][j]){
		   	    	
		   	    	if(i == 0){
		   	    		
		   	    		Y[i][j] = 1;
		   	    	}else{
		   	    		
		   	    		Y[i][j] = Y[i-1][j] + 1;
		   	    	}
		   	    	
		   	    	if(j == 0){
		   	    		
		   	    		X[i][j] = 1;
		   	    	}else{
		   	    		
		   	    		X[i][j] = X[i][j-1] + 1;
		   	    	}
		   	    }
		   }
		}
		
		//used to store the largest square submatrix
		int max_length = 0;
		
		//traverse each cell of X and Y starting from the last cell
		for(int i = N-1; i >= 0; i--){
			
			for(int j = M-1; j >= 0; j--){
				
				// stores the minimum of X[i][j] and Y[i][j]
				//len will be the right vertical line and bottom horizontal
				// line of square matrix ending at cell i,j
				int len = min(X[i][j], Y[i][j]);
					
				 while(len){
				 	
				 	//the horizontal and vertical continuous 1's ending at 'i,j' 
				 	// forms square submatrix if there exists a left vertical line
				//and top horizontal line of continuous 1's of at least length len
			
			bool isSquare = Y[i][j - len +1] >= len && X[i - len + 1][j] >= len;
				 // check if square ending at current cell is largest
				 	if(isSquare && max_length < len){
				 		max_length = len;
				 	}
				 	//reduce the length by 1 to check for smaller squares ending 
				 	//at the current cell
				 	len--;
				 }
		
			}
		}
		
		return max_length;
	}
};
