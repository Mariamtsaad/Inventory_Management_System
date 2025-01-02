/* ****************************************************** */
/* ************* File Definition Section **************** */
/* ****************************************************** */
/** \file inventory_priv.h
 *  \brief Configuration header file for the inventory management project 
 *  \details Includes the macros that needs to be configured by the project user      
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
#ifndef INVENTORY_CFG_H
#define INVENTORY_CFG_H

/* ******************************************************** */
/* **************** MACRO/DEFINE SECTION ****************** */
/* ******************************************************** */

/** \brief inventory file name
*   \details Type: string , Range: NA, Resolution: NA, Unit:NA
*/
#define FILE_NAME "inventory.txt"

/** \brief Maximum length for item names in the inventory
*   \details Type: int , Range: {50}, Resolution: NA, Unit:leters
*/
#define MAX_NAME_LENGTH ((int)50)

/** \brief The number of fields per item in the inventory file
*   \details Type: int , Range: {4}, Resolution: NA, Unit:Field
*/
#define NUM_FIELDS ((int)4)

/** \brief Maximum number of items that can be stored in the inventory
*   \details Type: int , Range: {100}, Resolution: NA, Unit:Item
*/
#define MAX_ITEMS ((int)100)

#endif /* INVENTORY_CFG_H */

/*  **************************** E N D (inventory_cfg.h) **************************** */
