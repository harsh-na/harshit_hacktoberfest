from tkinter import *
from turtle import bgcolor
from PIL import  ImageTk, Image
from tkinter import messagebox

import time
import datetime
import random

import sqlite3


rooting=Tk()
rooting.title("Hospital Management")
rooting.geometry("1540x800+0+0")

img = ImageTk.PhotoImage(Image.open("bg.png"))
ll=Label(rooting,image=img)
ll.pack()


# dframe=Frame(rooting,bd=20,relief=RIDGE)
# dframe.place(x=300,y=130,width=1000,height=400)

# lbltitile=Label(dframe,text="Login Page",fg="blue",bg="white",font=("times new roman",25,"bold"))
# lbltitile.pack(side=TOP,fill=X)

# l1b=Button(dframe,text="Appointment Login", bg="green",fg="white",font=("ariel",12,"bold"),width=23,height=1,padx=4,pady=0)
# l1b.place(x=370,y=80) 

# l2b=Button(dframe,text="Doctor Login", height="2", width="30")
# l2b.place(x=370,y=160) 



rooting.mainloop()