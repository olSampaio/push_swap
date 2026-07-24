/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarque <armarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:22:39 by lusampai          #+#    #+#             */
/*   Updated: 2026/07/23 23:56:29 by armarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_words(char const *s, char c)
{
	int	idx;
	int	size;

	idx = 0;
	size = 0;
	while (s[idx])
	{
		if ((idx == 0 || s[idx - 1] == c) && s[idx] != c)
			size++;
		idx++;
	}
	return (size);
}

static int	count_len(char const *s, char c, int idx)
{
	int	len;

	len = 0;
	while (s[idx] != c && s[idx])
	{
		idx++;
		len++;
	}
	return (len);
}

static char	*copy_word(char const *s, char c, int idx)
{
	char	*str;
	int		len;
	int		i;

	len = count_len(s, c, idx);
	str = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[idx + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_free_split(char **splitted_str, int str_idx)
{
	while (str_idx > 0)
		free(splitted_str[--str_idx]);
	free(splitted_str);
}

char	**ft_split(char const *s, char c)
{
	int		idx;
	int		str_idx;
	char	**splitted_str;

	idx = 0;
	str_idx = 0;
	if (!s)
		return (NULL);
	splitted_str = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!splitted_str)
		return (NULL);
	while (s[idx])
	{
		while (s[idx] && s[idx] == c)
			idx++;
		if (!s[idx])
			break ;
		splitted_str[str_idx] = copy_word(s, c, idx);
		if (!splitted_str[str_idx])
			return (ft_free_split(splitted_str, str_idx), NULL);
		idx += count_len(s, c, idx);
		str_idx++;
	}
	return (splitted_str[str_idx] = NULL, splitted_str);
}
