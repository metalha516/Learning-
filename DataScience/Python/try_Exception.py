try:
    age = int(input("enter number"))
    print(age/0)
except ZeroDivisionError:
    print("age can't be 0")
    