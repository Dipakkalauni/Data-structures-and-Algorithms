/*

Given a string, find all possible distinct palindromic substrings in it.

Input : "google"
Output: {"e", "l", "g", "o", "oo", "goog"}

*/

class Solution
{
public:
     //function to find the all palindromic substrings by expanding in both directions
    void expand(unordered_set<string> &palin, string s, int low, int high){
    	
    	 while(low >=0 && high < s.size() && s[low] == s[high]){
    	 	
    	 	 palin.insert(s.substr(low, high - low +1));
    	 	 
    	 	 low--;
    	 	 high++;
    	 }
    }
    
	unordered_set<string> findPalindromicSubstrings(string s)
	{
		int n = s.size();  //stores the size of the string
		
		unordered_set<string> palind;  //stores all the possible palindromic substring
		
		for(int i=0; i<n; i++){  //consider each character as the midpoint of the palindrome
			                      // and expand on both direction to find both even length and
			                      // odd length palindrome
			expand(palind, s, i, i);
			
			expand(palind, s, i, i+1);
		}
		
		return palind;
	}
};