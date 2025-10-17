#include <iostream>
#include <future>
using namespace std;

/*
Provides examples of asynchonous programming in c++.

*/

//Used to demonstate futures and promises
void calculate(std::promise<int>intPromise) {
	intPromise.set_value(10);
}

//Used to demonstrate callbacks
void execute(void(*callbackFunc)(int), int value) {
	callbackFunc(value);
}

//Used to demonstrate callbacks
void printValue(int value) {
	std::cout << "Value " << value << std::endl;
}

//ASync is used to create a task independently from the main task and run asynchonous
int calculate1() {
	return 10;
}

int main() {

	//Below code demonstrates callbacks
	execute(printValue, 5);

	//Below code demonstrates futures and callbacks
	std::promise<int>prom;
	std::future<int> fut = prom.get_future();
	std::thread t(calculate, std::move(prom));
	std::cout << fut.get() << std::endl; //Get result (potentially in another thread)

	t.join();

	//Async//Await
	std::future<int> fut2 = std::async(calculate1);
	std::cout << fut2.get() << std::endl;

	return 0;

};
