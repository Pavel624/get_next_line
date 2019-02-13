/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 04:48:02 by nbethany          #+#    #+#             */
/*   Updated: 2019/01/17 04:48:43 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_new_line(char **str, char **line, int fd)
{
	char *tmp;
	int i;
	
	i = 0;
	while (str[fd][i] != '\0'  && str[fd][i] != '\n')
		i++;
	if (str[fd][i] == '\0')
	{
		if (i == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);		
	}
	else if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		tmp = ft_strdup(str[fd] + i + 1);
		free(str[fd]);
		str[fd] = tmp;
			if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
    static char *str[127];
    char buf[BUFF_SIZE + 1];
    char *tmp;
    int i;

    if (fd < 0 || BUFF_SIZE <= 0 || line == NULL)
        return (-1);
    
    while ((i = read(fd, buf, BUFF_SIZE)) > 0)
    {
        buf[i] = '\0';
        if (!str[fd])
            str[fd] = malloc(1);
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
        if (ft_strchr(buf, '\n'))
        	break;
    }
    if (i < 0)
			return (-1);
    if (i == 0 && str[fd][0] == '\0')
			return (0);
    return (ft_new_line(str, line, fd));
}
