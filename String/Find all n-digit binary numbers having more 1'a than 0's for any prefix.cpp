/*

Given a positive integer n, find all n–digit binary numbers having more 1’s than 0’s for any prefix of the number.

Input : n = 4
Output: {1111, 1110, 1101, 1100, 1011, 1010}

Note that 1001 will not form part of the solution as it violates the problem constraints (1001 has 2 zeros and 1 one at third position). The same applies to all other 4–digit binary numbers.

*/

class Solution
{
public:
    void findNumber(unordered_set<string> &set, string res, int n, int zeros, int ones){
    	
    	if(ones < zeros){ //if total number of ones < zeros, return
    		
    		return;
    	}
    	
    	if(n == 0){  // base case
    		
    	   set.insert(res);
    	   return;
    	}
    	
    	//append 1 to the result and recur
    	 findNumber(set, res + '1', n-1, zeros, ones + 1);
    	
    
    	//append 0 to the result and recur
    	findNumber(set, res + '0', n-1, zeros + 1, ones);
    	
    }
    
    
	unordered_set<string> findNDigitNumbers(int n)
	{
		unordered_set<string> set;
		
		findNumber(set, "", n, 0, 0);
		
		return set;
	}
};