#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int validate_ip (char ip[]) { 

	return 1;
}

int main() {

	int choice;

	while (1) { 
		/* code */

	printf("=== NÄTVERKSVERKTYG ===\n");
	printf("1. Validera IP-adress\n");
	printf("2. Validera port\n");
	printf("3. Visa logg\n");
	printf("4. Avsluta\n");

	printf("Gör ett val (1-4): ");
	scanf("%d", &choice);

	printf("validerar: %d \n", choice);

	if (choice == 1) {
		char ip[50];

		printf("Ange IP-adress: ");
		scanf("%s", ip);

		if (validate_ip(ip)) {
			printf("%s är en giltig IP-adress\n", ip);
		} else {
			printf("\"%s\" är en ogiltig IP-adress\n", ip);
		}
	} 
	
	else if (choice == 2) {
		int port;

		printf("Ange port: ");
		scanf("%d", &port);

		printf("Testsvar: %d\n", port);

	}	

	else if (choice == 3) {

		printf("Här kommer loggen visas: \n");

	}

	else if (choice == 4) {

		printf("Avslutar...\n");
		break;

	}

	else {
		printf("Ogiltigt val, försök igen.\n");
	} 

} 

	return 0;
} 
