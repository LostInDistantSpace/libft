/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:13:33 by bmouhib           #+#    #+#             */
/*   Updated: 2024/05/23 15:00:45 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	vibe_check(const char *set, char c)
{
	while (*set)
	{
		if (c == *set++)
			return (0);
	}
	return (1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char const	*str;
	size_t		len;
	size_t		end;
	size_t		start;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && !vibe_check(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > 0 && !vibe_check(set, s1[end]))
		end--;
	len = end - start + 1;
	str = ft_substr(s1, start, len);
	return ((char *)str);
}

// int	main(int ac, char **av)
// {
// 	char	*str;

// 	if (ac == 3)
// 	{
// 		str = ft_strtrim(av[1], av[2]);
// 		printf("%s\n", str);
// 		free(str);
// 		return (0);
// 	}
// 	printf("Wrong argc\n");
// 	return (0);
// }
