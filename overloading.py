class Employee:
    no_of_leaves = 8
    def __init__(self, aname, asalary, arole):
        self.name = aname
        self.salary = asalary
        self.role = arole
    def printdetails(self):
        return f"The name is {self.name}.Salary is {self.salary}.Role is {self.role}"
    @classmethod
    def change_leaves(cls, new_leaves):
        cls.no_of_leaves = new_leaves

    def __add__(self, other):
        return self.salary + other.salary

    def __truediv__(self, other):
        return self.salary / other.salary    

    def __repr__(self):
        return f"Employee('{self.name}',{self.salary},'{self.role}')"    

emp1 = Employee("Harry", 344, "Student")
emp2 = Employee("Rohan", 543, "Officer")     

# print(emp1/emp2)
print(emp1)




