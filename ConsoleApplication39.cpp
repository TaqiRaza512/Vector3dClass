#include<iostream>
#include "Vector3D.h"
using namespace std;

int Read(istream& rdr, Vector3D* &Cs)
{
	double x, y, z;
	int size;
	rdr >> size;
	Cs = new Vector3D[size];
	for (int ri=0;ri<size;ri++)
	{
		rdr >> x >> y >> z;
		Cs[ri].Init(x, y, z);
	}
	return size;
}

void print(Vector3D* Cs,int size)
{
	cout << "\n\n==================================\n";
	for (int ri=0;ri<size;ri++)
	{
		cout << "V" << ri + 1;
		Cs[ri].Print();
		cout << endl;
	}
	cout << "\n\n==================================\n";
}
void MainMenu()
{
	cout << "\nplease enter 1 for unary operations \n";
	cout << "\nplease enter 2 for binary operations \n";
	cout << "\nplease enter 3 for to find the areas and projection\n";


}

void Menu()
{
	cout << "Use \"x\" for the cross multiplication of two vectors \n";
	cout << "Use \"*\" for the dot  multiplication of two vectors \n";
	cout << "Use \"-\" for the subtraction of two vectors \n";
	cout << "Use \"+\" for addition of two vectors \n";

}
void BinaryOpt(Vector3D* &Cs,int size)
{
		char oprt, d,tocont;
	do
	{
		int dv, ri, ui, li;
		double r;
		system("cls");
		print(Cs,size);
		Menu();
		cin >> d >> ri >> d >> d >> ui >> oprt >> d >> li;
		ri--;
		ui--;
		li--;
		switch (oprt)
		{
		case '+':
			Cs[ri] = Cs[ui].Add(Cs[li]);
			Cs[ri].Print();
			break;
		case '-':
			Cs[ri] = Cs[ui].Sub(Cs[li]);
			Cs[ri].Print();
			break;
		case 'x':
			Cs[ri] = Cs[ui].MultCross(Cs[li]);
			Cs[ri].Print();
			break;
		case '*':
			 r= Cs[ui].MultDot(Cs[li]);
			cout << "\nThe result of dot product of two vectors V" << ui+1 << " and V" << li+1 << " is " << r<<endl<<endl;
			break;
		default:
			cout << "\nNot valid input.........\n";
		}
		cout << "\n Do you want to continue (Y/N)..........\n";
		cin >> tocont;

	} while (tocont =='Y' or tocont =='y');

}

void UnaryMenu()
{
	cout << "please enter \"!V\" to find the magnitude of a vector \n";
	cout << "please enter \"^V\" to find the Unit Vector \n";



}
void UnaryOpt(Vector3D* &Cs,int size)
{
	Vector3D unit;
	double res = 0;
	int index;
	char tocont;
	char sign,d;
	do
	{
		system("cls");
		print(Cs,size);
		UnaryMenu();
		cin >> sign >> d >> index;
		index--;
		switch (sign)
		{
		case '!':
			res = Cs[index].Magnitude();
			cout << "The magnitude of V" << index + 1 << " is " << res << endl;
			break;
		case '^':
			unit = Cs[index].UnitVector();
			unit.Print();
			break;
		default:
			cout << "\n\nplease enter valid input \n";
			break;
		}
		cout << "\nDo you want to continue \n";
		cin >> tocont;
	} while (tocont == 'Y' or tocont == 'y');
}

void MenuArea()
{
	cout << "Use \"Va->Vb\" to find the projection of a vector \n";
	cout << "please enter \"Va / / Vb\" to find the area of a parallelogram\n";
	cout << "please enter \"Va /\\ Vb \" to find the area of a triangle\n";
}
void AreaOpt(Vector3D*& Cs, int size)
{
	print(Cs, size);
	MenuArea();

	double res = 0;
	char d,et;
	int ui, li;
	char tocont;

	cin >> d >> ui >> d >> d >> et >> li;
	ui--;
	li--;

	do
	{
		switch (d)
		{
		case '/':
			res = Cs[ui].Area_Parrallelogram(Cs[li]);
			cout << "The area of parallelogram is " << res<<endl;
			break;
		case '\\':
			res = Cs[ui].Area_Triangle(Cs[li]);
			cout << "The area of triangle is " << res<<endl;
			break;
		case '>':
			 res= Cs[ui].ProjectionAtV(Cs[li]);
			cout << "The projection of V"<<ui+1<< " on "<<li+1<< "is "<< res<<endl;
			break;
		default:
			cout << "\n\nplease enter valid input \n";
			break;
		}
		cout << "Do you want to continue (Y/N) ";
		cin >> tocont;

	} while (tocont == 'Y' or tocont == 'y');
}

int main()
{
	Vector3D* Cs{};
	ifstream rdr("Vectors.txt");
	int size=Read(rdr,Cs);
	char tocont;
	do
	{
	
		int opt;

		system("cls");
		MainMenu();
		cin >> opt;
		switch (opt)
		{
		case 1:
			UnaryOpt(Cs,size);
			break;
		case 2:
			BinaryOpt(Cs,size);
			break;
		case 3:
			AreaOpt(Cs,size);


		}
		cout << "\nDo you want to continue (Y/N) .....\n";
		cin >> tocont;

	}while(tocont =='Y' or tocont =='y');

}