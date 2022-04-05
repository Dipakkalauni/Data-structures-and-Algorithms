/*

Given two strings, determine if the first string can be transformed into the second string. The only operation allowed is moving a character from the first string to the front. If the string can be transformed, find the minimum number of operations required for the transformation.

Input: X = "ADCB", Y = "ABCD"
Output: 3
Explanation: The minimum number of operations required to convert the string "ADCB" to string "ABCD" is 3.

ADCB —> CADB (Move 'C' to the front)
CADB —> BCAD (Move 'B' to the front)
BCAD —> ABCD (Move 'A' to the front)

The solution should return -1 if the string cannot be transformed.

*/

class Solution
{
public:
	int getMinimumOperations(string X, string Y)
	{
		int n = X.size();  //size of string x and Y respectively
		int m = Y.size();
		
		if(m != n){    //if sizes of X and Y is not equal, return -1
			return -1;
		}
		
		//check the characters of string X and string Y
		unordered_multiset<char> set1(X.begin(), X.end());
		unordered_multiset<char> set2(Y.begin(), Y.end());
		
		if(set1 == set2){  //if characters are equal
			
			int count = 0;  //stores the count of moves
			
			for(int i = n-1, j = i; i>=0; i--, j--){ //start from the end of the strings and traverse to the start
				
				while(i >= 0 && X[i] != Y[j]){  //increase count if ith and jth characters of string X and Y
					                            // are not equal
					count++; 
					i--;
				}
			}
			
			return count;
		}
		
	   return -1;
	}
};