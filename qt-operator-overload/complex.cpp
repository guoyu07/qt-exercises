#include "complex.h"

Complex::Complex(double re, double im) : re(re), im(im) {}

Complex& Complex::operator+=(const Complex& c) {
    re += c.re;
    im += c.im;
    return *this;
}

Complex& Complex::operator-=(const Complex& c) {
    re -= c.re;
    im -= c.im;
    return *this;
}

ostream& operator<<(ostream& out, const Complex& c) {
    out << '(' << c.re << ',' << c.im << ')' ;
    return out;
}

Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1.re + c2.re, c1.im + c2.im);
}

Complex operator-(const Complex& c1, const Complex& c2) {
    return Complex(c1.re - c2.re, c1.im - c2.im);
}

Complex operator*(const Complex& c1, const Complex& c2) {
    return Complex(c1.re * c2.re - c1.im * c2.im, c1.im * c2.re + c1.re * c2.im);
}

Complex operator/(const Complex& c1, const Complex& c2) {
    return Complex((c1.re * c2.re + c1.im * c2.im) / (c2.re * c2.re + c2.im * c2.im),
                   (c1.im * c2.re - c1.re * c2.im) / (c2.re * c2.re + c2.im * c2.im));
}
