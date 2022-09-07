#include "heap.h"
#include "insert.h"
#include "quick.h"
#include "set.h"
#include "shell.h"
#include "stats.h"

#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define OPTIONS "aeisqr:n:p:h"

typedef enum { HEAP, SHELL, INSERTION, QUICK, HELP } Sorts;

// This helper function prepares the array before calling a sort and resets the moves and compares counters.
// This function takes as parameters a struct, a uint32_t type array, a uint32_t called seed which is the seed number we are using, and a uint32_t
// called size which is the size of the array.
void preparation(Stats *stats, uint32_t *A, uint32_t seed, uint32_t size) {
    srandom(seed);
    for (uint32_t i = 0; i < size; i++) {
        A[i] = random() & (((uint32_t) 1 << (30)) - 1);
    }
    reset(stats);
}

// Contains the main function and serves as the test harness for all the sorts. In this testing harness, an
// array of pseudorandom elements is generated in order to test each of the sorts.
// This function takes as parameters an int which will be represented by argc and a char which will be
// represented as argv.
int main(int argc, char **argv) {
    Set sorts_set = empty_set();
    int opt = 0;
    uint32_t seed = 13371453;
    uint32_t size = 100;
    uint32_t elements = 100;
    Stats stats;

    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a':
            sorts_set = insert_set(HEAP, sorts_set);
            sorts_set = insert_set(SHELL, sorts_set);
            sorts_set = insert_set(INSERTION, sorts_set);
            sorts_set = insert_set(QUICK, sorts_set);
            break;
        case 'e': sorts_set = insert_set(HEAP, sorts_set); break;
        case 'i': sorts_set = insert_set(INSERTION, sorts_set); break;
        case 's': sorts_set = insert_set(SHELL, sorts_set); break;
        case 'q': sorts_set = insert_set(QUICK, sorts_set); break;
        case 'r': seed = strtoul(optarg, NULL, 10); break;
        case 'n': size = strtoul(optarg, NULL, 10); break;
        case 'p': elements = strtoul(optarg, NULL, 10); break;
        case 'h': sorts_set = insert_set(HELP, sorts_set); break;
        }
    }
    uint32_t *A = (uint32_t *) calloc(size, sizeof(uint32_t));
    if (size < elements) {
        elements = size;
    }
    if (member_set(HELP, sorts_set)
        || ((member_set(HEAP, sorts_set) == false) && (member_set(SHELL, sorts_set) == false)
            && (member_set(INSERTION, sorts_set) == false)
            && (member_set(QUICK, sorts_set) == false))) {
        printf("SYNOPSIS\n");
        printf("   A collection of comparison-based sorting algorithms.\n\n");
        printf("USAGE\n");
        printf("   ,/sorting [haeisqn:p:r:] [-n length] [-p elements] [-r seed]\n\n");
        printf("OPTIONS\n");
        printf("   -h              display program help and usage.\n");
        printf("   -a              enable all sorts.\n");
        printf("   -e              enable Heap Sort.\n");
        printf("   -i              enable Insertion Sort.\n");
        printf("   -s              enable Shell Sort.\n");
        printf("   -q              enable Quick Sort.\n");
        printf("   -n length       specify number of array elements (default: 100).\n");
        printf("   -p elements     specify number of elements to print (default: 100).\n");
        printf("   -r seed         specify random seed (default: 13371453).\n");
    } else {
        if (member_set(HEAP, sorts_set)) {
            preparation(&stats, A, seed, size);
            heap_sort(&stats, A, size);
            printf("Heap Sort, %u elements, %lu moves, %lu compares\n", elements, stats.moves,
                stats.compares);
            for (uint32_t i = 0; i < elements; i++) {
                printf("%13" PRIu32, A[i]);
                if ((i + 1) % 5 == 0 || (i + 1) == elements) {
                    printf("\n");
                }
            }
        }
        if (member_set(SHELL, sorts_set)) {
            preparation(&stats, A, seed, size);
            shell_sort(&stats, A, size);
            printf("Shell Sort, %u elements, %lu moves, %lu compares\n", elements, stats.moves,
                stats.compares);
            for (uint32_t i = 0; i < elements; i++) {
                printf("%13" PRIu32, A[i]);
                if ((i + 1) % 5 == 0 || (i + 1) == elements) {
                    printf("\n");
                }
            }
        }
        if (member_set(INSERTION, sorts_set)) {
            preparation(&stats, A, seed, size);
            insertion_sort(&stats, A, size);
            printf("Insertion Sort, %u elements, %lu moves, %lu compares\n", elements, stats.moves,
                stats.compares);
            for (uint32_t i = 0; i < elements; i++) {
                printf("%13" PRIu32, A[i]);
                if ((i + 1) % 5 == 0 || (i + 1) == elements) {
                    printf("\n");
                }
            }
        }
        if (member_set(QUICK, sorts_set)) {
            preparation(&stats, A, seed, size);
            quick_sort(&stats, A, size);
            printf("Quick Sort, %u elements, %lu moves, %lu compares\n", elements, stats.moves,
                stats.compares);
            for (uint32_t i = 0; i < elements; i++) {
                printf("%13" PRIu32, A[i]);
                if ((i + 1) % 5 == 0 || (i + 1) == elements) {
                    printf("\n");
                }
            }
        }
    }
    free(A);
}
