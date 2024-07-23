/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:50:08 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/07/23 22:25:08 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Reverse rotates both stack a and b until one of them is in position.
// The given cost is negative since both positions are in the bottom half
// of their respective stacks. The cost is increased as the stacks are
// rotated, when one reaches 0, the stack has been rotated as far as possible
// and the top position is correct.
static void	do_rev_rotate_both(t_stack **a, t_stack **b,
								int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(a, b);
	}
}

// Rotates both stack a and b until one of them is in position.
// The given cost is positive since both positions are in the top half
// of their respective stacks. The cost is decreased as the stacks are
// rotated, when one reaches 0, the stack has been rotated as far as possible
// and the top position is correct.
static void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b);
	}
}

// Rotates stack a until it is in position. If the cost is negative,
// the stack will be reverse rotated, if it is positive, it will be 
// rotated.
static void	do_rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rra(a);
			(*cost)++;
		}
	}
}

// Rotates stack b until it is in position. If the cost is negative,
// the stack will be reverse rotated, if it is positive, it will be 
// rotated.
static void	do_rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rrb(b);
			(*cost)++;
		}
	}
}

// Chooses which move to make to get the b stack element to the correct
// position in stack a.
// If the costs of moving stack a and b into position match (i.e. both negative
// of both positive), both will be	rotated or reverse rotated at the same time.
// They might also be rotated separately, 
// before finally pushing the top b element
// to the top stack a.
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	do_pa(a, b);
}
