/*

Check if a given set of moves is circular or not. A move is circular if its starting and ending coordinates are the same. The moves can contain instructions to move one unit in the same direction (M), to change direction to the left of current direction (L), and to change direction to the right of current direction (R).

Input: "MRMRMRM"
Output: true

Input: "MRMLMRMRMMRMM"
Output: true

Assume that the initial direction is North.

*/

class Solution
{
public:
	bool isCircularMove(string s)
	{
		int n = s.size();  //stores the size of the string
		int x = 0;   //(x,y) stores the coordinates (0, 0)
		int y = 0;
		
		
		char dir = 'N'; //initial direction is North
		
		//traverse the input array
		for(int i = 0; i < n; i++){
			
			switch(s[i]){
				// move one unit in the same direction
				case 'M':
				
				    if(dir == 'N'){
				    	y++;
				    }else if(dir == 'S'){
				    	y--;
				    }else if(dir == 'E'){
				    	x++;
				    }else if(dir ==  'W'){
				    	x--;
				    }
				    
				  break;
				  
				  //change direction to the left of the current direction
				  case 'L':
				     
				     if(dir == 'N'){
				         dir = 'W';
				    }else if(dir == 'S'){
				         dir = 'E';
				    }else if(dir == 'E'){
				    	 dir = 'N';
				    }else if(dir ==  'W'){
				    	  dir = 'S';
				    }
				    
				  break;
				  
				  //change direction to the right of the current direction
				  case 'R':
				  
				  if(dir == 'N'){
				         dir = 'E';
				    }else if(dir == 'S'){
				         dir = 'W';
				    }else if(dir == 'E'){
				    	 dir = 'S';
				    }else if(dir ==  'W'){
				    	  dir = 'N';
				    }
				    
			}
		}
		
		return (!x && !y);  //return true if x, y is (0, 0)
	}
};