class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        retVar = 0
        for x in nums:
            retVar ^= x

        return retVar