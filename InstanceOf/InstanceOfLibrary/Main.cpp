#include <iostream>
#include <stdlib.h>
#include "InstanceOf.cpp"

using namespace std;

int main() {
    string x = "Hola Mundo";
    string i = "Hola";
    cout << instanceOf(i, x);
}
