#include <stdio.h>
#include <stdint.h>
#include "Def.h"
#include "Terminal.h"


// check on transaction amount if it is more than allowed and then enter transaction date if amount is below required amount

uint8_t TerminalData(ST_terminalData_t* pterminalInfo){
	printf("Please Enter the transaction Amount: \n"); fflush(stdout);
	scanf("%f", &pterminalInfo -> transAmount);
	fflush(stdin);
	if(pterminalInfo -> transAmount > pterminalInfo -> maxTransAmount)
	{
		return 0;
	}
	printf("Please Enter transaction Date: \n"); fflush(stdout);
	gets(pterminalInfo -> transactionDate);
	return 1;
}

// checks on expiry date if it is after transaction date and if balance in the account allows the transaction amount

uint8_t checkData(ST_cardData_t* pcardInfo, ST_terminalData_t* pterminalInfo){

	uint8_t expiryYear;
	uint8_t expiryMonth;
	uint8_t transactionYear;
	uint8_t transactionMonth;

	expiryYear = (pcardInfo -> cardExpirationDate[3] - '0') * 10 + (pcardInfo -> cardExpirationDate[4] - '0');
	expiryMonth = (pcardInfo -> cardExpirationDate[0] - '0') * 10 + (pcardInfo -> cardExpirationDate[1] - '0');
	transactionYear = (pterminalInfo -> transactionDate[8] - '0') * 10 + (pterminalInfo -> transactionDate[9] - '0');
	transactionMonth = (pterminalInfo -> transactionDate[3] - '0') * 10 + (pterminalInfo -> transactionDate[4] - '0');

	if((expiryYear < transactionYear) || (expiryYear == transactionYear && expiryMonth < transactionMonth))
    {
		return 0;
	}
	if(pterminalInfo -> transAmount > pterminalInfo -> maxTransAmount)
    {
		return 0;
	}
	float balance = getAccount(pcardInfo -> primaryAccountNumber);
	if(balance == -1 || balance < pterminalInfo -> transAmount)
    {
		return 0;
	}
	return 1;

}
