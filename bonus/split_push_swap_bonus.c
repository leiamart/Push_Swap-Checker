/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_push_swap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiamart <leiamart@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:54:49 by leiamart          #+#    #+#             */
/*   Updated: 2024/10/14 20:56:03 by leiamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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