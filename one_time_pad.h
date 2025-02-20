#ifndef ONE_TIME_PAD_H
#define ONE_TIME_PAD_H

#include <string>
#include <vector>
#include <cassert>

// Internal libraries
#include "crypto-utils/random.h"
#include "crypto-utils/hex.h"

class OneTimePad
{
public:
    /**
     * @brief Encrypts a given message using a randomly generated key.
     *
     * @param message The plaintext message to be encrypted.
     * @return A pair of hexadecimal strings: <key_hex, cipher_hex>.
     */
    std::pair<std::string, std::string> encrypt(const std::string& message) {
        size_t bytes = message.size();
        std::vector<unsigned char> msg(message.begin(), message.end());
        std::vector<unsigned char> key_val = GenerateCryptographicallySecureRandomNumber(bytes);
        std::vector<unsigned char> cipher_val(bytes);

        assert(key_val.size() == msg.size());
        
        for (size_t i = 0; i < bytes; i++) {
            cipher_val[i] = key_val[i] ^ msg[i];
        }

        return { to_hex(key_val), to_hex(cipher_val) };
    }

    /**
     * @brief Decrypts a given ciphertext using the provided key.
     *
     * @param key_hex The hexadecimal representation of the encryption key.
     * @param cipher_hex The hexadecimal representation of the ciphertext.
     * @return The decrypted plaintext message.
     * @throws std::invalid_argument if the key or ciphertext are invalid.
     */
    std::string decrypt(const std::string& key_hex, const std::string& cipher_hex) {
        std::vector<unsigned char> key_val = from_hex(key_hex);
        std::vector<unsigned char> cipher_val = from_hex(cipher_hex);

        if (key_val.size() != cipher_val.size()) {
            throw std::invalid_argument("Key and ciphertext sizes must match.");
        }

        std::vector<unsigned char> msg_val(cipher_val.size());
        for (size_t i = 0; i < cipher_val.size(); i++) {
            msg_val[i] = key_val[i] ^ cipher_val[i];
        }

        return std::string(msg_val.begin(), msg_val.end());
    }
};

#endif // ONE_TIME_PAD_H
