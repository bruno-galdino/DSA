class Stack {
  constructor(max_size) {
    this.data = new Array(max_size);
    this.max_size = max_size;
    this.pointer = 0;
  }

  isFull() {
    return this.pointer == this.max_size;
  }

  isEmpty() {
    return this.pointer == 0;
  }

  push(value) {
    if (this.isFull()) return false;
    this.data[this.pointer++] = value;
    return true;
  }

  pop() {
    if (this.isEmpty()) return { success: false, value: 0 };
    return { success: true, value: this.data[--this.pointer] };
  }
}

stack = new Stack(6);

for (i = 0; i < 10; i++) {
  if (!stack.push(i)) {
    console.log("Stack is Full!");
    break;
  }

  console.log("Push -> ", i);
}

while (true) {
  let { success, value } = stack.pop();

  if (!success) {
    console.log("Stack is Empty!");
    break;
  }

  console.log("Pop -> ", value);
}
