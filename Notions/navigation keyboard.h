//	Copyright (C) 2009, 2011, 2012 Vaptistis Anogeianakis <el05208@mail.ntua.gr>
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

#include "event handlers.h"
#include "global variables.h"

namespace Navigation
{
							/************
							* key press *
							************/

	void leftDown(const EventDispatcher &dispatcher, double time)						// leftDown
	{

	} // end function leftDown


	void rightDown(const EventDispatcher &dispatcher, double time)						// rightDown
	{
		if(state.locked)
		{
			state.mode = CONVERSION;
			paint.iPaint = defaultPainter;
			Conversion::setHandlers(dispatcher);
		} // end if
	} // end function rightDown


	void upDown(const EventDispatcher &dispatcher, double time)							// upDown
	{

	} // end function upDown


	void downDown(const EventDispatcher &dispatcher, double time)						// downDown
	{

	} // end function downDown


	void enterDown(const EventDispatcher &dispatcher, double time)						// enterDown
	{
		if(state.locked)
		{
			state.mode = CONVERSION;
			paint.iPaint = defaultPainter;
			Conversion::setHandlers(dispatcher);
		} // end if
		state.locked = !state.locked;
	} // end function enterDown


							/**************
							* key release *
							**************/

	void leftUp(const EventDispatcher &dispatcher, double time)								// leftUp
	{

	} // end function leftUp


	void rightUp(const EventDispatcher &dispatcher, double time)							// rightUp
	{
		if(!state.locked)
		{
			state.mode = CONVERSION;
			paint.iPaint = defaultPainter;
			Conversion::setHandlers(dispatcher);
		} // end if
	} // end function rightUp


	void upUp(const EventDispatcher &dispatcher, double time)								// upUp
	{

	} // end function upUp


	void downUp(const EventDispatcher &dispatcher, double time)								// downUp
	{

	} // end function downUp


	void enterUp(const EventDispatcher &dispatcher, double time)							// enterUp
	{
		// stay
	} // end function enterUp


}; // end namespace Navigation
