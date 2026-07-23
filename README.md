*This project has been created as part of the 42 curriculum by lusampai, armarque*

# Push_swap

## Description

The goal of this project is to develop a program that sorts a stack in ascending order using sorting algorithms. The initial stack (stack A) is provided as input by the user, while stack B starts empty. The stack must be sorted using only these two stacks and the operations allowed by the Push_swap subject. The sorting algorithm can be selected using different flags. If no algorithm is specified, the adaptive mode is used by default. Additional flags, such as `--bench`, can be used to display the number of operations and other execution statistics.

### Algorithms

#### `--simple` (Selection Sort)

This flag selects the Selection Sort algorithm, which is optimized for small input sizes.

**Time complexity:** O(n²)  
**Space complexity:** O(1)

#### `--medium` (Bucket Sort by Relative Index)

This flag selects the Bucket Sort algorithm, which is optimized for medium-sized inputs with a relatively low level of disorder.

**Time complexity:** O(n√n)  
**Space complexity:** O(1)

#### `--complex` (Radix Sort)

This flag selects the Radix Sort algorithm, which is optimized for large input sizes, regardless of the initial level of disorder.

**Time complexity:** O(n log n)  
**Space complexity:** O(1)

#### `--adaptive`

This flag automatically selects the algorithm according to the estimated disorder of the list. 

- Disorder below 20% -> `--simple`
- Disorder between 20% and 50% -> `--medium`
- Disorder above 50% -> `--complex`

### Adaptive Thresholds

The thresholds were chosen based on the behavior of each algorithm. Selection Sort performs better on nearly sorted and small inputs, Bucket Sort provides a good balance between operation count and input size for moderately disordered and medium inputs, and Radix Sort is more efficient for highly disordered or large inputs.

## Instructions

### Commands

To compile and run the program, use the following commands:

```bash
make
./push_swap [--bench] [--simple | --medium | --complex | --adaptive] <numbers>
```

`--bench` (optional)

- Displays the execution statistics

`numbers`

- The list of integers to sort

### Examples

```bash
./push_swap 6 2 7 9
./push_swap --bench 4 8 2 9 7
./push_swap --medium 9 0 2 8 4 7
./push_swap --bench --simple 7 3 5 6 1 0 9 8
```

## Team Contributions

### lusampai (Lucas)

- Implemented the Selection Sort (Simple algorithm).
- Implemented the Bucket Sort (Medium algorithm).
- Implemented the Adaptive Mode and algorithm selection logic.
- Developed the relative index system.
- Worked on the benchmark flag.
- Developed the Push_swap operations.
- Worked on the documentation.
- Worked on the main program structure.
- Worked on the `push_swap.c` functions.
- Developed helper functions.
- Developed the Makefile.
- Assisted with the project organization.
- Assisted with testing and optimization.

### armarque (Arthur)

- Implemented the Radix Sort (Complex algorithm).
- Developed small input sorting algorithms (2, 3, and 5 numbers).
- Worked on the main program structure.
- Worked on the `push_swap.c` functions.
- Developed helper functions.
- Developed the error handling system.
- Assisted with the project organization.
- Assisted with testing and optimization.
- Implemented helper functions for the bench flag.
- Implemented the operation output system.

## Resources

### Links

- [W3Schools - Selection Sort](https://www.w3schools.com/dsa/dsa_algo_selectionsort.php)
- [Wikipedia - Bucket Sort](https://pt.wikipedia.org/wiki/Bucket_sort)
- [GeeksforGeeks - Radix Sort](https://www.geeksforgeeks.org/dsa/radix-sort/)

### Use of AI

AI was used throughout the development of this project to assist with learning and understanding the algorithms, debugging, code review, and Git management. AI was also used to help create and improve this README file.
