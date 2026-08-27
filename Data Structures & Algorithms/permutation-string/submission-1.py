class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        char_s1 = [0] * 26
        char_s2 = [0] * 26

        for x in s1:
            char = ord(x) - ord('a')
            char_s1[char] += 1

        window = len(s1)
        front = 0
        for back in range(len(s2)):
            cur = ord(s2[back]) - ord('a')
            char_s2[cur] += 1
            if (back - front) >= window:
                cur_front = ord(s2[front]) - ord('a')
                char_s2[cur_front] -= 1
                front += 1
            if char_s1 == char_s2:
                return True

        return False
            
