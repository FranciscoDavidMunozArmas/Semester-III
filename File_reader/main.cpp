#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include "File_reader.cpp"

using namespace std;

class Person{
private:
    int age;
    string name;
    string _id;
public:
    Person();
    Person(int age, string name, string _id);
    int getAge();
    string getName();
    string get_Id();
    string to_string();
};

Person::Person(): age(0), name(""), _id(""){}

Person::Person(int age, string name, string _id){
    this->age = age;
    this->name = name;
    this->_id = _id;
}

int Person::getAge(){
    return age;
}

string Person::getName(){
    return name;
}

string Person::get_Id(){
    return _id;
}

string Person::to_string(){
    std::ostringstream oss;
    oss << "Id: " << _id << "\nName: " << name << "\nAge: " << age;
    return oss.str();
}


//https://stackoverflow.com/questions/15667530/fstream-wont-create-a-file
//https://www.tutorialesprogramacionya.com/cya/detalleconcepto.php?punto=71&codigo=71&inicio=60
//http://jbgarcia.webs.uvigo.es/asignaturas/TO/cursilloCpp/14_archivos.html
//https://algoritmosyalgomas.com/archivos-binarios-en-c-insertar-eliminar-actualizar-listar/
int main()
{
    File_reader fr;
    //fstream file;
    FILE* file;
    Person p(12, "Juan", "0");
    Person p2;
	fr._write_in_file(file,"file.txt",&p);
	fr._read_file(file,"file.txt", &p2);
	//fr._delete_all("file.txt");
    cout << p2.to_string() << endl;

    system("pause");
}
