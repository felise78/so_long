/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:55:07 by hemottu           #+#    #+#             */
/*   Updated: 2023/05/12 20:32:29 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_word_count(const char *s, char c)
{
	int	i;
	int	nb_mots;
	int	interrupteur;

	i = 0;
	interrupteur = 1;
	nb_mots = 0;
	while (s[i])
	{
		if (s[i] != c && interrupteur == 1)
		{
			interrupteur = 0;
			nb_mots++;
		}
		else if (s[i] == c)
		{
			interrupteur = 1;
		}
		i++;
	}
	return (nb_mots);
}

void	ft_free(char **split)
{
	int	j;

	j = 0;
	while (split[j])
	{
		free(split[j]);
		j++;
	}
	free(split);
}

static char	*ft_word_dup(const char *s, int start, int end, char **split)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
	{
		ft_free(split);
		return (NULL);
	}
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}	

char	**ft_splitdup(char const *s, char c, char **split)
{
	size_t	i;
	size_t	j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = (int)i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			split[j] = ft_word_dup(s, start, i, split);
			if (!split[j++])
				return (NULL);
			start = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = calloc((ft_word_count(s, c) + 1), sizeof(char *));
	if (!split)
		return (NULL);
	split = ft_splitdup(s, c, split);
	return (split);
}

// int	main ()
// {
// 	char a[] = "Une phrase avec plein de mots dedans.";
// 	char **b = ft_split(a, ' ');
// 	int i = 0;
// 	while (b && b[i])
// 		printf("%s\n", b[i++]);
// 	return 0;
// }

// Ajouter ca apres le malloc word.

// // if (end - start == 2)
// 	// {
// 	// 	free(word);
// 	// 	word = NULL;
// 	// }
