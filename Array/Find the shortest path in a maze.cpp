/*

Given a maze in the form of a binary rectangular matrix, find the length of the shortest path from a given source to a given destination. The path can only be constructed out of cells having value 1, and at any moment, you can only move one step in one of the four directions (Top, Left, Down, Right).

Input:

matrix = [
	[1, 1, 1, 1, 1, 0, 0, 1, 1, 1],
	[0, 0, 1, 0, 1, 1, 0, 1, 0, 1],
	[0, 0, 1, 0, 1, 1, 1, 0, 0, 1],
	[1, 0, 1, 1, 1, 0, 1, 1, 0, 1],
	[0, 0, 0, 1, 0, 0, 0, 1, 0, 1],
	[1, 0, 1, 1, 1, 0, 0, 1, 1, 0],
	[0, 0, 0, 0, 1, 0, 0, 1, 0, 1],
	[0, 1, 1, 1, 1, 1, 1, 1, 0, 0],
	[1, 1, 1, 1, 1, 0, 0, 1, 1, 1],
	[0, 0, 1, 0, 0, 1, 1, 0, 0, 1]
]
src  = (0, 0)
dest = (5, 7)

Output: 12

Explanation: The shortest path from (0, 0) to (5, 7) has length 12. The shortest path is marked below with x.

[
	[x, x, x, x, x, 0, 0, 1, 1, 1],
	[0, 0, 1, 0, x, 1, 0, 1, 0, 1],
	[0, 0, 1, 0, x, x, x, 0, 0, 1],
	[1, 0, 1, 1, 1, 0, x, x, 0, 1],
	[0, 0, 0, 1, 0, 0, 0, x, 0, 1],
	[1, 0, 1, 1, 1, 0, 0, x, 1, 0],
	[0, 0, 0, 0, 1, 0, 0, 1, 0, 1],
	[0, 1, 1, 1, 1, 1, 1, 1, 0, 0],
	[1, 1, 1, 1, 1, 0, 0, 1, 1, 1],
	[0, 0, 1, 0, 0, 1, 1, 0, 0, 1]
]

Note: The solution should return -1 if no path is possible.

*/

int row[] = {1, 0, -1, 0};
int col[] = {0, 1, 0, -1};

class Solution
{
public:
      // function to find if the current cell is valid to recur
    bool isValid(vector<vector<int>> const &mat, vector<vector<int>> &visited, int x, int y){
    
    	
    	if(x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size() && mat[x][y] == 1 && visited[x][y] == -1){
    		
    		return true;
    	}
    	
    	return false;
    }
    
    void shortestPath(vector<vector<int>> const &mat, vector<vector<int>> &visited, int i, int j, int x, int y, int &min_dist, int dist){
    	
    	if(i == x && j == y){ //if dest if found, update min_dist and return
    		
    	  min_dist = min(dist, min_dist);
    		
    		return;
    	}
    	
    	visited[i][j] = 0;  //current cell (i, j) is visited
    	
    	for(int k = 0; k < 4; k++){ //recur for all vaild cell that can be visited for current cell
    		
    		int a = i + row[k];
    		int b = j + col[k];
    		
    		if(isValid(mat, visited, a, b)){
    			
    			shortestPath(mat, visited, a, b, x, y, min_dist, dist+1);
    		}
    	}
    	
    	//backtrack
    	visited[i][j] = -1;
    	
    }
    
	int findShortestPath(vector<vector<int>> const &mat, pair<int,int> const &src, pair<int,int> const &dest)
	{
		// invalid input
		if(mat[dest.first][dest.second] == 0 || mat[src.first][src.second] == 0 || mat.size() == 0){
    	
    		return -1;
    	}
    	
		int min_dist = INT_MAX; //stores the minimum distance from source to destination
		
	   //size of (M x N) matrix
		int N = mat.size();
		int M = mat[0].size();
		
		vector<vector<int>> visited(N, vector<int>(M, -1)); //keeps track of visited cell
		
		shortestPath(mat, visited, src.first, src.second, dest.first, dest.second, min_dist, 0);
		
	   
	   	 if(min_dist !=  INT_MAX){
	
	   	 return min_dist;
	   	 }
	   	 
	   return -1;
	  
	}
};
