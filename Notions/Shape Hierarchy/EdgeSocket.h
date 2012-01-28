#ifndef EDGE_SOCKET_H
#define EDGE_SOCKET_H

#include "Socket.h"

struct EdgeSocket : public Socket
{
	/***************************
	* contructors & destructor *
	***************************/

	inline EdgeSocket()																					// EdgeSocket default constructor
	{
		// do nothing
	} // end EdgeSocket default constructor


	inline EdgeSocket(const EdgeSocket &original)														// EdgeSocket copy constructor
		:Socket(original),left(original.left),right(original.right)
	{
		// empty body
	} // end EdgeSocket copy constructor


	inline EdgeSocket(const Vector2D<> &point,double width,const Color<> &color, bool mark = false)		// EdgeSocket constructor
		:Socket(point,width,color,mark),left(0),right(0)
	{
		// empty body
	} // end EdgeSocket constructor


	inline EdgeSocket(double x,double y,double width,const Color<> &color, bool mark = false)			// EdgeSocket constructor
		:Socket(x,y,width,color,mark),left(0),right(0)
	{
		// empty body
	} // end EdgeSocket constructor


	virtual ~EdgeSocket()																				// EdgeSocket destructor
	{
		// empty body
	} // end EdgeSocket destructor



	/************
	* operators *
	************/

	virtual EdgeSocket &operator = (const EdgeSocket &original)											// operator =
	{
		Socket::operator =(original);
		left = original.left;
		right = original.right;
		return *this;
	} // end function operator =



	/*******************
	* member functions *
	*******************/

	inline EdgeSocket &setLeft(Vertex *leftVertex)														// setLeft
	{
		left = leftVertex;
		return *this;
	} // end function setLeft


	inline EdgeSocket &setRight(Vertex *rightVertex)													// setRight
	{
		right = rightVertex;
		return *this;
	} // end function setRight


	virtual Vector2D<> &position()																		// position
	{
		Vector2D::operator =((left->position()+right->position())*0.5);
		list<Plug *>::iterator begin = childs.begin();
		list<Plug *>::iterator end = childs.end();
		while(begin != end)
		{
			if((*begin)->permanent)
				(*begin)->Vector2D::operator =(*this);
			++begin;
		} // end while
		return *this;
	} // end function position


	virtual EdgeSocket *clone() const																	// clone
	{
		return new EdgeSocket(*this);
	} // end function clone



	/***************
	* data members *
	***************/

	Vertex *left;
	Vertex *right;

}; // end class EdgeSocket

#endif // EDGE_SOCKET_H