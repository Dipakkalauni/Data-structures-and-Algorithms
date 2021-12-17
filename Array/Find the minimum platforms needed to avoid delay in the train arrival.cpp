/*

Given a schedule containing the arrival and departure time of trains in a station, find the minimum number of platforms needed to avoid delay in any train’s arrival.

Input:

arrival = [2.00, 2.10, 3.00, 3.20, 3.50, 5.00]
departure = [2.30, 3.40, 3.20, 4.30, 4.00, 5.20]

Output: 2

Explanation: The minimum platforms needed is 2

The train arrived at 2.00 on platform 1
The train arrived at 2.10 on platform 2
The train departed at 2.30 from platform 1
The train arrived at 3.00 on platform 1
The train departed at 3.20 from platform 1
The train arrived at 3.20 on platform 1
The train departed at 3.40 from platform 2
The train arrived at 3.50 on platform 2
The train departed at 4.00 from platform 2
The train departed at 4.30 from platform 1
The train arrived at 5.00 on platform 1
The train departed at 5.20 from platform 1

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int findMinPlatforms(vector<double> arrival, vector<double> departure)
	{
	   sort(arrival.begin(), arrival.end());       //Sort the arrival array
	   sort(departure.begin(), departure.end());   // sort the departure array
	   
	   int count = 0;                    // stores the numbers of train in the platform at any given time
	   int max_count = 0;                // Stores the maximum number of train int he platform
	   
	   int i = 0;                       // used to loop through arrival array
	   int j = 0;                      // used to loop through departure array
	   
	   while(i < arrival.size()){   
	   	  
	   	   if(arrival[i] < departure[j]){  // if arrival time < departure time 
	   	   	                               // increase the count of train arrival
	   	   	 count++;                      // and go to the next arrival time
	   	   	  i++;
	   	   	  
	   	   	   if(count > max_count){     // compare max_count and count and update max_count
	   	   	
	   	     	max_count = count;
	   	      }
	   	   
	   	   }else{             // else decrease count and go to the next departure time
	   	   	  
	   	   	  count--;
	   	   	   j++;
	   	   }
	   	   
	   	  
	   }
	   
	   return max_count;      // return max_count
	}
};