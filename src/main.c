/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:13:19 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/09/27 16:55:25 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// Checking if stack is already sorted. 1 if is sorted, 0 if not.

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// Depends of how big stack is - choosing the right sorting method.

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

// Checks if the input is correct, in which case it initializes stacks a and b.
// Assigns each value indexes and sorts the stacks. 
// When sorting is done, frees the stacks and exits.

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	char	**array;

	array = NULL;
	if (argc == 2)
		array = ft_split(argv[1], ' ');
	else if (argc > 2)
		array = arraydup(&argv[1]);
	if (!array || argc < 2)
		return (0);
	if (!is_correct_input(array))
		exit_error(NULL, NULL, array);
	stack_b = NULL;
	stack_a = NULL;
	stack_a = fill_stack_values(stack_a, array);
	freearray(array);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
