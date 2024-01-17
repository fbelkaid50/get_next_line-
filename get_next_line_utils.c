/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:02:09 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/01/17 23:56:18 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int ft_check (char *str)
{
    int res;

    res =0;
    while (*str)
    {
        if (*str == '\n')
        {
            res =1;
            break;
        }
       else if (*str !='\n')
       str++;
    }
    return res;
}
void ft_addtoend (t_list **list, char *str, ssize_t readbytes)
{
    t_list *new_node = malloc(sizeof(t_list));
    new_node->str = str;
    new_node->next = NULL;

    if (*list == NULL) {
        *list = new_node;
    } else {
        t_list *current = *list;
        while (current->next != NULL) 
            current = current->next;
        current->next = new_node;
    }
} 
int ft_chercounter(char *str)
{
    size_t i ;

    i =0; 
    while(*str)
    {
        if (*str != '\n')
        {
            i++;
            str++;
        }
        else
            return i;
            
    }
    return (i);
}
void ft_founded (t_list **list, char *str)
{
    size_t i;
    char *part1;
    char  *part2;

    i = ft_chercounter(str);

    part1 = malloc((i + 1) * sizeof(char));
    strncpy(part1, str, i);
    part1[i] = '\0';

    ft_addtoend(list, part1, i);

    if (str[i] != '\0') {  // If there's more string after the newline
        part2 = malloc((strlen(str + i + 1) + 1) * sizeof(char));
        strcpy(part2, str + i + 1);
        ft_addtoend(list, part2, strlen(part2));
    }
}