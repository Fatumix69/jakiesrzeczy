from tkinter import *

okno = Tk()

t=StringVar()
etykieta = Label(okno,textvariable=t,text=" ", font=('Ink Free', 20, 'bold'), width=10, height=3)

def wpisz(znak):
    t.set(t.get() + str(znak))

def czysc():
    t.set("")

def oblicz():
    try:
        wynik = eval(t.get())
        t.set(str(wynik))
    except:
        t.set("Blad")
#przyciski cyfr
btn0 = Button(okno, text="0", width=10, height=3, command=lambda: wpisz(0))
btn1 = Button(okno, text="1", width=10, height=3, command=lambda: wpisz(1))
btn2 = Button(okno, text="2", width=10, height=3, command=lambda: wpisz(2))
btn3 = Button(okno, text="3", width=10, height=3, command=lambda: wpisz(3))
btn4 = Button(okno, text="4", width=10, height=3, command=lambda: wpisz(4))
btn5 = Button(okno, text="5", width=10, height=3, command=lambda: wpisz(5))
btn6 = Button(okno, text="6", width=10, height=3, command=lambda: wpisz(6))
btn7 = Button(okno, text="7", width=10, height=3, command=lambda: wpisz(7))
btn8 = Button(okno, text="8", width=10, height=3, command=lambda: wpisz(8))
btn9 = Button(okno, text="9", width=10, height=3, command=lambda: wpisz(9))


#przyciski arytmetyczne
btn10 = Button(okno, text="+", width=10, height=3, command=lambda: wpisz("+"))
btn11 = Button(okno, text="-", width=10, height=3, command=lambda: wpisz("-"))
btn12 = Button(okno, text="=", width=10, height=3, command=oblicz)
btn13 = Button(okno, text="*", width=10, height=3, command=lambda: wpisz("*"))
btn14 = Button(okno, text="/", width=10, height=3, command=lambda: wpisz("/"))
btn15 = Button(okno, text="C", width=10, height=3, command=czysc)

#zrobienie siatki
etykieta.grid(row=0, column=0, columnspan=4)
btn0.grid(row=4, column=1)
btn1.grid(row=3, column=0)
btn2.grid(row=3, column=1)
btn3.grid(row=3, column=2)
btn4.grid(row=2, column=0)
btn5.grid(row=2, column=1)
btn6.grid(row=2, column=2)
btn7.grid(row=1, column=0)
btn8.grid(row=1, column=1)
btn9.grid(row=1, column=2)

btn10.grid(row=4, column=3)
btn11.grid(row=3, column=3)
btn12.grid(row=4, column=2)
btn13.grid(row=2, column=3)
btn14.grid(row=1, column=3)
btn15.grid(row=4, column=0)

okno.mainloop()