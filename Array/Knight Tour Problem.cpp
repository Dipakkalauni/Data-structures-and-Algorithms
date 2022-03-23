/*

Given a chessboard, return all sequences of moves of a knight on a chessboard such that the knight visits every square only once. The solution should start the tour from the top-leftmost of the board, mark it as 1, and use the next numbers to represent the knight's consecutive moves.

Input: N = 5

Output:

{
	[[1, 18, 7, 12, 25], [8, 13, 2, 19, 6], [3, 20, 17, 24, 11], [14, 9, 22, 5, 16], [21, 4, 15, 10, 23]],
	[[1, 10, 21, 16, 7], [20, 15, 8, 11, 22], [9, 2, 23, 6, 17], [14, 19, 4, 25, 12], [3, 24, 13, 18, 5]],
	[[1, 18, 13, 8, 3], [12, 7, 2, 21, 14], [17, 22, 19, 4, 9], [6, 11, 24, 15, 20], [23, 16, 5, 10, 25]],
	[[1, 18, 13, 8, 21], [12, 7, 20, 3, 14], [19, 2, 17, 22, 9], [6, 11, 24, 15, 4], [25, 16, 5, 10, 23]]

	...and 300 more tours.
}

*/
int row[] = {2, 1, -1, -2, -2, -1, 1, 2, 2 };
int col[] = {1, 2, 2, 1, -1, -2, -2, -1, 1};

class Solution
{
public:
    bool isSafe(int n, int i, int j){
    	
    	if(i < 0 || j < 0 || i >= n || j >= n){
    		
    		return false;
    	}
    	
    	return true;
    }
    
    void KnightTour(set<vector<vector<int>>> &result, vector<vector<int>> &visited, int x, int y, int pos){
    
    int n = visited.size();
    // mark the current square as visited
    visited[x][y] = pos;
 
    // if all squares are visited, print the solution
    if (pos >= n*n)
    {
       result.insert(visited);
 
        // backtrack before returning
        visited[x][y] = 0;
        return;
    }
 
    // check for all eight possible movements for a knight
    // and recur for each valid movement
    for (int k = 0; k < 8; k++)
    {
        // get the new position of the knight from the current
        // position on the chessboard
        int newX = x + row[k];
        int newY = y + col[k];
 
        // if the new position is valid and not visited yet
        if (isSafe(n, newX, newY) && !visited[newX][newY]) {
            KnightTour(result, visited, newX, newY, pos + 1);
        }
    }
 
    // backtrack from the current square and remove it from the current path
    visited[x][y] = 0;
}
    	 
    
    
	set<vector<vector<int>>> _knightTour(int n)
	{
		set<vector<vector<int>>> result;
        
      
		vector<vector<int>> mat(n, vector<int>(n, 0));
		
		KnightTour(result, mat, 0, 0, 1);

		return result;
	}
};
