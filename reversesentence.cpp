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
        reverse(words.begin(), words.end()); // reverse()STL算法
        unsigned b = 0, e = b;
        while (b < words.size()) {
           if(words[b] == ' ')
           {
               ++b,++e;
           }
           else if( ( e < words.size() && words[e] == ' ') || e == words.size())
           {
               reverse(words.begin()+b,words.begin()+e);
               b = e;
           }
           else
               e++;
        }
        cout << words << endl;
    }
    return 0;
}
