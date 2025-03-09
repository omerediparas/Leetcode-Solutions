class Solution {
    public:
    // randomized partitioning solution,
    // does not work only on the 42th / 42 test, exceeds time limit on leetcode.
    // that test includes majority of 1's and quick select algorithm won't give us the evenly divided split. L-partition leaves right side > pivot, which leads to poor performance O(n^2). Hoare's partitioning algorithm might be better for that case.
        int findKthLargest(vector<int>& nums, int k) {
            int left = 0;
            int right = nums.size() - 1;
    
            while(true){
                // partition the array around the pivot
                int pivot_ix = random_partition(nums, left , right);
                // pivot checks and recursion here.
                if(pivot_ix < nums.size() - k){ // right side
                    left = pivot_ix + 1;
                }
                else if(pivot_ix > nums.size() - k){
                    right = pivot_ix - 1;
                }
                else{ //(pivot_ix == nums.size() - k)
                    return nums[pivot_ix];
                }
            }
        }
        int random_partition(vector<int>& nums, int left, int right){
            int random_ix = left + rand() % (right - left + 1); // Pick random pivot
            swap(nums[random_ix], nums[right]); // Move pivot to end
            return L_partition(nums,left,right);
        }
        // returns the index of the pivot, partitions the array once.
        int L_partition(vector<int>& nums, int left, int right){
            int pivot = nums[right];
    
            int i = left -1;
            int j = left;
    
            while(j < right){ // ending j position
                if(nums[j] <= pivot){
                    swap(nums[i+1], nums[j]);
                    i++;
                }
                j++;
            }
            swap(nums[right],nums[i+1]);
            return i+1;
        }
    };
    
    
    
    
    
    
    
    
    
    
    
    
    
    