#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct fridge{
    vector<string> getr;
    int getr_limit = 4;
    vector<string> verfg_getr = {"Cola", "Wasser", "Mate", "Ginger Ale"};

    vector<string> sk;
    int sk_limit = 6;
    vector<string> verfg_sk = {"Haribo", "Schokolade", "Kaugummi"};

    vector<string> sp;
    int sp_limit = 1;
    vector<string> verfg_sp = {"Kaese", "Wurst"};

    void einkauf(string was, string womit, int wieviel){
        if(was =="Getraenke"){
            if(womit == "Cola" || womit=="Wasser" || womit == "Mate" || womit == "Ginger Ale"){
                if(getr.size()+wieviel <= 4){
                    for(int i=0; i<wieviel; ++i)
                        getr.push_back(womit);
                } else {
                    std::cout << "Passt nicht mehr rein\n";
                }
            } else {
                std::cout << "Nicht verfuegbar" << std::endl;
            }
        }else if(was == "Suessigkeiten"){
            if(sk.size()+wieviel <= 6){
                for(int i=0; i<wieviel; ++i)
                    sk.push_back(womit);
            } else {
                std::cout << "Passt nicht mehr rein";
            }

        }else if(was == "Special"){
            if(sp.size()+wieviel <= 1){
                for(int i=0; i<wieviel; ++i)
                    sp.push_back(womit);
            } else {
                std::cout << "Passt nicht mehr rein";
            }
        } else {
            std::cout << "Gibts nicht." << std::endl;
        }

    }

    void freezer_anzeigen(){
        std::cout << "Getraenke: ";
        for(auto item: getr)
            std::cout << item << " ";
        std::cout << "\n";

        std::cout << "Suessigkeiten: ";
        for(auto item: sk)
            std::cout << item << " ";
        std::cout << "\n";

        std::cout << "Special: ";
        for(auto item: sp)
            std::cout << item << " ";
        std::cout << "\n";
    }

};

struct items{

};


int main(){

    string was;
    string womit;
    int wieviel;
    fridge myfridge;

    while(true){
        std::cout << "Was einkaufen (Getraenke, Suessigkeiten, Special): ";
        std::cin >> was;
        std::cout << "Was Genau: ";
        std::cin >> womit;
        std::cout << "Wie viel: ";
        std::cin >> wieviel;

        myfridge.einkauf(was, womit, wieviel);
        myfridge.freezer_anzeigen();
    }


    return 0;
}