// Simple Cipher
// Anthony Howell 
// March 2021
// Simple C++ program that allows the user to encrypt / decrypt a message

#include<iostream>  
#include <stdlib.h>
#include <limits>
#include <algorithm>
#include <string>

using namespace std;

/*
Creates a random 5-letter long string as a key
Loops through each letter in the message and shifts it based on the respective letter in the key
*/
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
	cout << "Encrypted message: " + output + "\n";
	return output;
}

/*
Takes in a string of letters as a key
Loops through each letter in the message and shifts it based on the respective letter in the key in the reverse direction
*/
string messageDecrypt(string s, string key){
	//Instantiate variables
	string output;
	int keyLoop = 0;
	
	//Invalid key error
	for (int j = 0; j < key.size(); j++){ //Loop through each character in the key
	    if (!isalpha(key[j])){ //If a non-letter character is found, exit with error code.
			cout << "Error: Invalid key (key cannot contain non-letter characters)\n";
			return "";                  
	    }
	}
	
	//Force key to lower
	transform(key.begin(), key.end(), key.begin(), ::tolower);
	
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
	
	cout << "Decrypted message: " + output + "\n";
	
	return output;
}

/*
Provides a UI system that allows the user to encrypt or decrypt a message
using the encryption and decryption functions
*/
void cipherMenu(){
	//Instantiate variables
	string outputMessage, cipherKey;
	string inputMessage;
	char actionType;
	
    //User inputs their message
    cout << "Please enter your message: "; 
    
    getline(cin, inputMessage);
    
    //User chooses to encrypt or decrypt their message
    cout << "\nEnter the corresponding letter (e/d) if you wish to encrypt or decrypt: ";
    
    cin >> actionType;
    
    //Encryption code
    if (actionType == 'e' or actionType == 'E'){
    	//Use specific key or random key?
    	
    	//Encrypt the message
    	outputMessage = messageEncrypt(inputMessage);
	}
	
	//Decryption code
	else if (actionType == 'd' or actionType == 'D'){
		//Enter the decryption key
	    cout << "\nEnter the key: ";
	    
	    cin >> cipherKey;
		
		//Decrypt the message
		outputMessage = messageDecrypt(inputMessage, cipherKey);
	}
	
	//Invalid actionType
	else {
		cout << "Invalid input, exiting application...";
	}
}

int main() 
{ 
	bool exit = false;
	string yesArray[] = {"Y","y","Yes","yes","YES"};
	string answer;
	
	while (exit == false){
		cipherMenu();
		
		cout << "\nDo you wish to encrypt/decrypt something else? (Y/N): ";
		cin >> answer;
		
		//Check if answer was not a yes
		if (find(yesArray, yesArray + 5, answer) == (yesArray + 5)){
			exit = true;
		} else {		
			cout << "\n";
			
        	cin.clear();
        	cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
	}

    return 0; 
} 
