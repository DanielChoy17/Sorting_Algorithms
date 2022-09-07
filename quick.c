#include "stats.h"

#include <stdint.h>
#include <stdio.h>

// This function is the part where an array gets partitioned into two sub-arrays by selecting an element from the array and designing it as pivot.
// Elements in the array that are less than the pivot go to the left sub_array, and elements in the array that are greater than or equal to the
// pivot go to the right sub-array. Then the index that indicates the division between the partitioned parts of the array is returned.
// This function returns the index that indicates the division between the partitioned parts of the array.
// This function takes in as parameters an array of type uint32_t, a uint32_t which will be represented by lo, and a uint32_t which will be
// represented as hi.
uint32_t partition(Stats *stats, uint32_t *A, uint32_t lo, uint32_t hi) {
    uint32_t i = lo - 1;
    for (uint32_t j = lo; j < hi; j++) {
        if (cmp(stats, A[j - 1], A[hi - 1]) == -1) {
            i = i + 1;
            swap(stats, &A[i - 1], &A[j - 1]);
        }
    }
    swap(stats, &A[i], &A[hi - 1]);
    return i + 1;
}

// This function is the part where quick_sorter is applied recursively on the partitioned parts of the array in order to sort each array partition
// containing at least one element.
// This function takes in as parameters an array of type uint32_t, a uint32_t which will be represented by lo, and a uint32_t which will be
// represented as hi.
void quick_sorter(Stats *stats, uint32_t *A, uint32_t lo, uint32_t hi) {
    if (lo < hi) {
        uint32_t p = partition(stats, A, lo, hi);
        quick_sorter(stats, A, lo, p - 1);
        quick_sorter(stats, A, p + 1, hi);
    }
}

// This function sorts an array by partitioning an array into two sub-arrays by selecting an element from the array and designing it as pivot.
// Elements in the array that are less than the pivot go to the left sub_array, and elements in the array that are greater than or equal to the
// pivot go to the right sub-array. Then the index that indicates the division between the partitioned parts of the array is returned.
// quick_sorter is then applied recursively on the partitioned parts of the array, sorting each array partition containing at least one element.
// This function takes in as parameters a struct, an array of type uint32_t, and a uint32_t which represents the number of elements
// in the array passed in the seconf parameter.
void quick_sort(Stats *stats, uint32_t *A, uint32_t n) {
    quick_sorter(stats, A, 1, n);
}
