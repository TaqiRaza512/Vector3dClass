#include<iostream>
#include<fstream>
#pragma once
using namespace std;
class Vector3D
{
private:
	double x, y, z;
	static Vector3D UnitX();
	static Vector3D UnitY();
	static Vector3D UnitZ();

public:
	Vector3D(double tx = 0, double ty = 0, double tz = 0);
	void Init(double tx, double ty, double tz);
	void Print();
	double Magnitude();
	Vector3D UnitVector();
	Vector3D Add(Vector3D V);
	Vector3D Sub(Vector3D V);
	Vector3D MultCross(Vector3D V);
	double MultDot(Vector3D V);
	double ProjectionAtV(Vector3D V);
	double Area_Parrallelogram(Vector3D V);
	double Area_Triangle(Vector3D V);



};


