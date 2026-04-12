#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int validate_ip (char ip[]) {
	char copy[50];
	strcpy(copy, ip);
	// kopierar IP-adressen så att originalet förblir (strtok ändrar strängen)
	
	char *part = strtok(copy, ".");
	// delar upp strängen vid varje punkt

	int count = 0;

	while (part != NULL) {
		// loopar så länge det finns delar kvar i IP-adressen

		for (int i = 0; part[i] != '\0'; i++) {
			if (!isdigit(part[i])) {
				return 0;
				// om det inte är siffror -> ogiltig IP
			}
		}
			int num = atoi(part);

			if (num < 0 || num > 255) {
				return 0;
				// om input är utanför intervallet -> ogiltig IP
			}


		count++;
		// räknar hur många delar det är 

		part = strtok(NULL, ".");
		// NULL -> gå vidare till nästa del i IP-adressen
	
	} 

	if (count == 4) {
		return 1;
		// om exakt 4 delar = kan vara en giltig IP-adress
	} else {
		return 0;
		// annars ogiltig
	}
}

int validate_port(int port) {
	if (port >= 1 && port <= 65535) {
		return 1;
	} else {
		return 0;
	}
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

		while (1) {
		printf("Ange port: ");
		
		if (scanf("%d", &port) != 1) {
			// försöker läsa integer i input, om det misslyckas:

			printf("Ogiltig input - ange siffror, tack!\n");
			// uppdaterar användaren att input är fel

			while (getchar() != '\n');
			// tömmer raden från input 
			// motverkar att en loop fastnar
			
			continue;
			// stannar kvar i denna loop (frågar igen)
		}

		if (validate_port(port)) {
			printf("%d är en giltig port\n", port);
			break;
			// korrekt -> avsluta loopen
		} else {
			printf("\"%d\" är en ogiltig port\n", port);
			// inkorrekt -> fråga igen
		}
	} 
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
