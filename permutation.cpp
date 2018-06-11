void Permutation( string &pBegin, int n, vector<string> &res)//n为下标值
{
    int size = pBegin.size();
    if (n == size)
        res.push_back(pBegin);//如果下标值等于字符串的长度，输出字符串
    else
    {
        for (int i = n; i < pBegin.size(); i++)
        {
            char temp = pBegin[i];
            pBegin[i] = pBegin[n];
            pBegin[n] = temp;
            Permutation(pBegin, n + 1, res);//移动下标
            temp = pBegin[i];
            pBegin[i] = pBegin[n];
            pBegin[n] = temp;
        }
    }
}
vector<string> Permutation(string pStr)
{
    vector<string> res;
    if (pStr.size() == 0)
        return res;
    Permutation(pStr, 0, res);
    sort(res.begin(), res.end());//使用unique的使用，要先排序
    res.erase(unique(res.begin(), res.end()), res.end());//unique去重
    //unique()函数将重复的元素放到vector的尾部 然后返回指向第一个重复元素的迭代器 再用erase函数擦除从这个元素到最后元素的所有的元素
    return res;
}
void main()
{
    char str[] = "aab";
    vector<string> res = Permutation(str);
    return;
}
