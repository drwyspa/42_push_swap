/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:13:53 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/09/26 19:11:45 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Freeing array table and clean the memory.
//
int	freearray(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (1);
}

// Count string lenght.
//
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

//Copy l number of bytes, to new string (old - src, new - dst).
//
size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n - 1 && n != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (n != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

// Duplicate string - helper for arraydup.
//
char	*ft_strdup(const char *s)
{
	char	*ptr;

	ptr = malloc(ft_strlen(s) + 1);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s, 1 + ft_strlen(s));
	return (ptr);
}

// Duplicate array to pass it later for checking and
// filling the stack.
//
char	**arraydup(char **array)
{
	int		i;
	char	**res;

	i = 0;
	while (array[i])
		i++;
	res = malloc((i + 1) * sizeof(char *));
	if (!res)
		return (0);
	i = 0;
	while (array[i])
	{
		res[i] = ft_strdup(array[i]);
		if (!res[i])
		{
			freearray(res);
			return (0);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}
