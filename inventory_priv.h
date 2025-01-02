/* ****************************************************** */
/* ************* File Definition Section **************** */
/* ****************************************************** */
/** \file inventory_priv.h
 *  \brief Private file for the inventory management project 
 *  \details Includes the required APIs used within the program      
 *
 *  Scope           : Private
 * 
 *  Coding Language : C
 * 
 *  Author          : Mariam TAREK
 * 
 **/

/* ******************************************************** */
/* **************** HEADER PROTECTION ********************* */
/* ******************************************************** */
#ifndef INVENTORY_PRIV_H
#define INVENTORY_PRIV_H

/* ******************************************************** */
/* ************** HEADER FILES INCLUDES ******************* */
/* ******************************************************** */
#include "inventory_cfg.h"

/* ******************************************************** */
/* **************** MACRO/DEFINE SECTION ****************** */
/* ******************************************************** */

/** \brief Value true
*   \details Type: int , Range: {1}, Resolution: NA, Unit:NA
*/
#define true  ((int)1)

/** \brief Value false
*   \details Type: int , Range: {0}, Resolution: NA, Unit:NA
*/
#define false ((int)0)

/** \brief Value matched
*   \details Type: int , Range: {0}, Resolution: NA, Unit:NA
*/
#define matched ((int)0)

/** \brief initial ID of the items
*   \details Type: int , Range: {0}, Resolution: NA, Unit:NA
*/
#define Initial_ID ((int)0)

/** \brief initial quantity of the items
*   \details Type: int , Range: {0}, Resolution: NA, Unit:NA
*/
#define Initial_Quantity ((int)0)

/* ******************************************************** */
/* ***************** Function SECTION ********************* */
/* ******************************************************** */
void writeItemToFile(Item *item);
int isDuplicateID(int id);


#endif /* INVENTORY_PRIV_H */

/*  **************************** E N D (inventory_priv.h) **************************** */