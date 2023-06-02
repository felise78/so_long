/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:09:45 by hemottu           #+#    #+#             */
/*   Updated: 2023/05/12 20:32:36 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*get_next_line(t_data game)
{
	static char	*res = NULL;
	char		*buf;
	char		*line;
	int			ret;

	ret = 1;
	while (ret > 0 && (ft_strchr(res, '\n') == 0))
	{
		buf = malloc(sizeof(char) * (50));
		if (!buf)
			return (NULL);
		ret = read(game.fd, buf, 49);
		if (ret == -1 || (ret == 0 && res == NULL))
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		res = ft_strjoin(res, buf);
	}
	line = ft_line(res);
	res = ft_rest(res);
	return (line);
}

char	*ft_line(char *line)
{
	char	*dest;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 2));
	if (!dest)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		dest[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		dest[i] = line[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_rest(char *res)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = NULL;
	if (!res || !res[i])
		return (NULL);
	while (res[i] && res[i] != '\n')
		i++;
	dest = malloc(sizeof(char) * (ft_strlen(res) - i + 1));
	if (!dest)
		return (NULL);
	while (res[i])
		dest[j++] = res[++i];
	dest[j] = '\0';
	free(res);
	if (!dest[0])
	{
		free(dest);
		return (NULL);
	}
	return (dest);
}

/*

# include <stdio.h>
# include <unistd.h>

int main()
{
    int fd;
	char *line;
   
    fd = open("fichier", O_RDONLY);
	if (fd == -1)
		return (0);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	
}
*/
