#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define LOG_BUFFER_SIZE 100 // max antal valideringar
#define LOG_ENTRY_LENGTH 100 // max längd per loggrad

char logs[LOG_BUFFER_SIZE][LOG_ENTRY_LENGTH];
// lagrar alla loggrader 

int log_count = 0;
// räknar hur många loggrader som används

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

void add_log(char entry[]) {
	if (log_count < LOG_BUFFER_SIZE) {
		// om det finns plats kvar -> spara ny loggrad

		strcpy(logs[log_count], entry);
		// kopiera till nästa plats i loggen

		log_count++;
		// ökar antalet sparade loggrader
	}
}

void show_log() {
	printf("=== LOGGEN ===\n");

	if (log_count == 0) {
		printf("Loggen är tom. \n");
		// om inga valideringar har gjorts

		return;
		// avslutar funktionen direkt
	}

	for (int i = 0; i < log_count; i++) {
		// loopar igenom loggraderna

		printf("%d. %s\n", i + 1, logs[i]);
		// skriver ut nummer för varje rad inklusive loggtexten
		// i + 1 ->  radnummer börjar på 1 istället för arrayens index (som börjar på 0)
	}

	printf("\n");

}

void show_menu() {

	printf("=== NÄTVERKSVERKTYG ===\n");
	printf("1. Validera IP-adress\n");
	printf("2. Validera port\n");
	printf("3. Visa logg\n");
	printf("4. Avsluta\n");
	printf("Gör ett val (1-4): ");
}


int main() {

	int choice;

	while (1) { 
		show_menu();
	
	if (scanf("%d", &choice) != 1) {
		printf("Ogiltigt val - ange siffror(1-4)\n");
		
		while (getchar () != '\n');
		// tömmer raden från felaktig input

		printf("\n");
		continue;
		// gå tillbaka till menyn
	}

	printf("\n");

	if (choice == 1) {
		char ip[50];
		char entry[100];

		while (1) {
			printf("Ange IP-adress: ");
			scanf("%s", ip);

		if (validate_ip(ip)) {
			printf("%s är en giltig IP-adress\n", ip);
			sprintf(entry, "IP %s - giltig", ip);
			add_log(entry);
			break;
		} else {
			printf("\"%s\" är en ogiltig IP-adress\n", ip);
			sprintf(entry, "IP \"%s\" - ogiltig", ip);
			add_log(entry);
		} 
	} 
} 

		
	
	else if (choice == 2) {
		int port;
		char entry[100];

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
			sprintf(entry, "Port %d - giltig", port);
			add_log(entry);
			break;
			// korrekt -> avsluta loopen
		} else {
			printf("\"%d\" är en ogiltig port\n", port);
			sprintf(entry, "Port \"%d\" - ogiltig", port);
			add_log(entry);
			// inkorrekt -> fråga igen
		}
	} 
} 

	else if (choice == 3) {
		show_log();
	}

	else if (choice == 4) {
		printf("Antal valideringar under körning av programmet: %d\n", log_count);
		// skriver ut totala antal valideringar

		printf("Avslutar...\n");
		break;
		// lämnar while-loopen och programmet avslutas

	}

	else {
		printf("Ogiltigt val, försök igen.\n");
	} 
}

 

	return 0;
} 
