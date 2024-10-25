/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:08:38 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/08 19:21:15 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_ps(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_free_ps(t_stack **stack)
{
	t_stack	*aux;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		aux = (*stack)->next;
		free(*stack);
		*stack = aux;
	}
	*stack = NULL;
}

int	ft_n_value(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	ft_write_error(t_stack **astack, t_stack **bstack)
{
	if (astack == NULL || *astack != NULL)
		ft_free_ps(astack);
	if (bstack == NULL || *bstack != NULL)
		ft_free_ps(bstack);
	write(2, "Error\n", 6);
	exit(1);
}

long int	ft_atoi_ps(const char *str)
{
	long int	n;
	int			c;
	int			i;

	n = 0;
	c = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		c *= -1;
		i++;
	}
	while (ft_is_digit_ps(str[i]))
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * c);
}
