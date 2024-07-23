/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:56:19 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/07/23 21:25:28 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Checks if argument is an number.
//1 if is and 0 if not.
static int	arg_is_number(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i] && argv[i + 1] != '\0'))
		i++;
	while (argv[i] && is_digit(argv[i]))
		i++;
	if (argv[i] != '\0' && !is_digit(argv[i]))
		return (0);
	return (1);
}

//Check if the're any duplicates in arguments.
//1 if yes and 0 if not.
static int	have_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && nbstr_cmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// Checks the argument is a 0 to avoid 0 +0 -0 duplicates
// and 0 0000 +000 -00000000 too.
// Return: 1 if the argument is a zero, 0 if it contains
// anything else than a zero.
static int	arg_is_zero(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] && argv[i] == 48)
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

//Validates all arguments. They should be numbers without duplicates.
//1 if are valid and 0 if not.
int	is_correct_input(char **argv)
{
	int	i;
	int	zeroes;

	zeroes = 0;
	i = 1;
	while (argv[i])
	{
		if (!arg_is_number(argv[i]))
			return (0);
		zeroes += arg_is_zero(argv[i]);
		i++;
	}
	if (zeroes > 1)
		return (0);
	if (have_duplicates(argv))
		return (0);
	return (1);
}
