#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    char buf[BUFSIZ];
    ssize_t len;
    int s;

    struct sockaddr_in remote_addr;
    memset(&remote_addr, 0, sizeof(remote_addr));

    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote_addr.sin_port = htons(8000);

    if((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket");
        return 1;
    }

    strcpy(buf, "Test message");
    printf("Sending: '%s'\n", buf);

    if((len = sendto(s, buf, strlen(buf), 0,
                     (struct sockaddr*)&remote_addr, sizeof (struct sockaddr))) < 0)
    {
        perror("sendto");
        return 1;
    }

    close(s);

    return 0;
}
