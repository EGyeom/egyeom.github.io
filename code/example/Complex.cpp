#include <iostream>

class Complex
{
private:
    double _real;
    double _img;
    /* data */
public:
    Complex(double real, double img) : _real(real), _img(img) {}
    Complex(const Complex& c) : _real(c._real), _img(c._real) {}
    ~Complex();
    Complex& operator=(const Complex& c);

    friend Complex operator+(const Complex& a,const Complex& b);
    friend Complex operator-(const Complex& a,const Complex& b);
    friend Complex operator*(const Complex& a,const Complex& b);
    friend Complex operator/(const Complex& a,const Complex& b);
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);


};


Complex::~Complex()
{
}

Complex& Complex::operator=(const Complex& c)
{
    _real = c._real;
    _img = c._img;
}

Complex operator+(const Complex& a,const Complex& b)
{
    Complex temp(a._real + b._real, a._img + b._img);
    return temp;
}
Complex operator-(const Complex& a,const Complex& b)
{
    Complex temp(a._real - b._real, a._img - b._img);
    return temp;
}
Complex operator*(const Complex& a,const Complex& b)
{
    Complex temp((a._real * b._real) + (a._img * b._img), (a._img * b._real) + (a._real * b._img));
    return temp;
}
Complex operator/(const Complex& a,const Complex& b)
{
    Complex temp((a._real * b._real + a._img * b._img)/(b._real * b._real + b._img * b._img),(a._real * -b._img + a._img * b._real)/(b._real * b._real + b._img * b._img));
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
    os << "(" << c._real << " , " <<  c._img <<"i"<< ")";
    return os;
}

int main()
{
    Complex a(3,5);
    Complex b(2,4);
    Complex c = a*b;

    std::cout << c << "\n";
}