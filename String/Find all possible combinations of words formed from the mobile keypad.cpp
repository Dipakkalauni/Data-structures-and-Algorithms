/*

Given a sequence of numbers between 2 and 9, print all possible combinations of words formed from the mobile keypad which has english alphabets associated with each key.

keypad = {
	2: ['A', 'B', 'C'],
	3: ['D', 'E', 'F'],
	4: ['G', 'H', 'I'],
	5: ['J', 'K', 'L'],
	6: ['M', 'N', 'O'],
	7: ['P', 'Q', 'R', 'S'],
	8: ['T', 'U', 'V'],
	9: ['W', 'X', 'Y', 'Z']
}

Input : [2, 3, 4]

Output: {"CEG", "AEH", "CDH", "CFI", "CEH", "BEI", "AFH", "BFG", "BDI", "ADH", "AEG", "AEI", "BEH", "BFH", "BDH", "CEI", "AFG", "BFI", "ADG", "CDG", "BDG", "CDI", "BEG", "AFI", "CFG", "CFH", "ADI"}

*/

class Solution
{
public:
   // recursive function to find all the combinations
    void combo(unordered_set<string> &combinations, unordered_map<int, vector<char>> &keypad, vector<int> &nums, string res, int n){
    	
    	if(n == nums.size()){  //if every key of nums is processed, return
    		
    		combinations.insert(res);
    		return;
    	}
    	
    	int digit = nums[n];  //current digit
    	
    	for(char c : keypad[digit]){  //get the list corresponding to the digit and replace the digit one by one 
    		                          // with the character of the list and recur for the next digit
    		combo(combinations, keypad, nums, res+c, n+1);
    	}
    	
    }
    
	unordered_set<string> findCombinations(unordered_map<int,vector<char>> &keypad,
					vector<int> &nums)
	{
		unordered_set<string> combinations; //stores all combinations
		
		if(keypad.size()==0 || nums.size()==0){  //if input invalid return 
			
			return combinations;
		}
		
		combo(combinations, keypad, nums, "", 0);  //recur and find all combinations
		
		return combinations;
		
	}
};