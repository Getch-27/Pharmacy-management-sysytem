# Pharmacy Management System using C++

This is a Pharmacy Management System implemented in C++. The system allows owner to add new medicine, remove medicine, sell medicine, and generate a sales summary.

The system uses structures and structure arrays to store information about the medicines and sales data.

## Features

The Pharmacy Management System includes the following features:

* Add new medicine: owner can add a new medicine to the system by providing its name, price, and quantity.
* Remove medicine: owner can remove a medicine from the system by providing its name.
* Sell medicine: owner can sell a medicine by providing its name and quantity. The system will calculate the total cost and update the medicine quantity.
* Generate receipt: owner can generate a receipt for a sale. The receipt will include name of selled drugs and total income.

## Implementation Details

The Pharmacy Management System is implemented using C++ and uses the following data structures:

* `struct Medicine [max]` - Stores information about a medicine, including its name, price, and quantity etc ..
* `struct transaction` - Stores information about a sale, including the medicine name, quantity, and total cost.
