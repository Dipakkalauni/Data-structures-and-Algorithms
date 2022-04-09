/*

Given a string, find all permutations of it.

Input : "ABC"
Output: ["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"]

There are exacly n! permutations for a string of length n, and the solution should return all permutations in any order. For strings containing duplicate characters, the solution should return duplicate permutations.

Input : "ABA"
Output: ["ABA", "AAB", "BAA", "BAA", "AAB", "ABA"]

*/

class Solution
{
public:
    void permutation(vector<string> &container, string s, int i, int n){
    	
    	if(i == n){
    		container.push_back(s);
    		return;
    	}
    	
    	for(int j = i; j < n; j++){
    		
    		swap(s[i], s[j]);
    		
    		permutation(container, s, i+1, n);
    		
    		swap(s[i], s[j]);
    	}
    	
    	
    }
    
	vector<string> findPermutations(string s)
	{
		vector<string> container;
		
		if(s.size() == 0){
			
			return container;
		}
		permutation(container, s, 0, s.size());
		
		return container;
	}
};