#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;


struct ShoppingItem{
    string name;
    int amount;
    ShoppingItem(){
        this->name = "__NONAME";
        this->amount = 0;
    }
    ShoppingItem(string init_name){
        this->name = init_name;
        this->amount = 0;
    }
};

class FridgeDrawer{
public:
    string name;
    int limit;
    vector<ShoppingItem> contents;
    ShoppingItem current_item;
    int *current_amount;

    FridgeDrawer(){
        this->name = "__NONAME";
    }

    FridgeDrawer(string initname, int initlimit, vector<ShoppingItem> vecItems){
        this->name = initname;
        this->limit = initlimit;
        this->contents = vecItems;
    }

    void buyDrawer(){
        string buy_what;
        cout << "Product (";
        for(auto item: contents) cout << item.name << ": " << item.amount << ", ";
        cout << "): ";
        cin >> buy_what;

        if(!ValidItem(buy_what)) return;
        SelectItem(buy_what);
        cout << current_item.name << endl;
        cout << current_item.amount << endl;

        int buy_how_much;
        cout << "How much do you want to buy: ";
        cin >> buy_how_much;


        if((current_item.amount + buy_how_much) > (this->limit)){
            cout << "Drawer doesn't have that much space\n";
            return;
        } else {
            (*current_amount) += buy_how_much;
        }

    }

    void show_contents(){
        cout << "(";
        for(ShoppingItem item: contents)
            cout << item.name << ": " << item.amount << ", ";
        cout << ")";
    }

    void SelectItem(string item_name){
        for(auto item: contents){
            if(item_name==item.name){
                current_item = item;
                current_amount = &(item.amount);
                return;
            }
        }
    }

    bool ValidItem(string item_name){
            for(ShoppingItem item: contents){
                if(item_name==item.name){
                    return true;
            }
        }
        cout << "You can't put that item in this drawer.\n";
        return false;
    }
};




class Fridge{
private:
    vector<FridgeDrawer> drawers;
    FridgeDrawer current_drawer;
public:


    Fridge(vector<FridgeDrawer> initdrawers){
        this->drawers = initdrawers;
    }

    void buy_stuff(){
        string buy_more = "Yes";
        while(buy_more != "No"){
            string buy_what_kind;
            cout << "Product category (";
            for(auto drawer: drawers) cout << drawer.name << ", ";
            cout << "): ";
            cin >> buy_what_kind;

            if(!ValidDrawer(buy_what_kind)) continue;
            SelectDrawer(buy_what_kind);

            current_drawer.buyDrawer();

            string buy_more;
            cout << "Buy more? (Yes/No): ";
            cin >> buy_more;
        }
    }

    void show_stuff(){
        for(auto item: this->drawers){
            cout << item.name << ":\n";
            item.show_contents();
        }
    }

    bool ValidDrawer(string drawer_name){
        for(FridgeDrawer drawer: drawers){
            if(drawer_name==drawer.name){
                return true;
            }
        }
        cout << "This fridge does not have that drawer.\n";
        return false;
    }

    void SelectDrawer(string drawer_name){
        for(FridgeDrawer drawer: drawers){
            if(drawer_name==drawer.name){
                current_drawer = drawer;
                return;
            }
        }
    }
};


int main(){
    ShoppingItem coke("Coke");
    ShoppingItem water("Water");
    ShoppingItem club_mate("Mate");
    vector<ShoppingItem> vecBeverages = {coke, water, club_mate};

    FridgeDrawer beverages("Beverages", 10, vecBeverages);
    vector<FridgeDrawer> drawers = {beverages};

    Fridge myfridge(drawers);
    myfridge.buy_stuff();

    return 0;
}






// bool inIntVector(int item, vector<int> vec){
//     for(auto pos = vec.begin(); pos != vec.end(); ++pos){
//         if (*pos == item) return true;
//     }
//     return false;
// }

// void printStrVector(vector<string> vec){
//     cout << "{";
//     for(auto item: vec)
//         cout << item << ", ";
//     cout << "}\n";
// }
