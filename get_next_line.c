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
#include <stdio.h>

int	get_next_line(const int fd, char **line)
{
    static char buf[BUFF_SIZE];
    size_t i;
    size_t size;

    if (fd < 0 || BUFF_SIZE <= 0)
        return (-1);

    while (read(fd, buf, BUFF_SIZE) > 0)
    {
        buf[BUFF_SIZE - 1] = '\0';
        if (buf[0] == '\n')
            return (1);
        if (ft_strchr(buf, '\n'))
        {
            printf("lal\n");
            i = 0;
            size = ft_strlen(buf);
            while (buf[i])
            {
                if (buf[i] == '\n')
                {
                    printf("lel\n");
                    if (!(*line = realloc(*line, i + size)))
                        return (-1);
                    ft_strncat(*line, buf, i);
                    return(1);
                }
                i++;
            }
        }
        printf("lol\n");
        if (!(*line = realloc(*line, BUFF_SIZE)))
            return (-1);
        ft_strncat(*line, buf, BUFF_SIZE);
    }
    return (0);
}