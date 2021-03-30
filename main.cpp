// Simple Cipher
// Anthony Howell 
// March 2021
// Simple C++ program that allows the user to encrypt / decrypt a message

#include<iostream>  
#include <stdlib.h>
using namespace std; 

//Creates a random 5-letter long string as a key
//Loops through each letter in the message and shifts it based on the respective letter in the key
string messageEncrypt(string s){
	//Instantiate variables
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	string key, output;
	int keyLoop = 0;
	
	//Create random key
	for (int i = 0; i < 5; i++){
		key += alphabet[rand() % 26];
	}

	//Loops through each letter in the message, and shift them based on the letter in the key
	for (int i = 0; i < s.length(); i++){
		char c = s.at(i); //The char in that position in the message

		if (isalpha(c)){ //If the character is a letter
			
			//Lowercase letters
			if (islower(c)){
				//Character overflow fix
				if (c + key.at(keyLoop) - 96 > 'z'){ 
					c = c - 'z' + 'a' - 1;
				}
				
				//Shift the character
				c += key.at(keyLoop) - 96; 
				
				//Store the result
				output += c; 
				
				//Increment through the key
				keyLoop++;
				
				if (keyLoop >= key.length()){
					keyLoop = 0;
				}
				
			} else 
			//Capital letters
			if (isupper(c)){
				//Character overflow fix
				if (c + key.at(keyLoop) - 96 > 'Z'){ 
					c = c - 'Z' + 'A' - 1;
				}
				
				//Shift the character
				c += key.at(keyLoop) - 96; 
				
				//Store the result
				output += c; 
				
				//Increment through the key
				keyLoop++;
				
				if (keyLoop >= key.length()){
					keyLoop = 0;
				}
				
			}
		} else {
			output += c; 
		}
	}
	
	cout << "Generated key: " + key + "\n";
	return output;
}

string messageDecrypt(string s, string key){
	//Instantiate variables
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	string output;
	int keyLoop = 0;
	
	//Loop through each letter in the message, and shift them in reverse based on the letter in the key
	for (int i = 0; i < s.length(); i++){
		char c = s.at(i); //The char in that position in the message

		if (isalpha(c)){ //If the character is a letter

			//Lowercase letters
			if (islower(c)){
				//Character overflow fix
				if (c - key.at(keyLoop) + 96 < 'a'){ 
					c = c + 'z' - 'a' + 1;
				}
				
				//Shift the character
				c -= key.at(keyLoop) - 96; 
				
				//Store the result
				output += c; 
				
				//Increment through the key
				keyLoop++;
				
				if (keyLoop >= key.length()){
					keyLoop = 0;
				}
				
			} else 
			//Capital letters
			if (isupper(c)){
				//Character overflow fix
				if (c - key.at(keyLoop) + 96 < 'A'){ 
					c = c + 'Z' - 'A' + 1;
				}
				
				//Shift the character
				c -= key.at(keyLoop) - 96; 
				
				//Store the result
				output += c; 
				
				//Increment through the key
				keyLoop++;
				
				if (keyLoop >= key.length()){
					keyLoop = 0;
				}
			}
			
		} else {
			output += c; 
		}
	}
	
	return output;
}

void cipherMenu(){
	//Instantiate variables
	string outputMessage, cipherKey;
	std::string inputMessage;
	char actionType;
	
    //User inputs their message
    cout << "Please enter your message: "; 
    
    std::getline(std::cin, inputMessage);
    
    //User chooses to encrypt or decrypt their message
    cout << "\nEnter the corresponding letter (e/d) if you wish to encrypt or decrypt: ";
    
    cin >> actionType;
    
    //Encryption code
    if (actionType == 'e' or actionType == 'E'){
    	//Use specific key or random key?
    	
    	//Encrypt the message
    	outputMessage = messageEncrypt(inputMessage);
    	
    	//Print out the encrypted message
    	cout << "Encrypted message: " + outputMessage + "\n";
    	
    	//Print out the key
	}
	
	//Decryption code
	else if (actionType == 'd' or actionType == 'D'){
		//Enter the decryption key
	    cout << "\nEnter the key: ";
	    
	    cin >> cipherKey;
		
		//Decrypt the message
		outputMessage = messageDecrypt(inputMessage, cipherKey);
		
		//Print out the decrypted message
    	cout << "Decrypted message: " + outputMessage + "\n";
	}
	
	//Invalid actionType
	else {
		cout << "Invalid input, exiting application...";
	}
}
  
int main() 
{ 
	cipherMenu();

    return 0; 
} 
