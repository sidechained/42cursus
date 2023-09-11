#include "BrickWall.hpp"

BrickWall::BrickWall()
{
	type = "Inconspicuous Red-brick Wall";
}

BrickWall::BrickWall(BrickWall &o)
{
	*this = o;
}

BrickWall& BrickWall::operator=(BrickWall &o)
{
	this->type = o.type;
	return *this;
}

BrickWall::~BrickWall()
{

}

BrickWall* BrickWall::clone() const
{
	return new BrickWall();
}
