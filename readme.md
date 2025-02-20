
#### One-Time Pad Stream Cipher
This project implements a simple One-Time Pad (OTP) data encryption and decryption system.

#### How It Works
Stream ciphers encrypt data bit-by-bit or byte-by-byte using a randomly generated keystream.  
It does this by XORing the plaintext with a truly random key, 

It provides perfect secrecy as long as:
1. The key is truly random.
2. The key is as long as the message.
3. The key is never reused.

##### Example XOR Encryption
```c++
Key:      10010100
Message:  01011010
Ciphertext:
       10010100
XOR    01011010
----------------
       11001110
```

---

### Usage

1. Installation

    ```sh
    git clone https://github.com/your-repo/otp-stream-cipher
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
