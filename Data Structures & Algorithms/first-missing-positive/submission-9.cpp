class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n = (int)nums.size();

        // Evict invalid values
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] <= 0)
            {
                nums[i] = n + 1;
            }
        }

        // Negative mark positions (overwriting values with negative indices)
        for (int i = 0; i < n; ++i)
        {
            int index = std::abs(nums[i]);
            if (index <= n && nums[index - 1] > 0)
            {
                nums[index - 1] *= -1;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0)
            {
                return i + 1;
            }
        }

        return n + 1;
    }
};