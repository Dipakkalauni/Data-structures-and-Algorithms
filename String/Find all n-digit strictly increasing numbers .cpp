/*

Given a positive number n between 1 and 9, find all n–digit strictly increasing numbers. A number is strictly increasing if every digit is greater than its preceding digit.

Input: n = 8
Output: {12345678, 12345679, 12345689, 12345789, 12346789, 12356789, 12456789, 13456789, 23456789}

Input: n = 7
Output: {1234567, 1234568, 1234569, 1234578, 1234579, 1234589, 1234678, 1234679, 1234689, 1234789, 1235678, 1235679, 1235689, 1235789, 1236789, 1245678, 1245679, 1245689, 1245789, 1246789, 1256789, 1345678, 1345679, 1345689, 1345789, 1346789, 1356789, 1456789, 2345678, 2345679, 2345689, 2345789, 2346789, 2356789, 2456789, 3456789}

*/

class Solution
{
public:

    void findIncreasingNumbers(unordered_set<int> &set, int s, int n, int i){
    	
    	if(n){  //if n > 0
    		
    		for(int j = i+1; j <= 9; j++){  
    			
    			 int out = s*10 + j;
    			 
    			findIncreasingNumbers(set, out, n-1, j);
    		}
    		
    	}else {
    		
    		set.insert(s);
    		return;
    	}
    }
    
	unordered_set<int> findStrictlyIncreasingNumbers(int n)
	{
		unordered_set<int> set;  //stores all the n-digit strictly increasing number
		
		findIncreasingNumbers(set, 0, n, 0); //recursive function to find all the n-digit strictly increasing number
		
		return set;
	}
};