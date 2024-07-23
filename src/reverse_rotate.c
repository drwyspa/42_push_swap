/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:43:17 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/07/15 19:52:36 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Bottom element of the stack, to the top.
static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_stack_bottom(*stack);
	before_tail = get_stack_before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

//Brings bottom element of the stack a, to the top.
//Prints "rra".
void	do_rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

//Brings bottom element of the stack b, to the top.
//Prints "rrb".
void	do_rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

//Brings bottom elements of both stack, to the top.
//Prints "rrr";
void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}
