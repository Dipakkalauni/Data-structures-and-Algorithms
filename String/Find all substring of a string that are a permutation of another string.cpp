/*

Given two strings, find all substrings of the first string that are anagrams of the second string and return the list of their indices.

Two words, X and Y, are anagrams if by rearranging the letters of X, we can get Y using all the original letters of X exactly once.

Input: X = "XYYZXZYZXXYZ", Y = "XYZ"
Output: [2, 4, 6, 9]

Explanation:

Anagram "YZX" present at index 2
Anagram "XZY" present at index 4
Anagram "YZX" present at index 6
Anagram "XYZ" present at index 9

Note: The solution should return the indices in ascending order.

*/

class Solution
{
public:
	vector<int> findAllAnagrams(string X, string Y)
	{
		int n = X.size();  //length of the string x and y respectively
		int m = Y.size();
		
		//stores the starting index of substring of X which is anagram to Y
		vector<int> index;
		
		if(m > n){ //invalid input
			
			return index;
		}
		//maintains the count of characters in the second string
	    unordered_multiset<char> map1;
	    //maintains the count of characters in the current window
	    unordered_multiset<char> map2;
	    
	    for(int i=0; i<m; i++){ //insert all characters of string 'Y' into a set
	    	map1.insert(Y[i]);
	    }
	    
	    int i = 0; //keeps track of starting index of window
	    int j = 0; //keeps track of ending index of window
	    
	    
	    while(j < n){
	    	//maintains a sliding window of size m
	    	while(map2.size() < m){
	    		map2.insert(X[j]);
	    		j++;
	    	}
	    	
	    	//if all characters in map1 == map2, we have found the substring
	    	if(map1 == map2){// and insert i into the index vector
	    		index.push_back(i);
	    	}
	        
	        
	    	map2.insert(X[j]); //add the next element to the right of the current substring into the window and erase the leftmost character from the window
	    	
	    	auto itr = map2.find(X[i]);
	    	if(itr != map2.end()){
	    		map2.erase(itr);
	    	}
	    	
	    	i++;
	    	j++;
	    }
	    
	    if(map1 == map2){
	    	index.push_back(i);
	    }
	    
	    return index;
	    
	}
};