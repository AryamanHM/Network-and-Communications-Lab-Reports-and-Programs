#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
int main()
{
int sd,sd2,nsd,clilen,sport,len;
char sendmsg[20],rcvmsg[20];
struct sockaddr_in servaddr,cliaddr;
printf("Enter server port\n");
scanf("%d",&sport);
sd=socket(AF_INET,SOCK_STREAM,0);
if(sd<0)
printf("Can't Create \n");
else
printf("Socket is Created\n");
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(sport);
sd2=bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
if(sd2<0)
printf("Can't Bind\n");
else
printf("\n Binded\n");
listen(sd,5);

do
 {
recv(nsd,rcvmsg,20,0);
printf("%s",rcvmsg);
fgets(sendmsg,20,stdin);
len=strlen(sendmsg);
sendmsg[len-1]='\0';
send(nsd,sendmsg,20,0); 
}
while(strcmp(sendmsg,"bye")!=0);
close(sd);
close(nsd);
}

