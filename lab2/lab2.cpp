#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <time.h>



using namespace std::chrono;
using namespace std;


double fibNumRec(double argNum);
double fibNumIter(double argNum);

double calls = 0; // checking to see the amt of calls used

int main(void) {
	double num = 12;
	clock_t start;

	cout << "\n***Iterative***";

	cout << "\nInput: " << num;
	
	auto timeBeg = high_resolution_clock::now();
	cout << fixed << setprecision(0) << "\nIterative Output: " << fibNumIter(num);
	auto timeEnd = high_resolution_clock::now();

	
	auto duration = duration_cast<microseconds>(timeEnd - timeBeg);
	cout << "\nTime: " << duration.count() << " microseconds" << endl;


	cout << "\n***Recursive***";

	cout << "\nInput: " << num;

	timeBeg = high_resolution_clock::now();
	cout << "\nRecursive Output: " << fibNumRec(num);
	timeEnd = high_resolution_clock::now();

	duration = duration_cast<microseconds>(timeEnd - timeBeg);
	cout << "\nTime: " << duration.count() << " microseconds" << endl;

	cout << "Calls: " << calls << endl; // checking to see amt of times recursive function was called


//gone
	return 0;

}


/************* Methods *************/
double fibNumIter(double argNum) {


	double previous = 0;
	double current = 1;
	double next;


	if (argNum == 0) {
		return previous;
	}


	for (int i = 2; i <= argNum; i++) { // i = 2 so we avoid 1's and 0's
		next = previous + current;
		previous = current;
		current = next;


	}


	return current;
}




double fibNumRec(double argNum){

	calls++;

	if (argNum <= 1) {
		return argNum;
	}

	else
		return fibNumRec(argNum - 1) + fibNumRec(argNum - 2); // = 2 * (fibonacci of argNum) - 1 would be the amount of calls


	//
	// ex:
	//                           fib(5)
	//                       fib(4) + fib(3)
	//          (fib(3) + fib (2))              (fib(2) + fib(1))
	//  (fib(2) + fib(1))  (fib(1) + fib(0))    (fib(1) + fib(0))   
	//  (fib(1) + fib(0))
	// adding all the 1's and 0's give us 5
}

