/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:26:21 by fbelkaid          #+#    #+#             */
/*   Updated: 2024/01/18 00:03:08 by fbelkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


// char *get_next_line(int fd)
// {
// 	static t_list *list  ;
//     char str[BUFFER_SIZE +1];
    
//     list = NULL;
    
//     if (fd < 0  || BUFFER_SIZE <=0 || read (fd,&str,0)<0)
//         return NULL;
//         read_bytes = read(fd, str, BUFFER_SIZE);
//     if (read_bytes <= 0)
//         return NULL;
//     if(list ==NULL)
//         read (fd,&str,BUFFER_SIZE);
//     if(list->str =='\0')
//         ft_addtoend(&list,str+ft_chercounter(str));
//     if (ft_check(&str[BUFFER_SIZE])==0)
//         ft_addtoend(&list,str);
//     else 
//         ft_founded(&list , str);
//     return (list->str);
// }
char *get_next_line(int fd)
{
    static t_list *list = NULL;
    char str[BUFFER_SIZE + 1];
    ssize_t read_bytes;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, str, 0) < 0)
        return NULL;

    read_bytes = read(fd, str, BUFFER_SIZE);
    if (read_bytes <= 0)
        return NULL;

    str[read_bytes] = '\0';  // Null-terminate the string

    if (list == NULL || list->str == NULL) {
        ft_addtoend(&list, str, read_bytes);
    } else if (ft_check(str) == 0) {
        ft_addtoend(&list, str, read_bytes);
    } else {
        ft_founded(&list, str);
    }

    return list->str;
}
int main ()
{
    int fd = open ("test.txt",O_RDONLY,0777);
  char *str = get_next_line(fd);
  while (str)
  {
    printf("%s",str);
    str++;
  }

    close (fd);
}
