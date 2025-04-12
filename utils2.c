/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi    <medayi@student.42istanbul>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:13:22 by medayi            #+#    #+#             */
/*   Updated: 2025/04/12 12:13:53 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_get_word(char const *s, char c, int *index)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	i = *index;
	while (s[i + len] && s[i + len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	len = 0;
	while (s[i] && s[i] != c)
	{
		word[len] = s[i];
		i++;
		len++;
	}
	word[len] = '\0';
	*index = i;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	result[count] = NULL;
	i = 0;
	j = 0;
	while (j < count)
	{
		while (s[i] == c)
			i++;
		result[j] = ft_get_word(s, c, &i);
		j++;
	}
	return (result);
}

void	ft_free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}