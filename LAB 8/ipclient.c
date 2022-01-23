#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
int main()
{
    char msg_s[200], msg_r[200];
    int sockfd=socket(AF_INET, SOCK_STREAM,0);
    struct sockaddr_in SA;
    SA.sin_family = AF_INET;
    SA.sin_port = htons(7011);
    SA.sin_addr.s_addr = INADDR_ANY;
    int c1 = connect(sockfd, (struct sockaddr *)&SA, sizeof(SA));
    printf("Enter the ipv4 address: ");
    scanf("%s",msg_s);
	//printf("The entered ip is %s",msg_s);
    send(sockfd,msg_s,200,0);
    recv(sockfd,msg_r,200,0);
    printf("Details : %s\n",msg_r);

    printf("Enter the subnet mask: ");
    scanf("%s",msg_s);
	//printf("The entered ip is %s",msg_s);
    send(sockfd,msg_s,200,0);
    recv(sockfd,msg_r,200,0);
    printf("Details : %s\n",msg_r);
	close(sockfd);
}
