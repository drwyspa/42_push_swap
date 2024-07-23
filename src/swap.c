/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:07:09 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/07/23 22:31:38 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Swaps top 2 elements of the stack.
static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

//Swaps top 2 elemets of the stack a.
//Prints "sa".
void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

//Swaps top 2 elements of the stack b.
//Prints "sb".
void	do_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

//Swaps top 2 elements on both stacks.
//Prints "ss".
void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
