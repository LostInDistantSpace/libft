/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:27:26 by bmouhib           #+#    #+#             */
/*   Updated: 2024/05/23 12:35:21 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

static size_t	word_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*str;
	char	*s1;

	s1 = (char *)s;
	str = malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	ft_memmove(str, s1, n);
	str[n] = '\0';
	return (str);
}

static char	**split_words(char *s, char **split, char c)
{
	size_t	i;
	size_t	wordl;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		wordl = word_len(s, c);
		if (wordl > 0)
		{
			split[i] = ft_strndup(s, wordl);
			if (!split[i])
			{
				while (i > 0)
					free(split[--i]);
				free(split);
				return (NULL);
			}
			split[i++][wordl] = '\0';
			s += wordl;
		}
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	words;

	i = 0;
	if (!s)
		return (NULL);
	words = word_count(s, c);
	array = malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array[words] = 0;
	array = split_words((char *)s, array, c);
	return (array);
}
/*
int	main(int ac, char **av)
{
	char	sep;
	char	*str = "      Pretty please I hate   my life     ";
	char	**tab;
	size_t	i;

	i = 0;
	sep = 32;
	if (ac == 2 || ac == 3)
	{
		if (ac == 3 && ft_strlen(av[2]))
			sep = av[2][0];
		printf("String taken from arguments\n");
		printf("Seperator : '%c' | %zu words\n", sep, word_count(av[1], sep));
		tab = ft_split(av[1], sep);
		while (i < word_count(av[1], sep))
		{
			printf("	[%zu] = %s\n", i, tab[i]);
			i++;
		}
		while (i > 0)
			free(tab[--i]);
		free(tab);
	}
	else
	{
		printf("NULL tab: ");
		tab = ft_split(NULL, sep);
		if (!tab)
			printf("return is NULL as expected\n");
		printf("Number of words : %zu\n", word_count(str, sep));
		tab = ft_split(str, 32);
		while (i < word_count(str, sep))
		{
			printf("	[%zu] = %s\n", i, tab[i]);
			i++;
		}
		while (i > 0)
			free(tab[--i]);
		free(tab);
	}
	return (0);
}
*/