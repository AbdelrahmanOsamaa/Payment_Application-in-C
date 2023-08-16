#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"terminal.h"




EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) 
{           
    uint8_t transactionDate[11];
    printf("please enter the transaction date :\n");
    gets(transactionDate);
    if (((strlen(termData-> transactionDate) == 10) && (termData-> transactionDate[2] == '/') && (termData->transactionDate[5] == '/')))
    {
        printf("Actual Result: invalid transaction date\n");
        return WRONG_DATE;
    }
    else
    {
        printf("Actual Result: valid transaction date\n");
        strcpy_s(termData->transactionDate,11,transactionDate);

            return TERMINAL_OK;
    }


}
void getTransactionDateTest(void) 
{
    uint8_t transactionDate[11];
    // [d ,d  /m ,m / y,y,y,y]

    printf("Tester name: Abdelrahman Osama \n");
    printf("Function name: GetTransactionDateTest \n");

    printf("Test Case 1: null \n");
    printf("Input Data:");
    gets(transactionDate);
    printf("Expected result: WRONG_DATE\n");
    if((strlen(transactionDate) == 10) && (transactionDate[2] == '/') && (transactionDate[5] == '/'))
    {
        printf("Actual Result: TERMINAL_OK\n");
    }
    else 
    {
    
        printf("Actual Result: WRONG_DATE\n");
    }
    printf("Test Case 2:less than 10 characters\n");
    printf("Input Data:");
    gets(transactionDate);
    printf("Expected result: WRONG_DATE\n");
    if ((strlen(transactionDate) == 10) && (transactionDate[2] == '/') && (transactionDate[5] == '/'))
    {
        printf("Actual Result: TERMINAL_OK\n");
    }
    else
    {

        printf("Actual Result: WRONG_DATE\n");
    } printf("Test Case 3:wrong format\n");
    printf("Input Data:");
    gets(transactionDate);
    printf("Expected result: WRONG_DATE\n");
    if ((strlen(transactionDate) == 10) && (transactionDate[2] == '/') && (transactionDate[5] == '/'))
    {
        printf("Actual Result: TERMINAL_OK\n");
    }
    else
    {

        printf("Actual Result: WRONG_DATE\n");
    }
    printf("Test Case 4:valid Date\n");
    printf("Input Data:");
    gets(transactionDate);
    printf("Expected result: TERMINAL_OK\n");
    if ((strlen(transactionDate) == 10) && (transactionDate[2] == '/') && (transactionDate[5] == '/'))
    {
        printf("Actual Result: TERMINAL_OK\n");
    }
    else
    {

        printf("Actual Result: WRONG_DATE\n");
    }

}
EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData) 
{
    uint8_t cardExpirationDate[6];
    uint8_t transactionDate[11];
    if((cardData->cardExpirationDate[0] >= termData->transactionDate[3]) && (cardData->cardExpirationDate[1] >= termData->transactionDate[4]) && (cardData->cardExpirationDate[3] >= termData->transactionDate[8]) && (cardData->cardExpirationDate[4] >= termData->transactionDate[9]))
    {
        return TERMINAL_OK;
    }
    else if ((cardData->cardExpirationDate[0] < termData->transactionDate[3]) || ((cardData->cardExpirationDate[0] = termData->transactionDate[3] ) && (cardData->cardExpirationDate[1]<termData->transactionDate[4])) || (cardData->cardExpirationDate[3]<termData->transactionDate[8]) || ((cardData->cardExpirationDate[3] == termData->transactionDate[8] && (cardData->cardExpirationDate[4]<termData->transactionDate[9]))))
    {
        return EXPIRED_CARD;
    }
}
void isCardExpriedTest(void)// 
{//[d,d/3m,4m 5/6y,7y,8y,9y] [0m,1m 2/ 3y,4y]
    uint8_t transactionDate[11];
    uint8_t cardExpirationDate[6];
    printf("Tester Name : Abdelrahman Osama;\n");
    printf("Function Name : isCardExpiredTest\n");
    printf("Case 1:Valid date\n");
    printf("Expected:TERMINAL_OK\n");
    printf("please enter the transaction date : ");
    gets(transactionDate);
    printf("please enter the card expiry date :");
    gets(cardExpirationDate);
    if ((cardExpirationDate[0] >= transactionDate[3]) && (cardExpirationDate[1] >= transactionDate[4]) && (cardExpirationDate[2] >= transactionDate[5]) && (cardExpirationDate[3] >= transactionDate[8]) && (cardExpirationDate[4] >= transactionDate[9]))
    {
        printf("Actual: TERMINAL_OK\n");
        
    }
    else if ((cardExpirationDate[0] < transactionDate[3]) || ((cardExpirationDate[0] = transactionDate[3]) && (cardExpirationDate[1] < transactionDate[4])) || (cardExpirationDate[3] < transactionDate[8]) || ((cardExpirationDate[3] == transactionDate[8] && (cardExpirationDate[4] < transactionDate[9]))))
    {
        printf("Actual : EXPIRED_CARD\n");
    }
}
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) 
{
    float transAmount;
    printf("please enter transaction amount:\n");
    scanf_s("%f", &transAmount);
    if (termData->transAmount<= 0)
    {
        printf("invalid amount\n");
        return INVALID_AMOUNT;
    }
    else
    {
        printf("terminal ok\n");
        termData->transAmount = transAmount;
        return TERMINAL_OK;
    }
}
void getTransactionAmountTest(void) 
{
    float transAmount;
    printf("Tester Name : Abdelragman Osama\n");
    printf("Function Name : getTransactionAmountTest\n");
    printf("Case 1: transaction amount equal to 0 or less\n");
    printf("please enter transaction amount:");
    scanf_s("%f", &transAmount);
    printf("Expected :INVALID_AMOUNT\n");
    if (transAmount <= 0)
    {
        printf("Actual : INVALID_AMOUN\nT");
    }
    else
    {
        printf("Actual : TERMINAL_OK\n");
    }

    printf("Case 2 :transcation amount more than 0\n");
    printf("please enter transaction amount:");
    scanf_s("%f", &transAmount);
    printf("Expected :TERMINAL_OK\n");
    if (transAmount <= 0)
    {
        printf("Actual : INVALID_AMOUNT\n");
    }
    else
    {
        printf("Actual : TERMINAL_OK\n");
    }
}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) 
{
    float maxTransAmount=0;
    float transAmount=0;
    if (transAmount > maxTransAmount) 
    {
        return EXCEED_MAX_AMOUNT;
    }
    else 
    {
        return TERMINAL_OK;
    }
}
void isBelowMaxAmountTest(void)
{
    float maxTransAmount;
    float transAmount;
    printf("Tester Name : Abdelrahman Osama\n");
    printf("Function Name:isBelowMaxAmountTest\n");
    printf("Case 1 : Transaction amount > max transaction amount\n");
    printf("please enter max transaction amount:");
    scanf_s("%f", &maxTransAmount);
    printf("please enter transaction amount:");
    scanf_s("%f", &transAmount);
    printf("Expected:invalid transaction process\n");
    if (transAmount > maxTransAmount)
    {
        printf("Actual :invalid transaction process\n\n");
    }
    else 
    {
        printf("Actual :valid transaction process\n\n");
    }

    printf("Case 2 : Transaction amount <= max transaction amount\n");
    printf("please enter max transaction amount:");
    scanf_s("%f", &maxTransAmount);
    printf("please enter transaction amount:");
    scanf_s("%f", &transAmount);
    printf("Expected:valid transaction process\n");
    if (transAmount > maxTransAmount)
    {
        printf("Actual:invalid transaction process");
    }
    else
    {
        printf("Actual:valid transaction process");
    }

}
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount) 
{   
    printf("please give max amount :");
    scanf_s("%f", maxAmount);
    if (maxAmount <= 0) 
    {
        return INVALID_MAX_AMOUNT;
    }
    else 
    {
        return TERMINAL_OK;
        termData->maxTransAmount = maxAmount;
    }
}
void setMaxAmountTest(void) 
{
    float maxAmount;
    printf("Tester Name :Abdelrahman Osama\n");
    printf("Function Name:setMaxAmountTest \n");
    printf("Case 1 : max amount <= 0\n");
    printf("please enter max amount :");
    scanf_s("%f", &maxAmount);
    printf("Expected : INVALID_MAX_AMOUNT\n");
    if (maxAmount<=0) 
    {
        printf("Actual:INVALID_MAX_AMOUNT\n");
    }
    else 
    {
        printf("Actual:TERMINAL_OK\n");
    }

    printf("Case  : max amount <= 0\n");
    printf("please enter max amount :");
    scanf_s("%f", &maxAmount);
    printf("Expected : TERMINAL_OK\n");
    if (maxAmount <= 0)
    {
        printf("Actual:INVALID_MAX_AMOUNT\n");
    }
    else
    {
        printf("Actual:TERMINAL_OK\n");
    }
}
