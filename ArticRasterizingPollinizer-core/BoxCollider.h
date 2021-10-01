#pragma once

namespace {
	class BoxCollider {
	private:
		float xMax, yMax, zMax, xMin, yMin, zMin;
	public:
		BoxCollider(float xMax, float yMax, float zMax, float xMin, float yMin, float zMin);
	};
}