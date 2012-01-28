#ifndef EVENT_HANDLERS_H
#define EVENT_HANDLERS_H

// includes
#include <direct input/mouse and keyboard/EventDispatcher.h>
#include "Shape Hierarchy.h"

// using declarations
using namespace MouseAndKeyboard;

// protorypes
void suspendProjectionMatrix();															// suspendProjectionMatrix
inline void restoreProjectionMatrix();													// restoreProjectionMatrix
void displayShapes();																	// displayShapes
void displayGrid();																		// displayGrid
inline void displayCursor();															// displayCursor
void displayNavigationGUI();															// displayNavigationGUI
void displayGUI();																		// displayGUI
void defaultPainter(const EventDispatcher &dispatcher , double time);					// defaultPainter
void navigationPainter(const EventDispatcher &dispatcher , double time);				// navigationPainter
void escape(const EventDispatcher &,double);											// escape
void disableKeyboardHandlers(const EventDispatcher &dispatcher);						// disableKeyboardHandlers

namespace Conversion
{
	void setHandlers(const EventDispatcher &dispatcher);								// setHandlers
	void enableKeyboardHandlers(const EventDispatcher &dispatcher);						// enableKeyboardHandlers
							/************
							* key press *
							************/
	void leftDown(const EventDispatcher &dispatcher, double time);						// leftDown
	void rightDown(const EventDispatcher &dispatcher, double time);						// rightDown
	void upDown(const EventDispatcher &dispatcher, double time);						// upDown
	void downDown(const EventDispatcher &dispatcher, double time);						// downDown
	void enterDown(const EventDispatcher &dispatcher, double time);						// enterDown
							/**************
							* key release *
							**************/
	void leftUp(const EventDispatcher &dispatcher, double time);						// leftUp
	void rightUp(const EventDispatcher &dispatcher, double time);						// rightUp
	void upUp(const EventDispatcher &dispatcher, double time);							// upUp
	void downUp(const EventDispatcher &dispatcher, double time);						// downUp
	void enterUp(const EventDispatcher &dispatcher, double time);						// enterUp
							/********
							* mouse *
							********/
	void mouseleftDown(const EventDispatcher &dispatcher, double time);					// mouseleftDown
	void mouseleftUp(const EventDispatcher &dispatcher, double time);					// mouseleftUp
	void mouseMove(const EventDispatcher &dispatcher, double time);						// mouseMove
}; // end namespace Conversion


namespace Creation
{
	void setHandlers(const EventDispatcher &dispatcher);								// setHandlers
	void enableKeyboardHandlers(const EventDispatcher &dispatcher);						// enableKeyboardHandlers
							/************
							* key press *
							************/
	void leftDown(const EventDispatcher &dispatcher, double time);						// leftDown
	void rightDown(const EventDispatcher &dispatcher, double time);						// rightDown
	void upDown(const EventDispatcher &dispatcher, double time);						// upDown
	void downDown(const EventDispatcher &dispatcher, double time);						// downDown
	void enterDown(const EventDispatcher &dispatcher, double time);						// enterDown
							/**************
							* key release *
							**************/
	void leftUp(const EventDispatcher &dispatcher, double time);						// leftUp
	void rightUp(const EventDispatcher &dispatcher, double time);						// rightUp
	void upUp(const EventDispatcher &dispatcher, double time);							// upUp
	void downUp(const EventDispatcher &dispatcher, double time);						// downUp
	void enterUp(const EventDispatcher &dispatcher, double time);						// enterUp
							/********
							* mouse *
							********/
	void mouseleftDown(const EventDispatcher &dispatcher, double time);					// mouseleftDown
	void mouseleftUp(const EventDispatcher &dispatcher, double time);					// mouseleftUp
	void mouseMove(const EventDispatcher &dispatcher, double time);						// mouseMove
}; // end namespace Creation


namespace Navigation
{
	void setHandlers(const EventDispatcher &dispatcher);								// setHandlers
	void enableKeyboardHandlers(const EventDispatcher &dispatcher);						// enableKeyboardHandlers
							/************
							* key press *
							************/
	void leftDown(const EventDispatcher &dispatcher, double time);						// leftDown
	void rightDown(const EventDispatcher &dispatcher, double time);						// rightDown
	void upDown(const EventDispatcher &dispatcher, double time);						// upDown
	void downDown(const EventDispatcher &dispatcher, double time);						// downDown
	void enterDown(const EventDispatcher &dispatcher, double time);						// enterDown
							/**************
							* key release *
							**************/
	void leftUp(const EventDispatcher &dispatcher, double time);						// leftUp
	void rightUp(const EventDispatcher &dispatcher, double time);						// rightUp
	void upUp(const EventDispatcher &dispatcher, double time);							// upUp
	void downUp(const EventDispatcher &dispatcher, double time);						// downUp
	void enterUp(const EventDispatcher &dispatcher, double time);						// enterUp
							/********
							* mouse *
							********/
	void mouseleftDown(const EventDispatcher &dispatcher, double time);					// mouseleftDown
	void mouseleftUp(const EventDispatcher &dispatcher, double time);					// mouseleftUp
	void mouseMove(const EventDispatcher &dispatcher, double time);						// mouseMove
}; // end namespace Navigation


namespace Selection
{
	void setHandlers(const EventDispatcher &dispatcher);								// setHandlers
	void enableKeyboardHandlers(const EventDispatcher &dispatcher);						// enableKeyboardHandlers
							/************
							* key press *
							************/
	void leftDown(const EventDispatcher &dispatcher, double time);						// leftDown
	void rightDown(const EventDispatcher &dispatcher, double time);						// rightDown
	void upDown(const EventDispatcher &dispatcher, double time);						// upDown
	void downDown(const EventDispatcher &dispatcher, double time);						// downDown
	void enterDown(const EventDispatcher &dispatcher, double time);						// enterDown
							/**************
							* key release *
							**************/
	void leftUp(const EventDispatcher &dispatcher, double time);						// leftUp
	void rightUp(const EventDispatcher &dispatcher, double time);						// rightUp
	void upUp(const EventDispatcher &dispatcher, double time);							// upUp
	void downUp(const EventDispatcher &dispatcher, double time);						// downUp
	void enterUp(const EventDispatcher &dispatcher, double time);						// enterUp
							/********
							* mouse *
							********/
	void mouseleftDown(const EventDispatcher &dispatcher, double time);					// mouseleftDown
	void mouseleftUp(const EventDispatcher &dispatcher, double time);					// mouseleftUp
	void mouseMove(const EventDispatcher &dispatcher, double time);						// mouseMove
}; // end namespace Selection


namespace Configuration
{
	void setHandlers(const EventDispatcher &dispatcher);								// setHandlers
	void enableKeyboardHandlers(const EventDispatcher &dispatcher);						// enableKeyboardHandlers
							/************
							* key press *
							************/
	void leftDown(const EventDispatcher &dispatcher, double time);						// leftDown
	void rightDown(const EventDispatcher &dispatcher, double time);						// rightDown
	void upDown(const EventDispatcher &dispatcher, double time);						// upDown
	void downDown(const EventDispatcher &dispatcher, double time);						// downDown
	void enterDown(const EventDispatcher &dispatcher, double time);						// enterDown
							/**************
							* key release *
							**************/
	void leftUp(const EventDispatcher &dispatcher, double time);						// leftUp
	void rightUp(const EventDispatcher &dispatcher, double time);						// rightUp
	void upUp(const EventDispatcher &dispatcher, double time);							// upUp
	void downUp(const EventDispatcher &dispatcher, double time);						// downUp
	void enterUp(const EventDispatcher &dispatcher, double time);						// enterUp
							/********
							* mouse *
							********/
	void mouseleftDown(const EventDispatcher &dispatcher, double time);					// mouseleftDown
	void mouseleftUp(const EventDispatcher &dispatcher, double time);					// mouseleftUp
	void mouseMove(const EventDispatcher &dispatcher, double time);						// mouseMove
}; // end namespace Configuration


#endif // EVENT_HANDLERS_H