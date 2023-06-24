#include <iostream>
#include "Cryptograph.h"
// Alvaro Emmanuel Socop Perez 202000194
using namespace std;
// This program is the sender
int main()
{
    // Create a Cryptograph object for X.
    Cryptograph x("llvPubX", "llvPrivX");

    // Get the recipient's public key.
    string llvReceiverPub = "llvPubY";
    cout << "------------- WELCOME PROGRAM X -----------------\n";
    // Create a message.
    string message = "Sistemas_Operativos_2_JUNIO_2023";

    // Encrypt the message and get the cryptogram.
    string cryptogram = x.send(llvReceiverPub, message);

    // Print the cryptogram.
    cout << "The cryptogram generated is: \n"
         << cryptogram << endl;

    return 0;
}