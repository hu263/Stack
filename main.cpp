
#include "stack.h"
#include "rainfall.h"
#include "stackAsArray.h"
#include "stackAsLinkedList.h"

#include <iostream>

class Stack;
class Rainfall;
class StackAsLinkedList;

void testCase (Stack& stack)
{
      /* Instantiate a new Rainfall object by using Dynamic Memory Management*/
    Rainfall *rain1 = new Rainfall();
    rain1->setAvgRainfall(2);
    rain1->setMaxRainfall(3);
    rain1->setMinRainfall(1);
    
    /* Instantiate a new Rainfall object by using constructor*/
    Rainfall rain2(4,5,6);

    /* Stack Pushes Rainfall objects into the stack*/
    stack.Push ( *rain1 );
    stack.Push ( rain2 );
    
    /** Print the top item of the stack
     * You should see the result showing below:
     * Rainfall(Min): 5
     * Rainfall(Max): 4
     * Rainfall(Avg): 6
     */
    stack.Top().print();
    
    cout << "\n";
    stack.Pop();

    /** Print the top item of the stack
     * You should see the result showing below:
     * Rainfall(Min): 1
     * Rainfall(Max): 3
     * Rainfall(Avg): 2
     */
    stack.Top().print();

    cout << "\n";

    /* Uncomment the follow code blocks for the task #4*/
    // stack.Pop();
    // /** Print the top item of the stack
    //  * You should see the result showing below:
    //  * Domain_error: stack is empty
    //  */    
    // stack.Top().print();
    // cout << "\n";
}

int main() {
  try{
    /* Instantiate a new StackAsLinkedList object */
    StackAsArray stack1(13);
    /* Instantiate a new StackAsLinkedList object */
    StackAsLinkedList stack2;

    testCase(stack1);
    testCase(stack2);
  }
  catch (const std::domain_error& de) {
	  std::cerr << "Domain_error: " << de.what() << '\n';
  }
  catch (const std::invalid_argument& ia) {
	  std::cerr << "Invalid argument: " << ia.what() << '\n';
  }

  return 0;
} 