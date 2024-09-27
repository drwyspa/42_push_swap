/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:13:53 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/09/27 16:55:29 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Frees elements in the stack and sets its pointer to NULL.
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

// Writes "Error\n" after freeing stack a and b.
// Exits with standard error code 1.
void	exit_error(t_stack **stack_a, t_stack **stack_b, char **array)
{
	if (stack_a == NULL || *stack_a != NULL)
		free(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free(stack_b);
	freearray(array);
	write(2, "Error\n", 6);
	exit(1);
}

//Convert ASCII to long int.
long int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

//Prints string to the standard output.
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

// Returns the absolute value of a given number.
// The absolute value of a number is used to measure the distance of that
// number from 0, whether it is positive or negative (abs value of -6 is 6).
int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
