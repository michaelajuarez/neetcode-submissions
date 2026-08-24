class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        retVal = 0
        hold = set(s)

        for x in hold:
            count = 0
            front = 0
            for back in range(len(s)):
                if s[back] == x:
                    count += 1
                
                while (back - front + 1) - count > k:
                    if s[front] == x:
                        count -= 1
                    front += 1
                retVal = max(retVal, back-front+1)

        return retVal
