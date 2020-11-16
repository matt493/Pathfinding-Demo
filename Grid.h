#pragma once
#include "Headers.h"

class Grid
{
private:
	Color color;
	Point point;
	bool obstacle, traversed, start, end;
	Grid* parent;

public:
	//constructors
	Grid();
	Grid(float, float);

	//getters
	int getX();
	int getY();
	Grid* getParent();
	Color getColor();
	bool isObstacle();
	bool isStartPoint();
	bool isEndPoint();
	bool isTraversed();


	//setters
	void setX();
	void setY();
	void setStartPoint();
	void setEndPoint();
	void setObstacle(bool);
	void setTraversed();
	void setParent(Grid*);
	void setPath();
};

