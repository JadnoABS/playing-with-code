#include <iostream>
#include <string>

using namespace std;

int romanToDecimal(string roman) {
	int result = 0;
	char subtractChar = ' ';

	for(int i = roman.length() - 1; i >= 0; i--){

		if(roman[i] == subtractChar){
			switch (roman[i]){
				case 'I': result -= 1; break;
				case 'V': result -= 5; break;
				case 'X': result -= 10; break;
				case 'L': result -= 50; break;
				case 'C': result -= 100; break;
				case 'D': result -= 500; break;
			}
			continue;
		}

		switch (roman[i]){
			case 'I':
				result += 1;
				break;
			case 'V':
				result += 5;
				subtractChar = 'I';
				break;
			case 'X':
				result += 10;
				subtractChar = 'I';
				break;
			case 'L':
				result += 50;
				subtractChar = 'X';
				break;
			case 'C':
				result += 100;
				subtractChar = 'X';
				break;
			case 'D':
				result += 500;
				subtractChar = 'C';
				break;
			case 'M':
				result += 1000;
				subtractChar = 'C';
				break;
		}
	}
	return result;
}

int main() {
	string romanNumber; int decimalNumber;
	
	cout << "Insert a Roman number:\n";
	cin >> romanNumber;
	
	decimalNumber = romanToDecimal(romanNumber);

	cout << decimalNumber << "\n";

	return 0;
}
