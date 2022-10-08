import random

rock = '''
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
'''

paper = '''
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
'''

scissors = '''
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
'''

tools = [rock,paper,scissors]
print("What do you choose ? Type 0 for Rock, 1 for Paper or 2 for Scissor :  ")
user = int (input())

if user >= 3 or user < 0 :
    print("Invalid Input, You Loose")
else :
    print("User choose : ")
    print(tools[user])
    computer = random.randint(0,2)
    print("Computer choose : ")
    print(tools[computer])


    if user == computer :
        print("It's Draw !")
    elif user == 0 and computer == 2 :
        print("Congratulations, You Win !")
    elif user == 2 and computer == 1 :
        print("Congratulations, You Win !")
    elif user == 1 and computer == 0 :
        print("Congratulations, You Win !")
    else:
        print("Ohh, You Loose !")