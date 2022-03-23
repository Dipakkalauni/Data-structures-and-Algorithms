/*

Given a rectangular path in the form of a binary matrix, find the length of the longest possible route from source to destination by moving to only non-zero adjacent positions, i.e., A route can be formed from positions having their value as 1. Note there should not be any cycles in the output path.

Input:

matrix = [
	[1, 0, 1, 1, 1, 1, 0, 1, 1, 1],
	[1, 0, 1, 0, 1, 1, 1, 0, 1, 1],
	[1, 1, 1, 0, 1, 1, 0, 1, 0, 1],
	[0, 0, 0, 0, 1, 0, 0, 1, 0, 0],
	[1, 0, 0, 0, 1, 1, 1, 1, 1, 1],
	[1, 1, 1, 1, 1, 1, 1, 1, 1, 0],
	[1, 0, 0, 0, 1, 0, 0, 1, 0, 1],
	[1, 0, 1, 1, 1, 1, 0, 0, 1, 1],
	[1, 1, 0, 0, 1, 0, 0, 0, 0, 1],
	[1, 0, 1, 1, 1, 1, 0, 1, 0, 0]
]
src  = (0, 0)
dest = (5, 7)

Output: 22

Explanation: The longest path is:

(0, 0) —> (1, 0) —> (2, 0) —> (2, 1) —> (2, 2) —> (1, 2) —> (0, 2) —> (0, 3) —> (0, 4) —> (1, 4) —> (1, 5) —> (2, 5) —> (2, 4) —> (3, 4) —> (4, 4) —> (5, 4) —> (5, 5) —> (5, 6) —> (4, 6) —> (4, 7) —> (4, 8) —> (5, 8) —> (5, 7)

Note: The solution should return 0 if no path is possible.

*/
int row[] = {1, 0, -1, 0};
int col[] = {0, 1, 0, -1};

class Solution
{
public:
    bool isValid(vector<vector<int>> const &mat, vector<vector<int>> &visited, int x, int y){
    	
    	if(x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size() && mat[x][y] == 1 && visited[x][y] == -1){
    		
    		return true;
    	}
    	
    	return false;
    }
    
    void longestPath(vector<vector<int>> const &mat, vector<vector<int>> &visited, int i, int j, int x, int y, int &max_dist, int dist){
    	
    	if(i == x && j == y){
    		
    		max_dist = max(max_dist, dist);
    		return;
    	}
    	
    	visited[i][j] = 0;
    	
    	for(int k = 0; k < 4; k++){
    		
    		int a = i + row[k];
    		int b = j + col[k];
    		
    		if(isValid(mat, visited, a, b)){
    			
    			longestPath(mat, visited, a, b, x, y, max_dist, dist + 1);
    		}
    	}
    	
    	visited[i][j] = -1;
    }
    
	int findLongestPathLen(vector<vector<int>> const &mat, pair<int,int> const &src, pair<int,int> const &dest)
	{
		if(mat.size() == 0 || mat[src.first][src.second] == 0 || mat[dest.first][dest.second] == 0){
			
			return 0;
		}
		
		int max_dist = 0;
		
		int N = mat.size();
		int M = mat[0].size();
		
		vector<vector<int>> visited(N, vector<int>(M, -1));
		
		longestPath(mat, visited, src.first, src.second, dest.first, dest.second, max_dist, 0);
		
		return max_dist;
	}
};
