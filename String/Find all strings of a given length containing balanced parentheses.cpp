/*

Given a positive number n, find all strings of length n containing balanced parentheses.

Input : n = 4
Output: {"(())", "()()"}

Input : n = 6
Output: {"((()))", "(()())", "(())()", "()(())", "()()()"}

Input : n = 5
Output: {}
Explanation: Since n is odd, balanced parentheses cannot be formed.

*/

class Solution
{
public:
    
    void permutation(unordered_set<string> &container, string res, int n, int count){
    	
    	    if(n == 0 && count == 0){  //base case
    	    	container.insert(res);
    	    	return;
    	    }
    	
    	 
    	   if(count > n){ //if count > n, return
    	   	  return;
    	   }
    	   //recur with open parantheses
    	   permutation(container, res + '(', n-1, count+1);
    	   
    	   //recur with closed parantheses only if output string has at least on unclosed parantheses
    	   if(count > 0){
    	   	
    	   permutation(container, res + ')', n-1, count-1);
    	   }
        }
        
	unordered_set<string> findPalindromicPermutations(int n)
	{
		unordered_set<string> container; //stores strings of length containing balanced parentheses
		
		if(n % 2 != 0 || n == 0){ //base case
			
			return container;
		}
		
		//recur to find all the balanced parentheses of length n
		permutation(container, "", n, 0);
		
		return container;  
		
	}
};
