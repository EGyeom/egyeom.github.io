#include <iostream>

class MyString
{
private:
    char * str;
    int len;
    int mem;

public:
    MyString(char s);
    MyString(int rev);
    MyString(const char* s);
    MyString(const MyString& s);
    ~MyString();

    int length(void) const;
    int capacity(void) const;
    
    void reserve(int rev);
    
    char& at(int idx);
    
    MyString append(const MyString& s);
    MyString append(const char * s);
    
    void erase(int start, int end = -1);
    
    void assign(const MyString& s);
    void assign(const char * s);
    
    bool find(const MyString& s);
    bool find(const char *s);

    int compare(const MyString& s);

    bool operator==(const MyString& s);
    bool operator!=(const MyString& s);
    bool operator<(const MyString& s);
    bool operator<=(const MyString& s);
    bool operator>(const MyString& s);
    bool operator>=(const MyString& s);

    MyString operator+(const MyString& s);
    MyString& operator=(const MyString& s);
    friend std::ostream& operator<<(std::ostream& os,const MyString& s);
};

std::ostream& operator<<(std::ostream& os,const MyString& s)
{
   os << s.str;
   return os;
}

MyString::MyString(char s) : len(1), mem(2)
{
    str = new char[2];
    str[0] = s;
    str[1] = '\0';
}

MyString::MyString(int rev) : mem(rev) 
{
    str = new char[mem];
}

MyString::MyString(const char * s)
{
    int count =0;
    while(s[count] != '\0')
    {
        count++;
    }
    len = count;
    mem = count+1;
    str = new char[mem];
    for(int i =0; i < len; i++)
    {
        str[i] = s[i];
    }
    str[len] = '\0';
}

MyString::MyString(const MyString& s) : len(s.len), mem(s.mem)
{
    str = new char[mem];
    for(int i =0; i < mem; i++)
    {
        str[i] = s.str[i];
    }
}

MyString::~MyString()
{
    delete[] str;
}

MyString MyString::operator+(const MyString& s)
{
    MyString temp(*this);
    temp.append(s);
    return temp;
}



MyString& MyString::operator=(const MyString& s)
{
    len = s.len;
    if(mem < s.mem)
    {
        mem = s.mem;
        delete[] str;
        str = new char[mem];
    }

    for(int i =0; i < mem; i++)
    {
        this->str[i] = s.str[i];
    }
    return *this;
}


MyString MyString::append(const MyString& s)
{
    this->append(s.str);
    return *this;
}

MyString MyString::append(const char * s)
{
    int count =0;
    while(s[count] != '\0')
    {
        count++;
    }
    if(mem <= len + count)
    {
        reserve(len+count+1);
    }   

    for(int i =0; i < count; i++)
    {
        str[len+i] = s[i];
    }
    len = len + count;
    str[len] = '\0';

    return *this;
}

int MyString::length(void) const
{
    return len;
}


int MyString::capacity(void) const
{
    return mem;
}

void MyString::reserve(int rev)
{
    if(rev == mem)
    {
        return;
    }
    MyString temp(str);
    delete[] str;
    mem = rev;
    str = new char[mem];
    for(int i =0; i <len; i++)
    {
        str[i] = temp.str[i];
    }
}

char& MyString::at(int idx)
{
    return str[idx];
}

void MyString::erase(int start , int end /* = -1 */)
{
    if(start >= len)
    {
        return;
    }

    if(end == -1)
    {
        end = len;
    }
    
    int index =0;
    for(int i =0; i <= len ;i++)
    {
        if( i >= start && i < end)
        {
            continue;
        }
        str[index++] = str[i];
    }
    for(int i = index+1; i <=len; i++)
    {
        str[i] = 0;
    }
    len = index-1;
}

void MyString::assign(const MyString& s)
{
    assign(s.str);
}

void MyString::assign(const char * s)
{
    int count =0;
    while(s[count] != '\0')
    {
        count++;
    }
    if(mem <= count)
    {
        mem = count+1;
        reserve(mem);
    }

    len = count;
    
    for(int i =0; i <= count; i++)
    {
        str[i] = s[i];
    }
}

bool MyString::find(const MyString& s)
{
    return find(s.str);
}
bool MyString::find(const char *s)
{
    int count = 0;
    bool isfind = true;
    while(s[count] != '\0')
    {
        count++;
    }

    for(int i =0; i < len; i++)
    {
        if(str[i] == s[0])
        {
            for(int j =0; j <count; j++)
            {
                if(str[i+j] == s[j])
                {
                    continue;
                }
                else
                {
                    i = i + j;
                    isfind =false;
                    break;
                }
            }
            if(isfind)
            {
                return 1;
            }
        }
    }
    return 0;

}
int  MyString::compare(const MyString& s)
{
    int min = (len < s.len) ? len : s.len;
    for(int i =0; i < len; i++)
    {
        if(str[i] < s.str[i])
        {
            return -1;
        }
        else if(str[i] > s.str[i])
        {
            return 1;
        }
    }
    if(len == s.len) return 0;
    else if( min == len) return -1;
    else return 1;
}
bool MyString::operator==(const MyString& s)
{
    return (compare(s) == 0);
}
bool MyString::operator!=(const MyString& s)
{
    return (compare(s) != 0);
}
bool MyString::operator<(const MyString& s)
{
    return compare(s) == -1;
}
bool MyString::operator<=(const MyString& s)
{
    return compare(s) <= 0;
}
bool MyString::operator>(const MyString& s)
{
    return compare(s) == 1;
}
bool MyString::operator>=(const MyString& s)
{
    return compare(s) >= 0;
}

int main()
{
    MyString str1('1');
    MyString str2("Hello");
    MyString str3("Wolrd");
    MyString str4(30);
    str2.append(" World");
    str4.assign("Hello hello4");
    std::cout << (str4 <= str2) << "\n";
    // std::cout << str2 << "\n";
    // std::cout << str4 << "\n";
    // str4.erase(5);
    // std::cout << str4 << "\n";
    std::cout << str4.find("hello") << "\n";
}