/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:47:16 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/09/26 18:26:02 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack_values(t_stack *stack_a, char **array)
{
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 0;
	while (array[i])
	{
		nb = ft_atoi(array[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 0)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

// Assigns an index to each value in stack a. This is a convenient way to order
// the stack because indexes can be checked 
// and compared instead of actual values,
// which may or may not be adjacent to each other.
// 	ex. values:		-3	 0	 9	 2
// 	indexes:		[1]	[2]	[4]	[3]
// The indexes are assigned from highest (stack_size) to lowest (1).
void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		val;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		val = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > val && ptr->index == 0)
			{
				val = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
