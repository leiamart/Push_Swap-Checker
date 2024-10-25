/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:43:16 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/10 21:34:03 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_is_digit_bonus(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_compare_checker(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

long int	ft_atoi_b(const char *str)
{
	long int	n;
	int			c;
	int			i;

	n = 0;
	i = 0;
	c = 1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		c *= -1;
		i++;
	}
	while (ft_is_digit_bonus(str[i]))
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * c);
}

void	*ft_free_ps_bonus(char **str, int c)
{
	int	i;

	i = 0;
	while (i < c)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
