#include <algorithm>>
#include <iostream>
#include <string>

void Reverse(char* pBegin,char* pEnd)
{
    if(pBegin == nullptr || pEnd == nullptr)
        return;



    while(pBegin < pEnd)
    {
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;
        pBegin++;
        pEnd--;
    }


}

char* ReverseSentence(char* pData)
{
    if(pData == nullptr)
        return nullptr;
    char* pBegin = pData;
    char* pEnd = pData;
    while(*pEnd != '\0')
        ++pEnd;

    --pEnd;
    Reverse(pBegin,pEnd);

    pBegin = pEnd = pData;
    while(*pBegin != '\0')
    {
        if(*pBegin == ' ')
        {
            ++pBegin;
            ++pEnd;
        }
        else if(*pEnd == ' ' || *pEnd == '\0')
        {
            Reverse(pBegin,--pEnd);
            pBegin = ++pEnd;
        }
        else
            ++pEnd;
    }

    return pData;
}


int main() {
    string words;
    while (getline(cin, words)) {
        reverse(words.begin(), words.end()); //reverse()STL算法
        unsigned i = 0, j = i;
        while (i < words.size()) {
            while (i < words.size() && words[i] != ' ') // words[i]不能解引用,i = words.size()
                ++i;
            reverse(words.begin() + j, words.begin() + i);
            j = ++i;
        }
        cout << words << endl;
    }
    return 0;
}
