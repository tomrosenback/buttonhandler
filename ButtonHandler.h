/*
ButtonHandler.h - ButtonHandler library for Arduino.
Copyright (C) 2017 Tom Rosenback (tom.rosenback@gmail.com).  All rights reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

See file LICENSE.txt for further informations on licensing terms.
*/


#ifndef BUTTONHANDLER_H
#define BUTTONHANDLER_H

#define BH_DEBOUNCE_TIME 100 // ms debounce period to prevent flickering when pressing or releasing the button

enum {
	BH_EVENT_NONE,
	BH_EVENT_CLICK,
	BH_EVENT_HOLD
};

class ButtonHandler {
	public:
		ButtonHandler(bool invertState, int holdTime = 3000);
		int handle(int currentState, unsigned long currentTime);

	protected:
		bool _dirty;					// to prevent click event to occur after HOLD event
		bool _invertState;   // In case we are using LOW instead of HIGH as trigger
		unsigned int _holdTime; // ms hold period: how long to wait for hold event

		// state variables
		bool _lastState;				// buffered value of the button's previous state
		unsigned long _lastStateTime;	// time of last event
};

#endif
