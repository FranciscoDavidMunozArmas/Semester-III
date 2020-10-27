#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

class ID {
public:
    bool ID_verificator(string ID) {
        if (!check_number(ID)) {
            return false;
        }

        if (ID.length() != 10) {
            return false;
        }

        char province[2] = { ID[0] , ID[1] };
        if (!is_between(0,to_int(province),24)) {
            return false;
        }
;
        if (!is_between(-1, to_int(ID[2]), 6)) {
            return false;
        }

        if (!check_last_digit(ID)) {
            return false;
        }

        return true;
    }

protected:
    bool check_number(string string_1) {
        for (char aux: string_1) {
            if (!isdigit(aux)) {
                return false;
                break;
            }
        }
        return true;
    }

    int to_int(char* num) {
        try {
            return atoi(num);
        }
        catch (std::invalid_argument& e) {
            cout << "Error" << endl;
        }
    }

    int to_int(char num) {
        try {
            return num - '0';
        }
        catch (std::invalid_argument& e) {
            cout << "Error" << endl;
        }
    }

    bool is_between(int min, int num, int max) {
        return (min < num < max);
    }

    int next_ten(int num) {
        while (num%10) {
            num++;
        }
        return num;
    }

    bool check_last_digit(string ID) {
        int check_number = 0;
        for (int i = 0; i < ID.length() - 1; i++) {
            if (i % 2) {
                check_number += to_int(ID[i]);
            }
            else {
                int number = to_int(ID[i]) * 2;
                if (number >= 10) {
                    check_number += number - 9;
                }
                else {
                    check_number += number;
                }
            }
        }

        if ((next_ten(check_number) - check_number) != to_int(ID[9])) {
            return false;
        }

        return true;
    }
};

class RUC: public ID {
public:
    bool RUC_verificator(string RUC) {
        
        if (!check_number(RUC)) {
            return false;
        }

        if (RUC.length() != 13) {
            return false;
        }

        char province[2] = { RUC[0], RUC[1] };
        if (!is_between(0, to_int(province),24)) {
            return false;
        }

        switch (to_int(RUC[2])) {
            case 6:
                if (!check_for_6(RUC, 3, 2, 7, 6, 5, 4, 3, 2)) {
                    return false;
                }
                break;
            case 9:
                if (!check_for_9(RUC, 4,3,2,7,6,5,4,3,2)) {
                    return false;
                }
                break;
            default:
                if (!is_between(-1, to_int(RUC[2]), 6)) {
                    return false;
                }
                string ID;
                for (int i = 0; i < 10; i++) {
                     ID += RUC[i];
                }
                if (!check_last_digit(ID)) {
                    return false;
                }
                break;
        }

        char last[3] = {RUC[10], RUC[11], RUC[12]};
        if (!last_digits(last)) {
            return false;
        }

        return true;
    }

private:

    bool check_for_6(string RUC, int coef_1, int coef_2, int coef_3, int coef_4, int coef_5, int coef_6, int coef_7, int coef_8) {
        int check_number = 0;
        for (int i = 0; i < 8; i++) {
            switch (i) {
            case 0:
                check_number += to_int(RUC[i]) * coef_1;
                break;
            case 1:
                check_number += to_int(RUC[i]) * coef_2;
                break;
            case 2:
                check_number += to_int(RUC[i]) * coef_3;
                break;
            case 3:
                check_number += to_int(RUC[i]) * coef_4;
                break;
            case 4:
                check_number += to_int(RUC[i]) * coef_5;
                break;
            case 5:
                check_number += to_int(RUC[i]) * coef_6;
                break;
            case 6:
                check_number += to_int(RUC[i]) * coef_7;
                break;
            case 7:
                check_number += to_int(RUC[i]) * coef_8;
                break;
            }
        }

        if (get_module(check_number, 11) != to_int(RUC[8])) {
            return false;
        }

        return true;
    }

    bool check_for_9(string RUC, int coef_1, int coef_2, int coef_3, int coef_4, int coef_5, int coef_6, int coef_7, int coef_8, int coef_9) {
        int check_number = 0;
        for (int i = 0; i < 9; i++) {
            switch (i) {
            case 0:
                check_number += to_int(RUC[i]) * coef_1;
                break;
            case 1:
                check_number += to_int(RUC[i]) * coef_2;
                break;
            case 2:
                check_number += to_int(RUC[i]) * coef_3;
                break;
            case 3:
                check_number += to_int(RUC[i]) * coef_4;
                break;
            case 4:
                check_number += to_int(RUC[i]) * coef_5;
                break;
            case 5:
                check_number += to_int(RUC[i]) * coef_6;
                break;
            case 6:
                check_number += to_int(RUC[i]) * coef_7;
                break;
            case 7:
                check_number += to_int(RUC[i]) * coef_8;
                break;
            case 8:
                check_number += to_int(RUC[i]) * coef_9;
                break;
            }
        }

        if (get_module(check_number, 11) != to_int(RUC[9])) {
            return false;
        }

        return true;
    }

    bool last_digits(char* digits) {
        return (0 <= to_int(digits) && to_int(digits) <= 3);
    }

    int get_module(int num, int den) {
        return den - (num % den);
    }
};

int main(){
    ID id;
    cout << id.ID_verificator("1818181818") << endl;

    RUC ruc;
    cout << ruc.RUC_verificator("1790085783001") << endl;
    cout << ruc.RUC_verificator("1760001040001") << endl;
    cout << ruc.RUC_verificator("0604704015001") << endl;
}