/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:40:43 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/07/13 19:49:03 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Find and returns the highest index in the stack.
static int	find_highest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

//Sorting stack of 3 numbers in 2 or less moves.
//Sorting by index, not values.
void	tiny_sort(t_stack **stack)
{
	int	h_indx;

	if (is_sorted(*stack))
		return ;
	h_indx = find_highest_index(*stack);
	if ((*stack)->index == h_indx)
		do_ra(stack);
	else if ((*stack)->next->index == h_indx)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}
