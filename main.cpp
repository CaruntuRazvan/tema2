#include <iostream>
#include <memory>
#include <vector>
#include "cmake-build-debug/IOStream.h"
#include "cmake-build-debug/IoBase.h"
#include "cmake-build-debug/Proprietate.h"
#include "cmake-build-debug/Casa.h"
#include "cmake-build-debug/Apartament.h"
#include "cmake-build-debug/Contract.h"
#include "cmake-build-debug/Exception1.h"
#include "cmake-build-debug/Exception2.h"

using namespace std;


class BaseMenu {
public:
    virtual void listOptions() {}

    virtual int chooseOption(int first, int last) {}

    virtual void mainLoop() {}
};

class SimpleMenu : public BaseMenu {
private:
    vector<shared_ptr<Contract> > contracte;
    vector<shared_ptr<Proprietate> > proprietatiDinContract;
public:
    void listOptions()  override {
        cout << "1. Citire n proprietati sau a n contracte." << '\n';
        cout << "2. Afisare n proprietati sau n contracte grupate dupa tip." << '\n';
        cout << "3. Gata" << '\n';
    }

    int chooseOption(int first, int last) override {
        int option = -1;
        while (option < first || option > last) {
            cout << '\n';
            cout << "Pentru a rula comanda, alegeti un numar intre "
                 << first << " si " << last << '\n';
            listOptions();
            cout << "Alegere: ";
            cin >> option;
        }
        return option;
    }

    void citire() {
        int n;
        int tip1;
        int tip2;
        cout << "Ce doriti sa adaugati? Introduceti 1 pentru proprietati si 2 pentru contracte.\n";
        while(true){
            try{
                cin >> tip1;
                if(tip1 < 1) throw Exception2();
                else if(tip1 > 2) throw Exception1();
                else break;
            }
            catch (const Exception1& err){
                cout<<err;
            }
            catch (const Exception2& err){
                cout<<err;
            }
        }
        if(tip1 == 1){
            cout << "Cate proprietati doriti sa adaugati?\n";
            cin >> n;
            for (int i = 0; i < n; ++i) {
                cout << "Introduceti 1 pentru casa si 2 pentru apartament.\n";
                while(true){
                    try{
                        cin >> tip2;
                        if(tip2 < 1) throw Exception2();
                        else if(tip2 > 2) throw Exception1();
                        else break;
                    }
                    catch (const Exception1& err){
                        cout<<err;
                    }
                    catch (const Exception2& err){
                        cout<<err;
                    }
                }
                if(tip2 == 1){
                    Casa p;
                    cin >> p;
                    proprietatiDinContract.push_back(make_shared<Casa>(p));
                }else if(tip2 == 2){
                    Apartament p;
                    cin >> p;
                    proprietatiDinContract.push_back(make_shared<Apartament>(p));
                }

            }
        }else if(tip1 == 2){
            cout << "Cate contracte doriti sa adugati?\n";
            cin >> n;

            for (int i = 0; i < n; ++i) {

                Contract c;
                cin >> c;
                cout << "Ce proprietate se stipuleaza in contract?\n";
                cout << "Toate proprietatile libere:\n";
                for (int j = 1; j <= proprietatiDinContract.size(); j++) {
                    cout << j << "." << *proprietatiDinContract[j-1] << '\n';
                }
                int ord;
                cout << "Care dintre cele de mai sus (introduceti nr de ord)\n";
                cin >> ord;
                std::vector<shared_ptr<Proprietate>> aux1 = c.getProprietati();
                aux1.push_back(proprietatiDinContract[ord-1]);
                c.setProprietati(aux1);
                contracte.emplace_back(make_shared<Contract>(c));
            }
        }
    }


    void afisareTip() {
        int tip;
        cout << "Ce doriti sa afisati? Introduceti 1 pentru a vedea toate proprietatile si 2 pentru a vedea toate contractele semnate\n";
        while(true){
            try{
                cin >> tip;
                if(tip < 1) throw Exception2();
                else if(tip > 2) throw Exception1();
                else break;
                }
            catch (const Exception1& err){
                cout<<err;
            }
            catch (const Exception2& err){
                cout<<err;
            }
        }

        if(tip == 1){
            cout << "Case:\n";
            for(const auto &i: proprietatiDinContract){
                shared_ptr<Casa> casa = dynamic_pointer_cast<Casa>(i);
                if(casa)
                    cout << *casa << '\n';
            }
            cout << "Apartamente:\n";
            for(auto i: proprietatiDinContract){
                shared_ptr<Apartament> apartament = dynamic_pointer_cast<Apartament>(i);
                if(apartament)
                    cout << *apartament << '\n';
            }

        }else if(tip == 2){
            cout << "Inch:\n";
            for(auto  i:contracte){
                shared_ptr<Contract> inch = dynamic_pointer_cast<Contract>(i);
                if(inch)
                    cout << *inch << '\n';
            }

        }
    }

    void mainLoop() override {
        while (true) {
            int option = chooseOption(1, 3);
            if (option == 1) {
                citire();
            } else if (option == 2) {
                afisareTip();
            } else if (option == 3) {
                break;
            }
        }
        cout << '\n'
             << "---------------------------------"
             << '\n'
             << "Programul s-a incheiat cu success ";
    }

};

int main() {

    SimpleMenu menu;
    menu.mainLoop();
    return 0;
}