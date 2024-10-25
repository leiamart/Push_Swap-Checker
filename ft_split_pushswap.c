/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pushswap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:52:16 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/24 21:53:53 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *s, char c)
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

static void	*free_all(char **str, int cont)
{
	int	i;

	i = 0;
	while (i < cont)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
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

static char	**fill_split(char	**str, char const *s, char c)
{
	size_t	len;
	size_t	i;
	size_t	j;
	int		start;

	len = ft_strlen_ps(s);
	i = 0;
	j = 0;
	start = -1;
	while (i <= len)
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == len) && start >= 0)
		{
			str[j] = ft_substr_ps(s, start, i - start);
			if (str[j] == NULL)
				return (free_all(str, j));
			j++;
			start = -1;
		}
		i++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split_ps(const char *s, char c)
{
	char	**str;

	str = (char **) malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (str == NULL)
		return (NULL);
	str = fill_split(str, s, c);
	return (str);
}
