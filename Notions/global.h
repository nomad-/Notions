//	Copyright (C) 2009, 2012 Vaptistis Anogeianakis <el05208@mail.ntua.gr>
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

// includes
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

#if LOGGING
#include <fstream>
using std::ofstream;
#endif

#include <vector>
using std::vector;

#include <algorithm>
using std::copy;
using std::for_each;
using std::transform;
using std::max_element;
using std::min_element;
using std::find_if;

#include <numeric>
using std::accumulate;
using std::adjacent_difference;

#include <iterator>
using std::back_inserter;

#if LOGGING
using std::ostream_iterator;
#endif

#include <functional>
using std::less;
using std::greater;
using std::less_equal;

#include <cstdlib>
using std::exit;

#include <cmath>
using std::sqrt;
using std::fabs;


#include <GL/glut.h>


#include "Triple.h"
#include "Statistics.h"
#include "Comparer.h"

// extern declarations for global variables.
extern vector<Triple> freePoints;
extern vector<Triple> velocities;
extern vector<GLdouble> velocity_magnitudes;

extern vector<Statistics> line_stats;
extern vector<Triple> line_segments;

extern unsigned int windowWidth;
extern unsigned int windowHeight;
extern double multiplier;
extern GLdouble max;
extern GLdouble min;
extern GLdouble threshold;
extern const GLdouble relative_threshold;

#if LOGGING
extern ofstream velocity_magnitudes_file;
extern ostream_iterator<GLdouble> outIter;
#endif

// prototypes
Triple getSpeed(const Triple &final , const Triple &initial);
GLdouble getMagnitude(const Triple &vector);
Statistics *add_to_sums(Statistics *statPtr , const Triple &point);


// templates
template<typename IterType>
void display(IterType begin , IterType end , GLenum mode)
{
	glBegin(mode);
	while(begin != end)
	{
		glVertex2d(begin->x / windowWidth , (windowHeight-1-begin->y) / windowHeight);
		++begin;
	} // end while
	glEnd();
} // end function template display

template<typename IterType1, typename IterType2>
void display_with_color(IterType1 first , IterType1 last , IterType2 point , GLenum mode)
{
	glBegin(mode);
	while(first != last)
	{
		if(*first > threshold)
		{
			glColor3d((*first-threshold)/(max-threshold),0,0);
		}
		else
		{
			glColor3d(0,0,(threshold-*first)/(threshold-min));
		} // end if-else
		glVertex2d(point->x / windowWidth , (windowHeight-1-point->y) / windowHeight);
		++point;
		++first;
	} // end while
	glEnd();
} // end function template display_with_color

template<typename IterType>
void register_line_segment(IterType begin , IterType end)
{
	if( begin==end || end-begin == 1 ) return;	// what kind of line will I get with a sole point?
	Statistics stats;

	accumulate(begin,end,&stats,add_to_sums);	// calculate sums.
	stats.n = end-begin;	// calculate number of points.

	GLdouble temp = stats.n*stats.x2 - stats.x*stats.x;	// calculate the common divisor.
	stats.a = (stats.n*stats.xy - stats.x*stats.y) / temp;	// calculate a
	stats.b = (stats.y*stats.x2-stats.x*stats.xy) / temp;	// and b.

	line_stats.push_back(stats);	// register the stats for future use.

	if( fabs(stats.a) <= 1 )
	{
		line_segments.push_back( Triple(begin->x , stats.a*begin->x + stats.b , begin->t) );
		line_segments.push_back( Triple(end->x , stats.a*end->x + stats.b , end->t) );
	}
	else
	{
		line_segments.push_back( Triple((begin->y-stats.b)/stats.a , begin->y , begin->t) );
		line_segments.push_back( Triple((end->y-stats.b)/stats.a , end->y , end->t) );
	} // end if-else
} // end function template register_line_segment