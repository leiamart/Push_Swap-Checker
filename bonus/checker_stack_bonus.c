/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_stack_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 23:06:44 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/16 21:55:13 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_add_bottom_bonus(t_stack **stack, t_stack *c)
{
	t_stack	*i;

	i = *stack;
	if (!i)
		*stack = c;
	else
	{
		while (i->next)
			i = i->next;
		i->next = c;
	}
}

t_stack	*ft_new_astack(int v)
{
	t_stack	*n;

	n = NULL;
	n = malloc(sizeof(t_stack));
	if (!n)
		return (NULL);
	if (n)
	{
		n->value = v;
		n->next = NULL;
		n->index = 0;
	}
	return (n);
}

int	ft_sizestack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack-> next;
	}
	return (i);
}

void	ft_clear_stack(t_stack **stack)
{
	t_stack	*aux;

	if (!stack)
		return ;
	while (*stack)
	{
		aux = (*stack)->next;
		free(*stack);
		*stack = aux;
	}
	*stack = NULL;
}

t_stack	*ft_stack_a_bonus(char *str, int l)
{
	t_stack	*astack;
	t_stack	*aux;
	char	**c;
	int		i;

	astack = NULL;
	i = 0;
	c = ft_split_ps(str, ' ');
	if (!c)
		return (NULL);
	if (ft_check_error(c) == 0)
	{
		ft_free_ps_bonus(c, ft_count_words(str, ' ') + 1);
		return (astack);
	}
	while (i < l)
	{
		aux = ft_new_astack(ft_atoi_b(c[i]));
		ft_add_bottom_bonus(&astack, aux);
		i++;
	}
	ft_free_ps_bonus(c, ft_count_words(str, ' ') + 1);
	ft_index_bonus(astack);
	return (astack);
}
