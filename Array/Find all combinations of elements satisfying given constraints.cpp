/*

Given a positive number `n`, find all combinations of `2×n` elements such that every element from 1 to `n` appears exactly twice and the distance between its two appearances is exactly equal to the value of the element.

Input : n = 3
Output: {[3, 1, 2, 1, 3, 2], [2, 3, 1, 2, 1, 3]}

Input : n = 4
Output: {[4, 1, 3, 1, 2, 4, 3, 2], [2, 3, 4, 2, 1, 3, 1, 4]}

Input : n = 5
Output: {}

*/

class Solution
{
public:
    void combo(set<vector<int>> &combinations, vector<int> &arr, int n, int num){
    	
    	if(num > n){ //if all elements are filled , insert the arr into set
    		
    		combinations.insert(arr);
    		return;
    	}
    	
    	for(int i = 0; i < 2*n; i++){ // try all possible combinations
    		
    		if((arr[i] == -1) && (i+num+1 < 2*n) && (arr[i+num+1] == -1)){
    			
    			arr[i] = num;
    			arr[i+num+1] = num;
    			
    			combo(combinations, arr, n, num+1);
    			
    			arr[i] = -1;
    			arr[i+num+1] = -1;
    		}
    	}
    	
    }
    
	set<vector<int>> findCombinations(int n)
	{
		set<vector<int>> combinations;
		//create a vector of double of size of n
		vector<int> arr(2*n, -1);
		
		combo(combinations, arr, n, 1);

		return combinations;
	}
};