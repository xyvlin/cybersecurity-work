import random
import string

#SHIFT CIPHER
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

def shiftE():
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

def shiftD():
    message = input("Enter the message you want to decrypt: ")
    print("What key was used to encrypt this message? ")
    while True:
        try:
            key = int(input("Enter a shift key (1-25): "))
            if 1 <= key <= 25:
                break
            else:
                print("Please enter a number between 1 and 25.")
        except ValueError:
            print("Invalid input. Please enter a number between 1 and 25.")
    plaintxt,a,b= shift_cipher(message,key*-1)
    print("This is the original message:",plaintxt)

#OTP
def generate_key(seed, length):
    random.seed(seed)
    return [random.randint(1, 9) for _ in range(length)]   

def shift_letter(letter, shift):
    if letter.isalpha():
        base = ord('A') if letter.isupper() else ord('a')
        return chr((ord(letter) - base + shift) % 26 + base)
    return letter 

def otp_cipher():
    print("🔐  Welcome to the OTP Shift Cipher Program!")
    print("This program encrypts messages using a one-time pad (OTP) shift cipher.")
    print("Each letter is shifted by a random amount, determined by your input seed.")
    
    message = input("\nEnter your message: ").strip()
    seed = int(input("Enter an integer seed: "))

    key = generate_key(seed, len(message))
    
    encrypted_message = [shift_letter(letter, shift) for letter, shift in zip(message, key)]

    print("\n🔑  Key Generated:", " ".join(map(str, key)))
    print("\nEncryption Process:")
    for i, (char, shift) in enumerate(zip(message, key)):
        if char.isalpha():
            print(f"{char.upper()} + {shift} → {encrypted_message[i].upper()}")
        else:
            print(f"{char} (unchanged)")

    print("\nCiphertext:", "".join(encrypted_message))

def unshift_letter(letter, shift):
    """Shifts a letter backwards (for decryption)."""
    if letter.isalpha():
        base = ord('A') if letter.isupper() else ord('a')
        return chr((ord(letter) - base - shift) % 26 + base)
    return letter

def otp_decrypt():
    message = input("Enter the encrypted message: ").strip()
    seed = int(input("Enter the same integer seed used for encryption: "))

    key = generate_key(seed, len(message))
    decrypted_message = [unshift_letter(letter, shift) for letter, shift in zip(message, key)]

    print("\n🔑 Key Used for Decryption:", " ".join(map(str, key)))
    print("\nDecryption Process")
    for char, shift, decrypted_char in zip(message, key, decrypted_message):
        if char.isalpha():
            print(f"{char.upper()} - {shift} → {decrypted_char.upper()}")
        else:
            print(f"{char} (unchanged)")

    print("\n📝 Decrypted Message:", "".join(decrypted_message))
    
def EorD():
    print("Do you want to encrypt a new message or decrypt an encoded message?")
    while True:
        choice = input('Enter "E" or "D": ')
        if choice=="E" or choice=="D":
            return choice
        

print('Enter "shift" to try out shift cipher or "otp" to try out one time pad')
choice = input(" > ")

while choice!="stop":
    if choice=="shift":
        print("=============Shift Cipher=============")
        eedd = EorD()
        if eedd=="E":
            shiftE()
        else:
            shiftD()
    elif choice=="otp":
        print("=================OTP=================")
        eedd = EorD()
        if eedd=="E":
            otp_cipher()
        else:
            otp_decrypt()
    elif choice=="stop":
        continue
    else:
        print('Enter "shift" or "cipher": ')
        choice = input(" > ")
        continue
    print('\n\nEnter "shift" to try out shift cipher or "otp" to try out one time pad')
    choice = input(" > ")
