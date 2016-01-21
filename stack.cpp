/***********************************************************************
* Program:
*    Assignment 09, Stack  
*    Brother Ercanbrack, CS165
* Author:
*    Jose Ricaurte
* Summary: 
*   Created a Stack class to illustrate the concept of stacks. Used static
* member variables so that all the Stack objects operated on the same stack.
* Included push, pop, lock, unlock functions for a more robust class. Tested
* the fucntionality of the Stack class in main.
************************************************************************/

#include <iostream>
using namespace std;


const int MAX_STACK_SIZE = 15;

/**********************************************************************
 * Stack Class - Consists of manty static variables in order for various
 * Stack objects to share the same stack array. Stack can be locked and
 * unlocked through member functions. Stack can also push and pop. top
 * and next are used by the push and pop functions, while lockOwner is
 * needed for the lock and unlock functions.
 **********************************************************************/

class Stack
{
private:
   bool lockOwner;
public:
   static int top;
   static int next;
   static int stackArray[MAX_STACK_SIZE];
   static bool locked;
   Stack();
   void lock();
   void unlock();
   bool getLockOwner();
   void setLockOwner(bool lockOwnerStatus);
   void push(int num);
   void pop();   
};

int Stack::top = -1;
int Stack::next = 0;
bool Stack::locked = false;
int Stack::stackArray[MAX_STACK_SIZE] = {0};
/**********************************************************************
 * main - creates various Stack objects and test the class's functionality.
 **********************************************************************/
int main (void)
{
   Stack aStack;
   aStack.push (1);
   Stack bStack;
   bStack.push (2);
   Stack cStack;
   cStack.push (3);
   Stack dStack;
   dStack.pop ();
   cStack.pop ();
   dStack.push (4);
   aStack.pop ();
   bStack.unlock ();
   cStack.lock ();
   cStack.push (5);
   aStack.pop ();
   dStack.lock ();
   bStack.unlock ();
   dStack.push (6);
   cStack.unlock ();
   cStack.push (7);
   aStack.pop ();
   dStack.pop ();
   bStack.pop ();
   cStack.pop ();
}

/**********************************************************************
 * Default Constructor - sets lockOwner to false
 *
 **********************************************************************/
Stack::Stack(): lockOwner(false)
{/*Body intentionally empty*/}

/**********************************************************************
 * lock - enables a Stack object to lock the stack, making the object who
 * locked it the lock Owner. Can only lock an unlocked stack.
 **********************************************************************/
void Stack::lock()
{
   if (locked == true)
      cout << "lock failed; stack locked\n";
   else
   {
      locked = true;
      lockOwner = true;
      cout << "lock successful\n";
   }
}

/**********************************************************************
 * unlock - enables a Stack object to unlock the the stack. Can only
 * unlock if object is the lockOwner and stack is locked.
 **********************************************************************/
void Stack::unlock()
{
   if (locked == false)
      cout << "unlock failed; stack not locked\n";
   else if (locked == true && lockOwner == false)
      cout << "unlock failed; not lock owner\n";
   else
   {
      locked = false;
      lockOwner = false;
      cout << "unlock successful\n";
   }
}

/**********************************************************************
 * getLockOwner - getter function for private variable lockOwner.
 * Returns lockOwner.
 *
 **********************************************************************/
bool Stack::getLockOwner()
{
   return lockOwner;
}

/**********************************************************************
 * setLockOwner - setter function for private variable lockOwner. Takes
 * bool argument and assigns to lockOwner.
 **********************************************************************/
void Stack::setLockOwner(bool lockOwnerStatus)
{
   lockOwner = lockOwnerStatus;
}

/**********************************************************************
 * push - takes int argument and assigns it to the next unfilled array
 * element. Only works if not locked OR if it is locked and the calling
 * object is the lockOwner. top keeps track of the last element of the
 * array that was filled. next keeps track of the proceeding empty element
 * to be filled.
 **********************************************************************/
void Stack::push(int num)
{
   if (locked == true && lockOwner == false)
      cout << num << " push failed; stack locked\n";
   else
   {     
      stackArray[next] = num;
      cout << num << " pushed to location " << next << endl;
      top++;
      next++;
      
   }
}

/**********************************************************************
 * pop - Removes the last element of the array that was filled. Can only
 * be called if the stack is unlocked OR the stack is locked and the calling
 * object is the lockOwner. Popping an empty stack outputs an error msg.
 **********************************************************************/
void Stack::pop()
{
   if (locked == true && lockOwner == false)
      cout << "pop failed; stack locked\n";
   else if (next == 0)
      cout << "error: nothing on stack to pop\n";
   else
   {
      cout << stackArray[top] << " popped from location " << top << endl;
      top--;
      next--;
   }
}
      
