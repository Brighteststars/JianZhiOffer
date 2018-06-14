int Partition(int data[],int length,int start,int end)
{
    if(data == nullptr || length <= 0 || start < 0 || end >= length)
         throw new std::exception("Invalid Parameters");
    swap(data[start],data[start + rand()%(end - start + 1)]);
    int pivot = data[start];
    int mi = start;
    for(int k = start + 1;k <= end;k++)
    {
        if(data[k] < pivot)
            swap(data[++mi],data[k]);
    }
    swap(data[start],data[mi]);
    return mi;
}

//void QuickSort(int data[],int length,int start,int end)
//{
//    if(start == end)
//        return;
//    int index = Partition(data,length,start,end);
//    if(index > start)
//        QuickSort(data,length,start,end - 1);
//    if(index < end)
//        QuickSort(data,length,start+1,end);
//}

bool inputInvalid = false;

bool CheckInvalidArray(int* numbers,int length)
{
    inputInvalid = false;
    if(numbers == nullptr || length <= 0)
    {
        inputInvalid = true;
    }
    return inputInvalid;
}

bool CheckMoreThanHalf(int* numbers,int length,int number)
{
    int times = 0;
    for(int i = 0;i < length;i++)
    {
        if(numbers[i] == number)
            ++times;

    }

    bool isMoreThanHalf = true;
    if(times*2 <= length)
    {
        isMoreThanHalf = false;
        inputInvalid = true;
    }

    return isMoreThanHalf;
}

int MoreThanHalfNum(int* numbers,int length)
{
    if(CheckInvalidArray(numbers,length))
        return 0;

    int start = 0;
    int end = length -1;
    int middle = (start + end)/2;
    int index = Partition(numbers,length,start,end);
    while(index != middle)
    {
        if(index > middle)
        {
            end = index - 1;
            index = Partition(numbers,length,start,end);
        }
        else{
            start = index +1;
            index = Partition(numbers,length,start,end);
        }
    }

    int result = numbers[middle];

    if(!CheckMoreThanHalf(numbers,length,result))
        result = 0;

    return result;
}

void main()
{
    int data[] = {2,2,2,2,2,3,4,9};
    vector<int> ret(begin(data),end(data));
    int len = ret.size();

   cout << MoreThanHalfNum(data,len) << endl;




    return;
}
