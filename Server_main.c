#include "lib.h"

int main ()
{
	int server_fd;
	pthread_t tid[BUFFER_SIZE];
	pthread_t tid1[BUFFER_SIZE];

	sem_init(&x, 0, 1);
	sem_init(&y, 0, 1);
	struct sockaddr_in server;
	bzero(&server,sizeof(server));

	server_fd = Socket(AF_INET,SOCK_STREAM, 0);
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = htonl(INADDR_ANY);


	Bind(server_fd, (struct sockaddr *)&server, sizeof(server));
	Listen(server_fd, 100);
	
	printf("Waiting Client >>>>>\n");
	int  i = 0;
	while (1)
	{
		socklen_t client_size = sizeof(client);
		int a = Accept(server_fd, (struct sockaddr *)&client, &client_size);

		int choice = 0;
		recv(a,&choice,sizeof(choice),0);

        if (choice == 1) 
        {
            if (pthread_create(&tid[i++], NULL,reader,&a)!= 0)
                printf("Failed to create thread\n");
        }
        else if (choice == 2)
         {
            if (pthread_create(&tid1[i++], NULL,disconnect, &a)!= 0)
            {
                printf("Failed to create thread\n");
            }
        }
        else if (choice == 3)
        {
        	if (pthread_create(&tid1[i++], NULL,get_time, &a)!= 0)
            {
                printf("Failed to create thread\n");
            }
        }
 
        if (i >= BUFFER_SIZE)
         {
            i = 0;
            while (i < BUFFER_SIZE)
            {
                pthread_join(tid[i++], NULL);
                pthread_join(tid1[i++],NULL);
            }
            i = 0;
        }
	}
	close(server_fd);
	return 0;
}