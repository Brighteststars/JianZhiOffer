#include "mystring.h"


ostream& operator<<(ostream &os, const String &str)
{
    return os << str.data;
}

istream &operator>>(istream &is, String &str)
{
    char tem[1000];
    is >> tem;

    char* orign = str.data;

    str.length = strlen(tem);
    str.data = new char[str.length +1];
    strcpy(str.data,tem);

    delete []orign;

    return is;


}

String::String(const char *str)
{
    if(!str)
    {
        data = new char[1];
        *data = '\0';
        length = 0;
    }
    else{
        length = strlen(str);
        data = new char[length +1];
        strcpy(data,str);
    }


}

String::String(const String &str)
{
    length = str.size();
    data = new char[length + 1];
    strcpy(data,str.c_str());
}

void String::swap(String rhs)
{
    char* ret = data;
    ret = rhs.data;
    rhs.data = ret;

    size_t len = length;
    length = rhs.length;
    rhs.length = len;
}

String &String::operator=(const String &str)
{

    String ret(str);
    swap(ret);
    return *this;

}

String::~String()
{
    delete []data;
    length = 0;
}

String &String::operator+=(const String &str)
{
    length += str.size();
    char* newData = new char[length+1];
    strcpy(newData,data);
    strcat(newData,str.c_str());
    delete []data;
    data = newData;
    return *this;

}

String String::operator+(const String &str) const
{
    String newStr;
    newStr.length += str.size() + length;
    newStr.data = new char[newStr.length + 1];
    strcpy(newStr.data,data);
    strcat(newStr.data,str.c_str());

    return newStr;
}

bool String::operator==(const String &str) const
{
    if(length != str.size())
        return false;
    else{
        return strcmp(data,str.c_str()) ? false : true;
    }
}

char &String::operator[](int n) const
{
    if(n >= (int)length)
        return data[length-1]; //处理n溢出
    else
        return data[n];
}

inline char *String::c_str() const
{
    return data;
}

inline size_t String::size() const
{
    return length;
}


