/*

Given a string, calculate its rank among all its lexicographically sorted permutations.

Input : "CBA"
Output: 6
Explanation: The rank of string "DCBA" in the lexicographically sorted permutations ["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"] is 6.

Input : "AABA"
Output: 2
Explanation: The rank of string "AABA" in the lexicographically sorted permutations ["AAAB", "AABA", "ABAA", "BAAA"] is 2.

Input : "DCBA"
Output: 24

*/

class Solution
{
public:
    unsigned long factorial(int n){
    	
    	unsigned long fact = 1;
    	
    	for(int i=1; i<=n; i++){
    		
    		fact = fact * i;
    	}
    	
    	return fact;
    }
	long findLexicographicRank(string s)
	{
		unsigned long rank = 1;
		
		for(int i=0; i<s.size()-1; i++){
			
			int count = 0;
			
			for(int j = i+1; j < s.size(); j++){
				
				if(s[j] < s[i]){
					count++;
				}
			}
			
			rank += count * factorial(s.size() - 1 - i);
		}
		
		return rank;
	}
};