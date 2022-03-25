#include "lib.h"

void* clienthread(void* args)
{
 
    int client_request = *((int*)args);
    int network_socket;
 
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
 
    Connect(network_socket,(struct sockaddr*)&server_address,sizeof(server_address));
 
    printf("Connection stabile\n");
 
    send(network_socket, &client_request, sizeof(client_request), 0);
 
    close(network_socket);
    pthread_exit(NULL);
    return 0;
}
 
int main()
{
    printf("Input < 1 > for : Print_ip and Print_port\n");
    printf("Input < 2 > for : client is Disconnect\n");
    printf("Input < 3 > for : print_time\n");

    int choice;
    scanf("%d", &choice);
    pthread_t tid;
 
    switch (choice)
    {
    case 1:
    {
        int client_request = 1;

        pthread_create(&tid, NULL,clienthread,&client_request);
        sleep(20);
        break;
    }
    case 2:
    {
        int client_request = 2;
        pthread_create(&tid, NULL, clienthread, &client_request);
        break;
    }
    case 3:
    {
        int client_request = 3;
        pthread_create(&tid,NULL,clienthread,&client_request);
        sleep(20);
        break;
    }
    default:
        printf("Invalid Input\n");
        pthread_exit(NULL);
        break;
    }
    pthread_join(tid, NULL);
}