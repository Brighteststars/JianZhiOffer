class Solution {
public:
    //如果*(pattern+1) == '*' && pattern 和 str第一个字符相等,有三种情况
    //直接匹配下一个 || 保持原状态 || 忽略'*'

    bool match(char* str, char* pattern)
    {
        if(str == nullptr || pattern == nullptr)
            return false;
        if(*str == '\0' && *pattern == '\0')
            return true;
        if(*str != '\0' && *pattern == '\0')
            return false;
        if(*(pattern+1) == '*')
        {
            if(*pattern == *str || (*pattern == '.' && *str != '\0'))
                return match(str+1,pattern +2) || match(str+1,pattern) || match(str,pattern+2);
            else
                return match(str,pattern+2); //忽略‘*’
        }
        if(*pattern == *str || (*pattern == '.' && *str != '\0'))
            return match(str+1,pattern+1);
        return false;
    }


};
