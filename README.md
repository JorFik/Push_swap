# Push_swap

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

## Description

`Push_swap` is a sorting program in C that uses two stacks, `A` and `B`. The goal is to sort the data in `stack[A]` in ascending order, using `stack[B]` as auxiliary workspace.

The program can perform the following operations:

`sa` : swap the first two elements in `stack[A]`.
`sb` : swap the first two elements in `stack[B]`.
`ss` : perform `sa` and `sb` simultaneously.
`pa` : move the top element from `stack[B]` to `stack[A]`.
`pb` : move the top element from `stack[A]` to `stack[B]`.
`ra` : rotate `stack[A]` upwards, moving the first element to the end.
`rb` : rotate `stack[B]` upwards, moving the first element to the end.
`rr` : perform `ra` and `rb` simultaneously.
`rra` : rotate `stack[A]` downwards, moving the last element to the front.
`rrb` : rotate `stack[B]` downwards, moving the last element to the front.
`rrr` : perform `rra` and `rrb` simultaneously.
The `Push_swap` program takes a list of integer numbers as arguments and returns a series of operations that, when performed, will sort the list. The goal is to do this with the least number of operations possible.


## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Installation

To install `Push_swap`, clone the repository 

#### SSH
```bash
git clone git@github.com:JorFik/Push_swap.git
```
#### HTTPS
```bash
git clone https://github.com/JorFik/Push_swap.git
```
#### GitHub CLI
```bash
gh repo cloneJorFik/Push_swap
```
This will create a directory called `Push_swap/`, enter with the command

```bash
cd Push_swap
```
Once inside, create the program `push_swap` with the following command

```bash
make
```

## Usage

To run the program you need to give a list of integers unsorted
```bash
./push_swap 2 4 3 5 7 9
```
It will print the operations to sort the values.
```bash
pb
pb
pb
sb
pb
pb
pa
pa
pa
pa
pa
```

## License

This project is licensed under the [MIT License](LICENSE).
