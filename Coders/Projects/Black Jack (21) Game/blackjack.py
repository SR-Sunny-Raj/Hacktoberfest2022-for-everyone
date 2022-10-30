import random
from blackjacklogo import logo

def dealcard():
    cards=[11,2,3,4,5,6,7,8,9,10,10,10,10]
    card=random.choice(cards)
    return card

def calcscore(cards):
    
    if 11 in cards and 10 in cards and len(cards)==2:
        return 0
    if 11 in cards and sum(cards)>21:
        cards.remove(11)
        cards.append(1)
    return sum(cards)

def compare(userscore,computerscore):
    if userscore==computerscore:
        return "Draw"
    elif computerscore==0:
        return "you loose, opponent has black jack"
    elif userscore==0:
        return "you win with a black jack"
    elif userscore>21:
        return "you lose with a went over"
    elif computerscore>21:
        return "opponent lost with wen over, you won"
    elif userscore>computerscore:
        return "you win"
    else:
        return "you lose"

while input("Do you want to play blackjack? 'y' for yes, 'n' for no: ") =="y":
    print(logo)
    usercards=[]
    computercards=[]
    isgameover=False

    for i in range(2):
        
        usercards.append(dealcard())
        computercards.append(dealcard())

    while not isgameover:

        userscore=calcscore(usercards)
        computerscore=calcscore(computercards)
        print(f"\nYour cards: {usercards}, current score: {userscore}")
        print(f"computer's first card: {computercards[0]}")

        if userscore==0 or computerscore==0 or userscore>21:
            isgameover=True
        else:
            usershoulddeal=input("\nenter 'y' for another card 'n' for pass: ")
            if usershoulddeal=="y":
                usercards.append(dealcard())
            else:
                isgameover=True

    while computerscore != 0 and computerscore<17:
        computercards.append(dealcard())
        computerscore=calcscore(computercards)


    print(f"\nyour final hand: {usercards}, final score: {userscore}")
    print(f"computer's final hand: {computercards}, final score: {computerscore}")
    print(compare(userscore,computerscore))


