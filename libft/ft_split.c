/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgamboa- <jgamboa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:15:36 by jgamboa-          #+#    #+#             */
/*   Updated: 2022/11/08 16:25:08 by jgamboa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*fucntions*/

int	count_words(const char *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c)
			|| (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			w++;
		i++;
	}
	return (w);
}

int	get_word_index(const char *s, int index, char c)
{
	int	i;

	i = 0;
	i += index;
	if (c == '\0')
		return (0);
	while (s[i] == c && s[i])
		i++;
	return (i);
}

int	ft_strlen_chr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] != c))
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	int		word_len;
	int		i;
	int		j;
	char	**string;

	string = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !string)
		return (0);
	word_len = 0;
	index = 0;
	j = -1;
	while (++j < count_words(s, c))
	{
		i = index + word_len;
		index = get_word_index(s, i, c);
		word_len = ft_strlen_chr(&s[index], c);
		string[count_words(s, c)] = 0;
		string[j] = ft_substr(s, index, word_len);
		if (!string[j])
			while (j != 0)
				free(string[j--]);
	}
	string[j] = 0;
	return (string);
}
