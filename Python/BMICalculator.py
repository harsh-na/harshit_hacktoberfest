def BMI(height, weight):
    bmi = weight/(height**2)
    return bmi
 
# Driver code
height = float(input("Enter your height in metres: ))
weight = float(input("Enter your weight in kilograms: ))
 
# calling the BMI function
bmi = BMI(height, weight)
print("The BMI is", format(bmi), "so ", end='')
 
# Conditions to find out BMI category
if (bmi < 18.5):
    print("underweight")
 
elif ( bmi >= 18.5 and bmi < 24.9):
    print("Healthy")
 
elif ( bmi >= 24.9 and bmi < 30):
    print("overweight")
 
elif ( bmi >=30):
    print("Suffering from Obesity")
