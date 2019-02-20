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
    int fd1, fd2, fd3, fd4;
    int res;
    char *line;

    fd1 = open("gnl7_1.txt", O_RDONLY);
    fd2 = open("gnl7_2.txt", O_RDONLY);
    fd3 = open("gnl7_3.txt", O_RDONLY);
    fd4 = open("file1.txt", O_RDONLY);
    if (fd1 < 0)
        return (-1);
    
    res = get_next_line(fd1,&line);
    printf("res: %d, descriptor: %d, line: %s\n",res,fd1,line);
    res = get_next_line(fd4,&line);
    printf("res: %d, descriptor: %d, line: %s\n",res,fd4,line);
    res = get_next_line(fd4,&line);
    printf("res: %d, descriptor: %d, line: %s\n",res,fd4,line);
    res = get_next_line(fd4,&line);
    printf("res: %d, descriptor: %d, line: %s\n",res,fd4,line);
    res = get_next_line(fd1,&line);
    printf("res: %d, descriptor: %d, line: %s\n",res,fd1,line);
    return (0);
}
