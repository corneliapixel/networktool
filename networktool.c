#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main() {

	int choice;

	printf("=== NÄTVERKSVERKTYG ===\n");
	printf("1. Validera IP-adress\n");
	printf("2. Validera port\n");
	printf("3. Visa logg\n");
	printf("4. Avsluta\n");

	printf("Gör ett val (1-4): ");
	scanf("%d", &choice);

	printf("validerar: %d \n", choice);




	return 0;
}
