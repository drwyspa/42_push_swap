/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:58:21 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/07/23 22:25:38 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Check if char is digit.
//1 if yes and 0 if not.
int	is_digit(char c)
{
	return (c >= 48 && c <= 57);
}

//Check if char is a sign (+ or -).
//Returns 1 if yes and 0 if not.
int	is_sign(char c)
{
	return (c == 43 || c == 45);
}

//Compares two strings of digits to check if they are the same or not.
//If one of the strings starts with a '+' sign, it is ignored and the rest
//of the number string is checked.
//This is so that +123 == 123 but -123 != 123.
//Returns 0 if the strings match, another value if they do not.
int	nbstr_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1[i] == 43)
	{
		if (s2[j] != 43)
			i++;
	}
	else
	{
		if (s2[j] == 43)
			j++;
	}
	while (s1[i] && s2[j] && s1[i] == s2[i])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
