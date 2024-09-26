/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:56:19 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/09/26 19:06:44 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Checks if argument is an number.
//1 if is and 0 if not.
static int	arg_is_number(char *array)
{
	int	i;

	i = 0;
	if (is_sign(array[i]) && array[i + 1] != '\0')
		i++;
	while (array[i] && is_digit(array[i]))
		i++;
	if (array[i] != '\0' && !is_digit(array[i]))
		return (0);
	return (1);
}

//Check if the're any duplicates in arguments.
//1 if yes and 0 if not.
static int	have_duplicates(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[j])
		{
			if (j != i && nbstr_cmp(array[i], array[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

//Validates all arguments. They should be numbers without duplicates.
//1 if are valid and 0 if not.
int	is_correct_input(char **array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (array[i])
	{
		while (array[i][j])
		{
			if (!arg_is_number(&array[i][j]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	if (have_duplicates(array))
		return (0);
	return (1);
}
