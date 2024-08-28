import os
class Star_Cinema:
    def __init__(self) -> None:
        self._hall_list=[]
    

    def _entry_hall(self,hall):
        self._hall_list.append(hall)

class Hall(Star_Cinema):
    def __init__(self,rows,cols,hall_no) -> None:
        super().__init__()
        self.__seats={}
        self.__show_list=[]    
        self._rows=rows
        self._cols=cols
        self._hall_no=hall_no
        self._entry_hall(self)

    def _entry_show(self,Id,movie_name,time):
        if Id in self.__seats:
            print(f"Show with Id {Id} already exists.")
            return
        show_info=(Id,movie_name,time)
        self.__show_list.append(show_info)
        seats=[['free' for _ in range(self._cols)] for _ in range(self._rows)]
        self.__seats[Id]=seats

    def book_seats(self,Id,booking):
        if not self.__show_list:
            print("No shows are available")
            return
        
        if Id not in self.__seats:
            print(f"No show with id {Id} exicts")
            return
        
        for seat in booking:
            row,col=seat

            if row>=self._rows or col>=self._cols or row<0 or col<0:
                print(f"There is no seat in : {row+1}, {col+1}")
                continue

            if self.__seats[Id][row][col]=='booked':
                print(f"The seat number : {row+1}, {col+1} is already booked")
                continue

            self.__seats[Id][row][col]='booked'
            print(f"The seat no : {row+1}, {col+1} has been booked successfully.")

    def view_show_list(self):
        if not self.__show_list:
            print("No shows are available")
            return
        
        for show in self.__show_list:
            Id, movie_name,time=show
            print(f"Movie Id: {Id}, Movie Name: {movie_name}, Time: {time}, Hall Name: {self._hall_no}")

    def view_available_seats(self,id):
        if not self.__show_list:
            print("No shows are available")
            return
        
        if id not in self.__seats:
            print(f"Invalid ID : {id}")
            return
        
        for row in range(self._rows):
            for col in range(self._cols):
                if self.__seats[id][row][col]=='free':
                    print(f"Seat is available in row : {row}, colum : {col}")
        print("\n\n")

        for row in range(self._rows):
            print("[",end="")
            for col in range(self._cols):
                if self.__seats[id][row][col]=='free':
                    if col==self._cols-1:
                        print("0]")
                    else:
                        print("0",end=" ")
                else:
                    if col==self._cols-1:
                        print("X]")
                    else:
                        print("X",end=" ")


    def count_available_seats(self,id):
        if id not in self.__seats:
            print(f"Invalid ID : {id}")
            return -1
        cnt=sum(row.count('free') for row in self.__seats[id])
        cnt=int(cnt)
        return cnt

def display():
    print("\n-------------Welcome To Star Cineplex-------------------\n")
    print("Option 1: Available Shows List")
    print("Option 2: View Available seats of a show")
    print("Option 3: Book Ticket For show")
    print("Option 4: Log Out")
    print("\nEnter: ",end=" ")


Hall_data=Hall(10,10,"ABC")
Hall_data._entry_show(1,"Avengers: endgame","12.00PM")
booking=[(0,0),(0,1),(0,2)]
Hall_data.book_seats(1,booking)

os.system('clear'if os.name=='nt' else 'clear')

while True:
    display()
    option=input()
    if option=='':
        print("Invalid input. Please enter a number.")
        continue
    option=int(option)
    if option==1:
        Hall_data.view_show_list()

    elif option==2:
        print("Enter Id of the Show:",end=" ")
        x=input()
        if x=='':
            print("You must enter ID")
            continue
        x=int(x)
        availabe_seat=Hall_data.count_available_seats(x)
        if availabe_seat==-1:
            continue
        Hall_data.view_available_seats(x)
        print(f"\nTotal available seats: {availabe_seat}")

    elif option==3:
        print("Enter Id of the Show:",end=" ")
        y=input()
        if y=='':
            print("You must enter ID")
            continue
        y=int(y)
        availabe_seat=Hall_data.count_available_seats(y)
        if availabe_seat==-1:
            continue
        print("Enter The Number OF seats you want to book:",end=" ")
        z=input()
        if z=='':
            print("You must enter the number of seat you want to book")
            continue
        z=int(z)
        if z<=0:
            print("Invalid Input")
        if z > availabe_seat:
            print(f"\nonly {availabe_seat} are available.Unable to book {z} seats")
            continue


        booking=[]
        for i in range(0,z):
            print(f"Enter The Row of the {i+1} Seat:",end=" ")
            row=input()
            if row=='':
                print("You have to input row number for book a seat")
                continue
            row=int(row)

            print(f"Enter The Coloum of the {i+1} Seat:",end=" ")
            col=input()
            if col=='':
                print("You have to input coloum number for book a seat")
                continue
            col=int(col)

            booking.append((row-1,col-1))
        Hall_data.book_seats(y,booking)

    elif option == 4:
        print("Thank You! Bye")
        break

    else:
        print("Invalid")