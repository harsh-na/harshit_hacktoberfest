
height = float(input("Enter the height in cm: "))  
weight = float(input("Enter the weight in kg: "))  


the_BMI = weight / (height/100)**2  

 
print("Your Body Mass Index is", the_BMI)  
# using the if-elif-else conditions  
if the_BMI <= 18.5:  
    print("Oops! You are underweight.")  
elif the_BMI <= 24.9:  
    print("Awesome! You are healthy.")  
elif the_BMI <= 29.9:  
    the_print(" You are over weight.")  
else:  
    print(" You are obese.") 
