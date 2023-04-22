#include <iostream>
#include <queue>

class Order {
    private:
        int orderTime;
        int durationToComplete;
        int id;
    public:
        Order(int orderTime, int durationToComplete) {
            this->orderTime = orderTime;
            this->durationToComplete = durationToComplete;
        }
        
        int getTimeOrderedAT() {
            return orderTime;
        }
        int getDurationToComplete() {
            return durationToComplete;
        }
        int getId(){
            return id;
        }
        void setId(int id) {
            this->id = id;
        }
};

class Restaurant {
    private:
        std::queue<Order> orders;
        int closingTime;
        int currentTime = 0;
        int biggestOrder = 0;
        std::queue<Order> overTimeOrders;
        std::queue<Order> inProgessOrdersAfterClosing;

    public:
        Restaurant(int closingTime) {
            this->closingTime = closingTime;
            std::cout<<"Restaurant is open until "<<closingTime<<std::endl;
        }

        void PushNewOrder(Order order) {
            if (order.getDurationToComplete() > biggestOrder && order.getTimeOrderedAT() < closingTime) {
                biggestOrder = order.getDurationToComplete();
            }
            order.setId(orders.size() + 1);
            orders.push(order);
        }

        void printCompletionTime() {
            std::queue <Order> temp = orders;
            int time = currentTime;
            int orderCount = 1;
            while (!temp.empty()) {
                Order order = temp.front();
                temp.pop();
                int actualCompletionTime;
                int expectedCompletionTime = order.getTimeOrderedAT() + order.getDurationToComplete();
                if (order.getTimeOrderedAT() - time > 0) {
                    std::cout<<"The chef takes a break between the times "<<time<<" and "<<order.getTimeOrderedAT()<<std::endl;
                    time += order.getTimeOrderedAT() - time;
                    actualCompletionTime = time + order.getDurationToComplete();
                }
                else {
                    actualCompletionTime = time + order.getDurationToComplete();
                }
                if (order.getTimeOrderedAT() > this->closingTime) {
                    this->overTimeOrders.push(order);
                }
                if (expectedCompletionTime > this->closingTime && order.getTimeOrderedAT() < this->closingTime) {
                    this->inProgessOrdersAfterClosing.push(order);
                }
                std::cout<<"Order "<<orderCount<<": expected completion time: "<<expectedCompletionTime<<", actual completion time: "<<actualCompletionTime<<std::endl;
                time += order.getDurationToComplete();
                orderCount++;
            }
        }
        

        int getBiggestOrder() {
            return this->biggestOrder;
        }

        void printOverTimeOrders() {
            std::queue <Order> temp = overTimeOrders;
            while (!temp.empty()) {
                Order order = temp.front();
                temp.pop();
                std::cout<<"Order "<<order.getId()<<" cannot be completed because it was received after closing the store!"<<std::endl;
            }
        }

        void printInProgressOrdersAfterClosing() {
            std::queue <Order> temp = inProgessOrdersAfterClosing;
            while (!temp.empty()) {
                Order order = temp.front();
                temp.pop();
                std::cout<<"Order "<<order.getId()<<" was in progress when the restaurant should've closed."<<std::endl;
            }
        }
};

int main() {

    int closingTime;
    int orderCount;

    std::cout<<"Enter data orderCount and closingTime"<<std::endl;
    std::cin >> orderCount >> closingTime;
    Restaurant restaurant(closingTime);

    for (int i = 0; i < orderCount; i++) {
        std::cout<<"Enter data from order "<<i<<" in the format: orderTime durationToComplete"<<std::endl;
        // randomize order time and duration
        int orderTime, durationToComplete;
        std::cin >> orderTime >> durationToComplete;
        Order order(orderTime, durationToComplete);
        restaurant.PushNewOrder(order);
    }
    std::cout<<std::endl;
    restaurant.printCompletionTime();
    std::cout<<std::endl<<"The biggest order the chef has completed took : "<<restaurant.getBiggestOrder()<<" hours"<<std::endl;
    std::cout<<std::endl;
    restaurant.printInProgressOrdersAfterClosing();
    std::cout<<std::endl;
    restaurant.printOverTimeOrders();
    return 0;
}
