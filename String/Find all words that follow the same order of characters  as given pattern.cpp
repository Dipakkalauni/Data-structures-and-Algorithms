/*

Given a list of words and a pattern, find all words in the list that follows the same order of characters as that of the pattern.

Input:

words = [leet, abcd, loot, geek, cool, for, peer, dear, seed, meet, noon, otto, mess, loss]
pattern = moon

Output: {leet, loot, geek, cool, peer, seed, meet}

Explanation: Pattern is 4 digits with distinct character at first and last index, and same character at 1st and 2nd index


Input:

words = [leet, abcd, loot, geek, cool, for, peer, dear, seed, meet, noon, otto, mess, loss]
pattern = pqrs

Output: {abcd, dear}

Explanation: Pattern is 4 digits and has all distinct characters

*/

class Solution{
public:
    // function to check if a word matches the pattern or not
    bool isValid(string s, string pattern){
    	
    	unordered_map<char, char> map1, map2; //maps to store the mapping from word to pattern
    	                                      // and pattern to word respectively.
    	                                      
    	if(s.size() != pattern.size()){    // if word and pattern are not of same size, return false
    		
    		return false;
    	}
    	
    	for(int i=0; i < s.size(); i++){  // traverse through word and pattern
    		
    		if(map1.find(s[i]) == map2.end()){  //if the ith char in word is seen for the first time
    			                                //insert it in map1 and match it with ith char in pattern
    			map1[s[i]] = pattern[i];
    			
    		}else if(map1[s[i]] != pattern[i]){ // else if ith chr in word is not mapped to ith char in pattern
    		                                     // return false
    		    return false;
    		}
    		
    		if(map2.find(pattern[i]) == map2.end()){  //if the ith char in pattern is not seen before 
    			                                      //insert it in map2 and match it with ith char in word
    			map2[pattern[i]] = s[i];
    			
    		}else if(map2[pattern[i]] != s[i]){  //else if ith char in pattern is not mapped to ith char in word 
    			                                 // return false
    			return false;
    		}
    	}
    	
    	return true;
    }
   
	unordered_set<string> patternMatch(unordered_set<string> const &words, string pattern)
	{
	    
	    unordered_set<string> combination;  // stores the matching words
	    
	    int n = words.size(); // size of the words list
	    
	    if(n == 0){     //if the words list is empty, return
	    	
	    	return combination;
	    }
	    
	    for(string s: words){  //loop through the words 
	    	
	    	if(isValid(s, pattern)){ //and if a word is valid i.e. matches the pattern
	    		
	    		combination.insert(s);  // than insert the word into combination
	    	}
	    }
	    
	    return combination;  // return combination
	}
};
