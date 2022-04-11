/*

Given a string, find all distinct lexicographic permutations of it where the repetition of characters is allowed.

Input : "AAB"
Output: {"AAA", "AAB", "ABA", "ABB", "BAA", "BAB", "BBA", "BBB"}

*/

class Solution
{
public:

   //function to find all the lexicographic Permutation of a string
    void lexicographicPerm(unordered_set<string> &set, string s, string result){
    	
    	if(s.size() == result.size()){  //base case
    		
    		set.insert(result);
    		return;
    	}
    	
    	for(int i = 0; i < s.size(); i++){  //consider all the characters of a string in a current index of result
    		
    		while(i+1 < s.size() && s[i] == s[i+1]){ //skip adjacent duplicates
    			i++;
    		}
    		
    		lexicographicPerm(set, s, result + s[i]);
    	}
    }
	unordered_set<string> findLexicographicPermutations(string s)
	{
	  unordered_set<string> set;  // stores all the distinct lexicographic permutations of a string 
	  
	  if(s.size() == 0){ //base case
	  	
	  	return set;
	  }
	   
	   sort(s.begin(), s.end());
	   
	   lexicographicPerm(set, s, "");
	   
	   return set;
	}
};