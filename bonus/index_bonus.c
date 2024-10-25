/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:13:33 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/16 21:58:00 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_index_bonus(t_stack *stack)
{
	t_stack	*aux;
	t_stack	*a;
	int		c;
	int		i;

	c = 0;
	i = 1;
	aux = stack;
	a = aux;
	if (!stack)
		return ;
	c = ft_sizestack(aux);
	while (i <= c)
	{
		while (aux != NULL)
		{
			if ((aux->value < a->value && aux->index == 0)
				|| (aux->index == 0 && a->index != 0))
				a = aux;
			aux = aux->next;
		}
		a->index = i++;
		aux = stack;
		a = aux;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	char	*p;
	size_t	len[2];
	int		i;

	len[0] = 0;
	len[1] = 0;
	i = 0;
	if (s1 != NULL)
		len[0] = ft_strlen_ps(s1);
	if (s2 != NULL)
		len[1] = ft_strlen_ps(s2);
	s3 = malloc(len[0] + len[1] + 2);
	if (s3 == NULL)
		return (NULL);
	p = s3;
	while (len[0]--)
		*p++ = s1[i++];
	*p++ = ' ';
	while (len[1]--)
		*p++ = *s2++;
	*p = '\0';
	if (ft_compare_checker(s1, ""))
		free(s1);
	return (s3);
}

int	ft_count_words(const char *s, char c)
{
	int	cont;
	int	check;

	cont = 0;
	check = 0;
	while (*s)
	{
		if (*s != c && check == 0)
		{
			cont++;
			check = 1;
		}
		else if (*s == c)
			check = 0;
		s++;
	}
	return (cont);
}

int	ft_check_stack_bonus(t_stack **astack)
{
	t_stack	*aux;

	aux = *astack;
	if (aux == NULL)
		return (1);
	while (aux->next)
	{
		if (aux->value < aux->next->value)
			aux = aux->next;
		else
			return (0);
	}
	return (1);
}
