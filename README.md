# Simple Encryption-Decryption

## Description

This is a simple C++ script that allows the user to input a message, then encrypt or decrypt it based on a corresponding key.

## How to Use

1. Upon startup, the user will be prompted to enter a message:
```
Please enter your message:
```
2. Once the user has entered their message, they will be asked if they want to encrypt it or decrypt it:
```
Please enter your message: Hello world!

Enter the corresponding letter (e/d) if you wish to encrypt or decrypt:
```
3. If the user chooses to encrypt the message, the randomly generated key and encrypted message will be printed out to the screen:
```
Please enter your message: Hello world!

Enter the corresponding letter (e/d) if you wish to encrypt or decrypt: e

Generated key: phqgh
Encrypted message: Xmcsw mwisl!
```
4. If the user chooses to decrypt the message, they will be asked to enter the decryption key. Afterwards the decrypted message will be printed out to the screen:
```
Please enter your message: Xmcsw mwisl!

Enter the corresponding letter (e/d) if you wish to encrypt or decrypt: d

Enter the key: phqgh
Decrypted message: Hello world!
```

## Algorithm

The encryption algorithm used in this script is a very simple transposition cipher. The algorithm loops through a 5-character long string and shifts each letter in the message based on the current character in the key. Currently the encryption algorithm only affects alphabetical characters and skips over any numbers, special characters, and whitespace.

Example:
```
Message: Hello world!
Key: phqgh

H -> p - > X
e -> h - > m
l -> q - > c
l -> g - > s
o -> h - > w
  ->   - >  
w -> p - > m
o -> h - > w
r -> q - > i
l -> g - > s
d -> h - > l
! ->   - > !

Output: Xmcsw mwisl!
```
The decryption algorithm works by simply shifting each letter in the message in the reverse direction.
