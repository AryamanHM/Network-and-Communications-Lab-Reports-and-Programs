#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main()
{
int listenfd,port,r;
char b[1024];
struct sockaddr_in servaddr,cliaddr;
socklen_t servlen;
listenfd = socket(AF_INET,SOCK_DGRAM,0);
if(listenfd==-1)
{
perror("Socket");
return 0;
}

printf("Enter the port no:");
scanf("%d",&port);
printf("The port no is:%d",port);
servaddr.sin_family = AF_INET;
servaddr.sin_port = htons(port);
servaddr.sin_addr.s_addr = INADDR_ANY;
sendto(listenfd,b,sizeof(b),0,(struct sockaddr*)&servaddr,sizeof(servaddr));
r=recvfrom(listenfd,b,sizeof(b),0,(struct sockaddr*)&servaddr,&servlen);
b[r]=0;
printf("\nThe time received from the server:%s\n",b);
exit(0);
return 0;
}

