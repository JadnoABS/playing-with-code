#include <iostream>
#include <vector>
#include <string>


/*
 * Jadno Barbosa - 06.02.2021
 * Algorithm that sorts the odd numbers of a given array
 * while the even remains in their initial indexes.
 */

bool isOdd(int value){
	if (value == 1){ return true; }
	if (value == 0){ return false; }

	if (value % 2 != 0) { return true; }
	return false;
}

std::vector<int> sortArray(std::vector<int> array){
	int temp;
	
	for (long i = 1; i < array.size(); i++){
		if (isOdd(array[i])){
			for (long x = 0; x < i; x++){
				if (isOdd(array[x]) && array[x] > array[i]){
					std::cout << array[x]
						<< " swapping with " << array[i] << "\n";
					temp = array[x];
					array[x] = array[i];
					array[i] = temp;
				}
			}
		}
	}

	return array;
}


int main(){

	std::vector<int> arr;
	long arrSize; int nextValue;
	std::cout << "Tell the size of the array:\n";
	std::cin >> arrSize;

	std::cout << "\n" << "Enter the array values: (Separated by spaces)\n";
	for(long i = 0; i < arrSize; i++){
		std::cin >> nextValue;
		arr.push_back(nextValue);
	}

	std::cout << "\n" << "Your array: ";

	for (long i = 0; i < arr.size(); i++){
		std::cout << arr[i] << " ";
	}
	std::cout << "\n \n";

	std::cout << "Odd numbers swaps: \n";

	std::vector<int> result = sortArray(arr);


	std::cout << "\n" << "This is the sorted array: \n";
	for (long i = 0; i < result.size(); i++){
		std::cout << result[i] << " ";
	}
	std::cout << "\n";
}
