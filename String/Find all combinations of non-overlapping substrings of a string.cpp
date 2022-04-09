/*

Given a string, return all combinations of non-overlapping substrings of it.

Input : "ABC"
Output: {["A", "B", "C"], ["A", "BC"], ["AB", "C"], ["ABC"]}

Input : "ABCD"
Output: {["A", "B", "C", "D"], ["A", "B", "CD"], ["A", "BC", "D"], ["A", "BCD"], ["AB", "C", "D"], ["AB", "CD"], ["ABC", "D"], ["ABCD"]}

*/

class Solution
{
public:

    void combinations(set<vector<string>> &combination, vector<string> &res, string s){
    	
      //if all character of string s, is processed , insert res into combination
    	if(s.size() == 0){
    		combination.insert(res);
    	}
    	
   //append each prefix str[0, i] for Output string and recur for remaining  substring str[i+1, n]
    	for(int i = 0; i < s.size(); i++){
    		
    		string Output = s.substr(0, i+1);
    		
    		res.push_back(Output);
    		
    		combinations(combination, res, s.substr(i + 1));
    		
    		res.pop_back();
    	}
    }
    
	set<vector<string>> findCombinations(string s)
	{
		set<vector<string>> combo;  //stores all combinations of non-overlapping substring
		  
		if(s.size() == 0){   //base case
			return combo;
		}
		
		vector<string> res;  //vector to store non-overlapping substring
		
		//recur to find all non-overlapping substring
		combinations(combo, res, s);
		return combo;
	}
};