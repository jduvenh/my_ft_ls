/* ************************************************************************** */

/*                                                                            */

/*                                                        :::      ::::::::   */

/*   ft_ls.h                                            :+:      :+:    :+:   */

/*                                                    +:+ +:+         +:+     */

/*   By: jduvenh <marvin@42.fr>                     +#+  +:+       +#+        */

/*                                                +#+#+#+#+#+   +#+           */

/*   Created: 2018/08/13 12:38:14 by jduvenh           #+#    #+#             */

/*   Updated: 2018/08/13 15:03:43 by jduvenh          ###   ########.fr       */

/*                                                                            */

/* ************************************************************************** */

#include <dirent.h> //opendir
#include <stdio.h>//printf
#include <unistd.h>//stat
#include <sys/stat.h>//stat
#include <sys/types.h>//stat
#include <pwd.h>//getpwuid
#include <grp.h>//getgrgid
#include <string.h>//strcpy
#include <time.h>//ctime

struct		s_ftls
{
	int	ac;
	char	**av;
	char	*output;
	char	*buff;
	int	track;
};

void	ft_constructor(int ac, char **av);
void	ft_print(struct s_ftls *print);
void	ft_opendir(struct s_ftls *local);
void	ft_perm(struct s_ftls *local);
