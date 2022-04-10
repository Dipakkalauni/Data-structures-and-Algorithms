/*

Given a positive number n between 1 and 9, find all n–digit binary numbers with an equal sum of left and right half. The binary number should not start with 0 and for odd numbers, the middle element can be 0 or 1.

Input: n = 6
Output: {100001, 100010, 101011, 110011, 100100, 101101, 101110, 110101, 110110, 111111}

Input: n = 7
Output: {1000001, 1001001, 1000010, 1001010, 1010011, 1011011, 1100011, 1101011, 1000100, 1001100, 1010101, 1011101, 1010110, 1011110, 1100101, 1101101, 1100110, 1101110, 1110111, 1111111}

*/

class Solution
{
public:
//function to find all n-digit binary numbers with equal sum of left and right halves
    void findNDigit(unordered_set<string> &set, int n, string left, string right, int diff){
    	
    	if(n == 0 && diff == 0){  //if the number is n-digit and difference between left 
    		                      //and right halves is zero
    		set.insert(left + right);
    		return;
    		
    	}else if(n && 2 * abs(diff) <= n){ //else if number is not n-digit and difference can be covered with n-digits
    	
    	if(n == 1){  //if n is odd recur with midpoint as '0' and '1'
    		
    		findNDigit(set, 0, left, '0'+ right, diff);
    		findNDigit(set, 0, left, '1' + right, diff);
    		return;
    	}
    	
    	if(left != ""){  //binary number should not start with 0
    		
    		findNDigit(set, n-2, left + '0', right + '0', diff);
    		
    		findNDigit(set, n-2, left + '0', right + '1', diff - 1);
    	}
    	
    	  findNDigit(set, n-2, left + '1', right + '0', diff + 1);
    	  
    	  findNDigit(set, n-2, left + '1', right + '1', diff);
    	  
    	}
    	 
    }
    
	unordered_set<string> findNDigitNumbers(int n)
	{
	        unordered_set<string> set;  //stores all n-digit binary number with equal sum of left and right halves
	        
	        findNDigit(set, n , "", "", 0);
	        
	        return set;
	}
};
