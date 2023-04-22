# 🚀 The One Chef Problem Challenge 🤔

This project is a solution to the One Chef Problem where we have to organize orders using queues.

**The challenge is to solve the problem by using a queue data structure.**

# 📝 The Problem

We have opened a restaurant, but we only have one chef. In this restaurant, we use queues to
organize the orders that come in. Each order is represented by two numbers: the time t (at
which the client comes in and places the order) and the duration d (time taken for our chef to
prepare the dish). The orders received will be sorted by their arrival time t. When the dish is
ready, we eliminate the order from our queue and the chef begins working on the next (if
there is one). The restaurant closes at the time T.

Using a Queue:

a) (0.5p) Choose a convenient method of storing the orders (arrival time and duration) -
e.g. a struct or a class. Read from the keyboard two numbers - N and T - and then the
N orders.

b) (0.75p) Print all the times at which the queue is empty and our chef can take a
breather. As an alternative, print these times as intervals. Only print values inside the
working time of the restaurant (before time T).

c) (0.5p) Print the maximum duration our chef has to work on a single order.

d) (0.75p) For each order, print the theoretical completion time (that the client hoped for)
and the actual completion time (when our chef will finally complete the client’s dish).

e) (0.5p) Determine if there are orders that remain incomplete after the closing time of
the restaurant OR orders that are completed after the closing time.

# 💻 The Solution

To solve this problem, we create a class Order with orderTime, durationToComplete, and id as its private members. We then create another class Restaurant that stores orders in a queue, and other data such as closingTime, currentTime, biggestOrder, overTimeOrders, and inProgressOrdersAfterClosing.

In Restaurant, we have methods such as PushNewOrder to add new orders, printCompletionTime to print the completion time for each order, getBiggestOrder to get the maximum duration our chef has to work on a single order, printOverTimeOrders to print orders that remain incomplete after the closing time, and printInProgressOrdersAfterClosing to print orders that are completed after the closing time.

The printCompletionTime method prints the completion time for each order, including the theoretical completion time and actual completion time. If there is a gap between orders, we print the time the chef can take a break. If an order is received after the closing time, we add it to the overTimeOrders queue. If an order is in progress when the restaurant should've closed, we add it to the inProgressOrdersAfterClosing queue.

# 🚀 Quick Start

    git clone https://github.com/lexofficial29/RestaurantQueue.git
    cd RestaurantQueue
    g++ main.cpp -o main
    ./main
