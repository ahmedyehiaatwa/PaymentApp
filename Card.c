#include <stdio.h>
#include <stdint.h>
#include "Def.h"
#include "Card.h"


// Function for user to input card name, account number , and expiry date

void readCard(ST_cardData_t* pcardInfo){
	printf("Please Enter your Card Holder Name: \n");
	fflush(stdout);
	gets(pcardInfo -> cardHolderName);
	printf("Please Enter your Primary Account Number: \n");
	fflush(stdout);
	gets(pcardInfo -> primaryAccountNumber);
	printf("Please Enter the card's Expiry date in MM/YY format \n");
	fflush(stdout);
	gets(pcardInfo -> cardExpirationDate);
}

