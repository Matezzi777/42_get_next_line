/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:33:29 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/15 17:12:07 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*str;
	int		i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < (len_s1 + len_s2))
	{
		str[i] = s2[i - len_s1];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*cursor;

	cursor = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		cursor[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocated;

	if ((nmemb >= 42949672926 || size >= 42949672926) && nmemb && size)
		return (NULL);
	allocated = (void *)malloc(nmemb * size);
	if (!allocated)
		return (NULL);
	ft_bzero(allocated, nmemb * size);
	return (allocated);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
