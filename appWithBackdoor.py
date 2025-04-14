cur_word = ""
ohno = 0
import random 

def play():
    global ohno
    print("\nhangman :)")
    cur = []
    for _ in range(len(cur_word)):
        cur.append("_")
    guess = ""
    while guess != cur_word:
        display(cur)
        guess = ask()
        if guess=="ansansans":
            print(cur_word)
        elif guess=="editeditedit":
            w=input("> ")
            if w in word_list:
                word_list.remove(w)
            else:
                word_list.append(w)
        elif guess=="listlistlist":
            print(word_list)
        elif len(guess)==1:
            y = add_letter(guess,cur)
            if not y:
                print(cur_word)
                print("you found the word! you saved the man you are a hero")
                return
        else:
            if guess==cur_word:
                print("you are CORRECT! you saved the man you are a hero")
                return
            else:
                print("NOOOOO you are WRONG")
                ohno+=1
        if ohno==9:
            print("the man is DEAD so you lost\n")
            return
        print()

def display(cur):
    print((9-ohno),"wrong guesses until your man is hung")
    for l in cur:
        print(l,end=" ")
    print()

def ask():
    while True:
        s = input("Your guess: ").strip().lower()
        if len(s)!=1 and len(s)!=len(cur_word) and s!="ansansans" and s!="editeditedit" and s!="listlistlist":
            print("enter a letter or a word with the right length!")
        else:
            return s

def add_letter(guess,cur):
    global ohno
    found = False
    for i in range(len(cur)):
        if guess==cur_word[i]:
            cur[i]=guess
            found = True
    if not found:
        ohno+=1
        print("you are WRONG >:(")
    empty = False
    for l in cur:
        if l=="_":
            empty=True
    return empty

word_list = [
    "hangman", "extreme", "water", "phones", "packet",
    "cybersecurity", "chairs", "jazz", "yodel", "handle",
    "language", "turbine", "window", "suicide", "desk",
    "folder", "food", "hungry", "satellite", "volcano",
    "oxygen", "notebook", "penguin", "island", "galaxy",
    "backpack", "lighthouse", "mirror", "keyboard", "engine",
    "tornado", "castle", "robot", "nebula", "fireworks",
    "compass", "rocket", "bicycle", "moonlight", "elephant",
    "giraffe", "kangaroo", "dolphin", "tiger", "owl"
]

while True:
    random.shuffle(word_list)
    cur_word = random.choice(word_list)
    ohno=0
    play()