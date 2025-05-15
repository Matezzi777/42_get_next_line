/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:26:00 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/15 07:01:53 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	Fonction Principale
*/
char	*get_next_line(int fd)
{
	
}

/*
	Retourne la taille à allouer avec malloc.
*/
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str[i])
		while (str[i])
			i++;
	return (i);
}

/*
	Copie une string dans une autre et retourne la copie allouée.
*/
char	*ft_strdup(char	*str)
{
	int		i;
	int		len;
	char	*copy;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*
	Concatène tmp et buff puis retourne la nouvelle chaîne.
*/

/*
	Libère tmp et buff et retourne la ligne si un '\n' est trouvé.
	Sinon retourne NULL.
*/

/*
	Extrait la partie après le saut de ligne dans tmp et retourne cette nouvelle partie.
*/
char	*ft_substr(char *str, unsigned int start, size_t len)
{
	int		i;
	char	*sub;

	if (!str || start <= ft_strlen(str))
	{
		sub = (char *)malloc(1 * sizeof(char));
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (str[start + i] && i < len)
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
