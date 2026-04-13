#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void remove_whitespace(char str[]); // deklarerar funktionen här så den kan användas innan den definieras (t ex i funktionen menu_choice)

#define LOG_BUFFER_SIZE 100 // max antal valideringar
#define LOG_ENTRY_LENGTH 100 // max längd per loggrad

char logs[LOG_BUFFER_SIZE][LOG_ENTRY_LENGTH];
// lagrar alla loggrader 

int log_count = 0;
// räknar hur många loggrader som används

int validate_ip (char ip[]) {
	char copy[50];
	strcpy(copy, ip);
	// kopierar IP-adressen så att originalet inte ändras (strtok ändrar strängen)
	
	char *part = strtok(copy, ".");
	// delar upp strängen vid varje punkt

	int count = 0;

	while (part != NULL) {
		// loopar igenom varje del (oktett) i IP-adressen

		for (int i = 0; part[i] != '\0'; i++) {
			if (!isdigit(part[i])) {
				return 0;
				// om det inte är siffror -> ogiltig IP
			}
		}
			int num = atoi(part);
			// konverterar sträng till heltal

			if (num < 0 || num > 255) {
				return 0;
				// om input är utanför intervallet -> ogiltig IP
			}


		count++;
		// räknar hur många delar det är (ska vara exakt 4)

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

int validate_port(char port[]) {

	if (port[0] == '\0') {
		return 0;
		// tom sträng = ogiltig input
	}

	for (int i = 0; port[i] != '\0'; i++) {
		if (!isdigit(port[i])) {
			return 0;
			// om innehåller annat än siffror -> ogiltig
		}
	}

	int number = atoi(port);
	// konverterar sträng till heltal

	if (number >= 1 && number <= 65535) {
		// kontrollerar att porten ligger innanför intervallet 
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
}

int menu_choice() {
	char input[20];
	// skapar array för att lagra användarens input
	printf("Gör ett val (1-4): ");

	fgets(input, sizeof(input), stdin);
	// läser nu hela raden som en text istället för endast ett heltal (integer)
	// säkrare än scanf för att den lämnar kvar onödigt innehåll i bufferten

	input[strcspn(input, "\n")] = '\0';
	// tar bort newline (\n) från input

	// tar bort whitespace i början och slutet
	remove_whitespace(input);

	if(!isdigit(input[0]) || strlen(input) != 1) {
		// kontrollerar att input är exakt en siffra

		return -1;
		// ogiltigt val
	}

	return input[0] - '0';
	// konverterar tecken till int - ('1') till heltal (1) osv
}


void remove_whitespace(char str[]) {
	int start = 0;	/* index för början av strängen */
	int end = strlen(str) -1; /* slutet av strängen */
	int i = 0; /* index för att skriva tillbaka den rensade strängen*/

	while (isspace((unsigned char)str[start])) {
		start++;
	}
		// hoppar över alla whitespace i början (t ex mellanslag, newline, tab)
		// hittar därefter det första "riktiga" tecknet

	while (end >= start && isspace((unsigned char)str[end])) {
		end--; 
	}
		// hoppar över alla whitespace i slutet
		// hittar sista "riktiga" tecknet

	while (start <= end) {
		str[i] = str[start];
		i++;
		start++;
	}
		// kopierar den rensade delen 
		// flyttar innehållet så det börjar på index 0
	
	str[i] = '\0';
		// avslutar strängen korrekt så att gammalt innehåll ignoreras
	
}

int main() {
	int choice;

	while (1) { 
		show_menu();

		choice = menu_choice();
		
		if (choice == -1) {
			printf("Ogiltigt val - försök igen!\n\n");
			continue; 
		} 

	printf("\n");

	if (choice == 1) {
		char ip[50];
		char entry[100];

		while (1) {
			printf("Ange IP-adress: ");
			fgets(ip, sizeof(ip), stdin);
			ip[strcspn(ip, "\n")] = '\0';
			remove_whitespace(ip);

			if (validate_ip(ip)) {
				printf("%s är en giltig IP-adress\n", ip);
				sprintf(entry, "IP %s - giltig", ip);
				add_log(entry);
			break;
			} else {
				printf("\"%s\" är en ogiltig IP-adress, försök igen!\n", ip);
				sprintf(entry, "IP \"%s\" - ogiltig", ip);
				add_log(entry);
			} 
		} 
	} 


	else if (choice == 2) {
		char port[20];
		char entry[100];

		while (1) {
			printf("Ange port: ");
			fgets(port, sizeof(port), stdin);
			port[strcspn(port, "\n")] = '\0';
			remove_whitespace(port);
		
		if (validate_port(port)) {
			printf("Port %s är en giltig port\n\n", port);
			sprintf(entry, "Port %s - giltig", port);
			add_log(entry);
			break;
			// korrekt -> avsluta loopen
		} else {
			printf("\"%s\" är en ogiltig port, försök igen!\n\n", port);
			sprintf(entry, "Port \"%s\" - ogiltig", port);
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
