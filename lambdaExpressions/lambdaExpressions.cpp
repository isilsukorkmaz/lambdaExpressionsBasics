#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

class Operations {
public:
	Operations(int number) :mNumber(number) {}

	void isDivisible(std::vector<int> list) {
		int anotherNumber = 5;
		int anotherDifferentNum = 7;

		//std::for_each(list.begin(), list.end(), [this](int number) { for mNumber
		//[&]
		//[=]
		//std::for_each(list.begin(), list.end(), [&](int number) {
		//	if (number % anotherNumber == 0){
		//		cout << number << " is divisible by " << anotherNumber << endl;
		//	}
		//	else {
		//		cout << number << " is not divisible by " << anotherNumber << endl;
		//		anotherNumber = anotherDifferentNum;
		//	}
		//		
		//	});

		//return type

		auto checkDivisible = [this](int num) {
			if (num % mNumber == 0)
				return true;
			else
				return false;
			};


		// clearly always returns boolean so no need to specify
		// compiler can predict return type
		// but what if 

		//auto checkDivisible = [this](int num) -> double  {
		//	if (num % mNumber == 0)
		//		return 1;
		//	else
		//		return double( num / mNumber);
		//	};


		std::for_each(list.begin(), list.end(), [this, checkDivisible](int num) {
			if (checkDivisible(num))
				cout << num << " is divisible by " << mNumber << endl;
			else
				cout << num << " is not divisible by " << mNumber << endl;
			});

	}
	//std::function 
	void operate(std::vector<int> list, std::function<int(int)> func) {
		std::transform(list.begin(), list.end(), list.begin(), func);
		std::for_each(list.begin(), list.end(), [](int number) {cout << number << endl; });
	}

private:
	int mNumber;

};

void printNumbers(std::vector<int> numberList) {
	for (auto number : numberList)
		cout << number << endl;
}

int main() {

	std::vector<int> numberList{ 4,7,9,11,15 };
	//printNumbers(numberList);

	//do this instead
	//auto printLambda = [](std::vector<int> list) {
	//	for (auto number : list)
	//		cout << number << endl; };

	//printLambda(numberList);

	//or even better
	/*std::for_each(numberList.begin(),numberList.end(), [](int number) {
			cout << number << endl; });*/

			// or immediately invoke it
			//[numberList]() {
			//	for (auto number : numberList)
			//		cout << number << endl; } ();

	Operations operationsClass(3);
	//operationsClass.isDivisible(numberList);

	//std::function
	operationsClass.operate(numberList, [](int number) {return number * 2; });
	operationsClass.operate(numberList, [](int number) {return --number; });


	//Changes made to C++17
	//Constexpr in Lambda Expressions
	// constexpr auto ....

	//Capture of [*this] in lambda expressions: 
	// Capture of [*this] by value in lambda expressions was introduced in C++17. 
	// Prior to C++17, this functionality was not allowed and so one would need to capture it by creating a copy (which is prone to errors).



}