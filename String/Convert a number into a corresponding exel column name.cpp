/*

Given a positive number, convert the number to the corresponding Excel column name.

Input: 1
Output: "A"

Input: 27
Output: "AA"

Input: 1001
Output: "ALM"

Note: Excel supports upto 2^14 columns, i.e. 16,384 columns.

*/

class Solution
{
public:
	string getColumnName(int n)
	{
		string result = "";
		
		while(n > 0){
			
			int digit = (n-1) % 26;
			
			result = char(digit + 'A') + result;
			
			n = (n-1)/26;
		}
		
		return result;
	}
};
