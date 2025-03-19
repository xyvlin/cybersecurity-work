def shift_cipher(message, key):
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    shifted_alphabet = alphabet[key:] + alphabet[:key]
    translation_table = {alphabet[i]: shifted_alphabet[i] for i in range(26)}
    
    message = message.upper()
    encrypted_message = "".join(translation_table.get(char, char) for char in message)
    
    return encrypted_message, alphabet, shifted_alphabet

def display_shift(alphabet, shifted_alphabet, key):
    print("translation table: ")
    alphabet = alphabet + alphabet[:key]
    shifted_alphabet = []
    for i in range(1,key+1): 
        shifted_alphabet+=[i]
    shifted_alphabet+=alphabet[:26]
    for i in range(0,len(alphabet)):
        print('\t',shifted_alphabet[i],alphabet[i])

def main():
    print("Shift Cipher works by shifting all the characters in your message by a fixed number of position.")
    print("For example, move A by 1 position and it becomes B; move A by 2 position it becomes C.")
    print('The number of positions you shift the letters is called the "key".') 
    print("This program will encrypt your message using a shift cipher.\n")
    
    message = input("Enter your message: ")
    while True:
        try:
            key = int(input("Enter a shift key (1-25): "))
            if 1 <= key <= 25:
                break
            else:
                print("Please enter a number between 1 and 25.")
        except ValueError:
            print("Invalid input. Please enter a number between 1 and 25.")
    
    encrypted_message, alphabet, shifted_alphabet = shift_cipher(message, key)
    display_shift(alphabet, shifted_alphabet, key)
    
    print("\nEncryption Process:")
    for original, encrypted in zip(message.upper(), encrypted_message):
        if original in alphabet:
            print(f"{original} → {encrypted}")
    
    print("\nCiphertext:", encrypted_message)

if __name__ == "__main__":
    main()
