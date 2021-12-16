/*

Given a list containing future prediction of share prices, find the maximum profit earned by buying and selling shares any number of times with the constraint, a new transaction can only start after the previous transaction is complete, i.e., you can only hold at most one share at a time.

Input : [1, 5, 2, 3, 7, 6, 4, 5]
Output: 10
Explanation: Total profit earned is 10

Buy on day 1 and sell on day 2
Buy on day 3 and sell on day 5
Buy on day 7 and sell on day 8


Input : [10, 8, 6, 5, 4, 2]
Output: 0

*/
  
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int findMaxProfit(vector<int> const &price)
	{
		int n = price.size();   //Stores the size of the array
		int profit = 0;         //Stores the total profit
		
	   int i = 0; 
	   int j = 1;
	   
	 
	   while(j < n){  // Loop through the array
	   	   
	      if(price[j] < price[j-1]){  //if the current price is less than the previous, than update i to j
	      	  
	      	  i = j;
	      }
	      
	      
	      // if the current price is greater than previous and the next price or next price is the 
	      // last element of the array, Update the profit.
	      if(price[j] >= price[j-1] && (price[j] > price[j+1] || j+1 == n)){
	      	
	      	    profit += (price[j] - price[i]);
	      }
	      
	      j++;
	   }
	   
	   return profit;        // return the profit
	}
	
};
