/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:37:50 by jguaglio          #+#    #+#             */
/*   Updated: 2024/10/02 20:37:50 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_all_file(int fd, char *str)
{
	char	*buf;
	int		oct;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	oct = 1;
	while (oct != 0 && in_str(str, '\n') == -1)
	{
		oct = read(fd, buf, BUFFER_SIZE);
		if (oct < 0)
			return (free(buf), free(str), NULL);
		buf[oct] = '\0';
		str = ft_strjoin(str, buf);
	}
	return (free(buf), str);
}

char	*get_lines(char *str, int i)
{
	char	*lign;

	if (i == -1)
		lign = ft_substr(str, 0, ft_strlen(str));
	else
		lign = ft_substr(str, 0, i + 1);
	if (!lign[0])
		return (free(lign), NULL);
	else
		return (lign);
}

// chercher pourquoi +1 sur lign

char	*get_end_file(char *str, int i)
{
	char	*str_new;

	if (!str[0] || i == -1)
		return (free(str), NULL);
	str_new = ft_substr(str, i + 1, ft_strlen(str));
	free(str);
	return (str_new);
}

char	*get_next_line(int fd)
{
	static char	*str[10000];
	char		*lign;
	int			i;

	str[fd] = get_all_file(fd, str[fd]);
	if (str[fd] == NULL)
		return (NULL);
	i = in_str(str[fd], '\n');
	lign = get_lines(str[fd], i);
	str[fd] = get_end_file(str[fd], i);
	return (lign);
}

/*
int main(void)
{
	int	fd;
	char	*line;

	fd = open("fichier.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	fd = open("t.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
}*/
