/* ****************************************************** */
/* ************* File Definition Section **************** */
/* ****************************************************** */
/**
 * \file inventory_Prg.c
 * \brief This file implements an inventory management system, enabling the user
 *        to perform operations such as adding items, displaying all items,
 *        searching for items by name, updating item quantities, and managing 
 *        inventory data stored in a file.
 *
 *  Scope           : Public
 * 
 *  Coding Language : C
 * 
 *  Author          : Mariam TAREK
 * 
 **/


/* ******************************************************** */
/* ************** HEADER FILES INCLUDES ******************* */
/* ******************************************************** */

#include "inventory_int.h"
#include "inventory_cfg.h"
#include "inventory_priv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ******************************************************** */
/* ****************** MAIN FUNCTION *********************** */
/* ******************************************************** */

int main() {
    /**: Call the menu function to display options and process user commands; */
    menu(); 
    return 0;
}

/* ******************************************************** */
/* ************** PUBLIC FUNCTION SECTION ***************** */
/* ******************************************************** */

/**
 * Function   : menu()
 * 
 * Brief      : Function to provide a user interface for managing inventory operations.
 * 
 * Scope      : Public
 * 
 * Parameters : None
 * 
 * Return     : None
 * 
 * Description: This Function displays a menu with the following options:
 *              1. Add a new item to the inventory.
 *              2. Display all items in the inventory.
 *              3. Search for an item by name.
 *              4. Update the quantity of an existing item by ID.
 *              5. Exit the program.
 *              The user is prompted to choose an option, and the corresponding function is called.
 *  
 **/
void menu() {
    /**: Variable to store the user's menu choice; */
    int choice;
 
    do {
        /**: Display the menu options to the user; */
        printf("\nMenu:\n");
        printf("1. Add Item\n");
        printf("2. Display All Items\n");
        printf("3. Search Item by Name\n");
        printf("4. Update Item Quantity\n");
        printf("5. Exit\n");

        /**: Prompt the user to enter their choice; */
        printf("Enter your choice: ");
        scanf("%d", &choice);

        /**: Execute the corresponding action based on the user's choice; */
        switch (choice) {
            case 1: 
                /**: Call addItem to add a new item to the inventory; */
                addItem(); 
                break;
            case 2: 
                /**: Call displayItems to display all items in the inventory; */
                displayItems(); 
                break;
            case 3: 
                /**: Call searchItem to search for an item by name; */
                searchItem(); 
                break;
            case 4: 
                /**: Call updateQuantity to update the quantity of an item by ID; */
                updateQuantity(); 
                break;
            case 5: 
                /**: Print a message and exit the program; */
                printf("Exiting program.\n"); 
                break;
            default: 
                /**: Handle invalid choices by prompting the user to try again; */
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5); /**: Keep showing the menu until the user chooses to exit; */
}

/**
 * Function   : addItems()
 * 
 * Brief      : function to add a new item to the inventory
 * 
 * Scope      : Public
 * 
 * Parameters : None
 * 
 * Return     : None
 * 
 * Description: This Function  1. Adds a new item to the inventory by collecting item details (ID, name, quantity, price).
 *                             2. Checks for duplicate IDs.
 *                             3.  Writes the item to the file if unique.
 *  
 **/

void addItem() {

    /**: Variable of type Item to store the details of the new inventory item; */
    Item newItem;

    /**: Flag variable to indicate if a duplicate ID is found; */
    int isDuplicate = false;

    /**: Open the inventory file in append mode; */
    FILE *file = fopen(FILE_NAME, "a+");

    if (!file) {
        /**: Handle error if the file cannot be opened; */
        printf("Error in opening the file!\n");
        return;        
    }

    /**: Prompt user to enter the item ID; */
    printf("Enter ID: ");
    scanf("%d", &newItem.id);

    /**: Set the isDuplicate flag to the result of the isDuplicateID function ;*/
    isDuplicate = isDuplicateID(newItem.id);

    /** if (Check if the entered ID is already in use) then (true) */
    if (isDuplicate) {
        printf("Error: The Item you entered with ID %d already exists.\n", newItem.id);
        fclose(file);
        return;
    }
    else
    {
        /**: Do Nothing ;*/
    }/**endif*/

    /**: Prompt user to enter the item name; */
    printf("Enter Name: ");
    scanf("%s", newItem.name);

    /**: Prompt user to enter the item quantity; */
    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);

    /**: Prompt user to enter the item price; */
    printf("Enter Price: ");
    scanf("%f", &newItem.price);

    /**: Write the new item details to the inventory file; */
    writeItemToFile(&newItem);
    printf("Item added successfully.\n");

    /**: Close the file to ensure data integrity; */
    fclose(file);
}

/**
 * Function   : displayItems()
 * 
 * Brief      : function to display all items in the inventory file
 * 
 * Scope      : Public
 * 
 * Parameters : None
 * 
 * Return     : None
 * 
 * Description: This Function displays a table with the following columns: ID, Name, Quantity, Price for the Items.
 *  
 **/
void displayItems() {

    /**: Variable of type Item to store the details of the new inventory item; */
    Item item; 

    /**: Open the inventory file in read mode; */
    FILE *file = fopen(FILE_NAME, "r");

    /** if (Check if there is an issue opening the file then (true) */
    if (!file) {
        printf("Error in finding the inventory data.\n");
        return;
    }

    else{
        printf("ID\tName\tQuantity\tPrice\n");
        /**: Loop through the file reading each item; */
        while (fscanf(file, "%d,%49[^,],%d,%f\n", &item.id, item.name, &item.quantity, &item.price) == NUM_FIELDS) {
          /**: Print a table to display the inventory items; */
          printf("%d\t%s\t%d\t\t%.2f\n", item.id, item.name, item.quantity, item.price);    
        }
    }/**endif*/

    /**: Close the file after reading all items; */
    fclose(file);
}

/**
 * Function   : searchItem()
 * 
 * Brief      : function to search for an item by name in the inventory file
 * 
 * Scope      : Public
 * 
 * Parameters : None
 * 
 * Return     : None
 * 
 * Description: This Function allows the user to search for an item in an inventory by its name then Display the item's details (ID, Name, Quantity, and Price).
 *  
 **/
void searchItem() {

    /**: Variable to store the name to search for; */
    char searchName[MAX_NAME_LENGTH];

    /**: Variable of type Item to store the current item being read; */
    Item item;

    /**: Flag variable to indicate if the item is found; */
    int found = false;

    /**: Open the inventory file for reading; */
    FILE *file = fopen(FILE_NAME, "r");

    /** if (Check if there is an issue opening the file then (true) */
    if (!file) {
        printf("Error in finding the inventory data.\n");
        return;
    }

    else{
        /**: Prompt user to enter the item name to search for; */
        printf("Enter Name to Search: ");
        scanf("%s", searchName);

        /**: Loop through the file reading each item; */
        while (fscanf(file, "%d,%49[^,],%d,%f\n", &item.id, item.name, &item.quantity, &item.price) == NUM_FIELDS) {

            /** if (current item's name matches the search name then (true) */
            if (strcmp(item.name, searchName) == matched) {
                /**: Set the found flag to true indicating the item has been found; */
                printf("Found: ID=%d, Name=%s, Quantity=%d, Price=%.2f\n", item.id, item.name, item.quantity, item.price);

                /**: Set the found flag to true indicating the item has been found; */
                found = true;

                /**: Break the loop since the item is found and no further searching is needed; */
                break;
            }
            else
            {
                /**:Do Nothing; */
            }/*endif*/
        }
        
        /** if (No item is found then (true) */
        if (!found) {
            printf("Item with name '%s' not found.\n", searchName);
        }
        else
        {
            /*Do Nothing*/
        }/*endif*/
    }

    /**: Close the file after reading; */
    fclose(file);
}

/**
 * Function   : updateQuantity()
 * 
 * Brief      : Function to update the quantity of an existing item by ID in the inventory file.
 * 
 * Scope      : Public
 * 
 * Parameters : None
 * 
 * Return     : None
 * 
 * Description: This Function searches for the item with the specified ID updates its quantity as provided.
 *  
 **/
void updateQuantity() {

    /**: Initialize variables for item ID, new quantity, and found flag; */
    int id = Initial_ID ;
    int  newQuantity = Initial_Quantity;
    int found = false;

    /**: Variable of type Item to store the current item being read; */
    Item item;

    /**: Open the inventory file in read-write mode; */
    FILE *file = fopen(FILE_NAME, "r+");

    /** if (Check if there is an issue opening the file then (true) */
    if (!file) {
        printf("No inventory data found.\n");
        return;
    }

    else
    {   
        /**: Do Nothing;*/
    }/*endif*/

    /**: Prompt the user to enter the ID of the item they want to update; */
    printf("Enter ID to Update: ");
    scanf("%d", &id);
    
    /**: Prompt the user to enter the new quantity for the item; */
    printf("Enter New Quantity: ");
    scanf("%d", &newQuantity);

     /**: Open a temporary file to store the updated inventory data; */
    FILE *tempFile = fopen("temp.txt", "w");

    /** if (Check if there is an issue creating temp file then (true) */
    if (!tempFile) {
        printf("Error creating temporary file!\n");
        fclose(file);
        return;
    }
    else
    {
       /**:Do Nothing ;*/
    }/*endif*/

    /**: Loop through each item in the original inventory file; */
    while (fscanf(file, "%d,%49[^,],%d,%f\n", &item.id, item.name, &item.quantity, &item.price) == NUM_FIELDS) {        
        /** if (Check the current item's ID matches the input ID then (true) */
        if (item.id == id) {
            /**:Update the quantity; */
            item.quantity = newQuantity;
            /**: Set the found flag to true indicating the item has been found; */
            found = true;
        }
        else 
        {
            /**:Do Nothing; */
        }
        /**: Write the item (updated or not) to the temporary file; */
        fprintf(tempFile, "%d,%s,%d,%.2f\n", item.id, item.name, item.quantity, item.price);
    }

    /**: Close both the original and temporary files; */
    fclose(file);
    fclose(tempFile);

    /**: Remove the original inventory file and rename the temporary file as the original file; */
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

     /** if (Check the item was found and updated then (true) */
    if (found) {
        printf("Quantity updated successfully.\n");
    } 
    else {
        printf("Item with ID %d not found.\n", id);
    }
}

/* ********************************************************* */
/* ************** PRIVATE FUNCTION SECTION ***************** */
/* ********************************************************* */

/**
 * Function   : writeItemToFile()
 * 
 * Brief      : Function to write an item's details to the inventory file.
 * 
 * Scope      : Private
 * 
 * Parameters : item (Item*): Pointer to the item structure containing the details to be written.
 * 
 * Return     : None
 * 
 * Description: This function appends the details of the specified item to the inventory file including the item ID, name, quantity, and price.
 *  
 **/
void writeItemToFile(Item *item) {
    /**: Open the inventory file in append mode; */
    FILE *file = fopen(FILE_NAME, "a+"); 

    /** if (Check the file was successfully opened then (true) */
    if (file) { 
        /**: Write the item details; */
        fprintf(file, "%d,%s,%d,%.2f\n", item->id, item->name, item->quantity, item->price); 

        /**: Close the file after writing; */
        fclose(file); 
    }
    else {
        printf("Error in opening the file!\n");
    } /*endif*/
}


/**
 * Function   : isDuplicateID()
 * 
 * Brief      : Function to check if an item with the given ID already exists in the inventory file.
 * 
 * Scope      : Private
 * 
 * Parameters : id (int): The ID of the item to be checked for duplication.
 * 
 * Return     : int: Returns true if the item with the specified ID is found (duplicate), false otherwise.
 * 
 * Description: This function searches through the inventory file to check if an item with the specified ID already exists. 
 *  
 **/
int isDuplicateID(int id) {

    Item temp;

    /**: Open the file in read mode; */
    FILE *file = fopen(FILE_NAME, "r"); 

    if (!file){
        return 0;  /**: If the file is not found, return 0 (indicating no duplicates or no file); */
    } 
  
    while (fscanf(file, "%d,%49[^,],%d,%f\n", &temp.id, temp.name, &temp.quantity, &temp.price) == NUM_FIELDS) { 
        /** if (Check the ID matches the given ID then (true) */
        if (temp.id == id) {  
            /**: Close the file after checking for duplicates; */
            fclose(file);  
            return true;  
        }
        else
        {
            /**:Do Nothing ;*/
        }
    }
    /**: Close the file after checking all items; */
    fclose(file);  
    return false; 
}