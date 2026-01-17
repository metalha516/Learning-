#basic class 
class Point:
    def move(self):
        print("move")
    def draw(self):
        print("Draw")

p1 = Point()
p1.draw()

#constructor 

class Student:
    def __init__(self, name, id):
        self.name = name
        self.id = id
    
    def details(self):
        print(f"Name : {self.name} and ID : {self.id}")

Std_1 = Student("Talha", 1016)
Std_1.details()

#Inheritance 
class Mammal:
    def walk(self):
        print("Walking")
    
class Dog(Mammal):
    def bark(self):
        print("Bow Bow")
        
Dog_1 = Dog()
Dog_1.walk()
Dog_1.bark()