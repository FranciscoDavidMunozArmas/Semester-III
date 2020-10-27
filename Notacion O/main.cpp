#include <iostream>

#include "Libraries/Menu.cpp"

#include "O(1).cpp"
#include "O(log_n).cpp"
#include "O(n).cpp"
#include "O(n-2).cpp"

using namespace std;

void menu(bool* _flag);
int _option();

void menu(bool* _flag) {
    switch (_option()) {
    case 1:
    {
        system("cls");
        Order_1_ _o_1;
        _o_1._run(10);
        _o_1._run(1000);
        _o_1._run(100000);
        _o_1._run(10000000);
    }
        break;
    case 2:
    {
        system("cls");
        Order_n_ _o_n;
        _o_n._run(1);
        _o_n._run(10);
        _o_n._run(100);
    }
        break;
    case 3:
    {
        system("cls");
        O_log_n_ _o_log_n;
        _o_log_n._run(10);
        _o_log_n._run(1000);
        _o_log_n._run(100000);
        _o_log_n._run(10000000);
    }
        break;
    case 4:
    {
        system("cls");
        Order_N_2 _o_n_2;
        _o_n_2._run(2);
        _o_n_2._run(4);
        _o_n_2._run(8);
    }
        break;
    default:
        *_flag = false;
        cout << endl;
        break;
    }
    system("pause");
}

int _option() {
    Menu _menu;
    char** _options = (char**)malloc(5*sizeof(char*));
    *(_options + 0) = "O(1)";
    *(_options + 1) = "O(n)";
    *(_options + 2) = "O(log(n))";
    *(_options + 3) = "O(n^2)";
    *(_options + 4) = "SALIR";

    return _menu.options_vetical(_options, 5, 1, 1);
}

int main()
{
    bool flag = true;
    do {
        system("cls");
        menu(&flag);
    } while (flag);
    system("cls");
}

