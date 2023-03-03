#include "pipex.h"

int msg(char *msg_err)
{
    write(2, msg_err, ft_strlen(msg_err));
    return (1);
}

int msg_error(char *msg_err)
{
    perror(msg_err);
    exit (1);
}