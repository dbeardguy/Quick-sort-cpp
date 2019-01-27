#include<iostream>
#include <chrono>			//to calculate time taken by the code
using namespace std;

int partition(int low, int high, int arr[]);
void qksort(int low, int high, int arr[]);

int main()
{

	
	int* arr = NULL;
	int n;
	cout << "\nhow many elements in the array?: ";
	cin >> n;
	if (n <= 1)
	{
		cout << "ERROR!! \nthe array must contain atleast 2 values";
		exit(0);
	}
	arr = new int[n];
	cout << "\nenter array values:";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	auto begin = std::chrono::high_resolution_clock::now();				//starting clock
	qksort(0, n - 1, arr);
	cout << "\nthe sorted array is :\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}
	auto end = std::chrono::high_resolution_clock::now();			//clock is stopped and time is noted in end
	std::chrono::duration<double> elapsed = end - begin;			//substracting end from beg to get the time taken
	cout << "\ntime taken by code: " << elapsed.count() << "ms";
}

void qksort(int low, int high, int arr[])
{
	//int m=0;
	if (low < high)
	{
		int div = partition(low, high, arr);			//the pivot element is retrieved from this partition function

		qksort(low, div - 1, arr);		//apply quicksort algo from lowest(start) value to pivot
		qksort(div + 1, high, arr);		//apply quicksort algo from pivot to highest(end)value
	}
}


int partition(int low, int high, int arr[])			//this function partitions the array based on the pivot which is = last val of the array
{
	int pivot = arr[high];
	int x = low - 1;
	int temp1, temp2;


	for (int i = low; i <= high - 1; i++)
	{
		if (arr[i] <= pivot)						//if val persent at i is less than pivot
		{
			x++;
			temp1 = arr[x];							//interchange lowest val w/ ith val
			arr[x] = arr[i];
			arr[i] = temp1;
		}
	}
	temp2 = arr[x + 1];								//this interchange will place pivot to its correct position 
	arr[x + 1] = arr[high];
	arr[high] = temp2;
	return (x + 1);
}


