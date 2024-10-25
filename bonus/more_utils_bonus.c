/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:02:19 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/16 21:57:42 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

char	*ft_substr_ps(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	c;
	char	*p;

	i = 0;
	c = 0;
	if (start > ft_strlen_ps(s))
		len = 0;
	else if (len > (ft_strlen_ps(s) - start))
		len = ft_strlen_ps(s) - start;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (s[i])
	{
		if (i >= start && c < len)
		{
			p[c] = s[i];
			c++;
		}
		i++;
	}
	p[c] = '\0';
	return (p);
}
