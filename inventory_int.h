/* ****************************************************** */
/* ************* File Definition Section **************** */
/* ****************************************************** */
/** \file inventory_int.h
 *  \brief Interface file for the inventory management project 
 *  \details Includes the required APIs      
 *
 *  Scope           : Public
 * 
 *  Coding Language : C
 * 
 *  Author          : Mariam TAREK
 * 
 **/

/* ******************************************************** */
/* **************** HEADER PROTECTION ********************* */
/* ******************************************************** */
#ifndef INVENTORY_INT_H
#define INVENTORY_INT_H

/* ******************************************************** */
/* ************** HEADER FILES INCLUDES ******************* */
/* ******************************************************** */
#include "inventory_cfg.h"

/* ******************************************************** */
/* ************** TYPE_DEF/STRUCT SECTION ***************** */
/* ******************************************************** */

/**:struct to store details of an inventory item including its ID, name, quantity, and price; */
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

/* ******************************************************** */
/* ***************** Function SECTION ********************* */
/* ******************************************************** */
void addItem(void);
void displayItems(void);
void searchItem(void);
void updateQuantity(void);
void menu(void);

#endif /* INVENTORY_INT_H */

/*  **************************** E N D (inventory_int.h) **************************** */
