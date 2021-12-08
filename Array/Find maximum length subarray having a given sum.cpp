#include<bits/stdc++.h>
using namespace std;
 
 vector<int> findMaxLenSubarray(vector<int> const &nums, int target){
         
        // stores the maximum subarray having given length
      vector<int> v;
     
      unordered_map<int, int> m;
      
      m.insert({0, -1})
       // stores the maximum subarray length
       

       int max_len = 0;

       //stores the current sum of elements
       int sum = 0;

       // stores the ending index of maximum subarray found so far
        int end = -1;

         // traverse the array
      for(int i=0; i<nums.size(); i++){
         
          sum += nums[i];
          // if the sum is not found, insert the sum and index number
          if(m.find(sum)==m.end()){
              m[sum] = i;
          }
       
         // if the length of subarray have the given sum is greater than the max_len
         // update the max_len and last index of curr maximum subarray

          if(m.find(sum - target) != m.end() && max_len < i - m[sum - target]){
              max_len = i - m[sum - target];
              end = i;
          }
      }

      // insert the maximum subarray in vector
      for(int i=(end - max_len)+1; i<=end; i++){
          v.push_back(nums[i]);
      }

      // return the vector
      return v;

  }

int main(){
    
    /* input the size of array and sum */

    int n, target;
    cin >> n >> target;

    /* input the array elements */

     vector<int> nums(n);

     for(int i=0; i<n; i++){
        cin >> nums[i];
     }
   
   /* Call a function which returns the maximum length of subarray having given sum */

    vector<int> ans = findMaxLenSubarray(nums, target);
 
    /* Print the subarray */

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

    cout << endl;



}