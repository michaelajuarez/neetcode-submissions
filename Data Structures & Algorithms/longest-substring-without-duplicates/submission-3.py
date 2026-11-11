class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        chars = {}
        front = 0
        substring = 0
        for back in range(len(s)):
            chars[s[back]] = chars.get(s[back], 0) + 1
            while front <= back and chars[s[back]] > 1:
                chars[s[front]] -= 1
                front += 1
            substring = max(substring, back - front + 1)
        return substring