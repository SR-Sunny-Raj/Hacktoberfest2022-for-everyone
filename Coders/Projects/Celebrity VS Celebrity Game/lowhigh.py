from lowhighlogo import logo, vs
from lowhighdata import data
import random

print(logo)
score=0
tocontinue=True
accB=random.choice(data)
while tocontinue:
    accA=accB
    accB=random.choice(data)
    while accA==accB:
        accB=random.choice(data)

    def checkans(guess,afc,bfc):
        if afc>bfc:
            return guess=="a"
        else:
            return guess=="b"

    def formatdata(account):
        accname=account["name"]
        accdesc=account["description"]
        acccountry=account["country"]
        return (f"{accname}, a {accdesc}, from {acccountry}")

    print(f"\nCompare A: {formatdata(accA)}")
    print(vs)
    print(f"Against B: {formatdata(accB)}")

    guess=input("Who has more followers? Type 'A' or 'B': ").lower()
    afc=accA["follower_count"]
    bfc=accB["follower_count"]

    iscorrect=checkans(guess,afc,bfc)
    if iscorrect:
        score+=1
        print(f"\nYou're right!, current score: {score}")
    else:
        print(f"\nYou're wrong, final score is: {score}")
        tocontinue=False

