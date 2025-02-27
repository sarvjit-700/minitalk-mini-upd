/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:14:19 by ssukhija          #+#    #+#             */
/*   Updated: 2025/02/26 14:58:52 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check 42 headers in everyfile 
// check speed is the same as school
// check differences - speed..
// norm
// search for printf 
// allowed functions
// read gitbook explainer again

#include "minitalk.h"

char	*msg;

void	response(int sig)
{
	static int	bitnum = 0;
	static int	i;
	char	c[2];
	
	if (sig == SIGUSR1)
		i |= (0x01 << bitnum);
	bitnum++;

	if (bitnum == 8)
	{
		//c = (char *)malloc(sizeof(char) * 2);
		//if (c == NULL)
	//		return ;
		c[0] = (char)i;
		c[1] = '\0';
		if (msg == NULL)
		{	
			msg = malloc(sizeof(char) * 1);
			if (msg == NULL)
				return ;
			msg[0] = '\0';
		}
		msg = ft_strjoin(msg, c);
		if (c[0] == '\n')
		{
			ft_putstr_fd(msg, 1);
			free(msg);
			msg = NULL;
		}
		bitnum = 0;
		i = 0;
	}
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		write(1, "--INTERRUPTED--", 15);
		write(1, "\n", 1);
		free(msg);
		exit(0);
	}
}


int	main(void)
{
	pid_t	pid;
	struct sigaction sa;

	pid = getpid();
	write(1, "SERVER PID : ", 12);
	ft_putnbr(pid);
	write(1, "\n", 1);
	sa.sa_handler = response;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGINT, &sa, NULL);

	while (pid)
		pause();
	return (0);
}
