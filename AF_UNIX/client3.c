#include"header.h"
#include"struct.h"
int main()
{

	int sockfd1;
	int sa,ret3;
	int a=9;
	struct sockaddr_un des_addr;
	socklen_t len1;
	des_addr.sun_family=AF_UNIX;
	strcpy(des_addr.sun_path, "socket1");

	sockfd1= socket(AF_UNIX,SOCK_STREAM,0);
	printf("sockfd1 is %d\n",sockfd1);
	if(sockfd1<0)
	{
		perror("sockfd1");
		goto OUT;
	}

	len1=sizeof(struct sockaddr_un);

	ret3=connect(sockfd1,(struct sockaddr *)&des_addr,len1);
	printf("ret3=%d\n",ret3);
	if(ret3<0)
	{
		perror("connect");
		goto OUT;
	}
	else
		printf("accept() is ok\n");
	write(sockfd1,&a,sizeof( int));


OUT:
	return -1;
}
