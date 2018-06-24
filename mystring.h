#ifndef MYSTRING_H
#define MYSTRING_H
#pragma once

#include <iostream>
using namespace std;

class String
{
    friend ostream& operator<<(ostream& os,const String& str);
    friend istream& operator>>(istream& is,String& str);
public:
    String(const char* str = nullptr); //default construct
    String(const String& str);          //copy construct
    String& operator=(const String& str); // overload copy operator
    ~String();                      //destruct function

    String& operator+=(const String& str); //overload +=
    String operator+(const String& str) const; //overload+
    bool operator==(const String& str) const; //overload ==

    char& operator[](int n) const;

    char* c_str() const; //return C字符串
    size_t size() const; //return 字符串length


    void swap(String rhs); //交换2个对象的私有成员

private:
    char* data; //data纸箱字符串
    size_t length;

};

#endif // MYSTRING_H
