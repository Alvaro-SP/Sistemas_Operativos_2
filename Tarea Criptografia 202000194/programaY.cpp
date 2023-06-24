
#include <iostream>
#include "Cryptograph.h"
// Alvaro Emmanuel Socop Perez 202000194
using namespace std;

int main()
{
    // Create a Cryptograph object for Y.
    Cryptograph y("llvPubY", "llvPrivY");

    // Get the sender's public key.
    string llvSenderPub = "llvPubX";

    // Get the cryptogram.
    string cryptogram = "The cryptogram is: ";
    cout << "------------- WELCOME PROGRAM Y -----------------\n";
    cout << "Enter the cryptogram: ";
    cin >> cryptogram;

    // Decrypt the cryptogram and get the message.
    string message = y.receive(llvSenderPub, cryptogram);

    // Print the message.
    cout << "\nThe message is: \n"
         << message << endl;

    return 0;
}
