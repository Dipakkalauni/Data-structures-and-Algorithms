/*

Given a string, find the length of the longest palindrome which can be constructed by shuffling or deleting characters in the string.

Input: "ABBDAB"
Output: 6
Explanation: The longest palindrome is "BABAB" (or "BADAB" or "ABBBA" or "ABDBA")

Input: "ABCDD"
Output: 5
Explanation: The longest palindrome is "DAD" (or "DBD" or "DCD")

*/

class Solution
{
public:
	int findLongestPalindrome(string s)
	{
		int n = s.size();  //stores the size of the string
		
		unordered_map<char, int> map; //stores the character and their frequency in the string
		
		for(int i=0; i<n; i++){ 
			
			map[s[i]]++;
		}
		
		int odd = 0; //counts the odd number of character in the string 
		
		for(auto itr: map){ //iterate through the map
			
			if(itr.second % 2 != 0){ //if frequency of character is odd
				                      //increase the odd
				odd++;
			}
		}
		
		if(odd <= 1){  //if odd <= 1, return n, i.e size of string
			
			return n;
		}else{        //else decrease (number of odd character -1) from sizeof string and return it
			
			return n-odd+1;
		}
		
	}
};