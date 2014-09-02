#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFLEN 1024

int main (int argc, char * argv[]) {
    int sock, port, s, n;
    char buf[BUFFLEN];
    struct sockaddr_in sa;

    /*parse command line arguments*/
    if (argc < 2) {
        printf ("Usage: server <port>\n");
        exit(-1);
    }
    port = atof(argv[1]);
    /*set the destination address*/
    memset(&sa, 0, sizeof(struct sockaddr_in));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr.s_addr = htonl(INADDR_ANY);
    /*create the socket & connect it*/
    sock=socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Creating the socket");
        exit(-1);
    }
    if (bind(sock, (struct sockaddr *) &sa, sizeof(sa)) < 0) {
        perror("Binding");
        exit(-1);
    }
    if (listen(sock, 0) < 0) {
        perror("Listening");
        exit(-1);
    }
    /*Accepting incoming request (main loop)*/
    while (1) {
        /*Accept new connection*/
        s = accept(sock, NULL, NULL);
        if (s < 0) {
            perror("Accepting");
            exit(-1);
        }
        /*Recive incoming data*/
        while (1) {
            memset(buf, 0, sizeof(buf));
            if ((n = read(s, buf, BUFFLEN-1)) < 0)
                perror("Receiving data");
            else if ( n == 0) break;
            else {
                printf("%s\n",buf);
                if(buf[n-1] == 4) break;
            }
        }
        close(s);
    }
    close(s);
    close(sock);
    return 0;
}
