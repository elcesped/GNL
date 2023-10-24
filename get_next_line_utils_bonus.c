/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:34:37 by elcesped          #+#    #+#             */
/*   Updated: 2023/06/16 17:47:10 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s || !c)
		return (NULL);
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if (s[i] == '\0' && (unsigned char)c != '\0')
		return (NULL);
	return ((char *)(&s[i]));
}

size_t	ft_lenght(char *temp, char *buffer)
{
	int	result;

	result = 0;
	if (temp == NULL && buffer == NULL)
		return (0);
	else if (ft_strchr(temp, '\n') != NULL)
		result = ft_strlensep(temp, '\n') + 2;
	else if (ft_strchr(temp, '\n') == NULL)
	{
		if (ft_strchr(buffer, '\n') != NULL)
			result = ft_strlensep(temp, '\n') + ft_strlensep(buffer, '\n') + 2;
		else if (ft_strchr(buffer, '\n') == NULL)
			result = ft_strlensep(temp, '\n') + ft_strlensep(buffer, '\n') + 1;
	}
	return (result);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char			*strsrc;
	char				*strdest;
	long unsigned int	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	strsrc = src;
	strdest = dest;
	while (i < n)
	{
		strdest[i] = strsrc[i];
		i++;
	}
	return (dest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*r;
	size_t			t;

	if (size != 0 && nmemb > sizeof(char) * 2147483424 / size)
		return (NULL);
	t = nmemb * size;
	r = (unsigned char *)malloc(sizeof(char) * t);
	if (!r)
		return (NULL);
	while (t != 0)
	{
		r[t - 1] = '\0';
		t--;
	}
	return (r);
}

int	ft_strlensep(char *str, char charset)
{
	int	k;

	k = 0;
	if (!str)
		return (0);
	while (str[k] != charset && str[k])
		k++;
	return (k);
}
// determine la longueur de la ligne
