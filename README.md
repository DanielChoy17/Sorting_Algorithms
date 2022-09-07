# Program Explanation

This program includes different types of sorting algorithms. The sorting algorithms in this program include Insertion Sort, Shell Sort, Heap Sort, and recursive Quicksort. The interfaces of these sorts are in the header files insert.h, shell.h, heap.h, and quick.h. The file that serves as the test harness for all the sorts is sorting.c. In this testing harness, an array of pseudorandom elements is generated in order to test each of the sorts. These sorting programs along with sorting an array will also provide us with statistics about each sort and its performance. The statistics include the size of the array, the number of moves required, and the number of comparisons required.


## Building

To build this program run:

...

$ make all

...

## Running 

To run the program:

...

$ ./sorting

...


This test harness supports the following command-line opetions:


-a: Employs all sorting algorithms.

-e: Enables Heap Sort.

-i: Enables Insertion Sort.

-s: Enables Shell Sort.

-q: Enables Quicksort.

-r seed: Set the random seed to seed. The default seed is 13371453.

-n size: Set the array size to size. The default size is 100.

-p elements: Print out elements number of elements from the array. The default number of elements to print out is 100.

-h: Prints out program usage.
