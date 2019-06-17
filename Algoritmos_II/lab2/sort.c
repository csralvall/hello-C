#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
#include <time.h> // Library to set the function time in partition2.

bool array_is_sorted(int array[], unsigned int length)
{
	unsigned int i = 0u;
	bool b = true;

	while ( i < (length-1) && b ) {
		b = (array[i] <= array[i+1]);
		i++;
	}

	return b;
}

// Function to change the positions between both elements.

void swap (int array[], unsigned int i, unsigned int j)
{
	int tmp = array[i];

	array[i] = array[j];
	array[j] = tmp;

	++swaps;
}

// Function to return the position of the minimum element of the array.

unsigned int min_pos_from (int array[], unsigned int length, unsigned int i)
{
	unsigned int min = i;

	for ( ; i < length; i++ ) { 
		++comparisons;
		if ( array[i] <= array[min] ) {
			++comparisons;
			min = i;
		}
	}

	return min;
}

void insert (int array[], unsigned int i)
{

/* Compare i with the previous elements until put it in the correct position*/

	while ( i > 0 && array[i] < array[i-1] ) { // i > 0 (range restriction).
		++comparisons;
		swap(array, i, i-1);
		i--;
	}
}

void insertion_sort(int array[], unsigned int length)
{
	unsigned int i = 1; /* Begining from the second element 
			       (i can't compare the first with the previous because of the range restriction)*/

	for ( ; i < length; i++ ) { // Going over the array from left to right.
		++comparisons;
		insert (array, i);
	}
}

void selection_sort(int array[], unsigned int length)
{
	unsigned int i = 0u;
	unsigned int minPosition = 0u;

	for ( ; i < length; i++ ) { 
		++comparisons;
		minPosition = min_pos_from (array, length, i);
		swap (array, i, minPosition);
	}
}


unsigned int partition2(int array[], unsigned int lft, unsigned int rgt)
{
	unsigned int irIzq = lft + 1;
	unsigned int venirDcha = rgt;
	unsigned int temp_ppiv = (rand()%(rgt-lft+1))+lft;
        swap(array, temp_ppiv, lft);
        unsigned int ppiv = lft;
	while (irIzq <= venirDcha) {
		if ( array[irIzq] <= array[ppiv] ) {
			++comparisons;
			++irIzq;
		}else if ( array[venirDcha] >= array[ppiv] ) {
			++comparisons;
			--venirDcha;
		}else { // ( array[irIzq] < array[ppiv] && array[venirDcha] > array[ppiv] )
			++comparisons;
			swap(array,irIzq,venirDcha);
			++irIzq;
			--venirDcha;
		}
	}
	swap(array,ppiv,venirDcha);
	ppiv = venirDcha;
	return ppiv;
}

unsigned int partition(int array[], unsigned int lft, unsigned int rgt)
{
	unsigned int irIzq = lft + 1;
	unsigned int venirDcha = rgt;
	unsigned int ppiv = lft;

	while (irIzq <= venirDcha) {
		if ( array[irIzq] <= array[ppiv] ) {
			++comparisons;
			++irIzq;
		}else if ( array[venirDcha] >= array[ppiv] ) {
			++comparisons;
			--venirDcha;
		}else { // ( array[irIzq] < array[ppiv] && array[venirDcha] > array[ppiv] )
			++comparisons;
			swap(array,irIzq,venirDcha);
			++irIzq;
			--venirDcha;
		}
	}
	swap(array,ppiv,venirDcha);
	ppiv = venirDcha;
	return ppiv;
}

void quick_sort_rec(int array[], unsigned int lft, unsigned int rgt)
{
	unsigned int ppiv;

	if (rgt > lft) {
		++comparisons;
		ppiv = partition2(array,lft,rgt);
		if (ppiv != 0u)
			quick_sort_rec(array,lft,ppiv-1);
		quick_sort_rec(array,ppiv+1,rgt);
	}
}

void quick_sort(int array[], unsigned int length)
{
	srand(time(NULL));

	if (length != 0u)
		quick_sort_rec(array,0,length-1);
}

void merge(int array[],	unsigned int lft, unsigned int mid, unsigned int rgt)
{
	int tmp[mid];
	unsigned int j,k,i;
	
	j = lft;
	k = mid + 1;

	for ( i = 0; i <= mid; ++i ) {
		++comparisons;
		tmp[i] = array[i];
	}

	for ( i = lft; i <= rgt; ++i ) {
		++comparisons;
		if ( j <= mid && (k > rgt || tmp[j] <= array[k])) {
				++comparisons;
				array[i] = tmp[j];
				++j;
		} else {
			array[i] = array[k];
			++k;
		}
	}
}

void merge_sort_rec(int array[], unsigned int lft, unsigned int rgt)
{
	unsigned int mid;

	if ( rgt > lft ) {
		++comparisons;
		mid = ( rgt + lft ) / 2;
		merge_sort_rec(array,lft,mid);
		merge_sort_rec(array,mid+1,rgt);
		merge(array,lft,mid,rgt);
	}
}

void merge_sort(int array[], unsigned int length)
{
	merge_sort_rec(array,0,length-1);
}
