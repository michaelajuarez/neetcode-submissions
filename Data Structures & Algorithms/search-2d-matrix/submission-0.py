class Solution:
    def search(self, arr, target):
        front = 0
        back = len(arr) - 1
        # print(arr)
        # return False
        while front <= back:
            mid = front + (back - front) // 2
            if arr[mid] < target:
                front = mid + 1
            elif arr[mid] > target:
                back = mid - 1
            else:
                return True
        return False


    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        front = 0
        back = len(matrix) - 1
        retVal = False

        while front <= back:
            mid = front + (back - front) // 2
            if matrix[mid][-1] < target:
                front = mid + 1
            elif matrix[mid][0] > target:
                back = mid - 1
            else:
                retVal = self.search(matrix[mid], target)
                return retVal

        return retVal
        