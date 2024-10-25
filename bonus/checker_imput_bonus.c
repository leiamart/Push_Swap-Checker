/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_imput_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:47:03 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/10 22:23:45 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_str_check(char **argv)
{
	int	i;
	int	c;

	i = 1;
	c = 0;
	while (argv[c])
	{
		while (argv[i])
		{
			if (ft_compare_checker(argv[c], argv[i]) == 0)
				return (0);
			i++;
		}
		c++;
		i = c + 1;
	}
	return (1);
}

int	ft_cmp_num(char **argv)
{
	int	i;
	int	c;

	i = 1;
	c = 0;
	while (argv[c])
	{
		while (argv[i])
		{
			if (ft_atoi_b(argv[c]) == ft_atoi_b(argv[i]))
				return (0);
			i++;
		}
		if (ft_atoi_b(argv[c]) > INT_MAX || ft_atoi_b(argv[c]) < -2147483648)
			return (0);
		c++;
		i = c + 1;
	}
	return (1);
}

int	ft_num_checker(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
	{
		i++;
		if (argv[i] == '0' || argv[i] == '\0')
			return (0);
	}
	while (argv[i] >= '0' && argv[i] <= '9')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

int	ft_zero_checker(char *argv)
{
	int	i;
	int	c;

	i = 0;
	c = -1;
	while (argv[i])
	{
		if (argv[i] != '0' && c == -1)
			c = 1;
		if (argv[i] == '0' && c == -1 && argv[i + 1] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_error(char **argv)
{
	int	i;

	i = 0;
	if (ft_str_check(argv) == 0)
		return (0);
	if (ft_cmp_num(argv) == 0)
		return (0);
	while (argv[i])
	{
		if (ft_num_checker(argv[i]) == 0)
			return (0);
		if (ft_zero_checker(argv[i]) == 0)
			return (0);
		if (ft_strlen_ps(argv[i]) > 11)
			return (0);
		i++;
	}
	return (1);
}
