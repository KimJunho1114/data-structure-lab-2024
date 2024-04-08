#include "Complex.h"
void Complex::readComplex(char* msg) {
	printf("%s", msg);
	scanf("%1f%1f", &real, &imag);
}
void Complex::printComplex(char* msg) {
	printf("%s %4.2f + %4.2fi/n", msg, real, imag);
}
void Complex::readComplex(Complex a, Complex b) {
	real = a.real + b.real;
	imag = a.imag + b.imag;
}