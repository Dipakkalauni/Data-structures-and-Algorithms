/*

Find all interleavings of given strings that can be formed from all the characters of the first and second string where the order of characters is preserved.

Input: X = "ABC", Y = "ACB"
Output: {"ACBABC", "AABCBC", "ACABCB", "ABCACB", "AACBBC", "ABACCB", "ACABBC", "ABACBC", "AACBCB", "AABCCB"}

*/

class Solution
{
public:
  // function to find the interleaving of X and Y
   void Interleaving(unordered_set<string> &combinations, string result, string X, string Y){
   	  
   	  if(X.size() == 0 && Y.size() == 0){  //insert the result into set if 
   	  	                                  // the end of both string is reached
   	  	combinations.insert(result);
   	  	return;
   	  }
   	  
   	  if(X.size()){  //if X is not empty, append the first char to the result and recur for remaining
   	  	  
   	  	 
   	  	Interleaving(combinations, result + X[0], X.substr(1), Y);
   	  }
   	  
   	  if(Y.size()){ // if Y is not empty, append the first char to the result and recur for remaining
   	  	
   	  	Interleaving(combinations, result + Y[0], X , Y.substr(1));
   	  }
   	    
   }
   
   
	unordered_set<string> findInterleavings(string X, string Y)
	{
		unordered_set<string> combinations;  //stores all the interleaving of X and Y
		
		if(X.size()==0 && Y.size() == 0){  //return if both strings are empty
			
			return combinations;
		}
		
		string result = "";
		
		Interleaving(combinations, result, X, Y);
		
		return combinations;
	}
};
