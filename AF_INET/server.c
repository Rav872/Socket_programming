#include"header.h"
#include"struct.h"
#include<unistd.h>
int main()
{


	struct sockaddr_in server;

	int sockfd,curr,ret2,ret3;
           char brr[50];
	socklen_t len1;
	struct sockaddr_in client;
	len1 =sizeof(struct sockaddr_in);

	server.sin_family=AF_INET;

	server.sin_port=htons(9000);

	server.sin_addr.s_addr=htonl(INADDR_ANY);
      

	sockfd=socket(AF_INET,SOCK_STREAM,0);
        //printf("kkkkk\n");
      ret2= bind(sockfd,(struct sockaddr*)&server,len1);
          if(ret2<0)
           {
               perror("bind");
                 goto OUT;
           }
     ret3=listen(sockfd,10);
       if(ret3<0)
     {
            perror("listen");
            goto OUT;
       }
        else
           printf("socket listen successfully\n");
         

	while(1)
	{
           printf("Waiting For Child\n");
		curr= accept(sockfd,(struct sockaddr*)&client,&len1);
                
         
		printf(" curr is %d\n",curr);

		if(curr<0)
		{

			perror("accept");
			goto OUT;
		}
           
while(1)
{
		read(curr,brr,sizeof(brr));

		printf(" client:%s\n",brr);
    
                fgets(brr,sizeof(brr),stdin);
         
                write(curr,brr,sizeof(brr));
 }              
               }
OUT:
		return -1;
	}







