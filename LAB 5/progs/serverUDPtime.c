 #include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <time.h>
int main()
{
int nsd,r,bi,port;
char b[1024];
struct sockaddr_in servaddr,cliaddr;
socklen_t clilen;
nsd=socket(AF_INET,SOCK_DGRAM,0);
if(nsd==-1)
{
perror("Socket");
return 0;
}
printf("Enter the port no:");
scanf("%d",&port);
printf("The port no is:%d\n",port);
servaddr.sin_family = AF_INET;
servaddr.sin_port = htons(port);
servaddr.sin_addr.s_addr = INADDR_ANY;
bi=bind(nsd,(struct sockaddr*)&servaddr,sizeof(servaddr));
if(bi==-1)
{
perror("Bind()");
return 0;
}
clilen = sizeof(cliaddr);
r=recvfrom(nsd,b,sizeof(b),0,(struct sockaddr*)&cliaddr,&clilen);
b[r]=0;
time_t ticks;
ticks = time(NULL);
snprintf(b,sizeof(b),ctime(&ticks));
sendto(nsd,b,sizeof(b),0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
exit(0);
return 0;
}
