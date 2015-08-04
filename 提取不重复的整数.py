class Solution:
    def fun(self, List):
        Dict = {}; res = ''
        for item in List:
            if item not in Dict:    Dict.setdefault(item,1)
            else:   Dict[item] += 1
        for i in range(len(List) - 1, -1, -1):
            if Dict[List[i]] > 0:
                res += List[i]
                Dict[List[i]] = 0
        return int(res)

if __name__ == "__main__":
    List = str(input())
    result = Solution().fun(List)
    print result
