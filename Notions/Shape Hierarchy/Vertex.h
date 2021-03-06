//	Copyright (C) 2009, 2011, 2012 Vaptistis Anogeianakis <nomad@cornercase.gr>
/*
 *	This file is part of Notions.
 *
 *	Notions is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	Notions is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with Notions.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef VERTEX_H
#define VERTEX_H

// includes
#include "Shape.h"
#include <gl/glut.h>
#include <Color/glColor.h>
#include <Graphics/glVertex2.h>


struct Vertex : public Shape , public Vector2D<>
{
	/***************************
	* contructors & destructor *
	***************************/

	inline Vertex()																							// Vertex default constructor
	{
		// do nothing
	} // end Vertex default constructor


	inline Vertex(const Vertex &original)																	// Vertex copy constructor
		:Shape(original),Vector2D(original)
	{
		// empty body
	} // end Vertex copy constructor


	inline Vertex(const Vector2D<> &point,double width,const Color<> &color, bool mark = false)				// Vertex constructor
		:Shape(width,color,mark),Vector2D(point)
	{
		// empty body
	} // end Vertex constructor


	inline Vertex(double x,double y,double width,const Color<> &color, bool mark = false)					// Vertex constructor
		:Shape(width,color,mark),Vector2D(x,y)
	{
		// empty body
	} // end Vertex constructor


	virtual ~Vertex()																						// Vertex destructor
	{
		// empty body
	} // end Vertex destructor




	/************
	* operators *
	************/

	virtual Vertex &operator = (const Vertex &original)														// operator =
	{
		Shape::operator =(original);
		Vector2D::operator =(original);
		return *this;
	} // end function operator =


	/*******************
	* member functions *
	*******************/

	inline Vertex &note()																					// note
	{
		glVertex2(position());
		return *this;
	} // end function note


	virtual Vertex &display()																				// display
	{
		if(marked)
		{
			double l = lineWidth*3;
			glColor(lineColor);
			glLineWidth(lineWidth*2);
			glBegin(GL_LINE_LOOP);
				glVertex2(position() + Vector2D<>(l,l));
				glVertex2(position() + Vector2D<>(-l,l));
				glVertex2(position() + Vector2D<>(-l,-l));
				glVertex2(position() + Vector2D<>(l,-l));
			glEnd();
		} // end if
		return *this;
	} // end function display


	virtual Vertex &display(double zoom)																	// display
	{
		if(marked)
		{
			double l = lineWidth*3;
			glColor(lineColor);
			glLineWidth(lineWidth*2*zoom);
			glBegin(GL_LINE_LOOP);
				glVertex2(position() + Vector2D<>(l,l));
				glVertex2(position() + Vector2D<>(-l,l));
				glVertex2(position() + Vector2D<>(-l,-l));
				glVertex2(position() + Vector2D<>(l,-l));
			glEnd();
		} // end if
		return *this;
	} // end function display


	virtual Vertex &move(const Vector2D<> &displacement)													// move
	{
		*this += displacement;
		return *this;
	} // end function move


	virtual Vertex &moveDisconnect(const Vector2D<> &displacement)											// moveDisconnect
	{
		move(displacement);
		return *this;
	} // end function moveDisconnect


	virtual Vertex *nearVertex(const Vector2D<> &point , double distance2)									// nearVertex
	{
		Vector2D<> diff = point - position();
		if(diff*diff < distance2) return this;
		else return 0;
	} // end function nearVertex


	virtual pair nearEdge(const Vector2D<> &point , double distance2)										// nearEdge
	{
		return pair(nullptr,nullptr);
	} // end function nearEdge


	virtual Vertex *clone() const																			// clone
	{
		return new Vertex(*this);
	} // end function clone


	virtual Vector2D<> &position()																			// position
	{
		return *this;
	} // end function position



	/***************
	* data members *
	***************/

}; // end class Vertex

#endif // VERTEX_H