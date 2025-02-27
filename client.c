/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:45:59 by ssukhija          #+#    #+#             */
/*   Updated: 2025/01/29 21:45:59 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void binary(int pid, char c)
{
    int bitnum;

    bitnum = 0;
    while (bitnum < 8)
    {
        if ((c & (0x01 << bitnum)) != 0)
            kill(pid, SIGUSR1);
        else // elseif not sigusr2 Error message
            kill(pid, SIGUSR2);
        usleep(500);
        bitnum++;
    }
}

static void message(int pid, char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        binary(pid, str[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    int i;
    int pid;

    i = 0;
    if (argc != 3)
    {
        exit(write(1, "Please use the format ./client PID 'text'\n", 42));

    }
    while (argv[1][i] != '\0')
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
            exit(write(1, "Sorry invalid PID!\n", 19));
        i++;
    }
    pid = ft_atoi(argv[1]);
    message(pid, argv[2]);
    message(pid, "\n");
    return (0);
}