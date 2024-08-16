
class Stack:

    def __init__(self, max_size):

        self.data = [0] * max_size
        self.max_size = max_size
        self.pointer = 0


    def is_full(self):

        return self.pointer == self.max_size

    def is_empty(self):

        return self.pointer == 0

    def push(self, value):

        if self.is_full(): return False

        self.data[self.pointer] = value
        self.pointer += 1

        return True

    def pop(self):

        if self.is_empty(): return (False, 0)

        self.pointer -= 1
        
        return (True, self.data[self.pointer])

    

stack = Stack(6)

for i in range(10):

    if not stack.push(i):

        print("Stack is Full!")
        break

    print("Push -> ", i)

while True:

    (success, value) = stack.pop()

    if not success:

        print("Stack is Empty!")
        break

    print("Pop -> ", value)
