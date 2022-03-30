/*

Given a positive integer `n`, find all combinations of numbers between 1 and `n` having sum `n`.

Input : n = 4
Output: {[4], [1, 3], [2, 2], [1, 1, 2], [1, 1, 1, 1]}

Input : n = 5
Output: {[5], [1, 4], [2, 3], [1, 1, 3], [1, 2, 2], [1, 1, 1, 2], [1, 1, 1, 1, 1]}

The solution should return a set containing all the distinct combinations in increasing order.

*/

class Solution
{
public:
    //function to find all the combinations of numbers between 1 and n having sum n
    void combo(set<vector<int>> &combinations, vector<int> &ans, int n, int j){
    	
    	 if(n == 0){ //if the sum becomes zero
    	 	
    	 	combinations.insert(ans);
    	 	return;
    	 }
    	  
    	  //start from jth to the nth element
    	 for(int i = j; i <= n; i++){
    	 	
    	 	ans.push_back(i);
    	 	combo(combinations, ans, n-i, i);
    	 	ans.pop_back();
    	 }
    }
    
	set<vector<int>> findCombinations(int n)
	{
		set<vector<int>> combinations; //used to store all combinations of numbers between 1 and n having sum n
        vector<int> ans; //used to store the current combination 
        
		combo(combinations, ans, n, 1);

		return combinations;
	}
};