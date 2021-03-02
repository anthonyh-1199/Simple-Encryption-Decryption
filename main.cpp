// Simple Cipher
// Anthony Howell 
// March 2021
// Simple C++ program that allows the user to encrypt / decrypt a message

#include<iostream>  
using namespace std; 
  
int main() 
{ 
	//Instantiate variables
	string inputMessage, outputMessage;
	int cipherKey;
	char actionType;
	
    //User inputs their message
    cout << "Please enter your message: "; 
    
    cin >> inputMessage;
    
    //User chooses to encrypt or decrypt their message
    cout << "\nEnter the corresponding letter (e/d) if you wish to encrypt or decrypt: ";
    
    cin >> actionType;
    
    //Encryption code
    if (actionType == 'e' or actionType == 'E'){
    	//Use specific key or random key?
    	
    	//Encrypt the message
    	
    	//Print out the encrypted message
    	
    	//Print out the key
	}
	
	//Decryption code
	else if (actionType == 'd' or actionType == 'D'){
		//Enter the decryption key
		
		//Decrypt the message
		
		//Print out the decrypted message
	}
	
	//Invalid actionType
	else {
		cout << "Invalid input, exiting application...";
	}

    
      
    return 0; 
} 
