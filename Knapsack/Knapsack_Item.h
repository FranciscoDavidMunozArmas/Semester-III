/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Declaration of Knapsack_Item
*/

#ifndef KNAPSACK_ITEM_H
#define KNAPSACK_ITEM_H


class Knapsack_Item
{
public:
    Knapsack_Item(double _item_weight, int _value);
    double _get_item_weight();
    int _get_value();

    ~Knapsack_Item();
protected:
private:
    double _item_weight;
    int _value;
};

#endif
