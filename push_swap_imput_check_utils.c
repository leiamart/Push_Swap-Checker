/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_imput_check_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:07:33 by leiamart          #+#    #+#             */
/*   Updated: 2024/09/02 17:50:32 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_compare(const char *s1, const char *s2)
{
	int	i;
	int	c;

	i = 0;
	c = i;
	if (s1[i] == '+')
	{
		if (s2[c] != '+')
			i++;
	}
	else
	{
		if (s2[c] == '+')
			c++;
	}
	while (s1[i] != '\0' && s2[c] != '\0' && s1[i] == s2[c])
	{
		i++;
		c++;
	}
	return ((unsigned char) s1[i] - (unsigned char)s2[c]);
}

int	ft_is_digit_ps(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_sign_ps(char c)
{
	return (c == '+' || c == '-');
}

size_t	ft_strlen_ps(const char *s)
{
	size_t	i;

	i = 0;
	while (((char *)s)[i] != '\0')
	{
		i++;
	}
	return (i);
}
