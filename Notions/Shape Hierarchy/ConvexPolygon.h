#ifndef POLYGON_H
#define POLYGON_H

#include "LineLoop.h"
#include <vector>
using std::vector;
#include <algorithms.h>

struct ConvexPolygon : public LineLoop
{
	/***************************
	* contructors & destructor *
	***************************/

	inline ConvexPolygon()																					// ConvexPolygon default constructor
	{
		// do nothing
	} // end ConvexPolygon default constructor


	inline ConvexPolygon(const ConvexPolygon &original)														// ConvexPolygon copy constructor
		:LineLoop(original)
	{
		// empty body
	} // end ConvexPolygon copy constructor


	inline ConvexPolygon(double width, const Color<> &color, bool mark = false)								// ConvexPolygon constructor
		:LineLoop(width,color,mark)
	{
		// empty body
	} // end ConvexPolygon constructor


	inline ~ConvexPolygon()																					// ConvexPolygon destructor
	{
		// empty body
	} // end ConvexPolygon destructor



	/************
	* operators *
	************/

	inline ConvexPolygon &operator = (const ConvexPolygon &original)										// operator =
	{
		LineLoop::operator =(original);
		return *this;
	} // end function operator =



	/*******************
	* member functions *
	*******************/

	virtual ConvexPolygon &display()																		// display
	{
		// fill
		glColor(fillColor);
		glBegin(GL_POLYGON);
			execute_indirect(vertices.begin(),vertices.end(),&Vertex::note);
		glEnd();

		LineLoop::display();
		return *this;
	} // end function display


	virtual ConvexPolygon &display(double zoom)																// display
	{
		// fill
		glColor(fillColor);
		glBegin(GL_POLYGON);
			execute_indirect(vertices.begin(),vertices.end(),&Vertex::note);
		glEnd();

		LineLoop::display(zoom);
		return *this;
	} // end function display


	virtual ConvexPolygon *clone() const																	// clone
	{
		return new ConvexPolygon(*this);
	} // end function clone


	virtual Region *inside(const Vector2D<> &point)															// inside
	{
		vector<Vector2D<> > sides(vertices.size());
		cyclic_difference(vertices.begin(),vertices.end(),sides.begin(),diff);

		vector<Vector2D<> >::iterator sBegin = sides.begin();
		list<Vertex *>::iterator vBegin = vertices.begin();
		list<Vertex *>::iterator vEnd = vertices.end();
		bool negative = *sBegin % (point - **vBegin) < 0;
		++sBegin , ++vBegin;
		while(vBegin != vEnd)
		{
			if(*sBegin % (point - **vBegin) < 0 != negative)
				return 0;
			++sBegin;
			++vBegin;
		} // end while

		return this;
	} // end function inside


	static inline Vector2D<> diff(Vector2D<> *left,Vector2D<> *right)										// diff
	{
		return *left - *right;
	} // end function diff


	/***************
	* data members *
	***************/

}; // end class ConvexPolygon

#endif // POLYGON_H