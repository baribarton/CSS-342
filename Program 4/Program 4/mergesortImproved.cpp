#include <vector>
#include <math.h> // may need to use pow( )
using namespace std;

/*
Program 4
Jabari Barton
CSS 342
*/

//merges the elements of the array back together
template <class Comparable>
void merge(vector<Comparable> &a, vector<Comparable> &b, int left, int right, int end) {

	int left2 = left;
	int right2 = right;

	// j is the index of array b that is being written to
	for (int j = left; j < end; j++)
	{
		/*
		If left index is still within it's subsection, and right index
		has passed the end OR left element is less than right element
		*/

		if (left2 < right && (right2 >= end || a[left2] <= a[right2])) {

			b[j] = a[left2];

			left2 += 1;  // shifting left section

		}
		else {

			b[j] = a[right2]; // choose number from right sub-array

			right2 += 1;  // shift right index
		}
	}
}

//swaps two elements in an array
template <class Comparable>
void swap(vector<Comparable> &a, vector<Comparable> &b) {
	
	vector<Comparable> temp = a;
	a = b;
	b = temp;
}


template <class Comparable>

//iterative version of merge sort
void mergesortImproved(vector<Comparable> &a) {

	int size = a.size();
	vector<Comparable> b(size);  // this is only one temporary array.
	
	// Length of sub-arrays
	for (int subLength = 1; subLength < size; subLength *= 2) {		// left = index of left subsection
		for (int left = 0; left < size; left += 2 * subLength) {
			int right = min(left + subLength, size);			// right = index of right subsection
			int end = min(left + 2 * subLength, size);		// end = index of next sub or end of vector

			merge(a, b, left, right, end);			// merge left and right subsections
		}

		swap(a, b);

	}
}