/*

Given a positive number n between 1 and 9, find all n–digit binary numbers with k–bits set where k ranges from 1 to n.

Input: n = 4

Output: {0001, 0010, 0100, 1000, 0011, 0101, 0110, 1001, 1010, 1100, 0111, 1011, 1101, 1110, 1111}

Explanation: 4–digit binary numbers are:

(k = 1) 0001 0010 0100 1000
(k = 2) 0011 0101 0110 1001 1010 1100
(k = 3) 0111 1011 1101 1110
(k = 4) 1111


Input: n = 5

Output: {00001, 00010, 00100, 01000, 10000, 00011, 00101, 00110, 01001, 01010, 01100, 10001, 10010, 10100, 11000, 00111, 01011, 01101, 01110, 10011, 10101, 10110, 11001, 11010, 11100, 01111, 10111, 11011, 11101, 11110, 11111}

Explanation: 5–digit binary numbers are:

(k = 1) 00001 00010 00100 01000 10000
(k = 2) 00011 00101 00110 01001 01010 01100 10001 10010 10100 11000
(k = 3) 00111 01011 01101 01110 10011 10101 10110 11001 11010 11100
(k = 4) 01111 10111 11011 11101 11110
(k = 5) 11111

*/

class Solution
{
public:
     void findNDigit(unordered_set<string> &set, int n, string &s){
     	
     	
     	for(int i = n-1; i >= 0; i--){  //traverse through the string from end to start 
     		                            //and set each ith bit to '1'
     		s[i] = '1';                 //and find all next_permutation of that string and stores them in set
     		
     		string res = s;
     		
     		set.insert(res);
     		
     		while(next_permutation(res.begin(), res.end())){
     			
     			set.insert(res);
     		}
     	}
     	
     }

     
	unordered_set<string> findNDigitNumbers(int n)
	{
		unordered_set<string> set; //stores all n-digit binary numbers with k-bit set
		
		string result = "";  
		
		for(int i=0; i<n; i++){   //construct n-bit binary number with all 0's
			
			result.push_back('0');
		}
		
		findNDigit(set, n, result);  //function to find all n-digit binary numbers with k-bit set
		
		return set;
	}
};