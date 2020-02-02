#include"header.h"
#include"struct.h"

int main()
{

	int ret1,ret2,ret3;
	int b,sa;
	char app[35];
	int i;
	int sockfd;

	struct sockaddr_un server_add;
	struct sockaddr_un client_add;
	socklen_t len;

	server_add.sun_family= AF_UNIX;
	strcpy(server_add.sun_path, "socket1");

	len=sizeof(struct sockaddr_un);

	sockfd=socket(AF_UNIX,SOCK_STREAM,0);
	printf(" value of fd is %d\n",sockfd);
	if(sockfd<0)
	{
		perror("socket");
		goto OUT;
	}

	ret1= bind(sockfd,(const struct sockaddr* )&server_add,len);

	if(ret1<0)
	{
		perror("bind");
		goto OUT;
	}

	ret2=  listen(sockfd,10);
	if(ret2<0)
	{
		perror("listen");
		goto OUT;
	}
	else
		printf("server listen successfully\n");

	sa=sizeof(struct sockaddr_un);
	while(1)
	{
		ret3= accept(sockfd,(struct sockaddr *)&client_add,&sa);

		if(ret3<0)
		{
			perror("accept");
			goto OUT;
		}
		else
			printf("accept() is ok\n");
		while(1)
		{
			read(ret3,app,sizeof(app));
			printf("received : %s\n",app);
		}      
	}


OUT:
	return -1;
}
