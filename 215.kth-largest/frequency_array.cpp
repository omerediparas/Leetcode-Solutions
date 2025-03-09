class Solution {
    public:
    // frequency counting -> O(n)
    // beats %96.68 of users in runtime.
    // we keep track of the frequencies of the array elements.
        int findKthLargest(vector<int>& nums, int k) {
            // find the min max
            int min = *min_element(nums.begin(),nums.end());
            int max = *max_element(nums.begin(),nums.end());
            int size = max - min + 1;
    
            // create the frequency array, initialize with all 0's.
            vector<int> freq(size, 0); // we are initializing with all 0's with this.
            
            // fill the frequency array
            for(int i = 0; i < nums.size(); i++){
                int index = nums[i] - min;
                freq[index]++;
            }
    
            // find the k-th item.
            int sum = 0;
            int j = size - 1; // pointer at the end.
            while(sum < k){
                sum += freq[j];
                j--;
            }
            int final_index = j+1;
            return final_index + min;
        }
    };
    
    
    
    
    
    
    
    
    
    
    
    
    
    