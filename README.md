# Inventory Management System

A C-based inventory management application designed for efficient tracking and management of items. The program supports essential inventory operations like adding items, searching by name, updating quantities by ID, and displaying all records.

---

## 🛠 Features

- **Add Items**: Seamlessly add new items to the inventory.
- **Display Inventory**: View all items with details such as ID, name, quantity, and price.
- **Search by Name**: Find items quickly by their names.
- **Update Quantity**: Modify the quantity of existing items by their ID.
- **Data Persistence**: Stores inventory data in a CSV-like text file for durability.

---

## 📂 File Structure

- `inventory_prg.c`: The main program file containing all function implementations for managing inventory operations.
- `inventory_int.h`: Header file providing declarations of required APIs and interfaces used across the program.
- `inventory_cfg.h`: Header file containing macros and configurations that need to be customized by the project user.
- `inventory_priv.h`: Header file defining internal APIs and utilities exclusively used within the program for internal logic.
  
---

## 🚀 How to Run

1. **Clone the repository**:
    ```bash
    git clone https://github.com/Mariamtsaad/Inventory_Management_System
    ```

2. **Navigate into the project directory**:
    ```bash
    cd <repository-directory>
    ```

3. **Compile the C program**:

    ```bash
    gcc -o inventory inventory_Prg.c
    ```

4. **Run the program**:
   - After compilation, an executable file `inventory.exe` will be produced in your repository directory.
   - Open the `inventory.exe` file to start the program.

---

## ⚙️ Assumptions
   - The program is designed to run on a Windows machine.
   - The user is expected to enter the item details using the keyboard when prompted.

---

## 📑 Example Usage

**Add Items**  
![Add Items](https://github.com/user-attachments/assets/82f5986c-6e2c-4ac7-b52d-bb1e12b9dd61)

**Display Inventory**  
![Display Inventory](https://github.com/user-attachments/assets/29dc78b8-f0f1-41c5-a3c9-1223d8b88eaa)

**Search by name**  
![Search by name](https://github.com/user-attachments/assets/549810b1-e3c8-4daf-ac1b-5d3e954c034d)

**Update quantity**  
![Update quantity](https://github.com/user-attachments/assets/52b87390-584a-4fbd-b65f-9555010ce0bc)






