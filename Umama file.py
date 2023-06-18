print("\t\tIOT Class")
name="Ali"
City1="Karachi"
City2="Lahore"
Cities=["Karachi","Lahore","Islamabad"]
print(Cities[1])
print(Cities[-3])
Cities.append("Quetta")
print(Cities)
Cities.insert(0,"New York")
print(Cities)
Cities[2]="Houston"
print(Cities)
a=Cities[ : : ]
print(a)
n=Cities[ 0: 2:1 ]
print(n)
b=Cities[ 1:3 : 1]
print(b)
c=Cities[-1 : -6:-1 ]
print(c)
Cities=c
del Cities[1]     #Index batate hai del me 
print(Cities)
Cities.remove("Quetta")  #Remove me string name kom likhre hai
print(Cities)
u=Cities.pop(1)   #Pop ho hai wo delete ke sath usse return bhi krta hai agr aap dekhna chahe to   
print(u)              #you can see your delete variable
print(Cities)

for i in range(1,11):
  print("2 x",i," =",2*i)

print("Table")
no= int(input("Enter any no."))
end=int(input("Enter the ending your table"))
for i in range(1,end+1):
  print(no," x",i," =",no*i)
print("\n")  
all_cities=["Karachi","Islamabad","Lahore"]
City="Karachi"
for i in all_cities:
    if (i==City):
        print(i,"is clean city")
    else:
        print(i,"is not a clean city")
#write a program to reverse an integer in python      
a="12345"
a=a[: :-1]
print(a)

#Write a program who checksthe value is armstrong or not? 
a=str(input("Enter any integer = "))  #Taking input in string 
n=len(a)                           #length store in n  (i.e 371=3)
result=0
for i in a:                        #string jitna hoga utne baar chalega(i.e 371enter kiya isse teen no?index mile 3 baar chalega loop)
    result=result+int(i)**n          #result=0+3power3,result=27+7power3,result=370+1power3
print(result)
if(result==int(a)):  #371==371
    print("Armstrong No.")
else:
    print("Not Armstrong No.")



