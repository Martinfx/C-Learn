#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    char buf[BUFSIZ];
    int s, fd, len;
    unsigned int sin_size;

    struct sockaddr_in my_addr;
    struct sockaddr_in remote_addr;
    memset(&my_addr, 0, sizeof(my_addr));

    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = INADDR_ANY;
    my_addr.sin_port = htons(8000);

    if((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket");
        return 1;
    }

    if(bind(s, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) < 0)
    {
        perror("bind");
        return 1;
    }

    sin_size = sizeof(struct sockaddr_in);

    printf("Waiting to packet... \n");

    while(((len = recvfrom(s, buf, BUFSIZ, 0, (struct sockaddr*)&remote_addr, &sin_size))) > 0)
    {
        printf("received packet from %s: \n", inet_ntoa(remote_addr.sin_addr));
        buf[len] = '\0';
        printf("Contents: %s\n", buf);

        if(((len = recvfrom(s, buf, BUFSIZ, 0, (struct sockaddr*)&remote_addr, &sin_size))) < 0)
        {
            perror("recvfrom");
            return 1;
        }
    }


    close(s);

    return 0;
}
