#include "server.h"
#include <stdio.h>

void file_intiation()
{
    float account_balance;
    uint8_t account_pan[20];

    FILE* account;
    account = fopen("./Database/accounts.txt", "r");
    FILE* transaction;
    fprintf(account, "1235.0, BLOCKED, 5231698741256321546\n");
    fprintf(account, "9552.0, RUNNING, 2564785123547989852\n");
    fprintf(account, "5536.0, RUNNING, 9851698741256321546\n");
    fprintf(account, "8974.0, RUNNING, 7584698741256321546\n");
    fprintf(account, "5422.0, RUNNING, 3544698741256321546\n");
    fclose(account);


}
ST_accountsDB_t* getaccountref(ST_accountsDB_t* accountRefrence)
{
    return accountRefrence;
}


EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence) 
{
    
    float balance;
    EN_accountState_t state;
    uint8_t primaryAccountNumber[20];
    FILE* account;
    account = fopen(". / Database / account.txt / ", "r");
    while (fscanf(account, "%f %s %s", &balance, &state, primaryAccountNumber) != EOF)
    {
        if (strcmp(cardData->primaryAccountNumber, primaryAccountNumber) == 0) {
            getaccountref(accountRefrence);
            return SERVER_OK;

        } 
           
        
    }
    fclose(account);
    accountRefrence = NULL;
    getaccountref(accountRefrence);
    return ACCOUNT_NOT_FOUND;
}
void isValidAccountTest()
{
    uint8_t PAN_in_File[20];
    uint8_t PAN_FROM_USER[20];
    float balance = 0;
    uint8_t state[10];

    FILE* test;
    test = fopen("./Database/test.txt","w");
    fprintf(test, "6000.0 RUNNING 3254698521475846982");
    fclose(test);
    printf("Tester Name: Abdelrahman Osama\n");
    printf("Function name : IsValidAccountTest\n");
    printf("Case 1 :valid account \n ");
    printf("Input Data: (19):");
    scanf("%s", PAN_FROM_USER);
    printf("expected:valid account\n");
    test = fopen("./Database/test.txt", "r");

    while (fscanf(test,"%s",PAN_in_File) != EOF)
    {

        if (strcmp(PAN_FROM_USER, PAN_in_File) == 0) {

            printf("actual:Valid account\n");
            fclose(test);
            return 0;
        }

    }
    printf("Actual : invalid account\n");
    fclose(test);
}

int main() {isValidAccountTest();}