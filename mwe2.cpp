// this is a question at Bilkent CS473 Algorithms Course, midweek exam question3 (40 points)

#include <iostream>
#include <vector>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For seeding random generator
#include <cmath>  // Include this for sqrt

// given an array of perfect square, find the elements appearing exactly sqrt(n) times.
using namespace std;


// returns the index of the first occurence of the element with the given index
// log_sqrt (n)
int findFirstOccurence(vector<int>& nums, int index){
    int element = nums[index];
    int sqrt_n = sqrt(nums.size());
   
    int start = index - sqrt_n;
    if(start < 0){ // *
        start = 0;
    }
    int end = index - 1;

    int first_occurence = index;
    while(start <= end){
        int i = (start + end) / 2;
        if(nums[i] == element) {// if the beginning is on the left side
            end = i-1;
            first_occurence = i;
        }
        else{
            start = i+1;// if the beginning is on the right side
        }
    }
    return first_occurence;
}
// returns the index of the first occurence of the element with the given index
// log_sqrt (n)
int findLastOccurence(vector<int>& nums, int index){
    int element = nums[index];
    int sqrt_n = sqrt(nums.size());
   
    int start = index;
    int end = index + sqrt_n;

    int last_occurence = index;
    while(start <= end){
        int i = (start + end) / 2;
        if(nums[i] == element) {// if the beginning is on the left side
            start = i+1;
            last_occurence = i;
        }
        else{
            end = i-1;// if the beginning is on the right side
        }
    }
    return last_occurence;
}

vector<int> func(vector <int>& nums){
    int n = nums.size();
    int sqrt_n = sqrt(n);
    vector<int> desired;
    for(int i = 0; i < sqrt_n; i++){
        int val1 = findFirstOccurence(nums,i * sqrt_n);
        int val2 = findLastOccurence(nums,i * sqrt_n);
        if(val2-val1+1 == sqrt_n){
            desired.push_back(nums[i * sqrt_n]);
        }
        //cout << nums[i * sqrt_n] << "val2:" << val2 << endl;
        //cout << nums[i * sqrt_n] << "val1:" << val1 << endl;
    }
    return desired;
} 

int main() {
    vector<int> randomVec = {2,2,2,2,3,3,4,4,4,6,9,9,9,9,14,19};

    vector<int> randomVec2 = {2,2,2,2,3,3,4,4,4,6,9,9,9,14,19,20,20,20,20,20,21,21,21,21,21,};

    // Print first 10 elfor verification
    cout << "First 10 elements of the random vector: ";
    for (int i = 0; i < randomVec.size(); i++) {
        cout << randomVec[i] << " ";
    }
    cout << endl;
    
    cout << "sqrt-Repeated elements of the random vector: ";
    vector<int> nums = func(randomVec);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

