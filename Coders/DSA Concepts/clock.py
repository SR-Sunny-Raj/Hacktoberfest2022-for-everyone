from tkinter import *
import time
from time import strftime

root=Tk()
root.geometry("900x800")
def timetake():
    timestr=strftime("%H:%M:%S %p")
    timelbl.config(text=timestr)
    timelbl.after(1000,timetake)

timelbl=Label(root,background="lightblue",foreground="green",font="comicsans 30 bold")
timelbl.pack()
timetake()


root.mainloop()