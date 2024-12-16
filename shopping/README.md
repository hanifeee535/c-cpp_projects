# Chain Store Management Program in C++

## Project Overview
This project is a **Chain Store Management System** written in C++. It allows users to manage and analyze data about chain stores, their locations, products, and prices. The program reads store data from an input file and provides an interactive interface for querying chains, stores, products, and the cheapest prices.



##Input File Format
The program expects an input file containing data in the following format:
chain_name;store_location;product_name;product_price

##Technology and concepts used:
#Object-Oriented Programming (OOP):
--Encapsulates chain, store, and product data in reusable classes and functions.
#Standard Template Library (STL):
--std::map: Used for hierarchical data storage.
--std::set: Ensures uniqueness of products.
#Error Handling:
--Detects and handles invalid inputs and commands.
--Ensures data integrity during operations.
#File I/O:
--Reads and processes input files with std::ifstream.
#String Manipulation:
--Uses custom split functions to parse input data.


##Sample Input and Output
#Input File (store_data.txt):
ChainA;Store1;Milk;1.25
ChainB;Store2;Bread;0.89
ChainA;Store1;Butter;out-of-stock
ChainB;Store3;Butter;2.50


##Once the program loads the data, you can interact using the following commands:
#chains
Lists all chain names.
Example:
> chains
ChainA
ChainB

#stores <chain_name>
Lists all stores in the specified chain.
Example:

> stores ChainA
Store1

#products
Lists all unique products available across all chains and stores.
Example:
> products
Bread
Butter
Milk

#selection <chain_name> <store_name>
Lists all products and their prices in a specific store.
Example:
> selection ChainA Store1
Butter out of stock
Milk 1.25
#cheapest <product_name>
Finds the cheapest price for a product and lists the store(s) offering it.
Example:

> cheapest Milk
1.20 euros
ChainB Store2
#quit
Exits the program.




