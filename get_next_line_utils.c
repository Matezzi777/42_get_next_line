/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:07:14 by mmartina          #+#    #+#             */
/*   Updated: 2024/04/28 20:07:14 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
bool	is_eol(char *str);
char	*clean_join(char *s1, char *s2);

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// Join 2 chaînes de caractères
char	*ft_strjoin(char const *s1, char const *s2)
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

// Renvoie 1 si la chaîne contient \n, renvoie 0 sinon
bool	is_eol(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			return (1);
	}
	return (0);
}

// ft_strjoin adapté pour free les chaînes initiales
char	*clean_join(char *s1, char *s2)
{
	int		i;
	int		len_s1;
	int		len_s2;
	char	*result;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	i = 0;
	while (i < (len_s1 + len_s2))
	{
		if (i < len_s1)
			result[i] = s1[i];
		else
			result[i] = s2[i - len_s1];
		i++;
	}
	result[i] = '\0';
	free(s1);
	free(s2);
	return (result);
}