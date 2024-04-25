# Push_swap 📊
This project is about to write a program that sort numbers in an optimal way (prioritizing the number of movements needed to sort), for this task we need to use 2 stacks and we're allowed to use just some specific movements. The goal of the project is sort the numbers with the minimum number of movements. 
For 100 numbers it should be maximun 600 movements, for 500 numbers it should be less than 5500 movements

## Movements 
The allowed movements are:

* *Swap*: the swap movement will switch the first 2 elements of the stack. 
* *Push*: the push movement will send the 1st element of a stack on top of the other stack. The stack receiving the element will have the received      number as the 1st element and the rest of the elements in the stack will move one position down. 
* *Rotate*: the rotate movement is sending the 1st element of the stack to the last position of the same stack, all the other numbers will move one position up.
* *Reverse rotate*: the reverse rotate movement send the last element of the stack to the top of the stack. All the other numbers will move one position down. 

## Algorithm ⚙️ 💡 
The selected algorithm to solve this problem was: 

The **Turkish Algorithm** https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a

Also used a rule (before/above AVG) to do an initial pre sort before the initial movements. More info here: https://github.com/duarte3333/Push_Swap 

## implementation
The data structure used in this project, were 2 single linked list (Stack_A and Stack_B). The stack_a will have the numbers as they're received from the user in the command line, and the stack_b will be empty at the beginning. After the program runs, both stacks can be used to move numbers between them, but only using the movements mentioned before. 
