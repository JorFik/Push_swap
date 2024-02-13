/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:14:02 by JFikents          #+#    #+#             */
/*   Updated: 2024/02/13 20:28:47 by JFikents         ###   ########.fr       */
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

//If changed here, adapt set_price accordingly
# ifndef START_INDEX
#  define START_INDEX 0
# endif

enum e_rs
{
	RAS,
	RRAS,
	RBS,
	RRBS,
};

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
	RRR,
	NONE,
	REV
};

enum e_stacks
{
	A,
	B,
	PRE_NUM,
	PRE_GOAL,
	NXT_NUM,
	NXT_GOAL,
};

enum e_exit_or_return
{
	RETURN,
	EXIT,
};

//_--------------------------------------------------------------------------_//

// ** ------------------------- DATA STRUCTURES ------------------------- ** //

/**
	@brief #### The moves needed to sort the stack
	@note//_DESCRIPTION
	@brief A linked list containing the moves needed to sort the stack.
	@note//_PARAMETERS
	@param cmd The move to be done.
	@param next Pointer to the next move in the list.
	@param prev Pointer to the previous move in the list.
	@note//_WARNING
	@warning Every node is allocated dynamically and must be freed after use.
 */
typedef struct s_moves
{
	enum e_operations	cmd;
	struct s_moves		*next;
	struct s_moves		*prev;
}				t_moves;

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
	@param free Flag to check if the node should be freed.
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
	int					free;
	t_moves				*moves;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

//_--------------------------------------------------------------------------_//

// ** ---------------------------- FUNCTIONS ---------------------------- ** //

/**
	@brief #### Swaps `stack[A]` and `stack[B]`
	@note//_DESCRIPTION
	@brief Swaps all the contents of `stack[A]` and `stack[B]`.
	@note//_PARAMETERS
	@param stack The pointer to the stacks to be swapped.
 */
void			swap_stacks(t_stack_node *stack);

/**
	@brief #### Prints the command to the standard output
	@note//_DESCRIPTION
	@brief Checks in the `e_operations` enum and prints the corresponding
		command to the standard output.
	@note//_PARAMETERS
	@param cmd The `int` value of the command to be printed.
	@note//_NOTES
	@note This function is used for debugging purposes, and it is not part of
		the final program.
 */
void			print_cmd(int cmd);

/**
	@brief #### Frees the moves list
	@note//_DESCRIPTION
	@brief Goes through the `moves` list and frees every node in it.
	@note//_PARAMETERS
	@param moves The moves list to be freed.
 */
void			free_moves(t_moves **moves);

/**
	@brief #### Checks if moves can be avoided and then applies them
	@note//_DESCRIPTION
	@brief Checks if the moves in `stack->moves` contain any `RA` and `RB` or
		`RRA` and `RRB` together, if they do, it changes them to `RR` and `RRR`
		respectively. Then applies the moves to the stack.
	@note//_PARAMETERS
	@param stack The structure containing everythig needed to sort the stack.
 */
void			do_moves(t_stack_node *stack);

/**
	@brief #### Adds the commmand in the `stack->moves` linked list.
	@note//_DESCRIPTION
	@brief Creates a new node with the command `command` and adds it to the
		`stack->moves` linked list.
	@note//_PARAMETERS
	@param stack The stack containing the moves list.
	@note//_WARNING
	@warning Every node is allocated dynamically and must be freed after use.
 */
void			add_move(t_stack_node *stack, int command);

/**
	@brief #### Checks if the stack is in ascending order.
	@note//_DESCRIPTION
	@brief Checks if the `stack` is in ascending order, by checking if the
		`goal` is smaller than 'next->goal' for every node in the stack, except
		for the smallest number, for it `next->goal` is `START_INDEX`.
	@note//_PARAMETERS
	@param stack The stack to be checked.
 */
int				check_order_a(t_stack_node *stack);

/**
	@brief #### Does the best moves to sort the stack
	@note//_DESCRIPTION
	@brief Uses the smallest price node in `stack[A]` to find the moves to sort
		the `stack`.
	@note//_PARAMETERS
	@param stack The stacks to be sorted.
	@note//_NOTES
	@note If there is more than one node with the same price, there are priority
		rules to choose the best node to be moved, check `get_cheapest` comments
		in `find_moves.c` for more information.
 */
void			find_moves(t_stack_node *stack);

/**
	@brief #### Find the perfect match for node in `stack[A]`
	@note//_DESCRIPTION
	@brief Looks for the biggest number in `stack[B]` that is smaller than
		`stack->num` or the biggest number in `stack[B]` if `stack->num` is
		smaller than the smallest number in `stack[B]`.
	@note//_PARAMETERS
	@param stack The node address to be matched.
	@param max_index_a The index of the top node in `stack[A]` that is the
		biggest index in `stack[A]`.
	@param top_match The pointer to save the match from `stack[B]`.
	@note//_RETURN
	@return The pointer to the node in `stack[B]` that is the best match for
		`stack`.
 */
t_stack_node	*find_closest_biggest(t_stack_node *stack,
					const int max_index_a);

/**
	@brief #### Gets the smallest number in the stack.
	@note//_DESCRIPTION
	@brief Goes through the `stack` and returns the smallest number in it.
	@note//_PARAMETERS
	@param stack The stack to be checked.
	@note//_RETURN
	@return The smallest `stack->num` value in the stack.
	@note The function will start from where you are in the stack, so make sure
		to send the pointer to the bottom of the stack if you want to check the
		entire stack.
 */
int				get_smallest_num(t_stack_node *stack);

/**
	@brief #### Gets the biggest number in the stack.
	@note//_DESCRIPTION
	@brief Looks for the biggest `stack->num` value in `stack` and returns it.
	@note//_PARAMETERS
	@param stack The stack to be checked.
	@note//_RETURN
	@return The biggest `stack->num` value in the stack.
	@note//_NOTES
	@note The function will start from where you are in the stack, so make sure
		to send the pointer to the bottom of the stack if you want to check the
		entire stack. 
 */
int				get_biggest_num(t_stack_node *stack);

/**
	@brief #### Checks if the stack is in descending order.
	@note//_DESCRIPTION
	@brief Checks if the `stack` is in descending order, by checking if the
		`goal` is bigger than 'next->goal' for every node in the stack, except
		for the biggest number, for it `next->goal` is `START_INDEX`.
	@note//_PARAMETERS
	@param stack The stack to be checked.
 */
int				check_order_b(t_stack_node *stack);

/**
	@brief #### Restarts the `goal` for each node in the stack.
	@note//_DESCRIPTION
	@brief Sets the `goal` for each node in the `stack` to `START_INDEX - 1`.
	@note//_PARAMETERS
	@param stack The stack to be restarted.
 */
void			restart_goal(t_stack_node *stack);

/**
	@brief #### Sets the goal for each node in descending order.
	@note//_DESCRIPTION
	@brief Sets the `goal` for each node in the `stack` in descending order.
	@note//_PARAMETERS
	@param stack The stack to be checked.
 */
void			set_goal_b(t_stack_node *stack);

/**
	@brief #### PENDING
	@note//_DESCRIPTION
	@brief PENDING
	@note//_PARAMETERS
	@param stack The stack to be sorted.
	@note//_NOTES
	@note PENDING
 */
void			sort(t_stack_node *stack);

/**
	@brief #### Sets the price for each node in the `stack[A]`
	@note//_DESCRIPTION
	@brief Sets the price for each node in the `stack[A]` based on the amount of
		movements needed to reach the top of the stack.
	@note//_PARAMETERS
	@param stack The stack to set the price for.
	@note//_WARNING
	@warning Send `stack` at the bottom of the stack.
	@note//_NOTES
	@note The index starts from `START_INDEX` that is `0` in the bottom, prices
		may vary if the index is different, but in theory the cheapest should be
		the same regardless of the index.
 */
void			set_price(t_stack_node *stack);

/**
	@brief #### Pushes the top node of the `stack[A]` to the `stack[B]`.
	@note//_DESCRIPTION
	@brief Moves the top node of the `stack[A]` to the top of the `stack[B]` taking
		into account if the node can be moved or if it needs to be copied.
	@note//_PARAMETERS
	@param stack The stacks to be modified.
	@note//_NOTES
	@note The function will not print the operation to the standard output that
		is done by the `move` function.
	@note If the node was copied the index will be set to `START_INDEX - 1`.
 */
void			push_b(t_stack_node stack[2]);

/**
	@brief #### Pushes the top node of `stack[B]` to `stack[A]`.
	@note//_DESCRIPTION
	@brief Moves the top node of the `stack[B]` to the top of the `stack[A]` taking
		into account if the node can be moved or if it needs to be copied.
	@note//_PARAMETERS
	@param stack The stacks to be modified.
	@note//_NOTES
	@note The function will not print the operation to the standard output that
		is done by the `move` function.
	@note If the node was copied the index will be set to `START_INDEX - 1`.
 */
void			push_a(t_stack_node stack[2]);

/**
	@brief #### Applies the `cmd` to the stacks
	@note//_DESCRIPTION
	@brief Applies the command `cmd` to the stacks `stack` and prints the
		operation to the standard output.
	@note//_PARAMETERS
	@param stack The stacks to be modified.
	@param cmd The command to be applied to the stacks.
	@note//_NOTES
	@note The list of commands is defined in `e_operations` in `push_swap.h`.
 */
void			move(t_stack_node *stack, int cmd);

/**
	@brief #### Checks if the stack is sorted
	@note//_DESCRIPTION
	@brief Checks if `stack->goal` is equal to `stack->index` for every node in
		the stack. If it is and `exit` is set to `1`, the function frees the
		stack and exits with code 0, else it returns 1 if the stack is sorted and
		0 if it is not.
	@note//_PARAMETERS
	@param stack the stack to be checked.
	@param exit The flag to select either if the function should exit or return
		a value.
	@note//_NOTES
	@note The function will exit with code 0 if the stack is sorted and `exit`
		is true. make sure to use it only after printing the operations.
	@note//_RETURN
	@return 1 if the stack is sorted, 0 if it is not.
 */
int				check_stack(t_stack_node *stack, int exit);

/**
	@brief #### Finds the ideal place for each number in the `stack[A]`
	@note//_DESCRIPTION
	@brief Goes through the `stack` and sets the `goal` variable to the index of
		the number in the sorted `stack`.
	@note//_PARAMETERS
	@param stack The stack containing the numbers to be sorted.
	@note//_NOTES
	@note The sorted stack is the one that has the numbers in ascending order.
 */
void			set_goal_a(t_stack_node *stack);

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
	@brief #### Get the bottom node of the stack
	@note//_DESCRIPTION
	@brief Moves the pointer to the bottom node of the stack.
	@note//_PARAMETERS
	@param stack The address to check for a previous node.
	@note//_RETURN
	@return The address of the bottom node of the stack.
 */
t_stack_node	*stack_bottom(t_stack_node *stack);

/**
	@brief #### Gets the top node of the stack
	@note//_DESCRIPTION
	@brief Finds the top node of the stack and returns its address.
	@note//_PARAMETERS
	@param stack The address to check for a next node.
	@note//_RETURN
	@return The address of the top node of the stack.
 */
t_stack_node	*stack_top(t_stack_node *stack);

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