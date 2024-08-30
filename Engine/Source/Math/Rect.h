#pragma once
struct Rect
{
	Rect() = default;
	Rect(int other_x, int other_y, int other_w, int other_h) {
		x = other_x;
		y = other_y;
		w = other_w;
		h = other_h;
	}

	int x = 0;
	int y = 0;
	int w = 0;
	int h = 0;
};