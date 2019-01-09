/*
** EPITECH PROJECT, 2018
** src/ls/flag_l
** File description:
** try not to segfault, good luck :)
*/

#include "my_ls.h"

int ls_flag_l(struct stat st)
{
    struct passwd *pwd = getpwuid(st.st_uid);
    struct group *grp = getgrgid(st.st_gid);

    if (!pwd || !grp)
        return EXIT_ERROR;
    put_char((S_ISDIR(st.st_mode)) ? 'd' : '-');
    put_char((st.st_mode & S_IRUSR) ? 'r' : '-');
    put_char((st.st_mode & S_IWUSR) ? 'w' : '-');
    put_char((st.st_mode & S_IXUSR) ? 'x' : '-');
    put_char((st.st_mode & S_IRGRP) ? 'r' : '-');
    put_char((st.st_mode & S_IWGRP) ? 'w' : '-');
    put_char((st.st_mode & S_IXGRP) ? 'x' : '-');
    put_char((st.st_mode & S_IROTH) ? 'r' : '-');
    put_char((st.st_mode & S_IWOTH) ? 'w' : '-');
    put_char((st.st_mode & S_IXOTH) ? 'x' : '-');
    put_char(' ');
    put_nbr(st.st_nlink);
    put_char(' ');
    put_str(pwd->pw_name);
    put_char(' ');
    put_str(grp->gr_name);
    return EXIT_OKAY;
}
