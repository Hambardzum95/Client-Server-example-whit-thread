#include "lib.h"

int readercount = 0;

int	Socket(int domain, int type, int protocol) 
{
	int result = socket(domain,type,protocol);
	if (result == -1)
	{
		perror("Socket creation failed...");
		exit(EXIT_FAILURE);
	}
	return result;
}

int	 	Accept(int server_fd, struct sockaddr *server_storeg, socklen_t *addr_size)
{
	int result = accept(server_fd, server_storeg, addr_size);
	if (result == -1)
	{
		perror("Accept failed...");
		exit(EXIT_FAILURE);
	}
	return result;
}
void	Bind(int sockfd, const struct sockaddr *addr, socklen_t addr_size)
{
	int result = bind(sockfd, addr,addr_size);
	if (result == -1)
	{
		perror("Socket bind failed...");
		exit(EXIT_FAILURE);
	}
}
void	Listen(int sockfd, int log)
{
	int result = listen(sockfd,log);
	if(result == -1)
	{
			perror("Listen failed...");
			exit(EXIT_FAILURE);
	}
}
void Connect(int sockfd, const struct sockaddr *addr, socklen_t addr_size)
{
	int result = connect(sockfd,addr,addr_size);
	if (result == -1)
	{
		perror("connect failed");
		exit(EXIT_FAILURE);
	}
}

void* reader()
{
    sem_wait(&x);
    readercount++;
    if (readercount == BUFFER_SIZE)
    {
        sem_wait(&y);
    }
    sem_post(&x);


	printf("Ip_addres,%s Port = %d\n ",inet_ntoa(client.sin_addr), ntohs(client.sin_port));
 
    sleep(5);
    sem_wait(&x);
    readercount--;
    if (readercount == 0)
    {
        sem_post(&y);
    }
    sem_post(&x);
    printf("\n%d Client is Disconnect\n",readercount + 1);
    pthread_exit(NULL);
}
void *get_time()
{
	time_t times;
	struct tm *t;
	time(&times);
	t = localtime(&times);


    printf("\nClient time  is %d : %d : %d \n%d : %d : %d \n",t->tm_year + 1900,t->tm_mon + 1,t->tm_mday,t->tm_hour, t->tm_min, t->tm_sec);
    printf("\n Client is Disconnect\n ");
    pthread_exit(NULL);
}
 
void* disconnect()
{
    printf("\nClient is Disconnect\n");
    pthread_exit(NULL);
}