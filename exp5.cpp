#include <iostream>
#include <stdexcept>

#define MAX_SIZE 100 // Define a maximum size for the stack/queue

class LIST
{
public:
    virtual void store(int value) = 0;
    virtual int retrieve() = 0;
    virtual ~LIST() {}
};

class Stack : public LIST
{
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    void store(int value) override
    {
        if (top >= MAX_SIZE - 1)
        {
            throw std::overflow_error("Stack Overflow");
        }
        arr[++top] = value;
    }

    int retrieve() override
    {
        if (top < 0)
        {
            throw std::underflow_error("Stack Underflow");
        }
        return arr[top--];
    }
};

class Queue : public LIST
{
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() : front(0), rear(-1) {}

    void store(int value) override
    {
        if (rear >= MAX_SIZE - 1)
        {
            throw std::overflow_error("Queue Overflow");
        }
        arr[++rear] = value;
    }

    int retrieve() override
    {
        if (front > rear)
        {
            throw std::underflow_error("Queue Underflow");
        }
        return arr[front++];
    }
};

int main()
{
    LIST *myStack = new Stack();
    LIST *myQueue = new Queue();

    try
    {
        // Using Stack
        myStack->store(10);
        myStack->store(20);
        myStack->store(30);
        std::cout << "Stack retrieve: " << myStack->retrieve() << std::endl; // 30
        std::cout << "Stack retrieve: " << myStack->retrieve() << std::endl; // 20

        // Using Queue
        myQueue->store(10);
        myQueue->store(20);
        myQueue->store(30);
        std::cout << "Queue retrieve: " << myQueue->retrieve() << std::endl; // 10
        std::cout << "Queue retrieve: " << myQueue->retrieve() << std::endl; // 20
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    delete myStack;
    delete myQueue;

    return 0;
}
