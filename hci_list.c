/*
 * hci_list.c : Find the list of bluetooth controller present as
 *		- If more the one controller found, prints the UP-RUNNING
 *		- If none is enabled, it prints the first found controller
 *		- If none found, prints nothing
 * Compile: gcc -o ./hci_list ./hci_list.c -lbluetooth
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

static int hci_devlist(struct hci_dev_info **di, int *num)
{
	int i;

	if((*di = malloc(HCI_MAX_DEV * sizeof(**di))) == NULL)
		return -1;

	for(i = *num = 0; i < HCI_MAX_DEV; i++)
		if (hci_devinfo(i, &(*di)[*num]) == 0)
			(*num)++;

	return 0;
}

int main(void)
{
	int i;
	int hci_devs_num;
	struct hci_dev_info *hci_devs;

	if(hci_devlist(&hci_devs, &hci_devs_num)) {
		printf("Couldn't enumerate HCI devices: %s", strerror(errno));
		return 1;
	}

	for(i = 0; i < hci_devs_num; i++)
		if(i == 0 || hci_test_bit(HCI_UP, &hci_devs[i].flags))
			printf("HCI Name : %s\nAddress  : %s\n", hci_devs[i].name, batostr(&hci_devs[i].bdaddr));

	free(hci_devs);
	return 0;
}
