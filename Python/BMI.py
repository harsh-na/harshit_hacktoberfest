#BMI calculator

w=float(input("Enter wieght in kilograms(kg):: "))
h=float(input("Enter hieght in meters(m):: "))

bmi=w/(h**2)
print("________________________________")
print("BMI -> ",bmi)
print("_________________________________")
print("                                    ")

if bmi<18.5:
    print("Underweight")

elif bmi>=18.5 and bmi<=24.9:
    print("Normal Wieght")


elif bmi>=25 and bmi<=29.9:
    print("Overwieght")
    

elif bmi>=30 and bmi<=34.9:
    print("Obesity Class I")
    

elif bmi>=35 and bmi<=39.9:
    print("Obesity Class II")
    

else:
    print("Obesity Class III")