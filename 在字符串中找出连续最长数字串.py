class Solution:
    def fun(self, List):
        temp_res = ''; res = ''
        temp_num = 0; num = 0
        shuzi = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
        for i in range(1, len(List)):
            if List[i] in shuzi:
                temp_res += List[i]
                if List[i - 1]: temp_num += 1
            else:
                if temp_num > num:
                    res = temp_res
                    num = temp_num
                temp_res = ''; temp_num = 0
        if temp_num > num:
                res = temp_res
                num = temp_num
        print res,',',num
        return
    
if __name__ == "__main__":
    List = str(raw_input("input string:"))
    result = Solution().fun(List)
