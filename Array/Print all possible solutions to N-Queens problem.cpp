/*

The N–queens puzzle is the problem of placing `N` chess queens on an `N × N` chessboard so that no two queens threaten each other. Thus, the solution requires that no two queens share the same row, column, or diagonal.

The solution should return a Set of each possible solution to the N–Queens problem.

Input: N = 4
Output:
{
	[[0, 0, 1, 0], [1, 0, 0, 0], [0, 0, 0, 1], [0, 1, 0, 0]],
	[[0, 1, 0, 0], [0, 0, 0, 1], [1, 0, 0, 0], [0, 0, 1, 0]]
}

Here 1 represents the position of a queen in chessboard. Note that the solution exists for all natural numbers, except for 2 and 3. The solution should return an empty set for N = 2 and N = 3.

Input: N = 2
Output: {}

*/

class Solution
{
public:
    // function to check if current position is safe or not
    bool isSafe(vector<vector<int>> &mat, int i, int j){
    	
    	 for(int k = i; k >= 0; k--){ //return false if there is a queen in current column
    	 	
    	 	if(mat[k][j] == 1){
    	 		return false;
    	 	}
    	 }
    	 
    	 //Also check for the two diagonal, on left and right side each
    	 for(int k = i, l = j; k >= 0 && l >= 0; k--, l--){
    	 	
    	 	if(mat[k][l] == 1){
    	 		return false;
    	 	}
    	 	
    	 }
    	 
    	 for(int k = i, l = j; k >= 0 && l < mat.size(); k--, l++){
    	 	
    	 	if(mat[k][l] == 1){
    	 		
    	 		return false;
    	 	}
    	 }
    	 
    	 return true;
    }
    void NQueen(set<vector<vector<int>>> &result, vector<vector<int>> &mat, int n, int r){
    	
    	 if(n == r){   //if all n queens are placed successfully
    	 	
    	 	result.insert(mat);  //insert the current configuration of all queens in set
    	 	return;
    	 }
    	 
    	 for(int i=0; i<n; i++){ //place queen at each position in current row and recur for valid movements
    	 	
    	 	if(isSafe(mat, r, i)){  //if current position is safe
    	 		
    	 		mat[r][i] = 1; //place queen at current position
    	 		
    	 		NQueen(result, mat, n, r+1); //recur for the next row
    	 		
    	 		mat[r][i] = 0;  // backtrack
    	 	}
    	 	
    	 
    	 	
    	 }
    }
	set<vector<vector<int>>> solveNQueen(int n)
	{
		set<vector<vector<int>>> result; //stores all the possible solutions
          
          
	   vector<vector<int>> mat(n, vector<int>(n, 0)); //keeps track of position of the queens 
		                                              // in current configuration
		  NQueen(result, mat, n, 0);

		return result;
	}
};