/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_imput_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 23:40:53 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/10 20:48:47 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_duplicated(char **argv)
{
	int	i;
	int	c;

	i = 1;
	while (argv[i])
	{
		c = 1;
		while (argv[c])
		{
			if (c != i && ft_compare(argv[i], argv[c]) == 0)
				return (1);
			c++;
		}
		i++;
	}
	return (0);
}

int	ft_duplicated_stack(t_stack *a)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = a;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->value == temp2->value)
				return (1);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (0);
}

static int	ft_is_zero(char *argv)
{
	int	i;
	int	flag;

	i = 0;
	flag = -1;
	while (argv[i])
	{
		if (argv[i] != '0' && flag == -1)
			flag = 1;
		if (argv[i] == '0' && flag == -1 && argv[i + 1] != '\0')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_is_number(char *argv)
{
	int	i;

	i = 0;
	if (ft_is_sign_ps(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && ft_is_digit_ps(argv[i]))
		i++;
	if (argv[i] != '\0' && !ft_is_digit_ps(argv[i]) && argv[i] != ' ')
		return (0);
	return (1);
}

int	ft_imput_push_swap(char **argv)
{
	int	c;
	int	i;

	c = 0;
	i = 1;
	while (argv[i])
	{
		if (!ft_is_number(argv[i]))
			return (0);
		c += ft_is_zero(argv[i]);
		i++;
	}
	if (c > 1)
		return (0);
	if (ft_duplicated(argv))
		return (0);
	return (1);
}
