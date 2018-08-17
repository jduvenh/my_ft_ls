/* ************************************************************************** */

/*                                                                            */

/*                                                        :::      ::::::::   */

/*   ft_ls.c                                            :+:      :+:    :+:   */

/*                                                    +:+ +:+         +:+     */

/*   By: jduvenh <marvin@42.fr>                     +#+  +:+       +#+        */

/*                                                +#+#+#+#+#+   +#+           */

/*   Created: 2018/08/13 12:38:14 by jduvenh           #+#    #+#             */

/*   Updated: 2018/08/13 15:03:43 by jduvenh          ###   ########.fr       */

/*                                                                            */

/* ************************************************************************** */

#include "ft_ls.h"

void	ft_opendir(struct s_ftls *point)
{
	DIR *dir;
	struct dirent *dent;
	dir = opendir(".");

	if (dir != NULL)
	{
		while ((dent = readdir(dir)) != NULL)
		{
			printf("%s", dent->d_name);
			printf("\t");
		}
	}
	printf("\n");
	return ;
}

void	ft_print(struct s_ftls *print)
{

	int i = 0;

	printf("NAME of exe : %s\n\n", print->av[0]);
	printf("\n total %d\n", print->ac);
	return ;
}

void	ft_readflags(struct s_ftls *local)
{
	if (local->ac > 1)
	{
		if (local->av[1][0] == 'a')
			ft_opendir(local);
		else if (local->av[1][0] == 'l')
			ft_perm(local);
		else
			ft_print(local);
	}

}

void	ft_constructor(int ac, char **av)
{
	struct	s_ftls local;

	local.ac = ac;
	local.av = av;
	local.output = NULL;
	local.buff = NULL;
	local.track = 0;
	ft_readflags(&local);
	return ;
}

int	main(int ac, char **av)
{
	ft_constructor(ac ,av);
	return (0);
}
