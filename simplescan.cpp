// example from the book
// g++ -o simplescan simplescan.c -lbluetooth

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include "iostream"

int main(int argc, char **argv)
{
    inquiry_info *ii = NULL;
    int max_rsp, num_rsp;
    int dev_id, sock, len, flags;
    int i;
    char addr[19] = { 0 };
    char name[248] = { 0 };
    dev_id = hci_get_route(NULL);
    sock = hci_open_dev( dev_id );
    if (dev_id < 0 || sock < 0) {
        perror("opening socket");
        exit(1);
    }

    len = 8;
    max_rsp = 255;
    flags = IREQ_CACHE_FLUSH;
    ii = (inquiry_info*)malloc(max_rsp * sizeof(inquiry_info));
    while (num_rsp < 1){
        num_rsp = hci_inquiry(dev_id, len, max_rsp, NULL, &ii, flags);
    }
    // num_rsp = hci_inquiry(dev_id, len, max_rsp, NULL, &ii, flags);
    // printf(">>> num_rsp: %i\n", num_rsp);
    std::cout << "Number of discovered devices: " << num_rsp << '\n';
    if(num_rsp < 0) perror("hci_inquiry");
    
    for (i = 0; i < num_rsp; i++) {
        ba2str(&(ii+i)->bdaddr, addr);
        memset(name, 0, sizeof(name));
        if (hci_read_remote_name(sock, &(ii+i)->bdaddr, sizeof(name),
            name, 0) < 0)
        strcpy(name, "[unknown]");
        //printf("%s %s\n", addr, name);
        std::cout << addr << ' ' << name << '\n';
    }

    free(ii);
    close(sock);
    return 0;
}
