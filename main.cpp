// EECS560_Lab1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include "ClosedHashTable.h"
#include "OpenHashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
using namespace std;

class Timer {
private:

	timeval startTime;
        timeval endTime;

public:

	void start(){
		gettimeofday(&startTime, NULL);
	}

	double stop(){
	        long seconds, nseconds;
		double duration;

		gettimeofday(&endTime, NULL);

		seconds  = endTime.tv_sec  - startTime.tv_sec;
		nseconds = endTime.tv_usec - startTime.tv_usec;

		duration = seconds + nseconds/1000000.0;

		return duration;
	}

	void printTime(double duration){
		printf("%5.6f seconds\n", duration);
	}
};

int main()
{
    Timer myTimer;
    double duration;
    const long M_SIZE = 600011;
    double loadFactor[] = {.2, .3, .4, .5, .6, .7, .8, .9};
	double openDuration[40];
	double quadraticDuration[40];
	double doubleDuration[40];
    long numValuesToUse[8];

    for(int i=0; i<8; i++)
    {
        numValuesToUse[i] = static_cast<long> (loadFactor[i] * M_SIZE);	// The number of values that we'll use is determined by the load factor
        for(int j=0; j<5; j++)											// We're going to have five sets of random values for each table
        {
            srand(j);													// use the same seed for each table
            long valuesToUse[numValuesToUse[i]];						// create an array for random values
            for(long k = 0; k<numValuesToUse[i]; k++)
            {
                valuesToUse[k] = rand() % RAND_MAX;						// put a random number in the array
            }

            OpenHashTable openTable(M_SIZE);							// For an open table

            ClosedHashTable closedQuadratic(M_SIZE);					// quadratic hashing

            ClosedHashTable closedDouble(M_SIZE);						// For double hashing
            closedDouble.setQuadraticHashing(false);					// Make sure double hashing is set

			myTimer.start();
            for(long c = 0; c < numValuesToUse[i]; c++)
            {
                openTable.insert(valuesToUse[c]);
            }
			openDuration[(i*5+j)] = myTimer.stop();

			myTimer.start();
            for(long c = 0; c < numValuesToUse[i]; c++)
            {
                closedQuadratic.insert(valuesToUse[c]);
            }
			myTimer.stop();
			quadraticDuration[(i*5+j)] = myTimer.stop();

			myTimer.start();
            for(long c = 0; c < numValuesToUse[i]; c++)
            {
                closedDouble.insert(valuesToUse[c]);
            }
			myTimer.stop();
			doubleDuration[(i*5+j)] = myTimer.stop();
        }
    }

	for(int i = 0; i < 8; i++)
	{
		// double openAverage = 0;
		// double quadraticAverage = 0;
		// double doubleAverage = 0;
		double openSum = 0;
		double quadraticSum = 0;
		double doubleSum = 0;

		double sum = 0;
		for(int j = 0; j < 5; j++)
		{
			openSum += openDuration[(i*5+j)];
			quadraticSum += quadraticDuration[(i*5+j)];
			doubleSum += doubleDuration[(i*5+j)];
		}

		std::cout << "For load factor " << loadFactor[i] << ":" << std::endl;
		std::cout << "\topenAverage is: " << (openSum/5) << "s" << std::endl;
		std::cout << "\tquadraticAverage is: " << (quadraticSum/5) << "s" << std::endl;
		std::cout << "\tdoubleAverage is: " << (doubleSum/5) << "s" << std::endl;
		cout << std::endl;
	}

    return 0;
}
