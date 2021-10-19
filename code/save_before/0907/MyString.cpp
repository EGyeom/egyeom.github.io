
#include <iostream>
#include <cstdio>
class MyString{
    char * string;
    int length;
    int memory_capacity;
public:
    MyString(char c);
    MyString(const char * c);
    MyString(MyString &str);
    void ShowString();
};

MyString::MyString(char c)
{

}

MyString::MyString(const char * c)
{
    length = 0;
    while(c[length] != '\0')
    {
        length++;
    }
    string = new char[length+1];

    for(int i =0; i <= length; i++)
    {
        string[i] = c[i];
    }
}

MyString::MyString(MyString &str)
{
    length = str.length;
    string = new char[length+1];
    for(int i =0; i <= length; i++)
    {
        string[i] = str.string[i];
    }
}


void MyString::ShowString()
{
    printf("%s\n", string);
}

int main()
{
    MyString str(MyString("hello"));
    str.ShowString();   
}