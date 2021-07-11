#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

unsigned long long int recursiveFunction(unsigned long long int n){
	if (n == 0)
		return 1;
	return 1*recursiveFunction(n-1);
}

int main() {

	/*
	 * We attempt to get a feel of scale and when exactly things begin to be a problem.
	 * A comparative analysis is made between loops and recursive function calls.
	 */

	auto start = high_resolution_clock::now();

    /*
     * It takes a trivial for-loop to be run a billion times for it to reach perceptible levels of time (seconds)
     * below 10^5 - > not measurable
     * 10^5 -> 592 microseconds
     * 10^6 -> 6 milliseconds
     * 10^9 -> 3.9 seconds
     */

    for(unsigned long long int i = 1; i <= 1000000000; ++i) {}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "\n Time taken by for-loop: "<< duration.count() << " microseconds" << endl;

	start = high_resolution_clock::now();

	/*
	 * For a trivial recursive function, space complexity becomes a limiting factor much before there any human perceptible time complexity.
	 * This is because each recursive function call utilizes memory from the stack, the size of which is limited by the physical RAM on
	 * the platform and/or limits placed on stack size by the OS/compiler. Moreover the maximum recursion depth depends on these factors
	 * plus the memory utilized by each call.
	 *
	 * In this case, the maximum recursion depth appears to top out at 10^4
	 *
	 * Another interesting thing to note is that time complexity of recursive function calls seems to become measurable at 10^4 itself,
	 * compared to 10^5 for the trivial for-loop
	 */

	recursiveFunction(20000);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "\n Time taken by recursive function: "<< duration.count() << " microseconds" << endl;
    return 0;
}


