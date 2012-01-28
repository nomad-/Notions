// includes
#include "global.h"

void resize(int width , int height)	// check
{
	windowHeight = height;
	windowWidth = width;
	glViewport(0,0,windowWidth,windowHeight);
	glutPostRedisplay();
} // end function resize

void drag(int x ,int y)	// check
{
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	freePoints.push_back(Triple(x,y,time.QuadPart*multiplier));
	glutPostRedisplay();
} // end function drag

void mouseClick(int button, int state, int x, int y)
{
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		selected = -1;
		for(unsigned int c = 0 ; c < polyLines.size() ; ++c)
		{
			if(polyLines[c].belongs(Triple(x,y,0)))
			{
				selected = c;
				break;
			} // end if
		} // end for
		glutPostRedisplay();
	} // end if

	if( button == GLUT_LEFT_BUTTON && state == GLUT_UP && freePoints.size())
	{
#ifdef PRODUCTION_MODE
		velocities.clear();
		velocity_magnitudes.clear();
		line_stats.clear();
#endif
		adjacent_difference(freePoints.begin(),freePoints.end(),back_inserter(velocities),getSpeed);
		velocities.front() = Triple(0,0,0);
		transform(velocities.begin(),velocities.end(),back_inserter(velocity_magnitudes),getMagnitude);
#if 0
		max = *max_element(velocity_magnitudes.begin(),velocity_magnitudes.end());
		min = *min_element(velocity_magnitudes.begin(),velocity_magnitudes.end());
		threshold = (max - min)*relative_threshold + min;
#else
		vector<GLdouble> temp(velocity_magnitudes.size());	// create a temporary vector
		copy(velocity_magnitudes.begin(),velocity_magnitudes.end(),temp.begin());	// end copy velocity_magnitudes elements in it.
		sort(temp.begin(),temp.end());	// then sort the temporary vector
		threshold = temp[floor(relative_threshold*temp.size())]; // and calculate threshold. Note: must be relative_threshold < 1!
		temp.clear();
#endif
		vector<GLdouble>::iterator last = velocity_magnitudes.begin();
		vector<GLdouble>::iterator first;
		//vector<GLdouble>::iterator temp;
		Comparer<GLdouble,greater<GLdouble> > over(threshold);
		Comparer<GLdouble,less_equal<GLdouble> > below(threshold);
		while(last != velocity_magnitudes.end())
		{
			first = find_if(last,velocity_magnitudes.end(),over);
			last = find_if(first,velocity_magnitudes.end(),below);
			/*while( (temp = find_if(last,velocity_magnitudes.end(),over)) - last == 1 )
				last = find_if(temp,velocity_magnitudes.end(),below);*/
			register_line_segment( (first-velocity_magnitudes.begin())+freePoints.begin() , (last-velocity_magnitudes.begin())+freePoints.begin() );
		} // end while
		
		if(line_stats.size())
		{
			for_each(line_stats.begin(),line_stats.end(),snap_to_grid);	// snap line segments to grid.

			if(line_stats.size() > 1)
			{
				// remove adjacent parallel segments.
				list<Statistics> temp(line_stats.size());	// create a temporary list object
				copy(line_stats.begin(),line_stats.end(),temp.begin());	// and copy line_stats contents into it.
				list<Statistics>::iterator previous = temp.begin();
				list<Statistics>::iterator current = temp.begin();
				++current;
				while(current != temp.end())
					if(current->a == previous->a && current->b == previous->b)
						current = temp.erase(current);
					else
					{
						++current;
						++previous;
					} // end if-else
				line_stats.resize(temp.size());	// resize line_stats to the size without the removed segments
				copy(temp.begin(),temp.end(),line_stats.begin());	// end copy the remaining segments back to it.
			} // end if



			polyLines.push_back(PolyLine(Triple(1,0.75,0),GL_LINE_STRIP,1.5,vector<Triple>()));	// create a new PolyLine object.
			// find intersection points between lines.
			polyLines.back().vertices.resize(line_stats.size());
			adjacent_difference(line_stats.begin() , line_stats.end() , polyLines.back().vertices.begin() , getIntersectionPoint);
			polyLines.back().vertices.front() = dummy_project(freePoints.front(),line_stats.front());
			polyLines.back().vertices.push_back(dummy_project(freePoints.back(),line_stats.back()));

			// close loop as needed.
			size_t n = polyLines.back().vertices.size();
			if( n > 2 )
			{
				Triple edge = getIntersectionPoint(line_stats.front(),line_stats.back());
				if(edge.t) // if the first and last segments were not parallel
				{
					if(check_intersecting(edge , polyLines.back().vertices[0] , polyLines.back().vertices[1] , polyLines.back().vertices[n-2] , polyLines.back().vertices[n-1]))
					{
						polyLines.back().vertices.pop_back();	// delete last element
						polyLines.back().vertices.front() = edge;	// end set first to edge
						polyLines.back().mode = GL_LINE_LOOP;
					} // end if
				}
				else	// if they were parallel
				{
					if(check_parallel(polyLines.back().vertices[0] , polyLines.back().vertices[1] , polyLines.back().vertices[n-2] , polyLines.back().vertices[n-1]))
					{
						polyLines.back().vertices.pop_back();	// delete last element
						polyLines.back().vertices.erase(polyLines.back().vertices.begin());	// and first element
						polyLines.back().mode = GL_LINE_LOOP;
					} // end if
				} // end if-else				
			} // end if
		} // end if
#ifdef _DEBUG
		copy(velocity_magnitudes.begin(),velocity_magnitudes.end(),outIter);
#endif
#ifdef PRODUCTION_MODE
		freePoints.clear();
#endif
		glutPostRedisplay();
	} // end if
} // end function mouseClick