/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:03:28 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/01/18 00:00:46 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include<fcntl.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <unistd.h>
 typedef struct s_list
{
    char *str;
    struct s_list *next ;
}t_list;

    void ft_founded (t_list **list, char *str);
    int ft_chercounter(char *str);
    void ft_addtoend (t_list **list, char *str, ssize_t readbytes);
    int ft_check (char *str);

#endif