#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include<math.h>

void subnetA(int arr[])
{
	int a[10],i,n=arr[1],count =0;
	for(i=0;n>0;i++)
	{
		if(n%2==1)
			count++;
		n=n/2;

	}
	float host= pow(2,(24-count)) - 2*pow(2,count);
	printf("Number of Subnets %.0f",(pow(2,count)-2));
	printf("Number of Hosts %.0f \n",host);
}
void subnetB(int arr[])
{	
	int a[10],i,n=arr[2],count =0;
	for(i=0;n>0;i++)
	{
		if(n%2==1)
			count++;
		n=n/2;
	}
	float host= pow(2,(16-count)) - 2*pow(2,count);
	printf("Number of Subnets %.0f \n",(pow(2,count)-2));
	printf("Number of Hosts %.0f \n",host); 
}
void subnetC(int arr[])
{
	int a[10],i,n=arr[3],count =0;
	
	for(i=0;n>0;i++)
	{
		if(n%2==1){
			count++;
			//a[i] = n%2;
		}
		n=n/2;
	}
	float host= pow(2,(8-count)) - 2*pow(2,count);
	printf("Number of Subnets %.0f \n",(pow(2,count)-2));
	printf("Number of Hosts %.0f \n",host);
} 
 


int main()
{
    struct sockaddr_in serv_addr, cli_addr;
    char msg_recv[200], msg_recv2[200] , msg[200];
	int arr[4],arr2[4];
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(7011);
    int b = bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    int l = listen(sockfd,3);
    int clen = sizeof(cli_addr);
    int newsockfd = accept(sockfd, ( struct sockaddr *)&cli_addr, &clen);
    recv(newsockfd,msg_recv,200,0);
    printf("ip received from client : %s\n",msg_recv);
	send(newsockfd,"IP received ",12,0);
	recv(newsockfd,msg_recv2,200,0);
    printf("mask received from client : %s\n",msg_recv2);
    int i=0;
    char * buffer1 = strtok(msg_recv,".");
	int buffer = atoi(buffer1);
	while(buffer1 != NULL)
	{
		arr[i++]=atoi(buffer1);
		buffer1 = strtok(NULL,".");
	}
    i=0;
    char * buffer2 = strtok(msg_recv2,".");
	buffer = atoi(buffer2);
	while(buffer2 != NULL)
	{
		arr2[i++]=atoi(buffer2);
		buffer2 = strtok(NULL,".");
	}



    if(arr[0] <=127 && arr[0] > 0){ 
		strcpy(msg,"Class A");
		subnetA(arr2);


	}
	else if(arr[0] <= 191){ 
		strcpy(msg,"Class B");
		subnetB(arr2);}
	else if(arr[0] <=223){ 
		strcpy(msg,"Class C");
		subnetC(arr2);}
	else if(arr[0] <= 239) 
		strcpy(msg,"Class D");
	else if(arr[0] <= 255) 
		strcpy(msg,"Class E");
	else 
		strcpy(msg,"invalid IP" ); 
    send(newsockfd,msg,200,0);
    close(newsockfd);
    close(sockfd);
}


