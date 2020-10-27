/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Declaration of Knapsack
*/

#ifndef KNASPSACK_H
#define KNASPSACK_H

#include "Knapsack_Item.h"
#include "Libraries/Array_dinamic.h"

class Knapsack
{
public:
    Knapsack();
    Knapsack(double max_weight);
    //Knapsack(double max_weight, int _max_value);
    double _fill_pack(int item_index, double _weight);
    //double _fill_pack(int item_index, double _weight, int* _combination);
    //double _fill_pack(int item_index, int _value, int* _combination);
    double _get_max_weight();
    void _set_item(Knapsack_Item _new_item);
    void _sort_backpack();
    void _start_Knapsack();

    ~Knapsack();
protected:
private:
    double max_weight;
    //int _max_value;
    Knapsack_Item* _backpack;
    //Knapsack_Item* _final_backpack;
    Array_dynamic _ad;
    //template<typename T>
    //double _get_max(T var_1, T var_2);
};

#endif
