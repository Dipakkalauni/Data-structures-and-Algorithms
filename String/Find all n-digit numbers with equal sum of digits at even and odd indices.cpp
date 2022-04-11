/*

Given a positive number n between 2 and 9, find all n–digit numbers with an equal sum of digits at even and odd indices.

Input: n = 3
Output: {110, 121, 132, 143, 154, 165, 176, 187, 198, 220, 231, 242, 253, 264, 275, 286, 297, 330, 341, 352, 363, 374, 385, 396, 440, 451, 462, 473, 484, 495, 550, 561, 572, 583, 594, 660, 671, 682, 693, 770, 781, 792, 880, 891, 990}

Input: n = 5
Output: {10010, 10021, 10032, 10043, 10054, 10065, 10076, 10087, 10098, 10120, 10131, 10142, 10153, 10164, 10175, 10186, 10197, 10230, 10241, 10252, 10263, 10274, 10285, 10296, 10340, 10351, 10362, 10373, 10384, 10395, 10450, 10461, 10472, 10483, 10494, 10560, 10571, 10582, 10593, 10670, 10681, 10692, 10780, 10791, 10890, 11000, 11011, 11022, 11033, 11044, 11055, 11066, 11077, 11088, 11099, 11110, 11121, 11132, 11143, 11154, 11165, 11176, 11187, 11198, 11220}

*/

class Solution
{
public:
  //fuction to find all n-digit numbers with an equal sum of digits at even and odd indices
    void findNDigit(unordered_set<int> &set, int num, int n, int odd, int even){
    	
    	if(n == 0 && odd == even){ //if num is of n-digit and sum of digits at even indices == sum of digits at odd
    		                        //indices
    		set.insert(num);
    		return;
    		
    	}else if( n > 0){ //else if num is less then n-digits
    	
    	  int i = 0;  //start digits from 0, if it is not a digit at a first place
    	  
    	  if(num == 0){
    	  	 i = 1;
    	  }
    	  
    	  for(; i<=9; i++){  //consider every valid digit and place it in the current index and recur for next index
    	  	
    	  	 if(n % 2 != 0){
    	  	 	
    	  	 	findNDigit(set, (num * 10 + i), n - 1, odd + i, even);
    	  	 }else{
    	  	 	
    	  	 	findNDigit(set, (num * 10 + i), n - 1, odd, even + i);
    	  	 }
    	  	 
    	  	 
    	  }
    	  
    	}
    	  
    }
    
	unordered_set<int> findNDigitNumbers(int n)
	{
		unordered_set<int> set;
		
		if(n == 0){
			return set;
		}
		
		findNDigit(set, 0, n, 0, 0);
		
		return set;
	}
};