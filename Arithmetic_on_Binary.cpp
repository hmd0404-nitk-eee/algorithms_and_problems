/*This program is perform arithmetic operations on Binary Numbers */

#include <bits/stdc++.h>
using namespace std;

string ToStr(int len, char c);
void addPaddingToBin(int padding, string &binNum1, string &binNum2);
string twoesComplement(string &binNum);
string decToBin(int num);
string decToBin(int num);
int binToDec(string &binNum);
string binAdd(string num1, string num2);
string binSub(string num1, string num2, bool *isNeg);

string ToStr(int len, char c) {
   return string(len, c );
}

void addPaddingToBin(int padding, string &binNum1, string &binNum2) {
	if(padding > 0) {
		binNum2.insert(0, ToStr(padding, '0'));
	} else {
		binNum1.insert(0, ToStr(-padding, '0'));
	}
}

string twoesComplement(string &binNum) {
	string onesComplOfBinNum, twoesComplOfBinNum;
	
	for(int i = binNum.length() - 1; i >= 0; i--) {
		if(binNum[i] == '0') {
			onesComplOfBinNum.insert(0, ToStr(1, '1'));
		} else {
			onesComplOfBinNum.insert(0, ToStr(1, '0'));
		}
	}
	
	twoesComplOfBinNum = binAdd(onesComplOfBinNum, ToStr(1, '1'));
	
	return twoesComplOfBinNum;
}

string decToBin(int num) {
	string binNum;
	char bit;
	
	while(num) {
		bit = (num % 2) + 48;
		binNum.insert(0, ToStr(1, bit));
		num /= 2;
	}
	
	return binNum;
}

int binToDec(string &binNum) {
	int num = 0;
	int j = 0;
	
	for(int i = binNum.length() - 1; i >= 0; i--) {
		num += (binNum[i] - 48) * (1 << j);
		j++;	
	}
	
	return num;
}

string binAdd(string binNum1, string binNum2) {
	//string binNum1, binNum2;
	int padding = 0;
	
	//binNum1 = decToBin(num1);
	//binNum2 = decToBin(num2);
	
	padding = binNum1.length() - binNum2.length();
	if(padding) {
		addPaddingToBin(padding, binNum1, binNum2);	
	}
	
	string binSum;
	char carry = '0';
	for(int i = binNum1.length() - 1; i >= -1; i--) {
		if(i >= 0) {
			if(binNum1[i] == binNum2[i]) {
				if(binNum1[i] == '0' )
				{
					if(carry == '1') {
						binSum.insert(0, ToStr(1, '1'));
						carry = '0';
					} else {
						binSum.insert(0, ToStr(1, '0'));	
					}
				} else {
					if(carry == '1') {
						binSum.insert(0, ToStr(1, '1'));
					} else {
						binSum.insert(0, ToStr(1, '0'));
						carry = '1';
					}
				}	
			} else {
				if(carry == '1') {
					binSum.insert(0, ToStr(1, '0'));
				} else {
					binSum.insert(0, ToStr(1, '1'));
				}
			}
		} else if(carry == '1') {
			binSum.insert(0, ToStr(1, carry));
			carry = '0';
		}
	}

	//return binToDec(binSum);
	return binSum;
}

string binSub(string binNum1, string binNum2, bool *isNeg) {
	//string binNum1, binNum2;
	int padding = 0;
	
	//binNum1 = decToBin(num1);
	//binNum2 = decToBin(num2);
	
	padding = binNum1.length() - binNum2.length();
	if(padding) {
		addPaddingToBin(padding, binNum1, binNum2);	
	}
	
	string subtrend = twoesComplement(binNum2);
	
	string binSum;
	char carry = '0';
	for(int i = binNum1.length() - 1; i >= -1; i--) {
		if(i >= 0) {
			if(binNum1[i] == subtrend[i]) {
				if(binNum1[i] == '0' )
				{
					if(carry == '1') {
						binSum.insert(0, ToStr(1, '1'));
						carry = '0';
					} else {
						binSum.insert(0, ToStr(1, '0'));	
					}
				} else {
					if(carry == '1') {
						binSum.insert(0, ToStr(1, '1'));
					} else {
						binSum.insert(0, ToStr(1, '0'));
						carry = '1';
					}
				}	
			} else {
				if(carry == '1') {
					binSum.insert(0, ToStr(1, '0'));
				} else {
					binSum.insert(0, ToStr(1, '1'));
				}
			}
		} else if(carry == '1') {
			carry = '0';
			return binSum;
		} else if(carry == '0'){
			*isNeg = true;
			return twoesComplement(binSum);
		}
	}
}

int main() {
	int num1, num2;
	bool isNeg = false;
	
	cout << "Enter two numbers: ";
	cin >> num1 >> num2;
	
	string binNum1, binNum2, binSum, binSum2;
	binNum1 = decToBin(num1);
	binNum2 = decToBin(num2);
	binSum = binAdd(binNum1, binNum2);
	binSum2 = binSub(binNum1, binNum2, &isNeg);
	
	int sum = binToDec(binSum);
	int sub = binToDec(binSum2);
	
	cout << num1 << " has binary " << binNum1 << endl;
	cout << num2 << " has binary " << binNum2 << endl;
	cout << "The sum is: " << sum << endl;
	
	if(isNeg) {
		cout << "The difference is: -" << sub << endl;	
	} else {
		cout << "The difference is: " << sub << endl;
	}
	
	return 0;
}
