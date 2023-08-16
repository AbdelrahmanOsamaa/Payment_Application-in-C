#include "card.h"
#include<stdint.h>
#include<stdio.h>
#include<string.h>

EN_cardError_t getCardHolderName(ST_cardData_t* cardData) 
{   
    uint8_t cardHolderName[25];
    printf("Please enter the cardholder name :");
    gets(cardData -> cardHolderName);
    if(cardData -> cardHolderName < 20 || cardData -> cardHolderName > 24 || cardData -> cardHolderName == 0)
    {
        return WRONG_NAME;
    }
    else if(cardData -> cardHolderName >= 20 && cardData -> cardHolderName <= 24)
    {
        strcpy_s(cardData->cardHolderName,25,cardHolderName);
        return CARD_OK;
    }
}
void getCardHolderNameTest(void) 
{
    
    
        int8_t name[50] ;
        uint8_t length_word;
        printf("Tester name: Abdelrahman Osama \n");
        printf("Function name: CardHolderName \n");
        printf("Test Case 1: null \n");
        printf("Input Data:");
        gets(name);
        printf("Expected result: WRONG_Name\n");


        length_word = strlen(name);
        if (length_word < 20 || length_word>24 || name == 0) {

            printf("Actual Result: WRONG_Name\n");
        }
        else if(length_word>=20 && length_word<=24)
        {
            printf("Actual Result: CARD_OK\n");
        }


        printf("Test Case 2: less than 20 characters\n");
        printf("Input Data:");
        gets(name);
        printf("Expected result: WRONG_Name\n");


        length_word = strlen(name);
        if (length_word < 20 || length_word>24 || name == 0) {

            printf("Actual Result: WRONG_Name\n");
        }
        else if (length_word >= 20 && length_word <= 24)
        {
            printf("Actual Result: CARD_OK\n");
        }




        printf("Test Case 3: more than 24 characters \n");
        printf("Input Data:");
        gets(name);
        printf("Expected result: WRONG_Name\n");

        
         length_word = strlen(name);
        if (length_word < 20 || length_word>24 || name == 0) {

            printf("Actual Result: WRONG_Name\n");
        }
        else if (length_word >= 20 && length_word <= 24)
        {
            printf("Actual Result: CARD_OK\n");
        }

        printf("Test Case 4: between 20 and 24 characters \n");
        printf("Input Data:");
        gets(name);
        printf("Expected result: CARD_OK\n");


        length_word = strlen(name);
        if (length_word < 20 || length_word>24 || name == 0) {

            printf("Actual Result: WRONG_Name\n");
        }
        else if (length_word >= 20 && length_word <= 24)
        {
            printf("Actual Result: CARD_OK\n");
        }

    
}
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{   
    uint8_t cardExpirationDate[6];
    printf("Please enter the expiry date :");
    scanf_s("%[^n]%*c",cardExpirationDate);
    if (((cardData -> cardExpirationDate[0] == '0' && cardData -> cardExpirationDate[1] < '10') ||  (cardData -> cardExpirationDate[0] == '1' && cardData -> cardExpirationDate[1] < '3')) && (cardData -> cardExpirationDate[2] == '/'  && strlen(cardData -> cardExpirationDate) == 5))
        {
        printf("Valid expiry date");
        strcpy_s(cardData->cardExpirationDate,6,cardExpirationDate);
            return CARD_OK;            
        }
         else if(cardData -> cardExpirationDate == NULL)
        {
        printf("invalid expiry date");
            return WRONG_EXP_DATE;
        }
        else 
        {
        printf("invalid expiry date");
            return WRONG_EXP_DATE;
        }
}
void getCardExpiryDateTest (void)
{
        uint8_t cardExpirationDate[6];        
        printf("Tester name: Abdelrahman Osama \n");
        printf("Function name: getCardExpiryDateTest \n");

        printf("Test Case 1: null \n");
        printf("Input Data:");
        gets(cardExpirationDate);
        printf("Expected result: WRONG_EXP_DATE\n");

        if ((((int)cardExpirationDate[0] == (int)'0' && (int)cardExpirationDate[1] < (int)'10') ||  ((int)cardExpirationDate[0] == (int)'1' && (int)cardExpirationDate[1] < (int)'3')) && (cardExpirationDate[2] == '/'  && strlen(cardExpirationDate) == 5))
        {
            printf("Actual Result: CARD_OK\n");            
        }
         else if(cardExpirationDate == NULL)
        {
            printf("Actual Result: WRONG_EXP_DATE\n");
        }
        else 
        {
            printf("Actual Result: WRONG_EXP_DATE\n");
        }
        printf("Test Case 2: less than 5 \n");
        printf("Input Data:");
        gets(cardExpirationDate);
        printf("Expected result: WRONG_EXP_DATE\n");

        if ((((int)cardExpirationDate[0] == (int)'0' && (int)cardExpirationDate[1] < (int)'10') || ((int)cardExpirationDate[0] == (int)'1' && (int)cardExpirationDate[1] < (int)'3')) && ((cardExpirationDate[2] == '/' && strlen(cardExpirationDate) == 5)))
        {
            printf("Actual Result: CARD_OK\n");
        }
         else if(cardExpirationDate == NULL)
        {
            printf("Actual Result: WRONG_EXP_DATE\n");
        }
        else 
        {
            printf("Actual Result: WRONG_EXP_DATE\n");
        }
        printf("Test Case 3: more than 5 \n");
        printf("Input Data:");
        gets(cardExpirationDate);
        printf("Expected result: WRONG_EXP_DATE\n");

        if ((((int)cardExpirationDate[0] == (int)'0' && (int)cardExpirationDate[1] < (int)'10') ||  ((int)cardExpirationDate[0] == (int)'1' && (int)cardExpirationDate[1] < (int)'3')) && (cardExpirationDate[2] == '/'  && strlen(cardExpirationDate) == 5))
        {
            printf("Actual Result: CARD_OK\n");            
        }
         else if(cardExpirationDate == NULL)
        {
            printf("Actual Result: WRONG_EXP_DATE\n");
        }
        else 
        {
            printf("Actual Result: WRONG_EXP_DATE\n");
        }
        printf("Test Case 4: wrong format \n");
        printf("Input Data:");
        gets(cardExpirationDate);
        printf("Expected result: WRONG_EXP_DATE\n");

        if ((((int)cardExpirationDate[0] == (int)'0' && cardExpirationDate[1] < '10') ||  ((int)cardExpirationDate[0] == (int)'1' && (int)cardExpirationDate[1] < (int)'3')) && (cardExpirationDate[2] == '/'  && strlen(cardExpirationDate) == 5))
        {
            printf("Actual Result: CARD_OK\n");            
        }
         else if(cardExpirationDate == NULL)
        {
            printf("Actual Result: WRONG_EXP_DATE\n");
        }
        else 
        {
            printf("Actual Result: WRONG_EXP_DATE\n");
        }
        printf("Test Case 5: valid date \n");
        printf("Input Data:");
        gets(cardExpirationDate);
        printf("Expected result: CARD_OK \n");

        if ((((int)cardExpirationDate[0] == (int)'0' && (int)cardExpirationDate[1] < (int)'10') ||  ((int)cardExpirationDate[0] == (int)'1' && (int)cardExpirationDate[1] < (int)'3')) && (cardExpirationDate[2] == '/'  && strlen(cardExpirationDate) == 5))
        {
            printf("Actual Result: CARD_OK\n");            
        }
         else if(cardExpirationDate == NULL)
        {
            printf("Actual Result: WRONG_EXP_DATE\n");
        }
        else 
        {
            printf("Actual Result: WRONG_EXP_DATE\n"); 
        }
}

EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
    uint8_t primaryAccountNumber[20];
    printf("please enter your PAN number :\n");
    gets(cardData->primaryAccountNumber);
    if (strlen(cardData->primaryAccountNumber) < 16 || strlen(cardData->primaryAccountNumber) > 19 || strlen(cardData->primaryAccountNumber) == NULL)
    {
        printf("invalid PAN number\n");
        return WRONG_PAN;
    }
    else if (strlen(cardData->primaryAccountNumber) > 16 && strlen(cardData->primaryAccountNumber) < 19)
    {
        printf("Valid PAN number\n");
        strcpy_s(cardData->primaryAccountNumber,20,primaryAccountNumber);
        return CARD_OK;

    }
};

void getCardPANTest(void) 
{
    uint8_t primaryAccountNumber[20];

    printf("Tester name : Abdelrahman Osama\n");
    printf("function name : getCardPAN\n");

    printf("Case 1 : NULL\n");
    printf("input Data :");
    gets(primaryAccountNumber);
    printf("Expected : WRONG_PAN\n");
    
    if (strlen(primaryAccountNumber)<16 || strlen(primaryAccountNumber)>19 || strlen(primaryAccountNumber)== NULL )
    {
        printf("WRONG_PAN\n");
        
    }
    else if (strlen(primaryAccountNumber)>16 && strlen(primaryAccountNumber)<19)
    {
        printf("Actual :CARD_OK\n");
        
    }

    printf("Case 2 : Less than 16 numbers\n");
    printf("input Data :");
    gets(primaryAccountNumber);
    printf("Expected : WRONG_PAN\n");
    
    if (strlen(primaryAccountNumber) < 16 || strlen(primaryAccountNumber) > 19 || strlen(primaryAccountNumber) == NULL)
    {
        printf("Actual :WRONG_PAN\n");
       
    }
    else if (strlen(primaryAccountNumber) > 16 && strlen(primaryAccountNumber) < 19)
    {
        printf("CARD_OK\n");
        
    }
    printf("Case 3 : more than 19 numbers\n");
    printf("input Data : ");
    gets(primaryAccountNumber);
    printf("Expected : WRONG_PAN\n");
    
    if (strlen(primaryAccountNumber) < 16 || strlen(primaryAccountNumber) > 19 || strlen(primaryAccountNumber) == NULL)
    {
        printf("Actual : WRONG_PAN\n");
        
    }
    else if (strlen(primaryAccountNumber) > 16 && strlen(primaryAccountNumber) < 19)
    {
        printf("Actual :CARD_OK\n");
        
    }
    printf("Case 4 : between 16 and 19 numbers\n");
    printf("input Data : ");
    gets(primaryAccountNumber);
    printf("Expected : CARD_OK\n");
    
    if (strlen(primaryAccountNumber) < 16 || strlen(primaryAccountNumber) > 19 || strlen(primaryAccountNumber) == NULL)
    {
        printf("Actual :WRONG_PAN\n");
        
    }
    else if (strlen(primaryAccountNumber) > 16 && strlen(primaryAccountNumber) < 19)
    {
        printf("Actual :CARD_OK\n");
        
    }
    
       
}