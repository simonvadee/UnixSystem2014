/*
** main.c for ftp in /home/vadee_s/PSU_2014_myftp/sources/server
** 
** Made by simon vadée
** Login   <vadee_s@epitech.net>
** 
** Started on  Sun Mar 22 10:23:48 2015 simon vadée
** Last update Sun Mar 22 10:23:49 2015 simon vadée
*/

#include "myftp.h"

int			main(int ac, char **av)
{
  int			socket_fd;
  struct sockaddr_in	server_in;
  int			port;
  e_errors		ret;

  if (ac != 2)
    {
      printf("Usage : ./serveur port");
      return (1);
    }
  if ((ret = init_serv(av[1], &socket_fd, &server_in, &port))
      || (ret = main_loop(socket_fd)))
    return (handle_errors(ret));
  if (close(socket_fd) == -1)
    return FAIL_CLOSE;
  return (0);
}
