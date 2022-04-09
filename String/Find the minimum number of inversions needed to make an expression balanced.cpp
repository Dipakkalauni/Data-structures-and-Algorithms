/*

Given an expression consisting of an opening brace '{' and a closing brace '}', find the minimum number of inversions needed to balance the expression.

Input : "{{}{{}{{"
Output: 2
Explanation: Minimum number of inversions needed is 2, as shown below:

{{}{{}{{ ——> {{}{{}}{ ——> {{}{{}}}


Input : "{{{{{{"
Output: 3
Explanation: Minimum number of inversions needed is 3, as shown below:

{{{{{{ ——> {{{}{{ ——> {{{}}{ ——> {{{}}}


The solution should return -1 on invalid input.

*/

class Solution
{
public:
	int findMinimumInversions(string s)
	{
		int n = s.size();  //stores the size of the array
		
		if(n % 2 != 0){  // if n is odd, return -1
			
			return -1;
		}
		int inversion = 0; //stores total number of inversion needed
		int count = 0;  //stores total number of opening brackets
		
		for(int i=0; i<n; i++){ // traverse the expression
			
			if(s[i] == '{'){ //if current character is opening brace
			
				count++;
			}else{   // if current character is closing brace
				
				if(count == 0){
				   inversion++;
					count++;
				}else{
					
					count--;
				}
				
			}
		}
	
		return inversion + count/2;
	}
};