class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int left = (n+m+1)>>1;
        int l = 0, r = n-1;
        while(true){
            int i1 = (l + r)>>1, i2 = (left - i1 - 2);
            int c1 = i1 < 0 ? INT_MIN : (i1 >= n ? INT_MAX : nums1[i1]);
            int c2 = i2 < 0 ? INT_MIN : (i2 >= m ? INT_MAX : nums2[i2]);
            int n1 = ++i1 < 0 ? INT_MIN : (i1 >= n ? INT_MAX : nums1[i1]);
            int n2 = ++i2 < 0 ? INT_MIN : (i2 >= m ? INT_MAX : nums2[i2]);
            i1--;i2--;
            if(c1 > n2){
                r = i1 - 1;
            }else if(c2 > n1){
                l = i1 + 1;
            }else{
                if( (n+m)&1 ) return max(c1,c2);
                else return (max(c1,c2) + min(n1,n2))/2.0f;
            }
        }
    }
};
