/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:22:40 by elcesped          #+#    #+#             */
/*   Updated: 2023/06/18 17:17:15 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_buffer(int fd)
{
	int		index;
	char	*buffer;

	index = 0;
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	index = read(fd, buffer, BUFFER_SIZE);
	if (index == -1 || (index == 0 && buffer[index] == '\0'))
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*ft_switch(char *result, char *buffer)
{
	char	*temp_result;
	int		k;

	k = 0;
	temp_result = ft_calloc(ft_lenght(result, buffer), 1);
	if (!temp_result)
		return (NULL);
	if (!result)
	{
		result = ft_calloc(ft_lenght(NULL, buffer), 1);
		if (!result)
		{
			free(temp_result);
			return (NULL);
		}
	}
	while (result[k] != '\0')
		k++;
	ft_memcpy(temp_result, result, ft_strlensep(result, '\0'));
	if (ft_strchr(buffer, '\n'))
		ft_memcpy(temp_result + k, buffer, ft_strlensep(buffer, '\n') + 1);
	else
		ft_memcpy(temp_result + k, buffer, ft_strlensep(buffer, '\0'));
	free(result);
	return (temp_result);
}

char	*ft_stocktemp(char *tostock)
{
	int		k;
	int		i;
	char	*temp;

	temp = NULL;
	k = 0;
	i = 0;
	if ((!tostock))
		return (NULL);
	if (tostock[k] != '\0' && tostock)
	{
		temp = ft_calloc(ft_strlensep(tostock, '\0') + 1, 1);
		if (!temp)
			return (NULL);
		while (tostock[k] != '\0')
			temp[i++] = tostock[k++];
	}
	return (temp);
}

/*
if (a > b)
	c = a+b;
else
	c = a-b;

= 

c = (a>b) * (a+b) + (a<=b) * (a-b);
*/

char	*ft_maketempb(char *tostock, int fd)
{
	char		*res;
	static char	*temp[1024];
	char		*newtemp;

	if (temp[fd])
	{
		res = ft_calloc(ft_lenght(NULL, temp[fd]), 1);
		if (!res)
			return (NULL);
		if (!ft_strchr(temp[fd], '\n'))
			res = ft_memcpy(res, temp[fd], ft_strlensep(temp[fd], '\0'));
		else
		{
			res = ft_memcpy(res, temp[fd], ft_strlensep(temp[fd], '\n') + 1);
			newtemp = ft_stocktemp(ft_strchr(temp[fd], '\n') + 1);
			free(temp[fd]);
			temp[fd] = newtemp;
			return (res);
		}
		free(temp[fd]);
		temp[fd] = NULL;
		return (res);
	}
	temp[fd] = ft_stocktemp(tostock);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*result;

	if (!(fd >= 0))
		return (NULL);
	result = ft_maketempb(NULL, fd);
	if (result && ft_strchr(result, '\n'))
		return (result);
	while (1)
	{
		buffer = ft_buffer(fd);
		if (!buffer)
			return (result);
		result = ft_switch(result, buffer);
		if (ft_strchr(buffer, '\n') != NULL || (!buffer))
			break ;
		free(buffer);
		if (!result)
			return (NULL);
	}
	if (ft_strchr(buffer, '\n') != NULL && result)
		ft_maketempb(ft_strchr(buffer, '\n') + 1, fd);
	free(buffer);
	return (result);
}

//int	main(void)
//{
//	int	fd;
//	char	*line;

//	fd = 0;
//	fd = open("text_1.txt", fd);

//	while (1)
//	{
//		line = get_next_line(fd);
//		printf("%s\n", line);

//		if (line == NULL)
//			break ;
//		free(line);
//	}

//	close(fd);
//}
