/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:14:02 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/03 13:51:34 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// ** ---------------------------- LIBRARIES ---------------------------- ** //

# include "libft.h"
# include <limits.h> // INT_MAX INT_MIN
# include <stdbool.h> // Include variable type bool
# include "errors.h"

//_--------------------------------------------------------------------------_//

// ** ------------------------- MACROS AND ENUMS ------------------------- ** //

enum e_operations
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

enum e_stacks
{
	A,
	B,
	START_INDEX = 0,
};

//_--------------------------------------------------------------------------_//

// ** ------------------------- DATA STRUCTURES ------------------------- ** //

/**
	@brief #### Node Stack structure
	@note//_DESCRIPTION
	@brief Node from the linked list stack, containing all relevant information
		for sorting.
	@note//_PARAMETERS
	@param num Numeric value to be sorted.
	@param index Index of the node in the stack.
	@param goal Index of the node in the sorted stack.
	@param price Amount of movements for the node to reach the goal.
	@param next Pointer to the next node in the stack.
	@param prev Pointer to the previous node in the stack.
	@note//_WARNING
	@warning Every node is allocated dynamically and must be freed after use.
 */
typedef struct s_stack_node
{
	int					num;
	int					index;
	int					goal;
	int					price;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

//_--------------------------------------------------------------------------_//

// ** ---------------------------- FUNCTIONS ---------------------------- ** //

/**
	@brief #### Finds the ideal place for each number in the stack
	@note//_DESCRIPTION
	@brief Goes through the stack and sets the `goal` variable to the index of
		the number in the sorted stack.
	@note//_PARAMETERS
	@param stack The stack containing the numbers to be sorted.
	@note//_NOTES
	@note This is the first step in the sorting process, and it is used to
		calculate the price of each number.
 */
void			set_goal(t_stack_node *stack);

/**
	@brief #### Prints the stack
	@note//_DESCRIPTION
	@brief Prints all the numbers in the stack, starting from the bottom.
	@note//_PARAMETERS
	@param stack The stack to be printed.
	@note//_NOTES
	@note This function is used for debugging purposes, and it is not part of
		the final program.
 */
void			print_stack(t_stack_node *stack);

/**
	@brief #### Adds a node to the stack
	@note//_DESCRIPTION
	@brief Allocates memory for a new node and adds it to the top of the stack.
	@note//_PARAMETERS
	@param stack The stack to which the node will be added.
	@param num The number to be added in `stack->num`.
	@note//_WARNING
	@warning The node is allocated dynamically and must be freed after use.
 */
void			add_node(t_stack_node *stack, int num);

/**
	@brief #### Check the arguments for errors
	@note//_DESCRIPTION
	@brief Checks that the argument is a number within the integer range, and
		it is not a duplicate.
	@note//_PARAMETERS
	@param argv The argument to be checked.
	@param stack The stack to be checked for duplicates and liberated if an
		error is found.
	@note//_NOTES
	@note Will exit the program if an error is found.
 */
void			check_arg(char *argv, t_stack_node stack[2]);

/**
	@brief #### Get the first node of the stack
	@note//_DESCRIPTION
	@brief Moves the pointer to the first node of the stack.
	@note//_PARAMETERS
	@param stack The address to check for a previous node.
	@note//_RETURN
	@return The address of the first node of the stack.
 */
t_stack_node	*stack_first(t_stack_node *stack);

/**
	@brief #### Gets the last node of the stack
	@note//_DESCRIPTION
	@brief Finds the last node of the stack and returns its address.
	@note//_PARAMETERS
	@param stack The address to check for a next node.
	@note//_RETURN
	@return The address of the last node of the stack.
 */
t_stack_node	*stack_last(t_stack_node *stack);

/**
	@brief #### Check for errors and exit the program if any is found
	@note//_DESCRIPTION
	@brief Checks `check[STATE]` for `-1` or if `check[STATE]` is `IF_NULL` and
		`if_null` is `NULL`. If any of these conditions are met, the function
		writes "Error" to the standard error output and prints the error message
		according to `check[ERROR]` and `check[WHERE]`. Then it frees the stacks
		and exits with the error code. If `check[STATE]` is `SUCCESS`, it frees
		the stacks and exits with code 0.
	@note//_PARAMETERS
	@param check Array of integers containing the state, where and error code,
		in that order.
	@param if_null Pointer to the variable to be checked for `NULL`.
	@param stacks Array of two `t_stack_node` structures, representing the two
		stacks to be freed.
	@note//_NOTES
	@note `STATE` is index 0, `WHERE` is 1 and `ERROR` is 2.
	@note For more information on the error codes and location codes available,
		see `errors.h`.
	@see `errors.h`
 */
void			exit_on_error(int check[3], void *if_null,
					t_stack_node stacks[2]);

//_--------------------------------------------------------------------------_//

#endif /* push_swap.h */