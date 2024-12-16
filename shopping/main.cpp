/* Chain stores
 *
 * Desc:
 *   This program reads input data concerning chain stores from an input
 * file, the lines of which are of the form:
 * chain_store;store_location;product_name;product_price.
 * The program checks if each line consists of the abovementioned four
 * data fields.
 *   The data written in the file is collected into an appropriate data
 * structure consisting of STL containers and structs. After that the user
 * can make searches for the data structure by using the commands
 * chains, stores, selection, cheapest, and products. These commands
 * have a varying number of parameters, and the program checks if the
 * user gave a correct number of parameters and if the given parameters
 * (chain store, store location, product name) can be found from the data
 * structure.
 *   The program terminates with the command quit.
 *
 * Program author :
 * E-Mail: mdsoyabbir.abuhanif@tuni.fi
 *
 * 
 * */



#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <limits>

using namespace std;

//defining the structure
//purpose: to represent a product with name and price
struct Product{
    string name;
    double price;
};

//Typedef for the main data structure
//Purpose: To hold information about chains, stores and products
//structure: chain_store;store_location;product_name;product_price

using storeData = map<string, map<string, map<string, double>>>;

//Function: Split :  to take the string data and split into parts
//purpose: Split string into parts based on the delimiter and
//returns a vector of strings
vector <string> Split (const string& s, char delimiter){
    vector <string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}


//function: readStoreData
//Purpose: to read data from a file and organize as storeData object
//return: storeData object
storeData readStoreData (const string& fileName){
    storeData storeDATA;
    ifstream inputFile(fileName); //attempts to open the file

    //checking if the file can be open or not
    if(!inputFile.is_open()){
        cout << "Error: the input file cannot be opened"<<endl;
        exit(EXIT_FAILURE);
    }

    //reading each of the line of the file:
    string line;
    while (getline(inputFile, line)) {
            vector<string> parts = Split(line, ';');
            if(parts.size()==4){
                string chain = parts[0];
                string store = parts[1];
                string product = parts[2];
                double price = (parts[3] == "out-of-stock") ? -1 : stod(parts[3]);
                storeDATA [chain][store][product] = price;
            }
            else {
                cout<< "Error: the input file has an erroneous line" << endl;
                exit(EXIT_FAILURE);
            }

    }

    return storeDATA;
}

//function: printChains
//Purpose: to print all of the chain names
void printChains (const storeData& storeDATA){
    for (const auto& chain : storeDATA) {
            cout << chain.first << endl;
        }
}

//function: printStore
//purpose: to print all of the stores in a specific chain
void printStore (const string& chain, const storeData& storeDATA){
    auto chainItterator = storeDATA.find(chain);
    if(chainItterator != storeDATA.end()){
        for (const auto& store : chainItterator ->second){
            cout <<store.first<<endl;
        }
    }
    else {
        cout << "Error: unknown chain name"<< endl;
    }
}

//function: printProducts
//purpose: to print products in a specific store of a chain
void printProducts(const storeData& storeDATA) {
    set<string> uniqueProducts; // Use a set to store unique product names

    // Iterate through the storeData structure
    for (const auto& chain : storeDATA) {
        for (const auto& store : chain.second) {
            for (const auto& product : store.second) {
                uniqueProducts.insert(product.first); // Add product name to the set
            }
        }
    }

    // Print all unique products
    for (const auto& product : uniqueProducts) {
        cout << product << endl;
    }
}


// Function to format price to two decimal places
string to_string_with_precision(double value, int precision) {
    stringstream stream;
    stream << fixed << setprecision(precision) << value;
    return stream.str();
}


//function: selectionProducts
//purpose: to print all products in a specific chain and store, sorted alphabetically
void selectionProducts (const string& chain, const string& store, const storeData& storeDATA){
    auto chainItterator = storeDATA.find(chain);
    if (chainItterator != storeDATA.end()) {
            auto storeItterator = chainItterator->second.find(store);
            if (storeItterator != chainItterator->second.end()) {
                // Create a vector to hold the products for sorting
                vector<pair<string, double>> products;
                for (const auto& product : storeItterator->second) {
                    products.emplace_back(product.first, product.second);
                }

                // Sort products alphabetically by name
                sort(products.begin(), products.end());

                // Print products with price formatted to two decimal places
                for (const auto& product : products) {
                    cout << product.first << " " << ((product.second == -1) ? "out of stock" : to_string_with_precision(product.second, 2)) << endl;
                }
            } else {
                cout << "Error: unknown store" << endl;
            }
        } else {
            cout << "Error: unknown chain name" << endl;
        }
}


//function: findChippest
//purpose: to find the cheapest products

void findChippest(const string& productName, const storeData& storeDATA) {
    double cheapestPrice = numeric_limits<double>::max();
    bool found = false; // Track if the product was found
    vector<pair<string, string>> availableStores; // To hold chains and stores with the cheapest price

    for (const auto& chain : storeDATA) {
        for (const auto& store : chain.second) {
            auto productIt = store.second.find(productName);
            if (productIt != store.second.end()) {
                found = true; // We found the product in the selection

                if (productIt->second != -1) { // Product is available
                    // Check for the cheapest price
                    if (productIt->second < cheapestPrice) {
                        cheapestPrice = productIt->second;
                        availableStores.clear(); // Clear previous entries
                        availableStores.emplace_back(chain.first, store.first); // Add new cheapest
                    } else if (productIt->second == cheapestPrice) {
                        // If it matches the current cheapest price, add to the list
                        availableStores.emplace_back(chain.first, store.first);
                    }
                }
            }
        }
    }

    // Determine the output based on the flags
    if (found) {
        if (availableStores.empty()) {
            // If we found the product, but no stores have it in stock
            cout << "The product is temporarily out of stock everywhere" << endl;
        } else {
            // Print the cheapest price
            cout << to_string_with_precision(cheapestPrice, 2) << " euros" << endl;
            // Sort and print available stores with the cheapest price
            sort(availableStores.begin(), availableStores.end());
            for (const auto& store : availableStores) {
                cout << store.first << " " << store.second << endl; // Print chain and store
            }
        }
    } else {
        cout << "The product is not part of product selection" << endl;
    }
}




//function: handleInput
//purpose: to process user input

void handleInput (const vector<string>& comandArgs, const storeData& storeDATA){
    if(comandArgs.empty()) return; //returns if any empty arguments

    if (comandArgs[0] == "quit"){
        exit(EXIT_SUCCESS);
    }
    else if (comandArgs[0] == "chains"){
        if(comandArgs.size()==1){
            printChains(storeDATA);
        }
        else{
            cout<< "Error: error in command chains" <<endl;
        }

    }
    else if (comandArgs[0] == "stores"){
        if (comandArgs.size() == 2){
            printStore(comandArgs[1], storeDATA);

        }
        else{
            cout<<"Error: error in command stores"<<endl;
        }
    }

    else if (comandArgs[0] == "products") {
        if (comandArgs.size() == 1) {  // Ensure only "products" is allowed
            printProducts(storeDATA);
        } else {
            cout << "Error: error in command products" << endl;
        }
    }

    else if (comandArgs[0] == "selection") {
        if (comandArgs.size() == 3) {
            selectionProducts(comandArgs[1], comandArgs[2], storeDATA);
        } else {
            cout << "Error: error in command selection" << endl;
        }
    }

    else if (comandArgs[0] == "cheapest") {
            if (comandArgs.size() == 2) {
                findChippest(comandArgs[1], storeDATA);
            } else {
                cout << "Error: error in command cheapest" << endl;
            }
        }



    else {
        cout << "Error: unknown command: " << comandArgs[0] << endl;
    }

}





//function: main
//purpose: 2nd stage of the project
//Handling the user input and showing the data by user interface

int main() {
    cout << "Input file: ";
    string filename;
    getline(cin, filename);

    storeData storeDATA = readStoreData(filename);
    while (true){
        cout << "> ";
        string input;
        getline(cin, input);
        vector<string> args = Split(input, ' ');
        handleInput(args, storeDATA);
    }


       return 0;
   }
