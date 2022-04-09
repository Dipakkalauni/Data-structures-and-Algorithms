/*

Given a string, check if it is a palindrome. A palindromic string is a string that remains the same with its characters reversed.

Input : "ABCBA"
Output: true

Input : "ABCA"
Output: false

*/

class Solution
{
public:
	bool isPalindrome(string s)
	{
		int n = s.size(); //stores the size of the string
		
		if(n == 0 || n == 1){ //base case
			return true;
		}
		int low = 0; //points to start of the string
		int high = n-1; // points to end of the string
		
		while(low < high){ 
			
			if(s[low] != s[high]){
				
				return false;
			}
			
			low++;
			high--;
		}
		
		return true;
	}
};