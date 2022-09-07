#include "stats.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

// This function is used to determine which child (the left or right) is the larger one.
// This function returns the max child between the left or the right.
// This function takes in as paramters an array of type uint32_t, a uint32_t which will be represented as first, and a uint32_t which will be
// represented as last.
uint32_t max_child(Stats *stats, uint32_t *A, uint32_t first, uint32_t last) {
    uint32_t left = 2 * first;
    uint32_t right = left + 1;
    if (right <= last && cmp(stats, A[right - 1], A[left - 1]) > 0) {
        return right;
    }
    return left;
}

// This function is needed as the array is sorted. This routine is used to repeatedly remove from the top of the heap the largest array elements
// and place them at the end of the sorted array. After removing the largest element from the heap, the heap needs to be fixed so that it obeys the
// contraints of a heap still.
// This function takes in as parameters an array of type uint32_t, a uint32_t which will be represented as first, and a uint32_t which will be
// represented as last.
void fix_heap(Stats *stats, uint32_t *A, uint32_t first, uint32_t last) {
    bool found = false;
    uint32_t mother = first;
    uint32_t great = max_child(stats, A, mother, last);
    while (mother <= last / 2 && found != true) {
        if (cmp(stats, A[mother - 1], A[great - 1]) == -1) {
            swap(stats, &A[mother - 1], &A[great - 1]);
            mother = great;
            great = max_child(stats, A, mother, last);
        } else {
            found = true;
        }
    }
}

// This function involves taking the array to sort and building a heap from it ordering the array elements such that they obey the contraints
// of a max heap which means that the largest element, the root of the heap, is the first element of the array from which the heap is built.
// This function takes in as parameters an array of type uint32_t, a uint32_t which will be represented by first, and a uint32_t
// which will be represented by last.
void build_heap(Stats *stats, uint32_t *A, uint32_t first, uint32_t last) {
    for (uint32_t father = last / 2; father > first - 1; father = father - 1) {
        fix_heap(stats, A, father, last);
    }
}

// This function sorts its elements using two routines which are building heap and fixing heap.
// This function takes in as parameters a struct, a uint32_t type array, and a uint32_t which represents
// the number of elements in the array passed in the second parameter of the function.
void heap_sort(Stats *stats, uint32_t *A, uint32_t n) {
    uint32_t first = 1;
    uint32_t last = n;
    build_heap(stats, A, first, last);
    for (uint32_t leaf = last; leaf > first; leaf = leaf - 1) {
        swap(stats, &A[first - 1], &A[leaf - 1]);
        fix_heap(stats, A, first, leaf - 1);
    }
}
