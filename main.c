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
#include "./libft/libft.h"

int main()
{
    int fd1, fd2;
    int res;
    char *line;

    fd1 = open("file.txt", O_RDONLY);
    fd2 = open("file1.txt", O_RDONLY);
    if (fd1 < 0)
        return (-1);
    
    res = get_next_line(fd1,&line);
    printf("descriptor: %d, line: %s\n",fd1,line);
    res = get_next_line(fd1,&line);
    printf("descriptor: %d, line: %s\n",fd1,line);
    res = get_next_line(fd2,&line);
    printf("descriptor: %d, line: %s\n",fd2,line);
    res = get_next_line(fd2,&line);
    printf("descriptor: %d, line: %s\n",fd2,line);
    res = get_next_line(fd1,&line);
    printf("descriptor: %d, line: %s\n",fd1,line);
    res = get_next_line(fd1,&line);
    printf("descriptor: %d, line: %s\n",fd1,line);
    res = get_next_line(fd2,&line);
    printf("descriptor: %d, line: %s\n",fd2,line);
    res = get_next_line(fd2,&line);
    printf("descriptor: %d, line: %s\n",fd2,line);
    return (0);
}
