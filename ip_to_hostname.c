#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>

main(int argc, char **argv)
{
        struct hostent *host;
        long addr;

        if (argc != 2) {
                printf("usage: %s i.p.address\n", argv[0]);
                return(1);
        }

        addr = inet_addr(argv[1]);

        if (host = gethostbyaddr((char *) &addr, sizeof(addr), AF_INET)) {
                printf("Hostname:\t%s\n", host->h_name);
                printf("Addresses:\t");
                while (host->h_addr_list[0])
                        printf("%s ", inet_ntoa(*(struct in_addr *) *host->h_addr_list++));
                printf("\n");
                return(0);
        }
        printf("host %s not found\n", argv[1]);
        return(1);
}
