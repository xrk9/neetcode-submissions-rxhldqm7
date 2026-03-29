class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int vol = (r-l)*min(heights[r], heights[l]);
        while(r>l){
                int voln = (r-l)*min(heights[r],heights[l]);
                if(voln > vol) vol = voln;
                if(heights[r]>heights[l]){
                    ++l;
                }else{
                    --r;
                }
        }
        return vol;
    }
};
