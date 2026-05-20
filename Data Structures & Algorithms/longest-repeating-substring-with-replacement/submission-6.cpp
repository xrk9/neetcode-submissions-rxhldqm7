class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if (n <= k+1) return n;

        // Since s only contains uppercase English letters,
        // using a flat array of 26 integers to store count
        int charCounts[26] = {0}; 
        
        int maxLength = k+1; // It's the min length we can have trivially
        int maxFrequency = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            int currentChar = s[right] - 'A'; 
            charCounts[currentChar]++; 
            
            maxFrequency = max(maxFrequency, charCounts[currentChar]);

            int currentWindowLength = right - left + 1;

            // If changes needed > k, shift the whole window right
            if (currentWindowLength - maxFrequency > k) {
                charCounts[s[left] - 'A']--;
                left++;
            } else {
                maxLength = max(maxLength, right - left + 1);
            }
        }
        return maxLength;
    }
};