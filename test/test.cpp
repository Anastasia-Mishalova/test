// test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <queue>
using namespace std;

// Составить описание класса многочленов от одной переменной, задаваемых сте­пенью многочлена и массивом коэффициентов. Предусмотреть методы 
// для вычисления значения многочлена для заданного аргумента, операции сложения, вычитания и умножения многочленов с получением нового объекта
// - многочлена, вывод на экран описания многочлена.

class Polynomial
{
	int arr[10], num;

public:
	void Input()
	{
		cout << "Введите степень: ";
		cin >> num;
		cout << endl;
		cout << "Введите коэффициенты: \n";
		for (int i = 0; i <= 9; i++)
		{
			arr[i] = 0;
		}
		for (int i = 0; i <= num; i++)
		{
			cout << " c" << i << " = "; cin >> arr[i];
		}
		cout << endl;
	}

	void Sum(Polynomial a, Polynomial b)
	{
		for (int k = 0; k <= 9; k++)
		{
			arr[k] = 0;
		}

		if (a.num > b.num)
		{
			num = a.num;
		}
		else
		{
			num = b.num;
		}

		for (int i = 0; i <= num; i++)
		{
			arr[i] = a.arr[i] + b.arr[i];
		}
	}

	void Sub(Polynomial a, Polynomial b)
	{
		for (int k = 0; k <= 9; k++)
		{
			arr[k] = 0;
		}

		if (a.num > b.num)
		{
			num = a.num;
		}
		else
		{
			num = b.num;
		}

		for (int i = 0; i <= num; i++)
		{
			arr[i] = a.arr[i] - b.arr[i];
		}
	}

	void Mult(Polynomial a, Polynomial b)
	{
		for (int k = 0; k <= 9; k++)
		{
			arr[k] = 0;
		}

		num = a.num + b.num;
		for (int i = 0; i <= a.num; i++)
		{
			for (int j = 0; j <= b.num; j++)
			{
				arr[i + j] = arr[i + j] + a.arr[i] * b.arr[j];
			}
		}
	}

	void Print()
	{
		int f = 0;

		cout << "C(x) = ";

		for (int i = num; i >= 0; i--)
			if (arr[i] != 0)
			{
				if (f == 0) {
					if (i != 0)cout << arr[i] << "*x^" << i; else cout << arr[i];
					f++;
				}
				else {
					if (i != 0)
						if (arr[i] > 0) cout << "+" << arr[i] << "*x^" << i;
						else cout << arr[i] << "*x^" << i;
					else
						if (arr[i] > 0) cout << "+" << arr[i];
						else cout << arr[i];
					f++;
				}
			}
		if (f == 0)
		{
			cout << 0;
		}
	}
};

// Создайте программму, которая ведет учет студентов в группе, минимум реализации : список студентов, оценки по предметам, присутсвие студентов на паре.
// В качестве создания классов можно импровизировать. Использовать виртуальность.

class StudentInfo
{
public:
	virtual void Info() = 0;
};

class Student
{
protected:
	string firstname = " ", lastname = " ";
	float academ_performance = 0;
	int id = 0, average_score = 0;

public:
	Student()
	{
		cout << "";
	}

	Student(int id, string firstname, string lastname, int average_score, float academ_performance)
	{
		this->firstname = firstname;
		this->lastname = lastname;
		this->id = id;
		this->average_score = average_score;
		this->academ_performance = academ_performance;
	}

	void Print()
	{
		cout << "id " << id << ". firstname - " << firstname << ", lastname - " << lastname << ", average score - " << average_score
			<< ", academ performance - " << academ_performance << endl;
	}

};
class Group1Budget : public StudentInfo, public Student
{
	Student* students_group1 = new  Student[5]
	{
		 Student(1,"A","A",10, 90),
		 Student(2,"Б","Б",5, 50),
		 Student(3,"В","В",9, 68),
		 Student(4,"Г","Г",12, 100),
		 Student(5,"Д","Д",10, 94),
	};

	unsigned grant = 100;

public:
	Group1Budget()
	{
		cout << "";
	}

	void Info()override
	{
		cout << "Group N1, budget basis" << endl;
		for (int i = 0; i < 5; i++)
		{
			students_group1[i].Print();
		}
		cout << "Grant for the current month - " << grant << "$" << endl;
	}
};

class Group2Paid : public StudentInfo, public Student
{
	Student* students_group2 = new  Student[6]
	{
		 Student(1,"Е","Е",3, 37),
		 Student(2,"Ё","Ё",12, 80),
		 Student(3,"Ж","Ж",8, 98),
		 Student(4,"З","З",12, 92),
		 Student(5,"И","И",10, 84),
		 Student(6,"Й","Й",11, 94),
	};

	unsigned payment = 3000;

public:
	Group2Paid()
	{
		cout << "";
	}
	void Info()override
	{
		cout << "Group N2, paid basis" << endl;
		for (int i = 0; i < 6; i++)
		{
			students_group2[i].Print();
		}
		cout << "payment for the current month of training - " << payment << "$";
	}
};

// Написать шаблонную функцию для работы с очередью, реализовать все основные методы.

template <typename T>
void Q_foo(T q)
{
	int a;
	cout << "Push" << endl;
	cout << "Введите 5 элементов в очередь: " << endl;

	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		q.push(a);
	}
	cout << endl;

	cout << "Pop" << endl;
	cout << "Первый элемент очереди удалён";
	q.pop();
	cout << endl << endl;

	cout << "Front" << endl;
	cout << "Первый элемент очереди - " << q.front();

	cout << endl << endl;

	cout << "Back" << endl;
	cout << "Последний элемент очереди - " << q.back();

	cout << endl << endl;

	cout << "Empty" << endl;
	if (!q.empty())
	{
		cout << "Очередь не пуста!" << endl;
	}
	else
	{
		cout << "Очередь пуста!" << endl;
	}
	cout << endl;
}


void main()
{
	setlocale(LC_ALL, "RU");

	//1
	Polynomial a, b, c;
	a.Input();
	b.Input();

	c.Sum(a, b);
	c.Print();
	cout << endl;

	c.Sub(a, b);
	c.Print();
	cout << endl;

	c.Mult(a, b);
	c.Print();
	cout << endl;



	//2
	//Group1Budget group1Budget;
	//Group2Paid group2Paid;

	//group1Budget.Info();
	//cout << endl;
	//group2Paid.Info();



	//3
	//queue <int> q;
	//Q_foo(q);


}