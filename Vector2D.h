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
	static Vector2D<T> Clamp(const Vector2D<T> &that, double low, double high);

public:
	Vector2D() { x = y = T{}; }
	Vector2D(T x, T y) :x(x), y(y) {}
	~Vector2D() {}

	//������ ���� ������ ���� �� ���� ���� ������ ��� �� �� �ִ�.
	float Dot(const Vector2D<T> &other) const { return (x * other.x) + (y * other.y); }

	//2���� ������ ���� ������ ���� ���⼺ �Ǵ��� �� �� �ִ�.
	//ccw or cw
	//http://bowbowbow.tistory.com/14
	float Cross(const Vector2D<T> &other) const { return (x * other.y) - (y * other.x); }

	//�ݻ� ���͸� ����Ѵ�.
	// return value : reflection Vector
	// parameter : collision position
	// this : Incident Vector
	Vector2D<T> Reflect(const Vector2D<T> &collsion) const;

	//���͸� ����ȭ��Ų��.
	void Normalize();
	static void Normalize(Vector2D<T> &that);

	//������ ���̸� ����Ѵ�.
	float Length() const { return std::sqrt(Dot(*this)); }
	static float Length(const Vector2D<T> &that) { return sqrt(that.Dot()); }

	bool isZero() const { return ::isZero(x) && ::isZero(y); }
public:
	Vector2D<T> operator+(const Vector2D<T> &other) const { return Vector2D<T>{ x + other.x, y + other.y }; }
	Vector2D<T> operator+(double scalar) const { return Vector2D<T>{ x + scalar, y + scalar }; }
	Vector2D<T> operator-(const Vector2D<T> &other) const { return Vector2D<T>{ x - other.x, y - other.y }; }
	Vector2D<T> operator-(double scalar) const { return Vector2D<T>{ x - scalar, y - scalar }; }
	Vector2D<T> operator*(const Vector2D<T> &other) const { return Vector2D<T>{ x * other.x, y * other.y }; }
	Vector2D<T> operator*(double scalar) const { return Vector2D<T>{ x * scalar, y * scalar }; }
	Vector2D<T> operator/(const Vector2D<T> &other) const { return Vector2D<T>{ x / other.x, y / other.y }; }
	
	Vector2D<T>& operator+=(const Vector2D<T> &other) { return *this = *this + other; }
	Vector2D<T>& operator+=(double sclar) { return *this = *this + sclar; }
	Vector2D<T>& operator-=(const Vector2D<T> &other) { return *this = *this - other; }
	Vector2D<T>& operator-=(double sclar) { return *this = *this - sclar; }
	Vector2D<T>& operator*=(const Vector2D<T> &other) { return *this = *this * other; }
	Vector2D<T>& operator*=(double sclar) { return *this = *this * sclar; }
	Vector2D<T>& operator/=(const Vector2D<T> &other) { return *this = *this / other; }
	Vector2D<T>& operator= (const Vector2D<T> &other) { x = other.x, y = other.y; return *this; }

	bool operator==(const Vector2D<T> &other) const { return (x == other.x && y == other.y); }
	bool operator!=(const Vector2D<T> &other) const { return (x != other.x && y != other.y); }

};

using Vector2i = Vector2D<int>;
using Vector2f = Vector2D<float>;
using Vector2d = Vector2D<double>;

template<class T>
inline Vector2D<T> Vector2D<T>::Clamp(const Vector2D<T>& that, double low, double high)
{
	double x = clamp(that.x, low, high);
	double y = clamp(that.y, low, high);
	return Vector2D<T>{x, y};
}

template<class T>
inline Vector2D<T> Vector2D<T>::Reflect(const Vector2D<T>& collsion) const
{
	Vector2d normal;
	return Vector2D<T>();
}
