#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
int main()
{
	int size,sock,connect;
	char senderdata[50],data[50];
	int val,count,i,port;
	struct sockaddr_in ser,cli;
	printf("\n\n--------Server Running------");
	if((sock=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		PERROR("\NSocket Creation Error");
		exit(-1);
	}
	printf("\nEnter the port number:");
	scanf("%d",&port);
	ser.sin_family=AF_INET;
	ser.sin_port=htons(port);
	ser.sin_addr.s_addr=INADDR_ANY;
	bzero(&(ser.sin_zero),0);
	if(bind(sock,(struct sockaddr *)&ser,sizeof(struct sockaddr))==-1)
	{
		perror("\n\t Error in Bind");
		exit(-1);
	}
	 if(listen(sock,2)==-1)
	 {
	 	perror("\n\t Error in listen");
		exit(-1);
	 }
	 printf("\n\t Waiting for Connection");
	 size=sizeof(struct sockaddr);
	 connect=accept(sock,(struct sockaddr *)&cli,&size);
	 if(connect=-1)
	 {
	 	perror("\n\t Connection Failed");
		exit(-1);
	 }
	 printf("\n\t Connected Succesfully");
	 printf("\n");
	 recv(connect,&val,sizeof(val),0);
	 count=val;
	 while(1)
	 {
	 	i=recv(connect,&data,sizeof(data),0);
	 	data[i]='\0';
	 	if(strcmp(data,"end")==0)
	 	{
	 		printf("\n\t Finished");
	 		break;
		 }
		 if(count!=val)
		 {
		 	strcpy(senderdata,"frame missing");
		 	send(connect,&count,sizeof(count),0);
		 	send(connect,senderdata,strlen(senderdata),0);
		 }
		 else
		 {
		 	printf("\n The frame number is: %d",val);
		 	printf("\n The data is : %s",data);
		 	count++;
		 	strcpy(senderdata,"send nextdata");
		 	send(connect,&count,sizeof(count),0);
		 	send(connect,senderdata,strlen(senderdata),0);
		 }
		 printf("\n The expected frame now is:%d\n",count);
		 recv(connect,&val,sizeof(val),0);
	 }
	 close(connect);
	 close(sock);
	 return 0;
}
