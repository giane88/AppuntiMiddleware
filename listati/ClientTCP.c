#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main (int argc, char * argv[]) {
    int sock, port;
    char *host, *msg;
    struct sockaddr_in sa;

    /*parse command line arguments*/
    if (argc < 3) {
        printf ("Usage: client <host> <port> [<message>]\n");
        exit(-1);
    }
    host = argv[1];
    port = atof(argv[2]);
    if (argc == 3) msg = "Let me try ...";
    else msg = argv[3];
    /*set the destination address*/
    memset(&sa, 0, sizeof(struct sockaddr_in));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr.s_addr = inet_addr(host);
    /*create the socket & connect it*/
    sock=socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Creating the socket");
        exit(-1);
    }
    if (connect(sock, (struct sockaddr *) &sa, sizeof(sa)) < 0) {
        perror("Binding");
        exit(-1);
    }
    /*Send the message*/
    if (send(sock, msg, strlen(msg), 0) < 0) {
        perror("Writeing");
        exit(-1);
    }
    /*Close the connection*/
    close(sock);
    return 0;
}
