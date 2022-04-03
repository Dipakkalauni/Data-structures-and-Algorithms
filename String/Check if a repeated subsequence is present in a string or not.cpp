/*

Given a string, check if a repeated subsequence is present in it or not. The repeated subsequence should have a length of 2 or more.

Input: "XYBAXB"
Output: true
Explanation: String "XYBAXB" has XB(XBXB) as a repeated subsequence

Input: "XBXAXB"
Output: true
Explanation: String "XBXAXB" has XX(XXX) as a repeated subsequence

Input: "XYBYAXBY"
Output: true
Explanation: String "XYBYAXBY" has XB(XBXB), XY(XYXY), YY(YYY), YB(YBYB), and YBY(YBYBY) as repeated subsequences.

Input: "ABCA"
Output: false
Explanation: String "ABCA" doesn’t have any repeated subsequence

*/

class Solution
{
public:
    bool ispalin(string s){   //function to find out if a string is palindrome or not
    	
    	int n = s.size();
    	
    	for(int i=0; i < n/2; i++){
    		
    		if(s[i] != s[n-i-1]){
    			return false;
    		}
    	}
    	
    	return true;
    }
    
    
	bool hasRepeatedSubsequence(string s)
	{
		int n = s.size();  //stores the size of the string
		
		unordered_map<char, int> map;  //stores the character and its frequency in the string
		
		for(int i=0; i<n; i++){   // traverse the string and stores the character and their frequency in map
			
			map[s[i]]++;
		}
		
		string new_str = "";  //string formed after removing all the character having single frequency
		
		for(int i=0; i<n; i++){
			
			if(map[s[i]] > 2){  // if any character have frequency more than 2 , return true
				
				return true;
			}else if(map[s[i]] > 1){
				
				new_str += s[i];
			}
		}
		
		if(ispalin(new_str)){    //if the  new_str is a palindrome , return false; else return true
			
			return false;
		}else {
			
			return true;
		}
	}
};