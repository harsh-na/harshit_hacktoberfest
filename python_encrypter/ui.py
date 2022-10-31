from tkinter import *
from tkinter.ttk import *
from tkinter.filedialog import askopenfile,asksaveasfile
#from file_opener import *
#from enc_dec import *

root=Tk()
root.title('encryptor by Amit yadav')
root.geometry('900x900+150+150')

label=Label(root,text='enter your message to encrypt or decrpyt',borderwidth=10).grid(row=0,column=0,pady=20)
endlab=Label(root,text='encrypt your file',borderwidth=10).grid(row=0,columnspan=4,padx=40,column=1,pady=20)

entry1=Entry(root)
entry1.grid(row=1,column=0,pady=20)

label1=Label(root,text='your encrypted/decrpyted message :').grid(row=5,columnspan=4,column=0,pady=20)
en_label=Entry(root)
en_label.grid(row=6,column=0,rowspan=10,columnspan=10,pady=20)

content=''
def open_file():
	file = askopenfile(mode ='r', filetypes =[('Text Files', '*.txt')])
	if file is not None:
		global content
		content = file.read()
	return content

def encrypter(*args):
	if len(content)>0:
		en_message=list(map(lambda a:chr(ord(a)+5),content))
		en_message1=''.join(map(str,en_message))
		en_label.insert(0,en_message1)
	else:
		en_label.delete(0,END)
		message=entry1.get()
		entry1.delete(0,END)
		en_message=list(map(lambda a:chr(ord(a)+5),message))
		en_message1=''.join(map(str,en_message))
		en_label.insert(0,en_message1)

def decrypter(*args):
	if len(content)>0:
		en_message=list(map(lambda a:chr(ord(a)-5),content))
		en_message1=''.join(map(str,en_message))
		en_label.insert(0,en_message1)
	else:
		en_label.delete(0,END)
		message=entry1.get()
		entry1.delete(0,END)
		en_message=list(map(lambda a:chr(ord(a)-5),message))
		en_message1=''.join(map(str,en_message))
		en_label.insert(0,en_message1)

def save_file():
	wf = open('D:\python_\python_encrypter\encrpyted_.txt','w')
	wf.write(en_label.get())
	#asksaveasfile(mode ='w', filetypes =[('Text Files', '*.txt')])



file_button=Button(root,text='click here to open file',command=open_file).grid(padx=10,row=1,column=1)
encrypt_button=Button(root,text='encrypt',command=encrypter).grid(row=4,column=0,pady=20)
encrypt_button=Button(root,text='decrypt',command=decrypter).grid(row=4,column=1,pady=20)
export_button=Button(root,text='export',command=save_file).grid(row=7,column=1,pady=20)
root.mainloop()