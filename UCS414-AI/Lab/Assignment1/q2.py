basic=int(input("enter the basic salary"));
gross=0;
if basic<=10000:
    gross=basic+0.2*basic+0.8*basic;
    print("the gross salary is----->"+str(gross));5
elif basic>10000 and basic<=20000:
    gross=basic+0.25*basic+0.9*basic;
    print("the gross salary is----->"+str(gross));
elif basic>20000:
    gross=basic+0.3*basic+0.95*basic;
    print("the gross salary is----->"+str(gross));
else:
    print("enter valid number");
