#pragma once
#include "Rectangle.hpp"
#include "RectangleType.hpp"

class RectangleFactory {
public:
	static Rectangle create(RectangleType type);
};