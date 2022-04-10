/*

Given a positive number n between 1 and 9, find all n–digit numbers with a given sum where sum <= 81 (Maximum possible sum in a 9–digit number).

Input: n = 3, target = 6

Output: {105, 114, 123, 132, 141, 150, 204, 213, 222, 231, 240, 303, 312, 321, 330, 402, 411, 420, 501, 510, 600}


Input: n = 5, target = 42

Output: {69999, 78999, 79899, 79989, 79998, 87999, 88899, 88989, 88998, 89799, 89889, 89898, 89979, 89988, 89997, 96999, 97899, 97989, 97998, 98799, 98889, 98898, 98979, 98988, 98997, 99699, 99789, 99798, 99879, 99888, 99897, 99969, 99978, 99987, 99996}

*/

class Solution
{
public:
    void findNdigit(unordered_set<int> &set, int num, int target, int n){
    	
    	if(n > 0 && target >= 0){  //if the number is less than n-digit and its sum of
    	                          //digits is less than the given sum
    	   int i = 0;
    	   
    	   if(num == 0){   //number cannnot start from zero
    	    	
    	   	  i = 1;
    	   }
    	
    	//consider every valid digit and append it to the end of num and recur for 
    	//next digit
    	 for(; i <= 9; i++){
    	  	
    	   findNdigit(set, (num *10 + i), target - i, n - 1);
    	   
       	}
    	
    	//if the number becomes n-digit and its sum of digit is equal to the given 
    	//sum, return
      } else if(n == 0 && target == 0){
    		
    		set.insert(num);
    		return;
    		
    	}
    }
    
	unordered_set<int> findNDigitNumbers(int n, int target)
	{
		unordered_set<int> set;  
		
		findNdigit(set, 0, target, n);
		
		return set;
	}
};