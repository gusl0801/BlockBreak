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

	//벡터의 내적 연산을 통해 두 벡터 간의 각도를 계산 할 수 있다.
	float Dot(const Vector2D<T> &other) const { return (x * other.x) + (y * other.y); }

	//2차원 벡터의 외적 연산을 통해 방향성 판단을 할 수 있다.
	//ccw or cw
	//http://bowbowbow.tistory.com/14
	float Cross(const Vector2D<T> &other) const { return (x * other.y) - (y * other.x); }

	//반사 벡터를 계산한다.
	// return value : reflection Vector
	// parameter : collision position
	// this : Incident Vector
	Vector2D<T> Reflect(const Vector2D<T> &collsion) const;

	//벡터를 정규화시킨다.
	void Normalize();
	static void Normalize(Vector2D<T> &that);

	//벡터의 길이를 계산한다.
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
