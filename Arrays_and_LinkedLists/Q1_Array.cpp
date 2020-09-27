/*
Q1. Arrays
This Program computes the product of two polynomials inputed as an array.

The program requires O(n*m) time, where n and m are the number of terms in the polynomials respectively and n,m <= degree of polynomial.
*/

#include <iostream>
using namespace std;

#define MAXSIZE 20

void getPolynomial(float* poly, int degree);
void setPolynomial(float* poly, int degree);
void multiplyPolynomials(float* poly1, int degree1, float* poly2, int degree2, float* ansPoly);
void printPolynomial(float* poly, int degree);

int main() {
	float *poly1 = NULL, *poly2 = NULL, *ansPoly = NULL;
	int degreePoly1, degreePoly2, degreeAnsPoly;
	
	cout << "This program is for Q1 from Arrays:\nThe Program computes the product of two polynomials inputed as an array." << endl;
	cout << "The program requires O(n*m) time, where n and m are the number of terms in the polynomials respectively and n,m <= degree of polynomial." << endl;
	
	//Getting the maximum power of the polynomials
	cout << "Enter the degree of the first polynomial: ";
	cin >> degreePoly1;
	cout << "Enter the degree of the second polynomial: ";
	cin >> degreePoly2;
	
	if(degreePoly1 <= MAXSIZE && degreePoly2 <= MAXSIZE && degreePoly1 >= 0 && degreePoly2 >= 0) {
		degreeAnsPoly = degreePoly1 + degreePoly2;
		
		//Allocate array to pointers
		poly1 = new float[degreePoly1 + 1];
		poly2 = new float[degreePoly2 + 1];
		ansPoly = new float[degreeAnsPoly + 1]; //As the maximum power of a term in answer will be the sum of degrees of the polynomials and can map index to power hence + 1
	} else {
		cout << "The degree is too high. Please try to limit the degree to 20." << endl;
		return 0;
	}
	
	if(poly1 != NULL && poly2 != NULL && ansPoly != NULL) {
		//Initialize the polynomials
		cout << "Input the First Polynomial: " << endl;
		getPolynomial(poly1, degreePoly1);
		cout << "Input the Second Polynomial: " << endl;
		getPolynomial(poly2, degreePoly2);
		setPolynomial(ansPoly, degreeAnsPoly);
		
		//Multiply the polynomials
		multiplyPolynomials(poly1, degreePoly1, poly2, degreePoly2, ansPoly);
		
		//Print the polynomial
		cout << "The product of " << endl;
		printPolynomial(poly1, degreePoly1);
		cout << "\nand " << endl;
		printPolynomial(poly2, degreePoly2);
		cout << "\nis " << endl;
		printPolynomial(ansPoly, degreeAnsPoly);
		return 0;
	} else {
		cout << "Error! Insufficient memory to perform the operation. Please try with smaller values." << endl;
		return -1;
	}
}

void setPolynomial(float* poly, int degree) {
	for(int i = 0; i <= degree; i++) {
		poly[i] = 0;
	}
	
	return;
}

void getPolynomial(float* poly, int degree) {
	bool done = false;
	float coeff;
	int power;
	
	setPolynomial(poly, degree);
	
	cout << "Please input -1 as power to stop inputing the current polynomial\n";
	do {
		cout << "Enter the coefficient: ";
		cin >> coeff;
		cout << "Enter the power: ";
		cin >> power;
		 
		if(power >= 0 && power <= degree) {
			poly[power] = coeff;
		} else if( power != -1){
			cout << "Error! Invalid Input." << endl;
		}
	} while(power > 0);
	
	return;
}

void printPolynomial(float* poly, int degree) {
	if(poly[degree] > 0) {
		cout << poly[degree] << "*(x^" << degree << ") ";
	} else {
		cout << poly[degree] << "*(x^" << degree << ") ";
	}
	
	for(int i = degree - 1; i >= 0; i--) {
		if(poly[i] > 0) {
			cout << "+ " << poly[i] << "*(x^" << i << ") ";
		} else if(poly[i] < 0){
			cout << "- " << -poly[i] << "*(x^" << i << ") ";
		}
	}
	
	return;
}

void multiplyPolynomials(float* poly1, int degree1, float* poly2, int degree2, float* ansPoly) {
	for(int i = degree1; i >= 0; i--) {
		for(int j = degree2; j >=0; j--) {
			ansPoly[i+j] += (poly1[i] * poly2[j]);
		}		
	}
	
	return;
}
