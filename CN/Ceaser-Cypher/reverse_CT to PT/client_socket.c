#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<string.h>
#include<sys/un.h>
#include<unistd.h>

int main(void)
{
	int client_sockfd;
	int client_len;
	char out_buf[100],in_buf[100];
	struct sockaddr_un client_address;
	client_sockfd=socket(AF_UNIX,SOCK_STREAM,0);
	client_address.sun_family=AF_UNIX;
	strcpy(client_address.sun_path,"server_socket");
	client_len=sizeof(client_address);
	printf("\n\nclient is requesting to server...\n");
	sleep(2);
	connect(client_sockfd,(struct sockaddr*)&client_address,client_len);
	while(1)
	{
		printf("Enter the message..:");
		gets(out_buf);
		send(client_sockfd,out_buf,(strlen(out_buf)+1),0);
		recv(client_sockfd,in_buf,sizeof(in_buf),0);
                int i, key=4;
   		int n=strlen(in_buf);

  		for(i=0;i<n;i++)
  		{
  		 in_buf[i]=(in_buf[i] - 'A' - key + 26) % 26 + 'A';
  		}
  		  printf("the cipher text is: \n");
    		 puts(in_buf);
		printf("\n\nMessage received from server....:'%s'\n",in_buf);
	}
close(client_sockfd);
return (0);
}
