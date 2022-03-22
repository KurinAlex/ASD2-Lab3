#include <queue>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Data.h"
#include "PriorityQueue.h"
#include "Heapsort.h"

using namespace std;

template <typename T>
float testPriorityQueueSpeed(T&& priorityQueue)
{
	const int iters = 100000;
	clock_t timeStart = clock();
	for (int i = 0; i < iters; i++)
	{
		int insertDataAmount = rand() % 6 + 5;
		for (int j = 0; j < insertDataAmount; j++)
		{
			priorityQueue.push(Data());
		}
		priorityQueue.top();
		priorityQueue.pop();
	}
	clock_t timeEnd = clock();
	float time = (float(timeEnd - timeStart)) / CLOCKS_PER_SEC;
	return time;
}

bool testPriorityQueue()
{
	srand(time(NULL));
	const int iters = 20000;
	PriorityQueue<Data> myPriorQueue;
	priority_queue<Data> stlPriorQueue;
	bool isDataEqual = true;
	for (int i = 0; i < iters; i++)
	{
		int insertDataAmount = rand() % 6 + 5;
		for (int j = 0; j < insertDataAmount; j++)
		{
			Data randData = Data();
			myPriorQueue.push(randData);
			stlPriorQueue.push(randData);
		}
		if (!(myPriorQueue.top() == stlPriorQueue.top()))
		{
			isDataEqual = false;
			cerr << "Comparing failed on iteration " << i << endl << endl;
			break;
		}
		int removeDataAmount = rand() % insertDataAmount;
		for (int j = 0; j < removeDataAmount; j++)
		{
			myPriorQueue.pop();
			stlPriorQueue.pop();
		}
	}
	int myQueueSize = myPriorQueue.size();
	int stlQueueSize = stlPriorQueue.size();
	float stlTime =
		testPriorityQueueSpeed<priority_queue<Data>>(priority_queue<Data>());
	float myTime = testPriorityQueueSpeed<PriorityQueue<Data>>(PriorityQueue<Data>());
	cout << "My PriorityQueue:" << endl;
	cout << "Time: " << myTime << ", size: " << myQueueSize << endl;
	cout << "STL priority_queue:" << endl;
	cout << "Time: " << stlTime << ", size: " << stlQueueSize << endl << endl;
	if (isDataEqual && myQueueSize == stlQueueSize)
	{
		cout << "The lab is completed" << endl << endl;
		return true;
	}
	cerr << ":(" << endl << endl;
	return false;
}

template<typename T>
bool isSorted(T* l, T* r)
{
	for (T* i = l + 1; i != r; i++)
	{
		if (*i < *(i - 1))
		{
			return false;
		}
	}
	return true;
}

template <typename T>
float testSortSpeed(void (*sort)(T*, T*), T* array, int size)
{
	clock_t timeStart = clock();
	sort(array, array + size);
	clock_t timeEnd = clock();
	float time = (float(timeEnd - timeStart)) / CLOCKS_PER_SEC;
	return time;
}

bool testHeapsort()
{
	const int size = 30000;
	Data mySortArray[size];
	Data stlSortArray[size];
	for (int i = 0; i < size; i++)
	{
		Data randData = Data();
		mySortArray[i] = randData;
		stlSortArray[i] = randData;
	}
	float myTime = testSortSpeed(heapsort, mySortArray, size);
	float stlTime = testSortSpeed(sort, stlSortArray, size);
	bool isDataSorted = isSorted(mySortArray, mySortArray + size);
	cout << "My sort:" << endl;
	cout << "Time: " << myTime << endl;
	cout << "STL sort:" << endl;
	cout << "Time: " << stlTime << endl << endl;
	if (isDataSorted)
	{
		cout << "The lab is completed" << endl << endl;
		return true;
	}
	cerr << ":(" << endl << endl;
	return false;
}

int main()
{
	cout << "PriorityQueue test:" << endl;
	testPriorityQueue();

	cout << "Heapsort test:" << endl;
	testHeapsort();
}