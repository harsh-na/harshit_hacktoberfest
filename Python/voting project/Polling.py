from ast import If
from turtle import bgcolor
import tkinter 
from tkinter import *
from PIL import  ImageTk, Image
from tkinter import ttk
from tkinter import messagebox
from tkinter import simpledialog
from tkinter import filedialog as fd
import sqlite3 as sqltor
import matplotlib.pyplot as plt

conn=sqltor.connect('main.db') #main database
cursor=conn.cursor() #main cursor
cursor.execute("""CREATE TABLE IF NOT EXISTS poll
                    (name)""")

def pollpage(): #page for polling
     rooter.destroy()
     def proceed():
        chose=choose.get()
        print(chose)
        command='update polling set votes=votes+1 where name=?'
        pd.execute(command,(chose,))
        pd.commit()
        messagebox.showinfo('Success!','You have voted')
        ppage.destroy()
     choose=StringVar()
     names=[]
     pd=sqltor.connect(plname+'.db') #poll database
     pcursor=pd.cursor() #poll cursor
     pcursor.execute('select name from polling')
     data=pcursor.fetchall()
     for i in range(len(data)):
         data1=data[i]
         ndata=data1[0]
         names.append(ndata)
     print(names)
     ppage=Toplevel()
     ppage.geometry('1500x850')
     ppage.title('Poll')
     ppage['bg']='#FFFFCC'

     l6=Label(ppage,text='Vote for any one person!',font='Helvetica 30 bold',bg='#FFFFCC')
     l6.place(x=560,y=50)
     for i in range(len(names)):
         b1=Radiobutton(ppage,text=names[i],value=names[i],variable=choose,font='Helvetica 30 bold',bg='#FFFFCC')
         b1.place(x=690,y=200+(i*60))
        #  .grid(row=2+i,column=1)
     b2=Button(ppage,text='Vote',font='Helvetica 30 bold',bg='#FFFFCC',command=proceed,width=25)
     b2.place(x=540,y=200+(i*60)+100)
     



def polls(): #mypolls
    def proceed():
        global plname
        plname=psel.get()
        if plname=='-select-':
            return messagebox.showerror('Error','select poll')
        else:
            mpolls.destroy()
            register()
    cursor.execute('select name from poll')
    data=cursor.fetchall()
    pollnames=['-select-']
    for i in range(len(data)):
        data1=data[i]
        ndata=data1[0]
        pollnames.append(ndata)
    psel=StringVar()
    mpolls=Toplevel()
    mpolls.geometry('270x200')
    mpolls.title('Voting Program')
    Label(mpolls,text='Select Poll',font='Helvetica 12 bold').grid(row=1,column=3)
    select=ttk.Combobox(mpolls,values=pollnames,state='readonly',textvariable=psel)
    select.grid(row=2,column=3)
    select.current(0)
    Button(mpolls,text='Proceed',command=proceed).grid(row=2,column=4)




def create():
    root.destroy()
    def proceed():
        global pcursor
        pname=name.get() #pollname
        can=cname.get()   #candidatename
        if pname=='':
            return messagebox.showerror('Error','Enter poll name')
        elif can=='':
            return messagebox.showerror('Error','Enter candidates')
        else:
            candidates=can.split(',') #candidate list
            command='insert into poll (name) values (?);'
            cursor.execute(command,(pname,))
            conn.commit()
            pd=sqltor.connect(pname+'.db') #poll database
            pcursor=pd.cursor() #poll cursor
            pcursor.execute("""CREATE TABLE IF NOT EXISTS polling
                 (name TEXT,votes INTEGER)""")
            for i in range(len(candidates)):
                command='insert into polling (name,votes) values (?, ?)'
                data=(candidates[i],0)
                pcursor.execute(command,data)
                pd.commit()
            pd.close()
            messagebox.showinfo('Success!','Poll Created')
            cr.destroy()

    name=StringVar()
    cname=StringVar()
    cr=Toplevel()
    cr.geometry('1500x850')
    cr.title('Create a new poll')
    cr['bg'] = '#FFFFCC'
    l1=Label(cr,text='Enter Details',font='Helvetica 30 bold',bg='#FFFFCC')
    l1.place(x=640,y=180)
    l2=Label(cr,text='Enter Poll name: ',font='Helvetica 20 bold',bg='#FFFFCC')
    l2.place(x=500,y=250)
    e1=Entry(cr,width=45,textvariable=name) #poll name
    e1.place(x=710,y=250)
    l3=Label(cr,text='Enter Candidates: ',font='Helvetica 20 bold',bg='#FFFFCC')
    l3.place(x=500,y=300)
    e2=Entry(cr,width=45,textvariable=cname) #candidate name
    e2.place(x=710,y=300)
    l5=Label(cr,text='Note: Enter the candidate names one by one by putting commas.',font='Helvetica 15',bg='#FFFFCC')
    l5.place(x=710,y=330)
    # Label(cr,text='eg: candidate1,candate2,candidate3....',bg='#FFFFCC',font='Helvetica 20 bold').grid(row=5,column=2)
    b1=Button(cr,text='Proceed',font='Helvetica 20 bold',bg='#FFFFCC',command=proceed)
    b1.place(x=670,y=400)

def selpl(): #pollresults
    def results():
        sel=sele.get()  #selected option
        if sel=='-select-':
            return messagebox.showerror('Error','Select Poll')
        else:
            pl.destroy()
            def project():
                names=[]
                votes=[]
                for i in range(len(r)):
                    data=r[i]
                    names.append(data[0])
                    votes.append(data[1])
                    plt.title('Poll Result')
                plt.pie(votes,labels=names,autopct='%1.1f%%',shadow=True,startangle=140)
                plt.axis('equal')
                plt.show()
            
            res=Toplevel() #result-page
            res.geometry('1500x850')
            res['bg']='#FFFFCC'
            res.title('Results!')
            ll6=Label(res,text='Here is the Result!',font='Helvetica 40 bold',bg='#FFFFCC')
            ll6.place(x=570,y=100)
            con=sqltor.connect(sel+'.db')
            pcursor=con.cursor()
            pcursor.execute('select * from polling')
            r=pcursor.fetchall() #data-raw
            for i in range(len(r)):
                data=r[i]
                ll7=Label(res,text=data[0]+': '+str(data[1])+' votes',font='Helvetica 30 bold',bg='#FFFFCC')
                ll7.place(x=643,y=200+(i*60))
            b9=Button(res,text='Project Results',font='Helvetica 20 bold',bg='#FFFFCC',command=project)
            b9.place(x=656,y=200+(i*60)+100)


    cursor.execute('select name from poll')
    data=cursor.fetchall()
    pollnames=['-select-']
    for i in range(len(data)):
        data1=data[i]
        ndata=data1[0]
        pollnames.append(ndata)
    sele=StringVar()
    pl=Toplevel()
    pl.geometry('300x200')
    pl.title('Voting System')
    Label(pl,text='Select Poll',font='Helvetica 20 bold').grid(row=1,column=1)
    sel=ttk.Combobox(pl,values=pollnames,state='readonly',textvariable=sele)
    sel.grid(row=2,column=1)
    sel.current(0)
    Button(pl,text='Get Results',command=results).grid(row=2,column=2)


def about():
    messagebox.showinfo('About','Developed by Aditya Muzumdar(112003002), Ankur Dhok(112003009)')

def validateLogin():
    passs=password.get()
    if passs == '9999':
        messagebox.showinfo('Login','Login Successfull')
        create()

    else:
        messagebox.showinfo('Login','wrong password')
	
def loginpage():
    global root
    root = Toplevel()
    root.geometry('500x500')
    root.title("Login Form")
    home['bg'] = '#FFFFCC'

    label_0 = Label(root, text="Login form",width=20,font=("bold", 30))
    label_0.place(x=70,y=53)


    label_1 = Label(root, text="FullName",width=20,font=("bold", 20))
    label_1.place(x=45,y=130)

    entry_1 = Entry(root)
    entry_1.place(x=240,y=130)

    label_2 = Label(root, text="Email",width=20,font=("bold", 20))
    label_2.place(x=45,y=180)

    entry_2 = Entry(root)

    entry_2.place(x=240,y=180)
    label_33 = Label(root, text="Password",width=20,font=("bold", 20))
    label_33.place(x=45,y=230)
    global password
    password = StringVar()
    password = Entry(root,show='*')
    password.place(x=240,y=230)

    Button(root, text='Submit',width=20,command=validateLogin).place(x=180,y=380)

    root.mainloop()



def register():
    global rooter
    rooter = Toplevel()
    rooter.geometry('500x500')
    rooter.title("Registration Form")

    label_0 = Label(rooter, text="Registration form",width=20,font=("bold", 20))
    label_0.place(x=90,y=53)


    label_1 = Label(rooter, text="FullName",width=20,font=("bold", 10))
    label_1.place(x=80,y=130)

    entry_1 = Entry(rooter)
    entry_1.place(x=240,y=130)

    label_2 = Label(rooter, text="Email",width=20,font=("bold", 10))
    label_2.place(x=68,y=180)

    entry_2 = Entry(rooter)
    entry_2.place(x=240,y=180)

    label_3 = Label(rooter, text="Gender",width=20,font=("bold", 10))
    label_3.place(x=70,y=230)
    var = IntVar()
    Radiobutton(rooter, text="Male",padx = 5, variable=var, value=1).place(x=235,y=230)
    Radiobutton(rooter, text="Female",padx = 20, variable=var, value=2).place(x=290,y=230)

    label_4 = Label(rooter, text="country",width=20,font=("bold", 10))
    label_4.place(x=70,y=280)

    list1 = ['Canada','India','UK','Nepal','Iceland','South Africa'];
    c=StringVar()
    droplist=OptionMenu(rooter,c, *list1)
    droplist.config(width=15)
    c.set('select your country') 
    droplist.place(x=240,y=280)

    
    Button(rooter, text='Submit',width=20,command=pollpage).place(x=180,y=380)

    rooter.mainloop()
    
home=Tk()

home.geometry('1500x850')
home.title('Voting Program')
home['bg'] = '#FFFFCC'
loader= Image.open("hell.png")
render1 = ImageTk.PhotoImage(loader)
img1 = Label(home, image=render1)
img1.place(x=100, y=80)
load= Image.open("hell1.png")
render2 = ImageTk.PhotoImage(load)
img = Label(home, image=render2)
img.place(x=1000, y=80)
load= Image.open("1.png")
render = ImageTk.PhotoImage(load)
o = Label(home, image=render)
o.place(x=130, y=500)
load= Image.open("2.png")
render3 = ImageTk.PhotoImage(load)
f = Label(home, image=render3)
f.place(x=1050, y=500)

a=Label(home,text='RPPOOP PROJECT: VOTING SYSTEM\n',font='Helvetica 30 bold',bg='#FFFFCC')
a.pack()
b=Button(home,text='Create new Poll (Admin only)',font='Helvetica 20 bold',command=loginpage, padx= 5, pady= 8)
b.config(height=1,
width=25)
b.pack()
ab=Label(home,text='\n',bg='#FFFFCC')
ab.pack()
c=Button(home,text='My Polls',font='Helvetica 20 bold',command=polls, padx= 5, pady= 8)
c.config(height=1,
width=25)
c.pack()
abc=Label(home,text='\n',bg='#FFFFCC')
abc.pack()
d=Button(home,text='Poll Results',font='Helvetica 20 bold',padx= 5, pady= 8,command=selpl)
d.config(height=1,
width=25)
d.pack()
e=Button(home,text='About',command=about,font='Helvetica 20 bold', padx= 5, pady= 8)
e.config(height=1,
width=25)
e.place(x=560,y=600)
home.mainloop()