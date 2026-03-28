#pragma once
#include <cmath>

struct Vec2 {
    float x, y;

    Vec2() : x(0), y(0) {}
    Vec2(float x_, float y_) : x(x_), y(y_) {}

    Vec2 operator+(const Vec2& b) const {
        return Vec2(x + b.x, y + b.y);
    }

    Vec2 operator-() const {
        return Vec2(-x, -y); // unary negate: -v
    }

    Vec2 operator-(const Vec2& b) const {
        return Vec2(x - b.x, y - b.y);
    }

    Vec2 operator*(float s) const {
        return Vec2(x * s, y * s);
    }

    Vec2 operator/(float s) const { 
        return Vec2(x / s, y / s); 
    }

    float length() const {
        return std::sqrt(x * x + y * y);
    }

    float lengthSquared() const {
        return x * x + y * y;
    }

    Vec2 normalized() const {
        float len = length();
        if (len < 1e-8f) return Vec2();
        return (*this) * (1.0f / len);
    }

    void normalize() {
        float len = length();
        if (len < 1e-8f) return;
        x /= len;
        y /= len;
    }
};

inline Vec2 operator*(float s, const Vec2& v) { return v * s; }

inline float dot(const Vec2& a, const Vec2& b) {
    return a.x * b.x + a.y * b.y;
}

inline float cross(const Vec2& a, const Vec2& b) {
    return a.x * b.y - a.y * b.x;
}