#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "Def.h"
#include "Server.h"


float getAccount(uint8_t* accountNumber){
    uint8_t index;
	for(index = 0; index < 10; index++){
		if(!strcmp(accountNumber, database[index].primaryAccountNumber)){
			return database[index].balance;
		}
	}
	return -1;
}

