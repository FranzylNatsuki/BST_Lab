Got it ✅ — here’s a **Markdown checklist** you can keep next to your code while working. I broke it into **structs/BST setup, features, and error-trapping reminders**.

---

# 📝 Laboratory Exercise #3 – Checklist

## 📦 Setup

* [/] Write program description, full name, start date, finish date at top of code.
* [/] Define **3 structs**:

    * [ ] `ITEM` (itemNumber, itemName, quantity, price)
    * [ ] `SALES` (sales\_number, itemNumber, quantity\_sold)
    * [ ] `GOODS` (goods\_number, itemNumber, quantity\_received)
* [/] Define **3 BST node structs** (`ItemNd`, `SalesNd`, `GoodsNd`).
* [/] Implement BST operations:

    * [ ] Insert node
    * [ ] Search node
    * [ ] Display (in-order traversal)

---

## 🖥️ Menu

* [/] Print this menu:

  ```
  <LastName> Enterprise
  1] Add New Item
  2] Edit Item Information
  3] Sales
  4] Goods Receipt
  5] Display Sales
  6] Display Goods Receipt
  7] Display All Items
  8] Exit
  ```
* [/] Loop until user chooses **Exit**.

---

## 🔑 Features

### 1. Add New Item

* [/] Prompt user for item number (string len 3), item name, quantity, price.
* [/] Insert into **Item BST** (use `itemNumber` as BST key).
* [/] ❗ Error trap: reject if item number already exists.

### 2. Edit Item Information

* [] Search item by `itemNumber`.
* [ ] Allow edit of:

    * [ ] Item Name
    * [ ] Item Price
* [ ] ❗ Error trap: if item does not exist → show error.

### 3. Sales

* [/] Prompt user for:

    * Item number
    * Quantity bought
* [/] Search item in **Item BST**.
* [/] If valid:

    * [/] Auto-decrease item quantity.
    * [/] Insert record into **Sales BST** (unique `sales_number`).
* [/] ❗ Error traps:

    * [/] Item does not exist
    * [/] Quantity bought ≤ 0
    * [/] Not enough stock (or quantity on hand = 0)

### 4. Goods Receipt

* [ ] Prompt user for:

    * Item number
    * Quantity received
* [ ] Search item in **Item BST**.
* [ ] If valid:

    * [ ] Auto-increase item quantity.
    * [ ] Insert record into **Goods BST** (unique `goods_number`).
* [ ] ❗ Error traps:

    * Item does not exist
    * Quantity received ≤ 0

### 5. Display Sales

* [ ] Traverse **Sales BST** in-order and print:

    * Sales number
    * Item number
    * Quantity sold

### 6. Display Goods Receipt

* [ ] Traverse **Goods BST** in-order and print:

    * Goods receipt number
    * Item number
    * Quantity received

### 7. Display All Items

* [ ] Traverse **Item BST** in-order and print:

    * Item number
    * Item name
    * Quantity
    * Price

### 8. Exit

* [ ] Cleanly exit program.

---

## ⚠️ Input / Error Handling Checklist

* [ ] Always strip `\n` when using `fgets`.
* [ ] Replace `gets()` with `fgets` (never use `gets`).
* [ ] After `scanf`, flush buffer (`Flush` macro or manual loop).
* [ ] Check input values:

    * [ ] Quantity must be ≥ 0
    * [ ] Price must be ≥ 0
* [ ] For transactions:

    * [ ] Generate unique IDs using counters (not random).
* [ ] When editing:

    * [ ] Only allow name/price changes.
    * [ ] Reject edits if item not found.

---

Do you want me to also add a **function-level checklist** (like `add_Record()`, `search_Record()`, `edit_Record()`, `displayAll()`, etc.) so you can track your implementation order step by step?
