#include <iostream>
#include <iomanip>
#include <string>
#define MAX_SIZE 5

class Stack{
    int arrSize;
    int arr[MAX_SIZE];
    //stores the index locaiton of the top value in the stack
    int top;

    public:
        Stack(){
            top = -1;
            //******OPTIONAL************
            //setting all the values of the array to 0
            /* for(int i=0; i<MAX_SIZE; i++)
                arr[i] = 0; */
        }

        //returns true or false whether the stack is empty or not
        bool isEmpty(){
            if(top==-1) return true;
            return false;
        }

        //returns true or false if the stack is full or not
        bool isFull(){
            if(top==MAX_SIZE-1) return true;
            return false;
        }

        //adds an element to the top of the stack
        void push(int data){
            //if the stack is not full
            if(!isFull()){
                top++;
                arr[top] = data;
            }
            else{
                std::cout << "Stack Overflow\n";
            }
        }

        //removes the top element of the stack and returns the top element
        int pop(){
            //if the stack is not empty
            if(!isEmpty()){
                int temp = arr[top];
                arr[top] = 0;
                top--;
                return temp;
            }
            else{
                std::cout << "Stack Underflow\n";
                return 0;
            }
        }

        //returns the amount of elements in the stack
        int count(){
            return top+1;
        }
        
        //returns the value of the stack at a given postion (only returns it does NOT delete it)
        int peek(int position){
            //if the stack is empty
            if(isEmpty()){
                std::cout << "Stack Underflow\n";
                return 0;
            }
            else{
                return arr[position];
            }
        }

        //changing the value inside the stack a certain position
        void change(int data, int pos){
            arr[pos] = data;
            std::cout << "Value changed at position " << pos << std::endl;
        }

        //returns the top element of the stack
        int topStack(){
            //if the list is not empty
            if(!isEmpty()) return arr[top];
        
            return 0;
        }

        //displays the all the elements in the stack
        void display(){
            std::cout << "All values in the stack are:\n";
            if(top!=-1) std::cout << ' ' << std::setw(9) << std::setfill('-') << '-'<< std::endl;
            for(int i=top; i>=0; i--){
                std::cout << '|' << std::setfill(' ') << std::setw(4 + std::to_string(arr[i]).length()) << arr[i]
                << std::setw(6- std::to_string(arr[i]).length()) << '|' << " " << i << std::endl;
                std::cout << ' ' << std::setw(9) << std::setfill('-') << '-'<< std::endl;
            } 
        }

};

int main(){
    Stack s;
    int choice, position, value;

    do
    {
        std::cout << "\nStack Operations: (Press 0 to exit.)\n1.) Push()\n2.) Pop()\n3.) isEmpty()\n4.) isFull()\n5.) peek()\n6.) count()\n7.) change()\n8.) display()\n9.) top()\n10.) Clear Screen\n\n";
        do
        {
            if(std::cin.fail() || choice < 0 || choice > 10){
                std::cin.clear();
                std::cin.ignore(100, '\n');
                std::cout << "Invalid input try again.\n";
            }
            std::cin >> choice;
        } while (std::cin.fail() || choice < 0 || choice > 10);

        switch (choice)
        {
        case 0:
            return 0;
            break;

        case 1:
            std::cout << "Enter a number you want to add to the stack.\n";
            do
            {
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                    std::cout << "Invalid input.\n";
                }
                std::cin >> value;
            } while (std::cin.fail());

            s.push(value);
            break;
        
        case 2:
            value = s.pop();
            std::cout << "The element popped out of the stack was " << value << std::endl;
            break;

        case 3:
            if(s.isEmpty()){
                std::cout << "The stack is empty\n";
            }
            else{
                std::cout << "The stack is not emtpy\n";
            }
            break;

        case 4:
            if(s.isFull()){
                std::cout << "The stack is full\n";
            }
            else{
                std::cout << "The stack is not full\n";
            }
            break;
        
        case 5:
            do
            {
                if(std::cin.fail() || position<0 || position > 4){
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                    std::cout << "Invalid index\n";
                }
                std::cout << "Enter a position in the stack:\n";
                std::cin>> position;
            } while (std::cin.fail() || position<0 || position > 4);
            
            std::cout << "Element at position " << position << " is " << s.peek(position) << std::endl;
            break;
        
        case 6:
            std::cout << "The stack has " << s.count() << " elements\n";
            break;

        case 7:
            std::cout << "Enter a number you want to add to the stack.\n";
            do
            {
                if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                    std::cout << "Invalid input.\n";
                }
                std::cin >> value;
            } while (std::cin.fail());

            do
            {
                if(std::cin.fail() || position<0 || position > 4){
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                    std::cout << "Invalid index\n";
                }
                std::cout << "Enter a position in the stack:\n";
                std::cin>> position;
            } while (std::cin.fail() || position<0 || position > 4);
            s.change(value, position);
            std::cout << "The value at position " << position << " was changed to " << value << std::endl;
            break;

        case 8:
            s.display();
            break;
        
        case 9:
            std::cout << "The top element of the stack is " << s.topStack() << std::endl;
            break;
        
        case 10:
            system("cls");
            break;
        }
         
    } while (choice!=0);
    
    return 0;
}