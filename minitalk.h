/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:02:29 by ssukhija          #+#    #+#             */
/*   Updated: 2025/01/28 15:02:29 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h> // not sure
# include <stdlib.h>
# include <stdbool.h> //not sure

size_t  ft_strlen(const char *s);

void	ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *s, int fd);
void    ft_putnbr(pid_t n);

char    *ft_strjoin(char *s1, char *s2);

//int	ft_putnbr(int nb)
int ft_atoi(const char *nptr);
#endif