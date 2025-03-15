// this is a question at Bilkent CS473 Algorithms Course, midweek exam question3 (40 points)

#include <vector>

// given an array of perfect square, find the elements appearing exactly sqrt(n) times.

vector<int> func(vector <int>& nums){
    int n = nums.size();
    int sqrt = sqrt(n);
    vector<int> desired;
    for(int i = 0; i < sqrt; i++){
        int val1 = findFirstOccurence(nums,i * sqrt);
        int val2 = findLastOccurence(nums,i * sqrt);
        if(val2-val1+1 == sqrt){
            desired.push_back(nums[i * sqrt]);
        }
    }
    return desired;
} 
// returns the index of the first occurence of the element with the given index
// log_sqrt (n)
int findFirstOccurence(vector<int>& nums, int index){
    int element = nums[index];
    int sqrt = sqrt(nums.size());
   
    int start = index - sqrt;
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
    int sqrt = sqrt(nums.size());
   
    int start = index;
    int end = index - sqrt;

    int last_occurence = index;
    while(start <= end){
        int i = (start + end) / 2;
        if(nums[i] == element) {// if the beginning is on the left side
            start = i+1
            last_occurence = i;
        }
        else{
            end = i-1;// if the beginning is on the right side
        }
    }
    return last_occurence;
}


int main(){
    
}