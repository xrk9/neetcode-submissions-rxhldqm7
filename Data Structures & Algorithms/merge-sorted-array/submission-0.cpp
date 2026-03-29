class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int arr[m];
        for(int i = 0; i<m; i++){
            arr[i] = nums1[i];
        }
        int i = 0, j = 0, k = 0;
        while(i<m && j<n){
            nums1[k++] = ( (arr[i] < nums2[j]) ? arr[i++] : nums2[j++] );
        }
        while(i<m){
            nums1[k++] = arr[i++];
        }
        while(j<n){
            nums1[k++] = nums2[j++];
        }
    }
};