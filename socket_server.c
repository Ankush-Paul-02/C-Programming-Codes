#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<string.h>
#include<sys/un.h>
#include<unistd.h>

int main(void)
{
	int server_sockfd,client_sockfd;
	int server_len,client_len;
	char in_buf[100],out_buf[100];
	struct sockaddr_un server_address,client_address;
	unlink("server_socket");
	server_sockfd=socket(AF_UNIX,SOCK_STREAM,0);
	server_address.sun_family=AF_UNIX;
	strcpy(server_address.sun_path,"server_socket");
	server_len=sizeof(server_address);


	printf("\n\n Server Is waiting for client respons\n");
	bind(server_sockfd,(struct sockaddr*)&server_address,server_len);
	listen(server_sockfd,5);
	client_len=sizeof(client_address);
	client_sockfd=accept(server_sockfd,(struct sockaddr*)&client_address,&client_len);
	printf("\n\n client request is accepted by the server\n");
	while(1)
	{
		recv(client_sockfd,in_buf,sizeof(in_buf),0);
		printf("string receive from client .............'%s'\n",in_buf);
		printf("enter the message  :");
		gets(out_buf);
		send(client_sockfd,out_buf,(strlen(out_buf)+1),0);
	}
  close(server_sockfd);
  close(client_sockfd);
  return 0;
}
