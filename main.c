#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Def.h"
#include "Card.h"
#include "Terminal.h"
#include "Server.h"



int main(void) {

	uint8_t continueOrNot;  //variable to check if user pressed y yes to do further actions or n for no
	ST_cardData_t cardInfo;
	uint8_t acceptedOrNot; // variable to check on input given by user
	ST_terminalData_t terminalInfo;
	float maxAmount = 5000.00;
	terminalInfo.maxTransAmount = maxAmount; // max amount is saved in struct's variable
	while(1){
	fflush(stdin);
	readCard(&cardInfo); // Function to input name, account number, and expiration date
	acceptedOrNot = TerminalData(&terminalInfo); // check if amount is higher than allowed
	if(acceptedOrNot){
		acceptedOrNot = checkData(&cardInfo, &terminalInfo); // if accepted then check on data given using checkdata
		if(acceptedOrNot){
			printf("Transaction APPROVED.\n");
			fflush(stdout);
		}
		else{
			printf("Transaction DECLINED.\n");
			fflush(stdout);
		}
	}
	else{
		printf("Transaction DECLINED.\n");
		fflush(stdout);
	}
	printf("Do you want to continue (please type y for yes and n for no)? \n");
	fflush(stdout);
	scanf("%c", &continueOrNot);
	if(continueOrNot != 'y'){
		break;
	}
	}
	return 0;
}

