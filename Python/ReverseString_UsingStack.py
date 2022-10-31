from collections import deque
class Stack:
    def __init__(self):
        self.container = deque()
    def push(self,val):
        self.container.append(val)
        return val
    def pop(self):
        return self.container.pop()
    def top(self):
        return self.container[-1]
    def length(self):
        return len(self.container)
    
def reverseString(string):
    s = Stack()
    rstr = ''
    for ch in string:
        s.push(ch)
    while s.length() !=0:
        rstr += s.pop()
    return rstr
print(reverseString("Hello world"))



        