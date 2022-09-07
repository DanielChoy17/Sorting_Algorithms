#include "stats.h"

#include <stdint.h>
#include <stdio.h>

// This function sorts the elements of an array,
// by considering elements one at a time, and placing them in their correct, ordered position.
// It compares an element with each of the preceding elements in descending order until its position is found.
// This function accepts as parameters a struct, a uint32_t type array, and a uint32_t which represents
// the number of elements in the array passed in the second parameter of the function.
void insertion_sort(Stats *stats, uint32_t *A, uint32_t n) {
    for (uint32_t i = 1; i < n; i++) {
        uint32_t j = i;
        uint32_t temp = A
            [i]; // Saving the value of the element currenty being compared to its preceding elements
        move(stats, A[i]);
        while (
            j > 0
            && cmp(stats, temp, A[j - 1])
                   == -1) { // Comparing the element in temp to its preceding elements one at a time
            A[j] = A[j - 1];
            move(stats, A[j - 1]);
            j = j - 1;
        }
        A[j] = temp; // Putting the element in temp in its correct, ordered position
        move(stats, temp);
    }
}
