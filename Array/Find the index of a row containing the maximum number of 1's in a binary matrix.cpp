/*

Given a binary `M × N` row-wise sorted matrix, find a row that contains the maximum number of 1’s in linear time.

Input:
[
	[0, 0, 0, 1, 1],
	[0, 0, 1, 1, 1],
	[0, 0, 0, 0, 0],
	[0, 1, 1, 1, 1],
	[0, 0, 0, 0, 1]
]

Output: 4
Explanation: The maximum 1’s are present in row 4


If multiple rows have same maximum number of 1’s, the solution should return the first row number. If no 1’s are present in the matrix, the solution should return 0.

Input:
[
	[1, 1, 1, 1],
	[1, 1, 1, 1],
	[1, 1, 1, 1],
]

Output: 1

*/

class Solution
{
public:
	int findRow(vector<vector<int>> const &mat)
	{
		if(mat.size() == 0){  //base case
			return 0;
		}
		
		// "M * N" matrix
		int N = mat.size();  
		int M = mat[0].size();
		
		//current row and column index 'i, j'
		int i = 0;
		int j = M-1;
		
		int row = -1;  // stores the row index with maximum 1s
		
		while(i < N && j >= 0){ 
			
			if(mat[i][j]){ //if current number is 1
				           // decrement j and upadate row
				j--;
				row = i;
			}else{          //else increase i
				
				i++;;
			}
		}
		
		return row+1;     //return row number
	}
};