#include "ft_ls.h"

void strmode(mode_t mode, char * buf)
{
	const char chars[] = "rwxrwxrwx";
	for (size_t i = 0; i < 9; i++)
		buf[i] = (mode & (1 << (8-i))) ? chars[i] : '-';
	buf[9] = '\0';
}

void ft_perm(struct s_ftls *local)
{
	struct stat permissions;//man 2 stat
	struct passwd *uid;//man 2 getpwuid
	struct group *grp;//man 2 getgrgid

	const char perms[] = "-rwxrwxrwx";//reg perms
	char permsize[11];//no of chars in reg perms incl '\0'
	mode_t combs[1];//declared combs as mode_t, [1] for 1 input
	size_t combcon = sizeof(combs) / sizeof(combs[0]);//for perms
	size_t i;//permissions

	lstat(local->av[2], &permissions);
	int res = permissions.st_mode;//permissions
	int sze = permissions.st_size;//size
	uid = getpwuid(permissions.st_uid);//username
	grp = getgrgid(permissions.st_gid);//group name
	combs[0] = res;//permissions to type of file
	i = 0;

	char time[100]; //time
	strcpy(time, ctime(&permissions.st_mtim.tv_sec));

	if (res >= 16384 && res <= 16895) //octal to decimal converted
		printf("d");
	else if (res >= 40960 && res <= 41471)//otod
		printf("l");
	else
		printf("-");

	strmode(combs[i], permsize);//convert octal to perm chars
	printf("%s ", permsize);//-rwx...
	printf("%s ", uid->pw_name);//user
	printf("%s ", grp->gr_name);//group
//	if (sze >= 1024)
//		sze /= 1024;
	printf("%d ", sze);//1kb
	printf("%.19s ", time);//time
	printf("%s\n", local->av[2]);//name of file param

	printf("%o\n", res);
	printf("read = 4, write = 2, exec = 1\n");
	return ;
}

