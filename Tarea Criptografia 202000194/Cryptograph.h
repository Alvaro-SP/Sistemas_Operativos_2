#include <string>
// Functions implementeds for the task for Operative Systems II
// Cryptograph class
// Alvaro Emmanuel Socop Perez 202000194
class Cryptograph
{
public:
  Cryptograph(std::string llvPub, std::string llvPriv);

  std::string send(std::string llvReceiver, std::string message);

  std::string receive(std::string llvSender, std::string cryptogram);

private:
  std::string llvPublic;
  std::string llvPrivate;

  std::string encrypt(std::string llv, std::string message);

  std::string decrypt(std::string llv, std::string cryptogram);
};

Cryptograph::Cryptograph(std::string llvPub, std::string llvPriv)
{
  llvPublic = llvPub;
  llvPrivate = llvPriv;
}

std::string Cryptograph::send(std::string llvReceiver, std::string message)
{
  // Generate the certified cryptogram using own keys and recipient's key
  std::string criptograma = encrypt(llvReceiver, message);

  // Return the generated cryptogram
  return criptograma;
}

std::string Cryptograph::receive(std::string llvSender, std::string cryptogram)
{
  // Receive the certified cryptogram using own keys and sender's key
  std::string mensaje = decrypt(llvSender, cryptogram);

  // Return the received message
  return mensaje;
}

std::string Cryptograph::encrypt(std::string llv, std::string message)
{
  // Implementation of RSA encryption using the specified llv (public or private key)
  // Here's a simple example using a basic Caesar cipher encryption

  std::string encryptedMessage = "";
  int shift = 3; // Number of positions to shift each character

  for (char c : message)
  {
    if (std::isalpha(c))
    {
      char base = std::isupper(c) ? 'A' : 'a';
      c = (c - base + shift) % 26 + base;
    }
    encryptedMessage += c;
  }

  // Return the encrypted cryptogram
  return encryptedMessage;
}

std::string Cryptograph::decrypt(std::string llv, std::string cryptogram)
{
  // Implementation of RSA decryption using the specified llv (public or private key)
  // Here's the corresponding decryption for the Caesar cipher encryption used in encripta()

  std::string decryptedMessage = "";
  int shift = 3; // Number of positions to shift each character

  for (char c : cryptogram)
  {
    if (std::isalpha(c))
    {
      char base = std::isupper(c) ? 'A' : 'a';
      c = (c - base - shift + 26) % 26 + base;
    }
    decryptedMessage += c;
  }

  // Return the decrypted message
  return decryptedMessage;
}