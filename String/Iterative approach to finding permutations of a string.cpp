/*

Given a string, find all permutations of it.

Input : "ABC"
Output: ["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"]

The solution should handle strings containing duplicate characters and don"t repeat the permutations.

Input : "ABA"
Output: ["ABA", "AAB", "BAA"]

Input : "AAA"
Output: ["AAA"]

*/

class Solution
{
public:
    
	vector<string> findPermutations(string s)
	{
		
	  vector<string> container;  //stores all the possible permutations
	   
	   int n = s.size();    //stores the size of the array
	   
	   if(n == 0){        //base case
	   	
	   	return container;
	   }
	   
	   if(n == 1){    //base case
	   	
	   	container.push_back(s);
	   	return container;
	   }
	   
	   sort(s.begin(), s.end());    //sort the string
	   
	   while(1){
	   	
	   	  container.push_back(s);   //insert the string into vector
	   	   
	   	   //algorithm to find the next permutation
	   	   
	   	  int i = n - 1;
	   	  
	   	  while(s[i-1] >= s[i]){
	   	  	
	   	  	if(--i == 0){
	   	  		
	   	  		return container;
	   	  	}
	   	  	
	   	  }
	   	  
	   	   int j = n-1;
	   	   
	   	   while(j > i && s[i-1] >= s[j]){
	   	   	   j--;
	   	   }
	   	   
	   	   swap(s[j], s[i-1]);
	   	   
	   	   reverse(s.begin()+i, s.end());
	   }
	   
	   return container;
	}
};