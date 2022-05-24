#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "OrgChart.hpp"
using namespace ariel;

int main() {
    OrgChart organization;
    organization.add_root("RMA");
    organization.add_sub("RMA","Benzema");
    organization.add_sub("RMA","Vini");
    organization.add_sub("RMA","Modric");
    organization.add_sub("Benzema","Mbappe");
    organization.add_sub("Modric","Valverde");
    /*
     *           RMA
     * |          |        |
     * Benzema   Vini    Modric
     * |                  |
     * Mbappe              Valverde
     */
    cout << "\n-----------BASIC PRINT-------------\n" << endl;
    cout << organization << endl;
    cout << "\n-----------LEVEL ORDER-------------\n" << endl;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        cout << (*it) << " " ;
    }
    cout << "\n\n-----------REVERSE ORDER-------------\n" << endl;
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
        cout << (*it) << " " ;
    }

    cout << "\n\n-----------PRE_ORDER-------------\n" << endl;
    for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
        cout << (*it) << " " ;
    }
    cout << "\n-----------DONE-------------\n" << endl;

}