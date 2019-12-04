#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int const static BUFFER_SIZE = 100;

int main() {
   // system("chcp 65001");
    set<int> mySet1;
    set<int> mySet2;
    set<int> mySet3;
    int Input;
    int Choise;
    cout << "Выполнить ручной ввод множества?" << endl << "Нажмите 1 если нужен ручной ввод или 0 если не нужен."<< endl;
    cin >> Input;

    switch(Input)
    {
        case 0: {
            ifstream fin;
            char buff[BUFFER_SIZE];
            int num = 0;
            fin.open("note.txt");
            if (fin.is_open()) {
                for (int j = 0; j < 10; j++) {
                    fin.getline(buff, BUFFER_SIZE, ';');
                    for (int k = 0; k < BUFFER_SIZE; k++)
                        if (buff[k] >= '0' && buff[k] <= '9')
                            num = num * 10 + (buff[k] - '0');

                    mySet1.insert(num);
                    mySet2.insert(num);
                    num = 0;
                }
                fin.close();
            } else
                cout << "Ошибка при открытии файла!" << endl;
            break;
        }
        case 1: {
            cout << "Ручной ввод первого множества!" << endl;
            int Ch;
            int Q;
            cout << "Введите мощность множества" << endl;
            cin >> Q;

            for (int i = 0; i < Q; i++) {
                cout << "Введите " << i + 1 << " элемент множества!" << endl;
                cin >> Ch;
                mySet1.insert(Ch);
                Ch = 0;
            }

            Q = 0;
            Ch = 0;

            cout << "Ручной ввод второго множества!" << endl;
            cout << "Введите мощность множества" << endl;
            cin >> Q;

            for (int i = 0; i < Q; i++) {
                cout << "Введите " << i + 1 << " элемент множества!" << endl;
                cin >> Ch;
                mySet2.insert(Ch);
                Ch = 0;
            }
            break;
        }
        default:
            cout << "Были введены неверные данные, невозможно продолжить программу." << endl;
            break;
    }

    cout << "Первое множество" << endl;

    for(auto i : mySet1)
        cout << i << " ";
    cout << endl;

    cout << "Второе множество" << endl;

    for(auto i : mySet2)
        cout << i << " ";
    cout << endl;

    Input = 0;
    cout << "Какую операцию над множествами вы хотете провести? Введите соответствующую цифру!" << endl
         << "1 - Создание пустого множества." << endl << "2 - Вставка элемента в множество." << endl
         << "3 - Удаление элемента из множества." << endl << "4 - Проверка вхождения элемента в множество." << endl
         << "5 - Объединение двух множеств." << endl << "6 - Пересечение двух множеств." << endl
         << "7 - Разность двух множеств." << endl << "8 - Проверка равенства множеств." << endl;

    cin >> Input;

    switch(Input){
        case 1:
            cout << "Какое множество вы хотите обратить в пустое?" << endl
                 << "Введите 1 если первое или 2 если второе." << endl;
            cin >> Choise;
            if(Choise == 1) {
                mySet1.clear();
                mySet1.insert(0);
                cout << "Первое множество" << endl;
                for(auto i : mySet1)
                    cout << i << " ";
                cout << endl;
            }
            if(Choise == 2) {
                mySet2.clear();
                mySet2.insert(0);
                cout << "Второе множество" << endl;
                for(auto i : mySet2)
                    cout << i << " ";
                cout << endl;
            }
            if((Choise < 1) || (Choise > 2))
                cout << "Были введены неверные данные, невозможно продолжить программу." << endl;
            break;
        case 2:
            cout << "В какое множество вы хотите добавить элемент?" << endl
                 << "Введите 1 если в первое или 2 если во второе." << endl;
            cin >> Choise;
            if(Choise == 1) {
                int num;
                cout << "Введите число которое необходимо включить в множество" << endl;
                cin >> num;
                mySet1.insert(num);
                cout << "Первое множество" << endl;
                for(auto i : mySet1)
                    cout << i << " ";
                cout << endl;
            }
            if(Choise == 2) {
                int num;
                cout << "Введите число которое необходимо включить в множество" << endl;
                cin >> num;
                mySet2.insert(num);
                cout << "Второе множество" << endl;
                for(auto i : mySet2)
                    cout << i << " ";
                cout << endl;
            }
            if((Choise < 1) || (Choise > 2))
                cout << "Были введены неверные данные, невозможно продолжить программу." << endl;
            break;
        case 3:
            cout << "В каком множестве вы хотите удалить элемент?" << endl
                 << "Введите 1 если в первом или 2 если во втором." << endl;
            cin >> Choise;
            if(Choise == 1) {
                int del;
                cout << "Какой элемент требуется удались из множества?" << endl;
                cin >> del;
                cout << del << " элемент будет удалён если он имеется в множестве." << endl;
                mySet1.erase(del);
                cout << "Первое множество" << endl;
                for(auto i : mySet1)
                    cout << i << " ";
                cout << endl;
            }
            if(Choise == 2){
                int del;
                cout << "Какой элемент требуется удались из множества?" << endl;
                cin >> del;
                cout << del << " элемент будет удалён если он имеется в множестве." << endl;
                mySet2.erase(del);
                cout << "Второе множество" << endl;
                for(auto i : mySet2)
                    cout << i << " ";
                cout << endl;
            }
            if((Choise < 1) || (Choise > 2))
                cout << "Были введены неверные данные, невозможно продолжить программу." << endl;
            break;
        case 4:
            cout << "В каком множестве вы хотите проверить элемент на принадлежность?" << endl
                 << "Введите 1 если в первом или 2 если во втором." << endl;
            cin >> Choise;
            if(Choise == 1) {
                int find;
                cout << "Какой элемент нужно проверить на вхождение в множество?" << endl;
                cin >> find;
                if (mySet1.find(find) != mySet1.end())
                    cout << "Данный элемент приндлежит множеству." << endl;
                else
                    cout << "Данный элемент не принадлежит множеству." << endl;
                cout << "Первое множество" << endl;
                for(auto i : mySet1)
                    cout << i << " ";
                cout << endl;
            }
            if(Choise == 2) {
                int find;
                cout << "Какой элемент нужно проверить на вхождение в множество?" << endl;
                cin >> find;
                if (mySet2.find(find) != mySet2.end())
                    cout << "Данный элемент приндлежит множеству." << endl;
                else
                    cout << "Данный элемент не принадлежит множеству." << endl;
                cout << "Второе множество" << endl;
                for(auto i : mySet2)
                    cout << i << " ";
                cout << endl;
            }
            if((Choise < 1) || (Choise > 2))
                cout << "Были введены неверные данные, невозможно продолжить программу." << endl;
            break;
        case 5:
            cout << "Объединение двух множеств" << endl;
            for(set<int>::iterator p=mySet1.begin();p!=mySet1.end();++p)
                mySet2.insert(*p);
            for(auto i : mySet2)
                cout << i << " ";
            cout << endl;
            break;
        case 6:
            cout << "Пересечение двух множеств" << endl;
            set_intersection(mySet1.begin(), mySet1.end(), mySet2.begin(), mySet2.end(), inserter(mySet3, mySet3.begin()));
            for(auto i : mySet3)
                cout << i << " ";
            cout << endl;
            break;
        case 7:
            cout << "Разность двух множеств" << endl;
            set_difference(mySet1.begin(), mySet1.end(), mySet2.begin(), mySet2.end(), inserter(mySet3, mySet3.begin()));
            for(auto i : mySet3)
                cout << i << " ";
            cout << endl;
            break;
        case 8:
            cout << "Равенство множеств:" << endl;
            if (equal(mySet1.begin(), mySet1.end(), mySet2.begin(), mySet2.end()) == 1)
                cout << "Множества равны" << endl;
            else
                cout << "Множества не равны" << endl;
            break;
        default:
            cout << "Были введены неверные данные, невозможно продолжить программу." << endl;
            break;
    }

    ofstream fout;
    fout.open("result.txt");
    if (fout) {
        copy(mySet1.begin(), mySet1.end(), std::ostream_iterator<int>(fout, "\n"));
        fout.write("\n", 1);
        copy(mySet2.begin(), mySet2.end(), std::ostream_iterator<int>(fout, "\n"));
        fout.write("\n", 1);
        copy(mySet3.begin(), mySet3.end(), std::ostream_iterator<int>(fout, "\n"));
        fout.write("\n", 1);
    } else
        cout << "Ошибка при открытии файла" << endl;
}