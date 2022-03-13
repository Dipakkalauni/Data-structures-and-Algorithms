/*

Suppose we are given n red and n blue water jugs, all of different shapes and sizes.
 All red jugs hold different amounts of water, as do the blue ones. Moreover, there is a blue jug for 
 every red jug that holds the same amount of water and vice versa. 
The task is to efficiently group the jugs into pairs of red and blue jugs that hold the same amount of water

*/

#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int start, int end, int chosen){

    int pIndex = start;

    for(int j=start; j < end; j++){

        if(arr[j] < chosen){
            swap(arr[pIndex], arr[j]);
            pIndex++;
        }else if(arr[j] == chosen){
            swap(arr[j], arr[end]);
            j--;
        }
    }
  
   swap(arr[pIndex], arr[end]);

   return pIndex;

}


void quicksort(vector<int> &red, vector<int> &blue, int start, int end){

    while(end <= start){
        return;
    }

    int r = rand() % (end - start + 1) + start;
    int chosen = red[r];

    int pivot = partition(red, start, end, chosen);
        
        partition(blue, start, end, chosen);

    quicksort(red, blue, start, pivot-1);
    quicksort(red, blue, pivot+1, end);

}



void print_array(vector<int> &arr, int n){

    for(int i=0; i<n; i++){

        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    vector<int> red = {2, 4, 3, 6, 5 ,1};

    vector<int> blue = {1, 3, 4, 5, 6, 2};
     
     int n = red.size();
     int m = blue.size();

     quicksort(red, blue, 0, n-1);

    print_array(red,  n);
    print_array(blue, m);
}