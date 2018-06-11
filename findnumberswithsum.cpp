//题目描述
//输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
//输出描述:
//对应每个测试案例，输出两个数，小的先输出。



class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    vector<int> res;
        int len = array.size();
        if(len < 2)
            return res;
        int start = 0, end = len - 1;
        int Sum = 0;
        while(start < end)
        {
            Sum = array[start] + array[end];
            if(Sum > sum)
                --end;
            else if(Sum < sum)
                ++start;
            else{
                res.push_back(array[start]);
                res.push_back(array[end]);
                break;
            }
        }
        return res;
    }
};
