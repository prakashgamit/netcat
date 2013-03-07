/* *********************************************************************** *
 *
 *       Filename:  wrapper.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 07 March 2013 12:44:15  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prakash Gamit (09211014), <prakashgamit23@gmail.com>
 *   Organization:  Indian Institute of Technology, Roorkee
 *
 * ********************************************************************* */

#include "wrapper.h"


int Socket(int family, int type, int protocol){
    int fd = socket(family, type, protocol);

    if(fd == -1){
        die("socket");
    }

    return fd;
}


int Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
    int status = bind(sockfd, addr, addrlen);

    if(status == -1)
        die("bind");

    return status;
}


int Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
    int status = connect(sockfd, addr, addrlen);

    if(status == -1)
        die("connect");

    return status;
}


int Listen(int sockfd, int backlog){
    int status = listen(sockfd, backlog);

    if(status == -1)
        die("listen");
    
    return status;
}


int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen){
    int clifd = accept(sockfd, addr, addrlen);

    if(clifd == -1)
        die("accept");

    return clifd;
}


int Inet_pton(int af, const char *src, void *dst){
    int status = inet_pton(af, src, dst);

    if(status == -1){
        die("inet_pton");
    }

    //TODO
    /* hostname given instead if IP-address 
     * resolve hostname */
    if(status == 0){
        //for now print error
        die("inet_pton");
    }

    return status;
}


int Select(int maxfdp1, fd_set *readset, fd_set *writeset,
        fd_set *exceptset, struct timeval *timeout){
    int readyCount = select(maxfdp1, readset, writeset, exceptset, timeout);

    if(readyCount == -1)
        die("select");

    return readyCount;
}


int Read(int fd, void *buf, size_t count){
    int bytes = read(fd, buf, count);

    if(bytes == -1)
        die("read");

    return bytes;
}


int Write(int fd, const void *buf, size_t count){
    int bytes = write(fd, buf, count);

    if(bytes == -1)
        die("write");

    return bytes;
}