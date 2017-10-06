#ifndef __INSERTION_SORT_CPP__
#define __INSERTION_SORT_CPP__

#include "InsertionSort.h"

template <typename T>
InsertionSort<T>::InsertionSort(int (*compare_function)(const T & first, const T & second)) 
	: AbstractSortAlgorithm<T>(compare_function) {}

template <typename T>
void InsertionSort<T>::sort(T array[], int size) {
	// Massivni saralash ikkinchi elementdan boshlanganligi sabab siklni 0 dan
	// emas 1 dan boshlaymiz
	for (int i = 1; i < size; i++) {
		// Element qiymatini alohida o'zgaruvchiga olamiz
		T itemValue = array[i];

		// Taqqoslab boriladigan element indeksi
		int j = i - 1;

		// Joriy elementdan katta bo'lgan elementlarni o'ngga suramiz
		while (j >= 0 && this->compare(array[j], itemValue) > 0) {
			// Elementni surish
			array[j + 1] = array[j];
			
			// Oldingi elementga o'tish
			j--;
		}

		// Barcha katta elementlar surib bo'linganidan keyin joriy elementni 
		// joylashtiramiz
		array[j + 1] = itemValue;
	}	
}

#endif
