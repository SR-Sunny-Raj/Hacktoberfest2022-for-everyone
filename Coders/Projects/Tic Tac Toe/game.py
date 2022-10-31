#import pygame
import numpy

def dell(X, basket):                                 #Remove all items in basket from list X
    for i in basket:
        X.remove(i)
    return X

def humanmov(mov):                                  #Comprehend the human's Move
    global lose, lose2, lose3, win, win2, win3, neut
    human.append(mov)
    arr[mov] = -1                                   #Update the move in arr and human list
    basket = []
    for i in range(len(win)):                       #If a human plays a move which blocks a winning path, then remove all such paths from win and win2
        if mov in win[i]:
            basket.append(win[i])
    win = dell(win, basket)
    basket = []
    for i in range(len(win2)):
        if mov in win2[i]:
            basket.append(win2[i])
    win2 = dell(win2, basket)
    basket = []
    for i in range(len(neut)):                      #If path is in neut and human plays a move in it then shift it to lose while deleting from neut
        j = neut[i]
        if mov in neut[i]:
            j.remove(mov)
            lose.append(j)
            basket.append(neut[i])
    neut = dell(neut, basket)
    basket = []
    for i in range(len(lose)):                       #If path already has a move played by human and human plays another move then shift it to lose2
        j = lose[i]
        if mov in lose[i]:
            j.remove(mov)
            lose2.append(j)
            basket.append(lose[i])
    lose = dell(lose, basket)
    basket = []
    for i in range(len(lose2)):                     #If path already has 2 moves played by human and human plays another move then shift it to lose3
        j = lose2[i]                                #Lose 3 being non empty denotes AI has lost
        if mov in lose2[i]:
            j.remove(mov)
            lose3.append(j)
            basket.append(lose2[i])
    lose2 = dell(lose2, basket)
    basket = []

def compmov(mov):                                   #Comprehend the AI's Move
    global lose, lose2, lose3, win, win2, win3, neut
    comp.append(mov)                                #Update the move in arr and comp list
    arr[mov] = 1
    basket = []
    for i in range(len(lose)):                      #If the AI plays a move which blocks a winning path for human, then remove all such paths from lose and lose2
        if mov in lose[i]:
            basket.append(lose[i])
    lose = dell(lose, basket)
    basket = []
    
    for i in range(len(lose2)):                     
        if mov in lose2[i]:
            basket.append(lose2[i])
    lose2 = dell(lose2, basket)
    basket = []
    for i in range(len(neut)):                      #If path is in neut and AI plays a move in it then shift it to win while deleting from neut
        j = neut[i]
        if mov in neut[i]:
            j.remove(mov)
            win.append(j)
            basket.append(neut[i])
    neut = dell(neut, basket)
    basket = []
    for i in range(len(win)):                       #If path already has a move played by AI and AI plays another move then shift it to win2
        j = win[i]
        if mov in win[i]:       
            j.remove(mov)
            win2.append(j)
            basket.append(win[i])
    win = dell(win, basket)
    basket = []
    for i in range(len(win2)):                      #If path already has 2 moves played by AI and AI plays another move then shift it to win3
        j = win2[i]                                 #Win3 being non empty denotes AI has won
        if mov in win2[i]:
            j.remove(mov)
            win3.append(j)
            basket.append(win2[i])
    win2 = dell(win2, basket)
    basket = []

def match(human, comp):                             #Decides which move AI should play next
    if(len(win2)>0):                                #First if we can win in 1 move make it,
        return win2[0][0]
    if(len(lose2)>0):                               #Second if we will lose in the nesst move prevent human from making it
        return lose2[0][0]
    if(len(win)>0):                                 #Third if no danger of losing, make a move taking in a direction towards win
        return win[0][0]
    if(len(lose)>0):                                #Fourth if no such move possible then make one blocking the human's winning path
        return lose[0][0]
    if(len(neut)>0):                                #Lastly make a move increasing our chances by a bit
        return neut[0][0]
    return arr.index(0)                             #If no move exists then take first possible move from 0,1,2,...7,8
        
def display(arr, over=False):                       #Present game on screen. If over then don't show instructions for next move
    displ = ['X' if item == -1 else 'O' if item==1 else '_' for item in arr]
    if not over:
        print("Please enter the coordinates of your move in the following pattern:")
        print("0  1  2 \n3  4  5 \n6  7  8")
    for i in range(3):
        for j in range(3):
            print(displ[3*i+j], end = "    ")
        print()

arr =  [0 for i in range(9)] 
# [0 1 2
#  3 4 5
#  6 7 8]
# We start with all possible moves which can secure a win if played by single player.
# And put them all in neut (neutral). Leave rest lists empty
neut = [[0,4,8], [2,4,6],            #diagonal win positions
        [0,1,2], [3,4,5], [6,7,8],   #horizontal win positions
        [0,3,6], [1,4,7], [2,5,8]]   #vertical win positions
        
win = []
win2 = []
win3 = []
lose = []          
lose2 = []
lose3 = []
human = []
comp = []

print("GAME START")
err = True
while(err):                                                 #Loop until correct input given
    x = input("Do you want to start first? (y/n):  ")
    if x=='y' or x=='Y':
        err = False
    elif x=='n' or x=='N':
        compmov(4)                                          #If AI starts first, play center(4) move
        err = False
while(True):
    display(arr)
    correct = False
    while(not correct):                                      #Loop until correct input given
        mov = int(input("Your move: "))
        if( 0<=mov<=8 and arr[mov]==0):
            correct=True
        else:
            print("WRONG INPUT. Please try again")
            display(arr)
    humanmov(mov)                                           #Comprehend human's move
    if(len(lose3)>0):                                      
        print("YOU WON")
        break
    
    nextmove = match(human, comp)                           #Calculate AI's best move and comprehend it
    compmov(nextmove)
    if(len(win3)>0):
        print("Better luck Next Time")
        break
    if(not 0 in arr):                                       #No result and out of moves, we draw
        print("A draw")
        break
    
display(arr, True)
print("END")
