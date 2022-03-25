# ifndef _LIB_H_
# define _LIB_H_

# include <stdlib.h>
# include <unistd.h>

# include <string.h>
# include <stdio.h>

# include <sys/types.h>
# include <sys/socket.h>
# include "time.h"
# include <netinet/in.h>
# include <arpa/inet.h>

# include <pthread.h>
# include <semaphore.h>


#define PORT 2560
#define BUFFER_SIZE 1024

int		Socket(int domain, int type, int protocol);
int	 	Accept(int server_fd, struct sockaddr *server_storeg, socklen_t *addr_size);
void	Bind(int sockfd, const struct sockaddr *addr, socklen_t addr_size);
void	Listen(int sockfd, int log);
void 	Connect(int sockfd, const struct sockaddr *addr, socklen_t addr_size);

void 	*disconnect();
void 	*get_time();
void	*reader();

sem_t x, y;
struct sockaddr_in client;

# endif