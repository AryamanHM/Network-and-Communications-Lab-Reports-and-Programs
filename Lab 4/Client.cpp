#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
int main()
{
         int csd,cport,len;
         char sendmsg[100],rcvmsg[100];
         struct sockaddr_in servaddr,cliaddr;
         printf("Enter server port\n");
         scanf("%d",&cport);
         printf("%d\n",cport);
         csd=socket(AF_INET,SOCK_STREAM,0);
         if(csd<0)
         printf("cant create\n");
         else
         printf("Socket is created\n");
         servaddr.sin_family=AF_INET;
         servaddr.sin_addr.s_addr=htonl(INADDR_ANY); //inet_addr("");
         servaddr.sin_port=htons(cport);
         if(connect(csd,(struct sockaddr*) &servaddr,sizeof(servaddr))<0)
         printf("cant connect");
         else
         printf("Connected");
         do
{
fgets(sendmsg,20,stdin);
len=strlen(sendmsg);
sendmsg[len-1]='\0';
send(csd,sendmsg,20,0);
 recv(csd,rcvmsg,20,0);
printf("%s",rcvmsg);
}
while(strcmp(rcvmsg,"bye")!=0); 
         close(csd);
         }
