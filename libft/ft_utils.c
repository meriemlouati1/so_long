/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouati <mlouati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:07:39 by mlouati           #+#    #+#             */
/*   Updated: 2024/08/02 12:22:09 by mlouati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		n1;
	int		n2;

	if (!s1 || !s2)
		return (0);
	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	str = (char *)malloc(n1 + n2 + 1);
	i = 0;
	if (!str)
		return (NULL);
	while (i < n1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < n1 + n2)
	{
		str[i] = s2[i - n1];
		i++;
	}
	str[i] = '\0';
	return (free(s1), str);
}

void	*ft_memcpy(void *dest, void *src, int n)
{
	unsigned char	*ptr;
	unsigned char	*s;
	int				i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	ptr = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (ptr == s)
		return ((void *)src);
	while (i < n)
	{
		ptr[i] = s[i];
		i++;
	}
	return ((void *)dest);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		len;

	len = ft_strlen(s);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s, len);
	str[len] = '\0';
	return ((char *)str);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
