/*

Given a lists of words, print all combinations of phrases that can be formed by picking one word from each list.

Input:

lists =
[
	["John", "Emma"],
	["Plays", "Hates", "Watches"],
	["Cricket", "Soccer", "Chess"]
]

Output:

{
	"John Plays Cricket",
	"John Plays Soccer",
	"John Plays Chess",
	"John Hates Cricket",
	"John Hates Soccer",
	"John Hates Chess",
	"John Watches Cricket",
	"John Watches Soccer",
	"John Watches Chess",
	"Emma Plays Cricket",
	"Emma Plays Soccer",
	"Emma Plays Chess",
	"Emma Hates Cricket",
	"Emma Hates Soccer",
	"Emma Hates Chess",
	"Emma Watches Cricket",
	"Emma Watches Soccer",
	"Emma Watches Chess"
}

*/

class Solution
{
public:
    void Combination(vector<vector<string>> const &lists, unordered_set<string> &set, string result, int index){
    	
    	//base case , 
    	if(index == lists.size()){
    		
    		set.insert(result.substr(1));
    		return;
    	}
    //traverse through each word in the current list
    	for(int i = 0; i < lists[index].size(); i++){
    		
    		//append current word to ouput
    	      string new_str = result + " " + lists[index][i];
    	      
    		 //recur for the next list
    		Combination(lists, set, new_str, index + 1);
    		
    		
    	}
    }
    
	unordered_set<string> findCombinations(vector<vector<string>> const &lists)
	{
		unordered_set<string> set;  //stores all the possible Combinations
		
		if(lists.size() == 0){  //base case
			
			return set;
		}
		
		Combination(lists, set, "", 0); 
		
		return set;
	}
};