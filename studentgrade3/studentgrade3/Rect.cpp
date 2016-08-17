#include "stdafx.h"
#include "Rect.h"
#include <vector>

using namespace std;

Rect::Rect()
{
	height = 1;
	width = 1;
}

void Rect::setHeight(double a)
{
	height = a;
}
void Rect::setWidth(double b)
{
	width = b;
}

double Rect::getHeight()
{
	return height;
}
double Rect::getWidth()
{
	return width;
}

bool Rect::checkValidity()
{
	if (width >= 1 && height >= 1)
	{
		return true;
	}
	else
		return false;
}
double Rect::getArea()
{
	double area = width * height;
	return area;
}