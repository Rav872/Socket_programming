#include"header.h"
#include"struct.h"
#include<unistd.h>
int main()
{

	int sokfd1;

	struct sockaddr_in client1; 
	int   sockfd1,ret,ret1,ret2;
	
          char arr[50];
	socklen_t len;
	client1.sin_family=AF_INET;

	client1.sin_port=htons(9000);

	client1.sin_addr.s_addr= inet_addr("127.0.0.1");

	sockfd1=socket(AF_INET,SOCK_STREAM,0);
        printf("sockfd1:%d\n",sockfd1);
	if(sockfd1<0)
	{

		perror("socket");
		goto OUT;
	}


	len=sizeof(struct sockaddr_in);


	ret=  connect(sockfd1,(struct sockaddr *)&client1,len);
	printf("value of ret is %d\n",ret);
	if(ret<0)

	{
		perror("connect");
		goto OUT;
	}
	while(1)
	{
                 fgets(arr,sizeof(arr),stdin);
		write(sockfd1,arr,sizeof(arr));

		read(sockfd1,arr,sizeof(arr));

		printf("server:%s\n",arr);

	}
OUT:
	return -1;
}


