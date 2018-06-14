#include <vector>
#include <algorithm>


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

void QuickSort(int data[],int length,int start,int end)
{
    if(start == end)
        return;
    int index = Partition(data,length,start,end);
    if(index > start)
        QuickSort(data,length,start,end - 1);
    if(index < end)
        QuickSort(data,length,start+1,end);
}

void main()
{
    int data[] = {1,2,4,6,4,3,4,9};
    vector<int> ret(begin(data),end(data));
    for_each(ret.begin(),ret.end(),[](const int &num){cout << num << " ";});
    cout << endl;

    int len = ret.size();
    QuickSort(data,len,0,len-1);

    vector<int> result(begin(data),end(data));
    for_each(result.begin(),result.end(),[](const int &num){cout << num << " ";});
    cout << endl;







    return;
}
