
const STACK_SIZE:usize = 6;

struct Stack {

    data:[i32; STACK_SIZE],
    pointer:usize
}

fn stack_is_full(stack: &Stack) -> bool {

    return stack.pointer == STACK_SIZE;
}

fn stack_is_empty(stack: &Stack) -> bool {

    return stack.pointer == 0;
}

fn stack_push(stack: &mut Stack, number:i32) -> bool {

    if stack_is_full(stack) {
        
        return false;
    }

    stack.data[stack.pointer] = number;
    stack.pointer += 1;

    return true;
}

fn stack_pop(stack: &mut Stack) -> (bool, i32) {

    if stack_is_empty(stack) {
        
        return (false, 0);
    }
    
    stack.pointer -= 1;
    return (true, stack.data[stack.pointer]);

}

fn main(){

    let arr = [1, 2, 3, 4, 5, 6, 7, 8, 9];
    let mut stack = Stack {data:[0;STACK_SIZE], pointer: 0};

    for &value in arr.iter(){

        if !stack_push(&mut stack, value){

            println!("Stack is Full!");
            break;
        }
        println!("push -> {}", value);
    }

    println!("");
    
    loop {

        let (success, value) = stack_pop(&mut stack);

        if !success{

            println!("Stack is Empty!");
            break;
        }

        println!("pop -> {}",value);
    }   
}