/*

Given a string, remove all occurrences of "AB" and "C" in a single traversal of it.

Input: "CBAABCAB"
Output: "BA"

The solution should remove of all adjacent, as well as non-adjacent occurrences of string "AB" and "C".

Input: "ADAABCB"
Output: "AD"
Explanation: Removing the first adjacent occurrence of "AB" and "C" results in string "ADAB", which again needs to be processed for adjacent "AB". Therefore, the final output string will be "AD".

Input: "AACBBC"
Output: ""
Explanation: AACBBC -> AABB -> AB -> ""

*/

class Solution
{
public:
	string remove(string s)
	{
		string result = "";  //stores the new string
		
		int i=0;  //keeps track of indexes of string s
		
		while(i < s.size()){  //loop through the string
			
			if(s[i] == 'C'){  //if current character is C, move to the next index
				
				i++;
			}else if(s[i] == 'A' && s[i+1] == 'B'){ //if ith character is A and i + 1 is B, skip these two index
				
				i += 2;
			}else if(s[i] == 'B'&& result[result.size()-1] == 'A'){ //if current character is B and last character
				                                                   // of result string is A, remove A, and skip B
				result.pop_back();
				i++;
			}
			else{                   //else add current index in result
				                       // increase i
				result += s[i];
				i++;
			}
		
		}
		
		return result;
	}
};