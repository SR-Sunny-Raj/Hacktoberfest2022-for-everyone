from tkinter import *
import string
import random
import pyperclip


def generator():
    small_alphabets = string.ascii_lowercase
    capital_alphabets = string.ascii_uppercase
    numbers = string.digits
    specialCharecters = string.punctuation

    mixed_password = small_alphabets + capital_alphabets + numbers + specialCharecters
    password_length = int(length_Box.get())

    clearPasswordField()

    if choice.get() == 1:
        passwordField.insert(0, random.sample(small_alphabets, password_length))

    if choice.get() == 2:
        passwordField.insert(0, random.sample(small_alphabets + capital_alphabets, password_length))

    if choice.get() == 3:
        passwordField.insert(0, random.sample(mixed_password, password_length))


def copy():
    random_password = passwordField.get()
    pyperclip.copy(random_password)


def clearPasswordField():
    passwordField.delete(0, END)


root = Tk()
root.geometry("450x425")
root.config(bg='gray20')
choice = IntVar()
Font = ('georgia', 18, 'bold')
passwordLabel = Label(root, text='Password Generator', font=('Courier New', 35, 'bold'), bg='gray20', fg='white')

passwordLabel.place(x=100, y=0)
passwordLabel.grid(pady=15)

weakRadioButton = Radiobutton(root, text='Weak', value=1, variable=choice, font=Font)
weakRadioButton.grid(pady=5)

mediumRadioButton = Radiobutton(root, text='Medium', value=2, variable=choice, font=Font)
mediumRadioButton.grid(pady=5)

strongRadioButton = Radiobutton(root, text='Strong', value=3, variable=choice, font=Font)
strongRadioButton.grid(pady=5)

lengthLabel = Label(root, text='Password Length', font=Font, bg='gray20', fg='white')
lengthLabel.grid(pady=5)

length_Box = Spinbox(root, from_=5, to_=15, width=5, font=Font)
length_Box.grid(pady=5)

generateButton = Button(root, text='Generate', font=Font, command=generator)
generateButton.grid(pady=10)

passwordField = Entry(root, width=25, bd=2, font=Font)
passwordField.grid()

copyButton = Button(root, text='Copy', font=Font, command=copy)
copyButton.grid(pady=15)

root.mainloop()
