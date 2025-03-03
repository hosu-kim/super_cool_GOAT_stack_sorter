<h1 align="center">Super Cool GOAT Stack Sorter</h1>
<p align="center">
  <img src="images/logo.jpeg" width="600">
</p>

![Version](https://img.shields.io/badge/Version-1.0-green)
![Status](https://img.shields.io/badge/Status-Completed-success)

A highly optimized integer sorting project implementing custom stack-based sorting algorithms through the `push_swap` program.

## Table of Contents
1. [Overview](#overview)
2. [Program Functionality](#program-functionality)
3. [Features](#features)
4. [Algorithm Design](#algorithm-design)
5. [Installation](#installation)
6. [Usage](#usage)
7. [Examples](#examples)
8. [Testing](#testing)
9. [Program Structure](#program-structure)
10. [Contributing](#contributing)
11. [License](#license)
12. [Author](#author)
13. [Support](#support)

## Overview

Super Cool GOAT Stack Sorter presents `push_swap`, a custom sorting application that implements efficient stack-based sorting algorithms. Given a set of integers, the program outputs a sequence of operations that sorts the data in the most efficient way possible using only two stacks and a limited set of operations.

## Program Functionality

The `push_swap` program takes a sequence of integers as input and:

1. Parses and validates the input data
2. Determines the most efficient sorting strategy based on input size
3. Executes the appropriate sorting algorithm
4. Outputs the sequence of operations needed to sort the data

The program uses two stack (A and B) and performs operations like swapping, pushing, and rotating elements to achieve the sorted state. What makes `push_swap` unique is its focus on minimizing the number of operations needed to sort the data.

### Available Stack Operations

| Operation | Description |
|-----------|-------------|
| **sa** | Swap the first 2 elements at the top of stack A |
| **sb** | Swap the first 2 elements at the top of stack B |
| **ss** | Execute sa and sb simultaneously |
| **pa** | Take the top element from stack B and push it to stack A |
| **pb** | Take the top element from stack A and push it to stack B |
| **ra** | Rotate stack A upward (first element becomes last) |
| **rb** | Rotate stack B upward (first element becomes last) |
| **rr** | Execute ra and rb simultaneously |
| **rra** | Reverse rotate stack A downward (last element becomes first) |
| **rrb** | Reverse rotate stack B downward (last element becomes first) |
| **rrr** | Execute rra and rrb simultaneously |

## Features

- **Multi-strategy sorting system** that selects the optimal algorithm based on input size
- **Memory-efficient implementation** that minimizes resource usage
- **Robust error handling** that validates input and prevents crashes
- **Optimized for performance** with minimal operation counts
- **Clean output format** showing the exact sequence of opertaions
- **Scalable from small to large datasets** with different optimization techniques

## Algorithm Design

The Super Cool GOAT Stack Sorter implements multiple sorting strategies optimized for different data sizes:

### Small Dataset Optimization
For small datasets (2-5 elements), the program uses specialized algorithms that:
- Handle each permutation with the minimum possible operations
- Use pattern recognition to immediately identify the optimal solution
- Execute direct, targeted operations without complex calculations

### Large Dataset Optimization
For larger datasets, the program employs a sophisticated chunking strategy:
- Data is divided into optimal-sized chunks based on the input size
- Elements are strategically distributed between stacks using pivot values
- Partial pre-sorting during distribution reduces later operations
- Final sorting uses position optimization to minimize movements

## Installation

Clone the repository:
```bash
git clone https://github.com/hosu-kim/super_cool_GOAT_stack_sorter.git
```
```bash
cd super_cool_GOAT_stack_sorter
```
Compile the program:
```bash
make
```

## Usage

```bash
./push_swap [integers]
```

The program accepts integers as command-line arguments and outputs the sequence of operations to sort them.

### Input Requirements
- Values must be integers
- Each number must be unique
- Numbers must be within the integer range (-2147483648 to 2147483647)

## Examples

### Example 1: Small Set
```bash
$ ./push_swap 3 1 2
sa
```
This performs one swap operation to sort the three numbers.

### Example 2: Medium Set
```base
$ ./push_swap 5 1 4 2 3
pb
ra
pb
sa
ra
pa
ra
pa
```
The program determines an efficient sequence of 8 operations to sort these 5 number.

### Example 3: Error Case
```bash
$ ./push_swap 10 20 10
Error
```
The program detects duplicate values and outputs an error message.

## Testing

You can verify the correctness of your push_swap implementation using the provided checker program located in the `test` directory:

```bash
ARG="4 67 3 87 23"; ./test/push_swap $ARG | ./checker_linux $ARG
```

This command:
1. Generates a sequence of operations from your push_swap program
2. Pipes these operations to the checker program
3. The checker verifies if the operations correctly sort the input numbers

### Checker Results

The checker will output one of the following:
- `OK`: The operations correctly sort the input numbers
- `KO`: The operations fail to sort the input numbers
- `Error`: An error occurred during execution (invalid operation or other issue)

### Testing Random Inputs

For thorough testing with random numbers:

```bash
# Test with 5 random numbers
ARG=$(shuf -i 1-100 -n 5 | tr "\n" " "); echo $ARG; ./push_swap $ARG | ./test/checker_linux $ARG

# Test with 100 random numbers and count operations
ARG=$(shuf -i 1-1000 -n 100 | tr "\n" " "); ./push_swap $ARG | wc -l
```

### Performance Benchmarks

For optimal grading results, aim for:
- 3 numbers: ≤ 2 operations
- 5 numbers: ≤ 12 operations
- 100 numbers: ≤ 700 operations 
- 500 numbers: ≤ 5500 operations

## Program Structure

| Component | Description |
|-----------|-------------|
| **Core Engine** | Main program logic and algorithm selector |
| **Stack Implementation** | Custom stack data structure with optimized operations |
| **Operation Modules** | Implementation of push, swap, rotate and reverse operations |
| **Sorting Algorithms** | Small-set and large-set sorting strategies |
| **Utility Functions** | Input validation, error handling, and helper functions |

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Author

hosu-kim (hosu@outlook.cz)

## Support

For support, please create an issue in the GitHub repository or contact me directly.
