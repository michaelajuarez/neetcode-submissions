class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hold = {}
        retArr = []
        for x in strs:
            cur = sorted(x)
            cur = ''.join(cur)
            if cur not in hold:
                hold[cur] = [x]
            else:
                hold[cur].append(x)
        for k, v in hold.items():
            retArr.append(v)
        return retArr