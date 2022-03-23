/*

Given a rectangular binary matrix, calculate the area of the largest rectangle of 1’s in it. Assume that a rectangle can be formed by swapping any number of columns with each other.

Input:

[
	[0, 1, 0, 1, 1],
	[1, 1, 0, 0, 1],
	[1, 1, 0, 1, 1],
	[1, 1, 1, 1, 1]
]

Output: 9

Explanation: The area of the largest rectangle of 1’s is 9. The largest rectangle of 1’s can be formed by swapping column 3 with column 5.

[0, 1, 1, 1, 0]
[1, 1, 1, 0, 0]
[1, 1, 1, 1, 0]
[1, 1, 1, 1, 1]


Input:

[
	[0, 1, 1, 0],
	[1, 0, 0, 1],
	[1, 1, 0, 1],
	[1, 1, 1, 1]
]

Output: 6

Explanation: The area of the largest rectangle of 1’s is 6. The largest rectangle of 1’s can be formed by swapping column 2 with column 4 or swapping column 3 with column 4.

[0, 0, 1, 1]
[1, 1, 0, 0]
[1, 1, 0, 1]
[1, 1, 1, 1]

OR

[0, 1, 0, 1]
[1, 0, 1, 0]
[1, 1, 1, 0]
[1, 1, 1, 1]

*/

class Solution
{
public:
	int findLargestRectangleArea(vector<vector<int>> &mat)
	{
		if(mat.size() == 0){
			return 0;
		}
		
	
		
		int N = mat[0].size();
		int M = mat.size();
		
	    // update the matrix to store the counts of consecutive 1's present in each column
    for (int j = 0; j < N; j++)
    {
        // process each column from bottom to top
        for (int i = M - 2; i >= 0; i--)
        {
            if (mat[i][j] == 1) {
                mat[i][j] = mat[i+1][j] + 1;
            }
        }
    }
 
    // keep track of the largest rectangle of 1's found so far
    int maxArea = 0;
 
    // traverse each row in the modified matrix to find the maximum area
    for (int i = 0; i < M; i++)
    {
        // create a count array for each row `i`
        int count[M + 1] = { 0 };
 
        // process row `i`
        for (int j = 0; j < N; j++)
        {
            if (mat[i][j] > 0)
            {
                // increment value in the count array using the current element
                // as an index
                count[mat[i][j]] += 1;
 
                // the area can be calculated by multiplying the current
                // element `mat[i][j]` with the corresponding value
                // in the count array `count[mat[i][j]]`
 
                maxArea = max(maxArea, mat[i][j] * count[mat[i][j]]);
            }
        }
    }
		
		
		return maxArea;
	}
};