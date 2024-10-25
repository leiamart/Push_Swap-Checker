/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 22:54:21 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/08 19:30:44 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_source_to_dest(t_stack **src, t_stack **dst)
{
	t_stack	*aux;

	if (*src == NULL)
		return ;
	aux = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = aux;
}

void	ft_pa(t_stack **astack, t_stack **bstack)
{
	ft_source_to_dest(bstack, astack);
	ft_putstr_ps("pa\n");
}

void	ft_pb(t_stack **astack, t_stack **bstack)
{
	ft_source_to_dest(astack, bstack);
	ft_putstr_ps("pb\n");
}
