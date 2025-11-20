#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

vector<int> integers{14, 16, 19, 32, 32, 32, 56, 69, 72}; // Массив целых чисел

int binoSearch(vector<int> &numbers, int controlPoint) // Ф-ция поиска больших чисел в массиве;
{
  int leftPoint = 0;                  // начальное значение левой точки - начало массива (0);
  int rightPoint = 0;                 // начальное значение правой точки
  int summaryLength = numbers.size(); // начальное количество элементов - длина массива
  int leftLength = 0;                 // кол-во элементов слева
  int rightLength = 0;                // кол-во элементов справа
  int result = 0;                     // кол-во чисел, больших чем контрольное число

  while (true)
  {
    if (summaryLength == 1) // если оставшаяся длина == 1, то...;
    {
      if (numbers[leftPoint] > controlPoint) //...и если число под левой точкой больше контрольного...;
      {
        result += 1; //...увеличиваем результат на 1...;
        break;       //... и слом цикла;
      };
      if (numbers[leftPoint] <= controlPoint) //...а если число под левой точкой не больше контрольного...;
      {
        result += 0; // результат не меняется...;
        break;       //...и слом цикла;
      };
    };
    /*рассчитываем поля и точки при каждом пробеге по циклу*/
    leftLength = summaryLength / 2;           // левое кол-во = суммарное кол-во /2 без ост-ка
    rightLength = summaryLength - leftLength; // правое кол-во = суммар. кол-во - левое кол-во
    rightPoint = leftPoint + leftLength;      // правая точка = лев.тчк. + лев. кол-во
    /*после переустановки в каждом начале цикла пробегаем по условиям*/
    if (numbers[leftPoint] > controlPoint) // если левая точка больше контр. числа... ,
    {
      result = numbers.size(); //... то все числа массива больше.
      break;                   // слом цикла;
    };

    if ((numbers[leftPoint] <= controlPoint) && (numbers[rightPoint] > controlPoint)) // если левая точка меньше или равна контрольной, а правая - больше
    {
      result += rightLength;      // результат = результат + правое кол-во;
      summaryLength = leftLength; // суммарная длина = левая длина;
      /*левая точка - без исменений, левое и правое поля и правую точку рассчитаем в начале цикла*/
      continue; // бежим в начало цикла;
    };

    if ((leftPoint <= controlPoint) && (rightPoint <= controlPoint)) // если левая и правая точки равны или меньше контрольной
    {
      summaryLength = rightLength; // суммарная длина = правая длина;
      leftPoint = rightPoint;      // левая точка = правая точка;
    };
  };

  return result;
};

/*Подпрограмма выполнения бинопоиска по массиву*/
int main()
{
  SetConsoleOutputCP(CP_UTF8);

  int controlPoint = 0;
  cout << "Вводим число: ";
  cin >> controlPoint;

  cout << binoSearch(integers, controlPoint) << endl;
  return 0;
};