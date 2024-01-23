//timing programs
#include <iostream>
#include <conio.h>
#include <windows.h>  //include file for the timer
using namespace std;

__int64 t1 = 0, t2 = 0, freq;
float tt;

#define SIZE 10
#define RUNS 500

int randArray[SIZE];

void selectionSort(int array[], int size) {

	for (int j = 0; j < SIZE; j++)
	{
		int min = randArray[j];//set a minimum to be the first element in the list
		int ms = j;//set minimum value array index
		for (int i = j + 1; i < SIZE; i++) //loop to check for minimum 
		{
			if (randArray[i] < min)//if element less then set min
			{
				min = randArray[i];
				ms = i;//save the array position of the minimum slot
			}
		}//end of i loop
		randArray[ms] = randArray[j];
		randArray[j] = min;
	}//end of j loop
}

//void bubbleSort(int array[], int size) {
//	bool swapped;
//	do {
//		swapped = false;
//		for (int i = 0; i < size - 1; ++i) {
//			if (array[i] > array[i + 1]) {
//				std::swap(array[i], array[i + 1]);
//				swapped = true;
//			}
//		}-0 -----
//	} while (swapped);
//}

//void bubbleSort(int array[], int size) {
//
//	// loop to access each array element
//	for (int step = 0; step < size; ++step) {
//
//		// loop to compare array elements
//		for (int i = 0; i < size - step; ++i) {
//
//			// compare two adjacent elements
//			// change > to < to sort in descending order
//			if (array[i] > array[i + 1]) {
//
//				// swapping elements if elements
//				// are not in the intended order
//				int temp = array[i];
//				array[i] = array[i + 1];
//				array[i + 1] = temp;
//			}
//		}
//	}
//}

void bubbleSort(int array[], int size) {

	for (int step = 0; step < size; ++step) { // loop to access each array element

		for (int i = 0; i < size - step; ++i) {	// loop to compare array elements

			if (array[i] > array[i + 1]) { // compare two adjacent elements

				// swapping elements if left element is greater then right element
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}

			//// Print the array after each comparison
			//cout << "Step " << step << ", iterration " << i << ": ";
			//for (int j = 0; j < size; ++j) {
			//	cout << array[j] << " ";
			//}
			//std::cout << std::endl;
		}
	}
}

//void insertionSort(int array[], int size) {
//	for (int i = 1; i < size; ++i) {
//		int key = array[i];
//		int j = i - 1;
//		while (j >= 0 && array[j] > key) {
//			array[j + 1] = array[j];
//			--j;
//		}
//		array[j + 1] = key;
//	}
//}

void insertionSort(int array[], int size) {

	for (int i = 1; i < size; ++i) { //for loop iterating from the second element array[1]
									//so element can be compared with array[0]

		int rightElement = array[i]; //store element in rightElent varible 

		int leftElement = i - 1; //leftElement vaiable initilized to index before rightElement

		//checks if we are at the start then if the left element is greater then the right
		while (leftElement >= 0 && array[leftElement] > rightElement) { 

			//if the condition is true space needs to be made for this element, this shifts the element to the right
			array[leftElement + 1] = array[leftElement];
			--leftElement; //left element now need needs to decrement ready for the next iteration comparison
		}


		// Place the rightElement in its correct sorted position.
		array[leftElement + 1] = rightElement;
	}
}


void quickSort(int array[], int first, int last) {
	if (first < last) {
		// Select the pivot element (in this case, we choose the first element).
		int pivot = array[first];
		int left = first + 1; // Initialize the left index.
		int right = last;    // Initialize the right index.

		while (true) {
			// Find the first element from the left that is greater than or equal to the pivot.
			while (left <= right && array[left] <= pivot) {
				++left;
			}

			// Find the first element from the right that is less than or equal to the pivot.
			while (right >= left && array[right] >= pivot) {
				--right;
			}

			if (left <= right) {
				// Swap the elements at the left and right indices.
				std::swap(array[left], array[right]);
			}
			else {
				// The left and right indices have crossed or are equal, exit the loop.
				break;
			}
		}

		// Swap the pivot element (first element) with the element at the 'right' index.
		std::swap(array[first], array[right]);

		// Recursively sort the subarrays to the left and right of the pivot.
		quickSort(array, first, right - 1); // Sort the left subarray.
		quickSort(array, right + 1, last);  // Sort the right subarray.
	}
}

// Sorting function using Merge Sort
void merge(int array[], int left, int mid, int right) {

	// Finding the size of the subarrays
	int subL = mid - left + 1;
	int subR = right - mid;

	// Create temporary arrays to hold the left and right subarrays
	int* leftArray = new int[subL];
	int* rightArray = new int[subR];

	// Divide the original array into two subarrays by copying data
	// from the original array to the left and right temporary arrays
	for (int i = 0; i < subL; ++i) {
		leftArray[i] = array[left + i];
	}
	for (int j = 0; j < subR; ++j) {
		rightArray[j] = array[mid + 1 + j];
	}

	// Print the left and right subarrays (for debugging or visualization)
	//cout << "\nLeft sub-array: ";
	//for (auto i = 0; i < subL; i++) {
	//	cout << leftArray[i] << " ";
	//}
	//cout << endl;

	//cout << "\nRight sub-array: ";
	//for (auto j = 0; j < subR; j++) {
	//	cout << rightArray[j] << " ";
	//}
	//cout << "\n" << endl;

	// Initialize counters for the left, right, and merged arrays
	int i = 0; // i is the index for the left array
	int j = 0; // j is the index for the right array
	int k = left; // k is the index for the merged array 

	// Merge the left and right subarrays into the original array
	while (i < subL && j < subR) {
		if (leftArray[i] <= rightArray[j]) {
			array[k] = leftArray[i];
			//cout << "Copied " << leftArray[i] << " from leftArray to array at index " << k << endl;
			++i;
		}
		else {
			array[k] = rightArray[j];
			//cout << "Copied " << rightArray[j] << " from rightArray to array at index " << k << endl;
			++j;
		}
		++k;
	}

	// Copy any remaining elements from the left subarray
	while (i < subL) {
		array[k] = leftArray[i];
		//cout << "Copied " << leftArray[i] << " from leftArray because i > subL to array at index " << k << endl;
		++i;
		++k;
	}

	// Copy any remaining elements from the right subarray
	while (j < subR) {
		array[k] = rightArray[j];
		//cout << "Copied " << rightArray[j] << " from rightArray because j > subR to array at index " << k << endl;
		++j;
		++k;
	}

	// Deallocate memory for temporary arrays
	delete[] leftArray;
	delete[] rightArray;
}

void mergeSort(int array[], int left, int right) {
	//This is the base case for the recursion is left lesss than right
	if (left < right) {

		//finding the middle of the array by deviding by two
		int mid = left + (right - left) / 2;

		mergeSort(array, left, mid); //Calls mergeSort to spilt the left array 
		mergeSort(array, mid + 1, right); //Calls mergeSort to split the right

		merge(array, left, mid, right); //performs sorting on the two arrays
	}
}

void merge2(int array[], int left, int mid1, int mid2, int mid3, int right) {

	int subL1 = mid1 - left + 1;
	int subL2 = mid2 - mid1;
	int subL3 = mid3 - mid2;
	int subR = right - mid3;

	int* leftArray1 = new int[subL1];
	int* leftArray2 = new int[subL2];
	int* rightArray1 = new int[subL3];
	int* rightArray2 = new int[subR];

	for (int i = 0; i < subL1; ++i) {
		leftArray1[i] = array[left + i];
	}

	for (int i = 0; i < subL2; ++i) {
		leftArray2[i] = array[mid1 + 1 + i];
	}

	for (int i = 0; i < subL3; ++i) {
		rightArray1[i] = array[mid2 + 1 + i];
	}

	for (int i = 0; i < subR; ++i) {
		rightArray2[i] = array[mid3 + 1 + i];
	}

	//// Print the four sub-arrays
	//cout << "\nLeft sub-array 1: ";
	//for (int i = 0; i < subL1; ++i) {
	//	cout << leftArray1[i] << " ";
	//}
	//cout << endl;

	//cout << "\nLeft sub-array 2: ";
	//for (int i = 0; i < subL2; ++i) {
	//	cout << leftArray2[i] << " ";
	//}
	//cout << endl;

	//cout << "\nRight sub-array 1: ";
	//for (int i = 0; i < subL3; ++i) {
	//	cout << rightArray1[i] << " ";
	//}
	//cout << endl;

	//cout << "\nRight sub-array 2: ";
	//for (int j = 0; j < subR; ++j) {
	//	cout << rightArray2[j] << " ";
	//}
	//cout << "\n" << endl;

	int i = 0;
	int j = 0;
	int k = left;

	while (i < subL1 && j < subL2 && k < subL3 && k < subR) {
		if (leftArray1[i] <= leftArray2[j] && leftArray1[i] <= rightArray1[k] && leftArray1[i] <= rightArray2[k]) {
			array[k] = leftArray1[i];
			//cout << "Copied " << leftArray1[i] << " from leftArray1 to array at index " << k << endl;
			++i;
		}
		else if (leftArray2[j] <= leftArray1[i] && leftArray2[j] <= rightArray1[k] && leftArray2[j] <= rightArray2[k]) {
			array[k] = leftArray2[j];
			//cout << "Copied " << leftArray2[j] << " from leftArray2 to array at index " << k << endl;
			++j;
		}
		else if (rightArray1[k] <= leftArray1[i] && rightArray1[k] <= leftArray2[j] && rightArray1[k] <= rightArray2[k]) {
			array[k] = rightArray1[k];
			//cout << "Copied " << rightArray1[k] << " from rightArray1 to array at index " << k << endl;
			++k;
		}
		else {
			array[k] = rightArray2[k];
			//cout << "Copied " << rightArray2[k] << " from rightArray2 to array at index " << k << endl;
			++k;
		}
	}

	// Handle any remaining elements in the sub-arrays
	while (i < subL1) {
		array[k] = leftArray1[i];
		//cout << "Copied " << leftArray1[i] << " from leftArray1 to array at index " << k << endl;
		++i;
		++k;
	}

	while (j < subL2) {
		array[k] = leftArray2[j];
		//cout << "Copied " << leftArray2[j] << " from leftArray2 to array at index " << k << endl;
		++j;
		++k;
	}

	while (k < subL3) {
		array[k] = rightArray1[k];
		//cout << "Copied " << rightArray1[k] << " from rifghtArray1 to array at index " << k << endl;
		++k;
	}

	while (k < subR) {
		array[k] = rightArray2[k];
		//cout << "Copied " << rightArray2[k] << " from rightArray2 to array at index " << k << endl;
		++k;
	}

	delete[] leftArray1;
	delete[] leftArray2;
	delete[] rightArray1;
	delete[] rightArray2;
}

void mergeSort2(int array[], int left, int right) {
	//This is the base case for the recursion is left lesss than right
	if (left < right) {

		//finding the four quaters of the array by deviding by four
		int mid1 = left + (right - left) / 4;  
		int mid2 = left + 2 * (right - left) / 4; 
		int mid3 = left + 3 * (right - left) / 4;

		mergeSort2(array, left, mid1); //Calls mergeSort to spilt the left array 
		mergeSort2(array, mid1 + 1, mid2); //Calls mergeSort to spilt the left mid array 
		mergeSort2(array, mid2 + 1, mid3); //Calls mergeSort to spilt the right mid array 
		mergeSort2(array, mid3 + 1, right); //Calls mergeSort to spilt the right array 


		merge2(array, left, mid1, mid2, mid3, right); //performs sorting on the four arrays
	}
}


void main(void)
{

	srand(time(NULL)); //ensuring the random number generator is random


	DWORD starttime, endtime;//variables to store start and end times
	float totaltime;//a float variable for the total time

	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);


	QueryPerformanceCounter((LARGE_INTEGER*)&t1);

	for (int i = 0; i < SIZE; i++) {
		randArray[i] = rand() % 100;
	}

	//for (int i = 0; i < SIZE; i++) cout << "randArray[" << i << "]=" << randArray[i] << endl; //pinting out the array list

	//selectionSort(randArray, SIZE);
	//bubbleSort(randArray, SIZE);
	//insertionSort(randArray, SIZE);
	//quickSort(randArray, 0, SIZE - 1); //parameters array, starting index and final index
	//mergeSort(randArray, 0, SIZE - 1);
	mergeSort2(randArray, 0, SIZE - 1);


	QueryPerformanceCounter((LARGE_INTEGER*)&t2);
	cout << "\nClock frequency = " << (float)(freq / 1000000.0) << "GHz" << endl;
	tt = (float)((t2 - t1) / ((float)freq));
	cout << "Total time=" << tt << " s" << endl;

	//for (int i = 0; i < SIZE; i++) cout << "randArray[" << i << "]=" << randArray[i] << endl;//pinting out the array list in order

}