#include "Grid.h"

Grid::Grid()
{
	color.r = 0, color.g = 0, color.b = 0;
	point.x = 0, point.y = 0;
	obstacle = false;
	start = false;
	end = false;
	traversed = false;
	parent = NULL;
}

Grid::Grid(float x, float y)
{
	//CO-ORD
	point.x = x;
	point.y = y;

	//OBSTACLE
	this->obstacle = false;

	//COLOR
	this->color.r = this->color.g = this->color.b = 1;

	//PARENT
	parent = NULL;
}

int Grid::getX() { return point.x; }
int Grid::getY() { return point.y; }

Grid* Grid::getParent() { return parent; }

Color Grid::getColor() { return this->color; }

bool Grid::isObstacle() { return obstacle; }

bool Grid::isStartPoint() { return start; }

bool Grid::isEndPoint() { return end; }

bool Grid::isTraversed() { return traversed; }

void Grid::setStartPoint()
{
	if (end || obstacle)
	{
		//do nothing
	}
	else
	{
		this->color.r = 0;
		this->color.g = 0;
		this->color.b = 1;
		parent = NULL;
		start = true;
	}
}

void Grid::setEndPoint()
{
	if (start || obstacle)
	{
		//do nothing
	}
	else
	{
		this->color.r = 1;
		this->color.g = 0;
		this->color.b = 0;
		end = true;
	}
}

void Grid::setObstacle(bool state)
{
	if (state)
	{
		this->color.r = 0;
		this->color.g = 0;
		this->color.b = 0;
	}
	else
	{
		this->color.r = 1;
		this->color.g = 1;
		this->color.b = 1;
	}
	obstacle = state;
}

void Grid::setTraversed()
{
	if (this->start || this->end)
	{
		//dont change color
	}
	else
	{
		this->color.r = 0;
		this->color.g = 1;
		this->color.b = 0;
	}
	traversed = true;
}

void Grid::setParent(Grid* parent)
{
	this->parent = parent;
}

void Grid::setPath()
{
	if (this->start || this->end)
	{
		//dont change color
	}
	else
	{
		this->color.r = 1;
		this->color.g = 1;
		this->color.b = 0;
	}
}
