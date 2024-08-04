/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouati <mlouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:32:25 by mlouati           #+#    #+#             */
/*   Updated: 2024/07/29 00:16:13 by mlouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_words(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	nb_words(char *s, char c)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	len = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		if (s[j])
			len++;
		while (s[j] && s[j] != c)
			j++;
		i = j;
	}
	return (len);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*sub;
	int		i;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	sub = (char *)malloc(len + 1);
	i = 0;
	if (!sub)
		return (NULL);
	while (s[i + start] && i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

void	**cpy_words(char **str, char *p, char c, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		while (*p && *p == c)
			p++;
		if (*p && *p != c)
		{
			str[i] = ft_substr(p, 0, len_words(p, c));
			if (!str[i])
			{
				while (i >= 0)
					free(str[--i]);
				free(str);
				free(p);
				return (NULL);
			}
			i++;
		}
		p = p + len_words(p, c);
	}
	return ((void *)str);
}

char	**ft_split(char *s, char c)
{
	int		len;
	char	**str;
	char	*p;
	char	*ptr;

	if (!s)
		return (0);
	p = ft_strdup(s);
	ptr = p;
	if (!p)
		return (NULL);
	len = nb_words(p, c);
	str = malloc((len + 1) * sizeof(char *));
	if (!str)
	{
		free(str);
		free(ptr);
		return (NULL);
	}
	cpy_words(str, p, c, len);
	str[len] = NULL;
	free(ptr);
	return (str);
}
