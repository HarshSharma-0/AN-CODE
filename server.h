#include <filesystem>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include "handlerequest.h"
#include <fstream>
#include <stdio.h>
#include "ReadFile.h"
void  server_start(){
     
        
        
        
	struct sockaddr_in socket_qe,cli_addr;
	int server_fd=socket(AF_INET,SOCK_STREAM,0);
	if(server_fd<0){
		std::cout<<"error createing socket  "<<strerror(errno)<<std::endl;
	};
	socket_qe.sin_family=AF_INET;
	socket_qe.sin_port=htons(1500);
	socket_qe.sin_addr.s_addr = INADDR_ANY;
	socklen_t socket_len=sizeof(socket_qe);


	if(bind(server_fd, (struct sockaddr *)&socket_qe,socket_len) < 0){
		std::cout<<"\nerror binding\n";

	};
	std::cout<<socket_qe.sin_addr.s_addr<<":"<<socket_qe.sin_port<<std::endl;
	if(listen(server_fd,3)<0){
		std::cout<<"error listening"<<std::endl;
	}
	socklen_t clilen=sizeof(cli_addr);
	int cfd=accept(server_fd, (struct sockaddr*)&socket_qe,&socket_len);
	if (cfd<0){
		std::cout<<"error accept"<<std::endl;
	}
      
       sendfile(cfd,"index.html");
       

	std::cout<<"send sucess"<<std::endl;
	close(cfd);
	if(shutdown(server_fd, SHUT_RDWR)<0){
		std::cout<<"error shutdown"<<std::endl;
		shutdown(server_fd, SHUT_RDWR);
	}


}
