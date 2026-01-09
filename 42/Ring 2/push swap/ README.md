*This project has been created as part of the 42 curriculum by wwiedijk.*

## Description

push_swap is a 42 project that implements a sorting program using two stacks and a limited set of operations. The goal is to sort a list of integers (ascending) while producing the smallest possible sequence of operations. This repository contains a C implementation that parses input, builds two stacks, and uses algorithmic strategies to minimize the number of operations required to sort the numbers.

Key points:
- Input: list of integers passed as program arguments (or quoted string arguments).
- Output: the program prints a sequence of stack operations (one per line) that, when applied to the initial stack, will result in a sorted stack.
- Constraints: only allowed stack operations must be used (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr).

### AI usage

- a AI assistance was used to draft and format this `README.md` file and to suggest wording and examples for the Instructions and Resources sections.


## Instructions

 Ensure you have a checker for the operating system you using, if not download it.  
for mac https://cdn.intra.42.fr/document/document/44202/checker_Mac
for linux https://cdn.intra.42.fr/document/document/44203/checker_linux

### Usage
- Basic usage:
```bash
make
```

- This will build the `push_swap` binary.

```bash
./push_swap 3 2 1 0
```

- You can also pass a single quoted string with space-separated integers:

```bash
./push_swap "2 1 0"
```


```bash
# Generate operations and validate with checker
./push_swap 3 2 1 | ./checker_linux 3 2 1
```

## Project structure (selected files)

- `main.c`, `sort.c`, `stack1.c`, `operations1.c`, `utils.c` — core program logic.
- `Pushswap.h` — project header and types.
- `libft/` — utility library used by the project.

## The Algorithm

This implementation is based on the Turk algorithm, developed by A. Yigit Ogun
(https://medium.com/@ayogun/push-swap-c1f5d2d41e97
), named after the Mechanical Turk.

The algorithm can be described as a highly optimized variant of insertion sort adapted to the constraints of the push_swap project. The sorting process is performed using two stacks (A and B) and relies on cost-based decision-making to minimize the total number of operations.

At each step, the algorithm evaluates all candidate nodes in the active stack and computes the cost of moving each node to its correct position in the target stack. This cost includes the number of required rotations and reverse rotations for both stacks. The node with the lowest total cost is selected as the cheapest node and moved accordingly.