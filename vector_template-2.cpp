#include<iostream>
#include<string>
#include<vector>
#include <iomanip>
#include <algorithm>

template <typename T> class Item{
    public:
        T name;
        T expiration;
        T category;
        int quantity;
        Item(T n, T e, T c, int q){
            name = n;
            expiration = e;
            category = c;
            quantity = q;
        }
};
template<typename T> class Inventory{
    public:
        // Write Your code 

    void addNewItem(const Item<T>& newItem) {
        items.push_back(newItem);
    }

    void increaseQuantity(const T& itemName, int increaseQuantity) {
        for (auto& item : items) {
            if (item.name == itemName) {
                item.quantity += increaseQuantity;
                std::cout<< "updated quantity " << itemName << ": " << item.quantity << std::endl;
                return;
            }
        }
        std::cout << "Item " << itemName << " not found." << std::endl;
    }

    void updateItem(const T& itemName, const T& newExpiration, const T& newCategory, int newQuantity) {
        for (auto& item : items) {
            if (item.name == itemName) {
                item.expiration = newExpiration;
                item.category = newCategory;
                item.quantity = newQuantity;
                std::cout << "upated item: " << itemName << std::endl;
                return;
            }
        }
        std::cout << "Item " << itemName << " not found." << std::endl;
    }

    void removeItem(const T& itemName) {
        auto it = std::remove_if(items.begin(), items.end(), 
            [&itemName](const Item<T>& item) {
                return item.name == itemName;
    });
        
        if (it != items.end()) {
            items.erase(it, items.end());
        }
    }

    int Total() {
        int totalQuantity = 0;
        for (const auto& item : items) {
            totalQuantity += item.quantity;
            std::cout << "Total Number of Items in inventory = " << totalQuantity << "\n";
        }
        return totalQuantity;
    }

    void searchItem(const T& itemName) {
        for (const auto& item : items) {
            if (item.name == itemName) {
                std::cout << "Item found: " << std::endl;
                std::cout << "Name: " << item.name << std::endl;
                std::cout << "Expiration: " << item.expiration << std::endl;
                std::cout << "Quantity: " << item.quantity << std::endl;
                std::cout << "Category: " << item.category << std::endl;
                return;
            }
        }
        throw std::runtime_error("Item not found!!" );
    }

        void displayItems(){
            std::cout<<"-------Inventory-------"<<std::endl;
            std::cout<<std::left<<std::setw(20)<<"Name"<<std::setw(15)<<"Expiration"<<std::setw(15)<<"Quantity"<<std::setw(10)<<"Category"<<std::endl;
            for(int i=0; i<items.size();i++){
                std::cout<<std::left << std::setw(20)<<items[i].name<<std::setw(15)<<items[i].expiration<<std::setw(15)<<items[i].quantity<<std::setw(15)<<items[i].category<<std::endl;
            }
        }

    private:
        std::vector<Item<T>> items;

};





template<typename T>class Appointment{
    public: 
        T c_name;
        T ap_date;
        T ap_time;
        T CWID;
        Appointment(T n, T d, T t, T cw){
            c_name = n;
            ap_date = d;
            ap_time = t;
            CWID = cw; 
        }
};
template<typename T>class AppointmentSystem{
        public:

        void schedule(const Appointment<T>& appointment) {
        for (const auto& ap : appts) {
            if (ap.CWID == appointment.CWID) {
                std::cout << "You have already scheduled an appointment!!!" << std::endl;
                return;
            }
        }
        appts.push_back(appointment);

    }

        int Total_appointments(const T& date, const T& time) {
        int count = 0;
        for (const auto& ap : appts) {
            if (ap.ap_date == date && ap.ap_time == time) {
                count++; 
            }
        }
        return count;
    }

    void removeRecent() {
        if (appts.empty()) {
            std::cout << "No appointments to remove! " << std::endl;
            return;
        }
        appts.pop_back();
    }


        void display(){
            std::cout <<"-------Appointments-------"<<std::endl;
            std::cout << std::left << std::setw(20) << " Name "
                      << std::setw(15) << "Date"
                      << std::setw(15) << "Time"
                      << std::setw(15) << "CWID" << std::endl;
            for (int i=0; i<appts.size();i++){
                std::cout<<std::left << std::setw(20) << appts[i].c_name << std::setw(15) << appts[i].ap_date << std::setw(15) << appts[i].ap_time << std::setw(15) << appts[i].CWID << std::endl;
            }
        }
        private:
            std::vector<Appointment<T>> appts;
};


int main(){

    Inventory<std::string> i1;
    Item<std::string> I1("Protien Bar","05/09/2023","Snacks",4);
    i1.addNewItem(I1);
    Item<std::string> I2("Milk","05/12/2023","Regular",2);
    i1.addNewItem(I2);
    Item<std::string> I3("Cerels","09/12/2023","Snacks",5);
    i1.addNewItem(I3);
    i1.displayItems();
    i1.updateItem("Milk","09/24/2023","Regular",3);
    i1.displayItems();
    i1.increaseQuantity("Cerels",10);
    i1.displayItems();
    try{
        i1.updateItem("bar","09/12/2023","Snacks",3);
    }
    catch(const char* msg){
        std::cout <<msg << std::endl;
    }
    i1.displayItems();
    i1.updateItem("Cerels","09/27/2023","Regular",4);
    i1.displayItems();
    i1.Total();
    try{
        i1.removeItem("Bread");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    try{
        i1.removeItem("Milk");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    i1.displayItems();
    try{
        i1.searchItem("Cerels");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    Appointment<std::string> a1("John Bob","09/12/2023","9:30AM","889456723");
    Appointment<std::string> a2("Jim Lee","09/12/2023","10:30AM","883476923");
    Appointment<std::string> a3("Chris Lynn","09/12/2023","12:00PM","879455714");
    Appointment<std::string> a4("Arnav Shah","09/12/2023","12:00PM","879459583");
    AppointmentSystem<std::string> s1;
    s1.schedule(a1);
    s1.schedule(a2);
    s1.schedule(a3);
    s1.schedule(a4);
    s1.display();
    s1.Total_appointments("09/12/2023","12:00PM");
    Appointment<std::string> a5("Chris Lynn","09/12/2023","12:00PM","879455714");
    s1.schedule(a4);
    s1.removeRecent();
    s1.display();
};