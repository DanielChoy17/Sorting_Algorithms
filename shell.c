#include "stats.h"

#include <math.h>
#include <stdint.h>
#include <stdio.h>

static uint32_t decrease_count = 0;

// This function generates the gap sequence.
// This function returns the new gap generated.
// The parameters that this function accepts is a uint32_t which represents the number of elements
// in the array that we are sorting.
uint32_t gaps(uint32_t n) {
    uint32_t i = (log(3 + (2 * n)) / log(3)) - decrease_count;
    return ((pow(3, i) - 1) / 2); // Computes and returns gap
}

// This function sorts an array by first sorting pairs of elements which are far apart from each other
// where the distance between these pairs of elements are called a gap. Each iteration the gap decreases
// until a gap of 1 is used which at this point means that the array has been sorted.
// This function accepts as parameters a struct, a uint32_t type array, and a uint32_t which represents
// the number of elements in the array passed in the second parameter of the function.
void shell_sort(Stats *stats, uint32_t *A, uint32_t n) {
    for (uint32_t gap = gaps(n); decrease_count + 1 <= (log(3 + (2 * n)) / log(3));
         decrease_count++) { // Iterates through each gap in the gap sequence
        gap = gaps(n); // Calls the function gaps to generate a new gap for the next iteration
        for (uint32_t i = gap; i < n; i++) {
            uint32_t j = i;
            uint32_t temp = A[i];
            move(stats, A[i]);
            while (j >= gap && cmp(stats, temp, A[j - gap]) < 0) {
                A[j] = A[j - gap];
                move(stats, A[j - gap]);
                j = j - gap;
            }
            A[j] = temp;
            move(stats, temp);
        }
    }
}
