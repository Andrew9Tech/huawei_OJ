class Solution:
    def fun(self, F):
        result = 0; flag = 0
        if F < 0: result = F - 0.5
        else: result = F + 0.5
        return int(result)
    
if __name__ == "__main__":
    F = input("input string:")
    result = Solution().fun(F)
    print result
