
#### One-Time Pad Stream Cipher
This project implements a simple One-Time Pad (OTP) data encryption and decryption system.

#### How It Works
Stream ciphers encrypt data bit-by-bit or byte-by-byte using a randomly generated keystream.  
It does this by XORing the plaintext with a truly random key, 
---

### Usage

1. Installation

    ```sh
    git clone https://github.com/ismaelsadeeq/otp-stream-cipher
    cd otp-stream-cipher
    git clone https://github.com/ismaelsadeeq/crypto-utils
    ```


2. Include the library in your project

    E.g Create a new file, `main.cpp`

    ```c++
    // main.cpp
    #include <iostream>
    #include "one_time_pad.h"

    int main() {
        try {
            OneTimePad otp;

            // Message to encrypt
            std::string message = "Secret123";

            // Encrypt the message
            auto encrypted = otp.encrypt(message);
            std::cout << "Key:      " << encrypted.first << "\n"
                    << "Cipher:   " << encrypted.second << "\n";

            // Decrypt the message
            std::string decrypted = otp.decrypt(encrypted.first, encrypted.second);
            std::cout << "Decrypted message: " << decrypted << std::endl;
        } catch (const std::exception& ex) {
            std::cerr << "Exception: " << ex.what() << std::endl;
            return 1;
        }
        return 0;
    }
    ```

Note: This implementation doesn't require any external libraries. You can compile it with your preferred C++ compiler.
