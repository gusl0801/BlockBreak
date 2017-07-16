#pragma once

template <class T>
class Vector2D
{
public:
	union
	{
		T arr[2];
		struct { T x, y; };
	};

public:
	Vector2D() { x = y = T{}; }
	Vector2D(T x, T y) :x(x), y(y) {}
	~Vector2D() {}

	//������ ���� ������ ���� �� ���� ���� ������ ��� �� �� �ִ�.
	float Dot(Vector2D<T> &other) const { return (x * other.x) + (y * other.y); }

	//2���� ������ ���� ������ ���� ���⼺ �Ǵ��� �� �� �ִ�.
	//ccw or cw
	//http://bowbowbow.tistory.com/14
	float Cross(const Vector2D<T> &other) const { return (x * other.y) - (y * other.x); }
	
	//�ݻ� ���͸� ����Ѵ�.
	Vector2D<T> Reflect(const Vector2D<T> &other) const;

	//���͸� ����ȭ��Ų��.
	void Normalize();
	static void Normalize(Vector2D<T> &that);

	//������ ���̸� ����Ѵ�.
	float Length() const { return std::sqrt(Dot(this)); }
	static float Length(const Vector2D<T> &that) { return sqrt(that.Dot()); }

public:
	Vector2D<T> operator+(const Vector2D<T> &other) const { return { x + other, y + other.y }; }
	Vector2D<T> operator+(int scalar) const { return { x + scalar, y + scalar }; }
	Vector2D<T> operator-(const Vector2D<T> &other) const { return { x - other, y - other.y }; }
	Vector2D<T> operator-(int scalar) const { return { x - scalar, y - scalar }; }
	Vector2D<T> operator*(const Vector2D<T> &other) const { return { x * other, y * other.y }; }
	Vector2D<T> operator*(int scalar) const { return { x * scalar, y * scalar }; }
	Vector2D<T> operator/(const Vector2D<T> &other) const { return { x / other, y / other.y }; }
	
	Vector2D<T>& operator+=(const Vector2D<T> &other) { return *this = *this + other; }
	Vector2D<T>& operator+=(int sclar) { return *this = *this + sclar; }
	Vector2D<T>& operator-=(const Vector2D<T> &other) { return *this = *this - other; }
	Vector2D<T>& operator-=(int sclar) { return *this = *this - sclar; }
	Vector2D<T>& operator*=(const Vector2D<T> &other) { return *this = *this * other; }
	Vector2D<T>& operator*=(int sclar) { return *this = *this * sclar; }
	Vector2D<T>& operator/=(const Vector2D<T> &other) { return *this = *this / other; }
	Vector2D<T>& operator= (const Vector2D<T> &other) { x = other.x, y = other.y; return *this; }

	bool operator==(const Vector2D<T> &other) const { return (x == other.x && y == other.y); }
	bool operator!=(const Vector2D<T> &other) const { return (x != other.x && y != other.y); }
};

using Vector2i = Vector2D<int>;
using Vector2f = Vector2D<float>;
using Vector2d = Vector2D<double>;
