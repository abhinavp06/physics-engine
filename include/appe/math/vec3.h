#pragma once
#include <cmath>

struct Vec3 {
    float x, y, z;

    Vec3() : x(0), y(0), z(0) {}
    Vec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}

    Vec3 operator+(const Vec3& b) const {
        return Vec3(x + b.x, y + b.y, z + b.z);
    }

    Vec3 operator-() const {
        return Vec3(-x, -y, -z); // unary negate: -v
    }

    Vec3 operator-(const Vec3& b) const {
        return Vec3(x - b.x, y - b.y, z - b.z);
    }

    Vec3 operator*(float s) const {
        return Vec3(x * s, y * s, z * s);
    }

    float length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    float lengthSquared() const {
        return x * x + y * y + z * z;
    }

    Vec3 normalized() const {
        float len = length();
        if (len < 1e-8f) return Vec3();
        return (*this) * (1.0f / len);
    }

    void normalize() {
        float len = length();
        if (len < 1e-8f) return;
        x /= len;
        y /= len;
        z /= len;
    }
};

inline Vec3 operator*(float s, const Vec3& v) { return v * s; }

inline float dot(const Vec3& a, const Vec3& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline Vec3 cross(const Vec3& a, const Vec3& b) {
    return Vec3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}