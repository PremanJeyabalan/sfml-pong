#pragma once

#ifndef PONG_FIELD_H
#define PONG_FIELD_H

#include "../../VisibleObject.h"

class Field : public VisibleObject {

public:
	Field();
	void update(float timeElapsed);
};

#endif // !PONG_FIELD_H

