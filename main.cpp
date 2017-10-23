#include <iostream>
using namespace std;
struct complex_t {
    float real;
    float imag;
};
complex_t add(complex_t rhs,complex_t lhs){
complex_t result;
    result.real=rhs.real+lhs.real;
    result.imag=rhs.imag+lhs.imag;
    return result;
}
complex_t sub(complex_t rhs,complex_t lhs){
    complex_t result;
    result.real=rhs.real-lhs.real;
    result.imag=rhs.imag-lhs.imag;
    return result;
}
complex_t mul(complex_t rhs,complex_t lhs){
    complex_t result;
    result.real=rhs.real*lhs.real-rhs.imag*lhs.imag;
    result.imag=rhs.imag*lhs.real+rhs.real*lhs.imag;
    return result;
}
complex_t div(complex_t rhs,complex_t lhs){
  complex_t result;
    result.real=(rhs.real*lhs.real+rhs.imag*lhs.imag)/(lhs.real*lhs.real+lhs.imag*lhs.imag);
    result.imag=(rhs.imag*lhs.real-rhs.real*lhs.imag)/(lhs.real*lhs.real+lhs.imag*lhs.imag);
    return result;
}
std::istream & read( std::istream & stream, complex_t & complex ){
    char f1,f2,f3;
    float real;
    float imag;
    if (stream>>f1 && f1=='(' && stream>>real && stream>>f2 && f2 == ',' && stream>>imag && stream>> f3 && f3 == ')') {
        complex.real = real;
        complex.imag = imag;
    }
    else {
        stream.setstate(std::ios::failbit);
    }

    return stream;
}
std::ostream & write( std::ostream & stream, complex_t complex ){
      stream<<"("<<complex.real<<","<<complex.imag<<")";
    return stream;
}
int main() {
    char op;
    complex_t comp1,comp2;

    if(read(cin,comp1)&&(cin>>op)&&read(cin,comp2)){
    switch(op){
        case '+':
            write(cout,add(comp1,comp2));
            break;
        case '-':
            write(cout,sub(comp1,comp2));
            break;
        case '*':
            write(cout,mul(comp1,comp2));
            break;
        case '/':
            write(cout,div(comp1,comp2));

            break;
        default: cout<<"\nAn error has occured while reading input data"; break;
    }}else{  cout<<"\nAn error has occured while reading input data";}
    return 0;
}
