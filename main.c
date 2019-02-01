/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 04:49:15 by nbethany          #+#    #+#             */
/*   Updated: 2019/01/17 04:58:44 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"

int main()
{
    int fd;
    int res;
    char *line;

    fd = open("file.txt", O_RDONLY);
    if (fd < 0)
        return (-1);
    
    printf("%d \n", fd);
    res = get_next_line(fd,&line);
    printf("%d %s\n",res,line);
    res = get_next_line(fd,&line);
    printf("%d %s\n",res,line);
    res = get_next_line(fd,&line);
    printf("%d %s\n",res,line);
    res = get_next_line(fd,&line);
    printf("%d %s\n",res,line);
    res = get_next_line(fd,&line);
    printf("%d %s\n",res,line);
    res = get_next_line(fd,&line);
    printf("%d %s\n",res,line);
    return (0);
}
