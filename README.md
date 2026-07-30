*This project has been created as part of the 42 curriculum by lusampai, armarque*

# Push_swap

## Description

The goal of this project is to develop a program that sorts a stack in ascending order using sorting algorithms. The initial stack (stack A) is provided as input by the user, while stack B starts empty. The stack must be sorted using only these two stacks and the operations allowed by the Push_swap subject. The sorting algorithm can be selected using different flags. If no algorithm is specified, the adaptive mode is used by default. Additional flags, such as `--bench`, can be used to display the number of operations and other execution statistics.

### Algorithms

#### `--simple` (Selection Sort)

This flag selects the Selection Sort algorithm, which is optimized for small input sizes.

For each remaining element in stack A, the algorithm performs a linear scan (`ft_get_smaller`) to find the minimum value, then rotates A (`ra` or `rra`, whichever side is closer) until that element reaches the top, and pushes it onto B (`pb`). Once A is empty, all elements are pushed back (`pa`), restoring the sorted order. Since each of the n elements requires an O(n) scan plus O(n) rotations in the worst case, the total cost is O(n²) operations.

**Time complexity:** O(n²)  
**Space complexity:** O(1)

#### `--medium` (Bucket Sort by Relative Index)

This flag selects the Bucket Sort algorithm, which is optimized for medium-sized inputs with a relatively low level of disorder.

The stack is split into √n buckets based on each element's relative index (`ft_bucket_count`, `ft_bucket_init`), each covering a contiguous range of ranks. For each bucket, the algorithm repeatedly finds the closest element within that range (`ft_bucket_nearest`), rotates A the shortest way to bring it to the top, and  ushes it onto B (`ft_move_best`). Once all buckets are processed, `ft_organize_return` empties B back into A by repeatedly rotating to the largest remaining  alue and pushing it in (`pa`). Since each of the n elements needs an O(√n) search plus O(√n) rotation within its bucket, the total cost is O(n√n) operations.

**Time complexity:** O(n√n)  
**Space complexity:** O(1)

#### `--complex` (Radix Sort)

This flag selects the Radix Sort algorithm, which is optimized for large input sizes, regardless of the initial level of disorder.

The stack is sorted based on each element's relative index (its rank between 0 and n-1), processing one bit at a time, least significant first. In each bit pass, every element in A is checked once: if the bit is 1 it's rotated (`ra`) to the end; if it's 0 it's pushed to B (`pb`), then pushed back (`pa`) to preserve order. Since each element is processed once per one of log(n) bit passes, the total cost is O(n log n) operations.  Note: since sorting is based on the relative index (always the set {0, ..., n-1}) rather than the raw values, the total number of operations depends only on n — not on the initial order. That's why shuffling the same n values with `shuf` doesn't change the operation count, only which elements move to `ra` vs `pb` in each pass.

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

AI tools (ChatGPT and Claude) were used to support the development of this project,
specifically for:

- Understanding sorting algorithm complexity and how it applies to the Push_swap
  operation model.
- Debugging the bucket sort's index-range logic and the radix sort's bit processing.
- Code review for Norm compliance.
- Drafting and formatting this README.

All AI-assisted content was reviewed and understood by both learners before
submission.
