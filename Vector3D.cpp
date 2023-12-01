#include "Vector3D.h"
#include<cmath>
#include<iostream>
using namespace std;
//return type class name::function name(parameters)

Vector3D::Vector3D(double tx,double ty,double tz)
{
	x = tx;
	y = ty;
	z = tz;

}
void Vector3D::Print()
{
	cout << "( " << this->x << " , " << this->y << " , " << this->z<<" )";
}
void Vector3D::Init(double tx, double ty, double tz)
{
	x=tx;
	y = ty;
	z = tz;
}
double Vector3D::Magnitude()
{
	double r;
	r = sqrt((this->x) * (this->x) + (this->y) * (this->y) + (this->z) * (this->z));
	return r;
}
Vector3D Vector3D::UnitVector()
{
	Vector3D Res;
	Res.Init(this->x/(this->Magnitude()) , this->y /(this->Magnitude()) ,this-> z/(this->Magnitude()));
	return Res;
}
Vector3D Vector3D::Add(Vector3D V)
{
	Vector3D Res(this->x+V.x, this->y + V.y, this->z + V.z);
	return Res;
}
Vector3D Vector3D::Sub(Vector3D V)
{
	Vector3D Res(this->x - V.x, this->y - V.y, this->z - V.z);
	return Res;

}
Vector3D Vector3D::MultCross(Vector3D V)
{
	Vector3D Res(this->y*V.z-V.y*this->z,-(this->x*V.z-V.x*this->z),this->x*V.y-V.x*this->y);
	return Res;

}
double  Vector3D::MultDot(Vector3D V)
{
	double res = this->x * V.x + this->y * V.y + this->z * V.z;
	return res;
}
Vector3D Vector3D::UnitX()
{
	return(1, 0, 0);
}
Vector3D Vector3D::UnitY()
{
	return(0, 1, 0);
}
Vector3D Vector3D::UnitZ()
{
	return(0, 0, 1);
}
double Vector3D::ProjectionAtV(Vector3D V)
{
	double prod = (*this).MultDot(V) ;
	double mag = V.Magnitude();
	double res = prod / mag;
	return res;
}
double Vector3D::Area_Parrallelogram(Vector3D V)
{
	Vector3D area = (*this).MultCross(V);
	double res = area.Magnitude();
	return res;
}
double Vector3D::Area_Triangle(Vector3D V)
{
	Vector3D area = (*this).MultCross(V);
	double res = area.Magnitude()/2;
	
	return res;
}
