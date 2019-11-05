/*
ButtonHandler.cpp - ButtonHandler library for Arduino.
Copyright (C) 2017 Tom Rosenback (tom.rosenback@gmail.com).  All rights reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

See file LICENSE.txt for further informations on licensing terms.
*/

#include "ButtonHandler.h"

ButtonHandler::ButtonHandler(bool invertState) {
	_dirty = false;
	_lastState = false;
	_lastStateTime = 0;
	_invertState = invertState;
};

int ButtonHandler::handle(int currentState, unsigned long currentTime) {
	if(_invertState) {
		currentState = !currentState;
	}

	int currEvent = BH_EVENT_NONE;
	unsigned long interval = currentTime - _lastStateTime;

	if(currentState != _lastState && interval > BH_DEBOUNCE_TIME || currentState == _lastState)	{
		if(currentState && !_lastState) { // LOW => HIGH
			// nothing to do
		}
		else if(currentState && _lastState && interval > BH_HOLD_TIME && !_dirty) { // HIGH => HIGH
			currEvent = BH_EVENT_HOLD;
			_dirty = true;
		} else if(!currentState && _lastState) { // HIGH => LOW
			if(!_dirty)	{
				currEvent = BH_EVENT_CLICK;
			}

			_dirty = false;
		}

		if(currentState != _lastState) {
			_lastState = currentState;
			_lastStateTime = currentTime;
		}
	}

	return currEvent;
}
