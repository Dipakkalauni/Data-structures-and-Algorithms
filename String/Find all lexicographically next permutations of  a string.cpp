/*

Given a string, find all lexicographically next permutations of it.

The words are arranged in the same order in the lexicographic order as they are presumed to appear in a dictionary. For example, the lexicographically next permutation of string "ABCD" is "ABDC", for string "ABDC" is "ACBD", and for string "ACBD" is "ACDB".

Input : "ABCD"
Output: ["ABCD", "ABDC", "ACBD", "ACDB", "ADBC", "ADCB", "BACD", "BADC", "BCAD", "BCDA", "BDAC", "BDCA", "CABD", "CADB", "CBAD", "CBDA", "CDAB", "CDBA", "DABC", "DACB", "DBAC", "DBCA", "DCAB", "DCBA"]

Input : "CABD"
Output: ["CABD", "CADB", "CBAD", "CBDA", "CDAB", "CDBA", "DABC", "DACB", "DBAC", "DBCA", "DCAB", "DCBA"]

Input : "ABA"
Output: ["ABA", "BAA"]

Input : "AAA"
Output: ["AAA"]

Note that the solution should not print duplicate permutations.

*/

class Solution
{
public:
	vector<string> findPermutations(string s)
	{
	    vector<string> combinations; //stores all next lexicographically next permutations of it.
	    
	    int n = s.size();  // size of the string
	    
	    if(n == 0){        //base case
	    	return combinations;
	    }
	    
	    if(n == 1){ //base case
	    	combinations.push_back(s);
	    	 return combinations;
	    }
	    
	    while(1){
	    	  // insert the current string into vector
	    	combinations.push_back(s);
	    	
	    	//algorithm to find the lexicographically next permutation
	    	int i = n-1;
	    	
	    	while(s[i -1] >= s[i]){
	    		
	    		if(--i == 0){
	    			
	    			return combinations;
	    		}
	    	}
	    	
	    	int j = n-1;
	    	
	    	while(s[j] <= s[i-1]){
	    		
	    		j--;
	    	}
	    	
	    	swap(s[j], s[i-1]);
	    	
	    	reverse(s.begin()+i, s.end());
	    }
	}
};
