#pragma once
#include <cmath>
#include "appe/math/vec3.h"

struct Mat4 {
	float m[4][4]; // row-major: m[row][col]
	
	Mat4() : m{} {
		m[0][0] = 1.0f;
		m[1][1] = 1.0f;
		m[2][2] = 1.0f;
		m[3][3] = 1.0f;
	}

	static Mat4 identity() {
		return Mat4();
	}

	Mat4 operator*(const Mat4& b) const {
		Mat4 result{};

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				result.m[i][j] = 0.0f;
				for (int k = 0; k < 4; k++) {
					result.m[i][j] += m[i][k] * b.m[k][j];
				}
			}
		}

		return result;
	}

	Vec3 multiplyPoint(const Vec3& v) const {
		Vec3 result{};

		float x = v.x;
		float y = v.y;
		float z = v.z;

		result.x = m[0][0] * x + m[0][1] * y + m[0][2] * z + m[0][3];
		result.y = m[1][0] * x + m[1][1] * y + m[1][2] * z + m[1][3];
		result.z = m[2][0] * x + m[2][1] * y + m[2][2] * z + m[2][3];

		return result;
	}

	Vec3 multiplyDirection(const Vec3& v) const {
		Vec3 result{};

		float x = v.x;
		float y = v.y;
		float z = v.z;

		result.x = m[0][0] * x + m[0][1] * y + m[0][2] * z;
		result.y = m[1][0] * x + m[1][1] * y + m[1][2] * z;
		result.z = m[2][0] * x + m[2][1] * y + m[2][2] * z;

		return result;
	}
};