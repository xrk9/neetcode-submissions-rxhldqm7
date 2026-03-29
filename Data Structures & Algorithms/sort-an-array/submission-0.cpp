class Solution {
    private:
        int partition(vector<int>& nums, int l, int r){
            int pivot = nums[l+(r-l)/2];
            int i = l - 1;
            int j = r + 1;
            while(1){
                do{
                    i++;
                }while(nums[i] < pivot);

                do{
                    j--;
                }while(nums[j] > pivot);

                if(i>=j) return j;

                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }

        void quickSort(vector<int>& nums, int l, int r){
            if(r<=l) return;
            int middle = partition(nums,l,r);
            quickSort(nums, l,middle);
            quickSort(nums, middle+1, r);
        }
    public:
        vector<int> sortArray(vector<int>& nums) {
            quickSort(nums,0,nums.size()-1);
            return nums;
        }
};