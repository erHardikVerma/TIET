password=input("enter password");
f=False;
g=False;
h=False;
j=False;

for i in password:
    if i.isupper():
        f=True;
    elif i.islower():
        h=True;
    elif i.isdigit():
        g=True;
    elif i in ['$','#','@']:
        j=True;
if len(password)>=6 and len(password)<=16 and f and g and h and j:
    print("password is valid");
else:
    print("password is invalid");
