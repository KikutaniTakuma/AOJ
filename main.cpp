#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <array>
#include <string>

#include <array>

#define _USE_MATH_DEFINES
#include <math.h>

#pragma region Hoge

/// <summary>
/// �O�����z��
/// </summary>
class Vector3 final {
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
public:
	constexpr Vector3() noexcept;
	Vector3(float x, float y, float z) noexcept;
	constexpr Vector3(const Vector3&) noexcept = default;
	constexpr Vector3(Vector3&&) noexcept = default;
public:
	~Vector3() = default;

	/// <summary>
	/// ���Z�q�̃I�[�o�[���[�h
	/// </summary>
public:
	// �P�����Z�q

	 Vector3 operator+() const noexcept;
	 Vector3 operator-() const noexcept;


	// �񍀉��Z�q

	Vector3& operator=(const Vector3&) = default;
	Vector3& operator=(Vector3&&) = default;
	 Vector3 operator+(const Vector3& right) const noexcept;
	 Vector3 operator-(const Vector3& right) const noexcept;
	Vector3& operator+=(const Vector3& right) noexcept;
	Vector3& operator-=(const Vector3& right) noexcept;
	 Vector3 operator*(float scalar) const noexcept;
	Vector3& operator*=(float scalar) noexcept;
	 Vector3 operator/(float scalar) const noexcept;
	Vector3& operator/=(float scalar) noexcept;

	 Vector3 operator*(const class Quaternion& right) const;
	Vector3& operator*=(const class Quaternion& right);


	// ���䉉�Z�q

	 bool operator==(const Vector3& right) const noexcept;
	 bool operator!=(const Vector3& right) const noexcept;

	// 
	 float& operator[](size_t index);
	 const float& operator[](size_t index) const;


	/// <summary>
	/// �����o�֐�
	/// </summary>
public:
	 float Dot(const Vector3& right) const noexcept;
	 Vector3 Cross(const Vector3& right) const noexcept;
	 float Length() const noexcept;
	 Vector3 Normalize() const noexcept;

	/// <summary>
	/// �ÓI�萔
	/// </summary>
public:
	/// <summary>
	/// x = 1.0f, y = 1.0f, z = 1.0f
	/// </summary>
	static const Vector3 kIdentity;
	/// <summary>
	/// x = 0.0f, y = 0.0f, z = 0.0f
	/// </summary>
	static const Vector3 kZero;
	/// <summary>
	/// x = 1.0f, y = 0.0f, z = 0.0f
	/// </summary>
	static const Vector3 kXIdentity;
	/// <summary>
	/// x = 0.0f, y = 1.0f, z = 0.0f
	/// </summary>
	static const Vector3 kYIdentity;
	/// <summary>
	/// x = 0.0f, y = 0.0f, z = 1.0f
	/// </summary>
	static const Vector3 kZIdentity;

	/// <summary>
	/// �����o�ϐ�
	/// </summary>
public:
	float x;
	float y;
	float z;
};




/// <summary>
/// 4�����z��
/// </summary>
class Vector4 final {
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
public:
	constexpr Vector4() noexcept;
	constexpr Vector4(const Vector4&) = default;
	constexpr Vector4(Vector4&&) = default;
	Vector4(float x, float y, float z, float w) noexcept;
	Vector4(const class Vector3& vec3, float w) noexcept;
	Vector4(const std::array<float, 4>& right) noexcept;
public:
	~Vector4() = default;

	/// <summary>
	/// ���Z�q�̃I�[�o�[���[�h
	/// </summary>
public:
	 Vector4 operator+() const noexcept;
	 Vector4 operator-() const noexcept;

	Vector4& operator=(const Vector4& right) noexcept = default;
	Vector4& operator=(Vector4&& right) noexcept = default;
	Vector4& operator=(const class Vector3& right) noexcept;

	 Vector4 operator+(const Vector4& right) const noexcept;
	Vector4& operator+=(const Vector4& right) noexcept;

	 Vector4 operator-(const Vector4& right) const noexcept;
	Vector4& operator-=(const Vector4& right) noexcept;

	 Vector4 operator*(float scalar) const noexcept;
	Vector4& operator*=(float scalar) noexcept;
	 Vector4 operator/(float scalar) const noexcept;
	Vector4& operator/=(float scalar) noexcept;

	 bool operator==(const Vector4& right) const noexcept;
	 bool operator!=(const Vector4& right) const noexcept;

	 float& operator[](size_t index) noexcept {
		return m[index];
	}

	 const float& operator[](size_t index) const noexcept {
		return m[index];
	}

	/// <summary>
	/// �����o�֐�
	/// </summary>
public:
	 float Length() const noexcept;

	 Vector4 Normalize() const noexcept;

	 float Dot(const Vector4& right) const noexcept;

	 class Vector3 GetVector3() const noexcept;

	/// <summary>
	/// �ÓI�萔
	/// </summary>
public:
	/// <summary>
	/// x = 1.0f, y = 1.0f, z = 1.0f, w = 1.0f
	/// </summary>
	static const Vector4 kIdentity;
	/// <summary>
	/// x = 0.0f, y = 0.0f, z = 0.0f, w = 0.0f
	/// </summary>
	static const Vector4 kZero;
	/// <summary>
	/// x = 1.0f, y = 0.0f, z = 0.0f, w = 0.0f
	/// </summary>
	static const Vector4 kXIdentity;
	/// <summary>
	/// x = 0.0f, y = 1.0f, z = 0.0f, w = 0.0f
	/// </summary>
	static const Vector4 kYIdentity;
	/// <summary>
	/// x = 0.0f, y = 0.0f, z = 1.0f, w = 0.0f
	/// </summary>
	static const Vector4 kZIdentity;
	/// <summary>
	/// x = 0.0f, y = 0.0f, z = 0.0f, w = 1.0f
	/// </summary>
	static const Vector4 kWIdentity;


	/// <summary>
	/// �����o�ϐ�
	/// </summary>
public:
	union {
		std::array<float, 4> m;
		struct {
			float x;
			float y;
			float z;
			float w;
		} vec;
		struct {
			float r;
			float g;
			float b;
			float a;
		} color;
	};

};

/// <summary>
/// �N�H�[�^�j�I���N���X
/// </summary>
class Quaternion final {
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
public:
	constexpr Quaternion();
	constexpr Quaternion(const Quaternion&) = default;
	constexpr Quaternion(Quaternion&&) = default;
	Quaternion(const Vector4& right);
	Quaternion(const Vector3& right, float w);
	Quaternion(const std::array<float, 4>& right);
	Quaternion(float x, float y, float z, float w);
	~Quaternion() = default;

	/// <summary>
	/// �P�����Z�q
	/// </summary>
public:
	 Quaternion operator+() const noexcept;
	 Quaternion operator-() const noexcept;

	/// <summary>
	/// �񍀉��Z�q�̃I�[�o�[���[�h
	/// </summary>
public:
	Quaternion& operator=(const Quaternion&) = default;
	Quaternion& operator=(Quaternion&&)noexcept = default;

	Quaternion& operator=(const Vector4& right);

	 Quaternion operator*(const Quaternion& right) const;
	Quaternion& operator*=(const Quaternion& right);

	 Quaternion operator+(const Quaternion& right) const;
	Quaternion& operator+=(const Quaternion& right);

	 Quaternion operator-(const Quaternion& right) const;
	Quaternion& operator-=(const Quaternion& right);

	 Quaternion operator*(float right) const;
	friend Quaternion operator*(float right, const Quaternion& left);
	Quaternion& operator*=(float right);

	 Quaternion operator/(float right) const;
	friend Quaternion operator/(float right, const Quaternion& left);
	Quaternion& operator/=(float right);

	 bool operator==(const Quaternion& right) const;
	 bool operator!=(const Quaternion& right) const;

public:
	/// <summary>
	/// ����
	/// </summary>
	/// <returns>���̃N�H�[�^�j�I���̋����𔽓]����������</returns>
	 Quaternion Conjugate() const;

	/// <summary>
	/// �N�H�[�^�j�I����4�����x�N�g���Ƃ��Ă̓���
	/// </summary>
	/// <param name="other">���̃N�H�[�^�j�I��</param>
	/// <returns>���ό���</returns>
	 float Dot(const Quaternion& other) const;

	/// <summary>
	/// �����擾
	/// </summary>
	/// <returns>�m����</returns>
	 float Length() const;

	/// <summary>
	/// ����1�̃N�H�[�^�j�I����Ԃ�
	/// </summary>
	/// <returns>�P�ʃN�H�[�^�j�I��</returns>
	 Quaternion Normalize() const;

	/// <summary>
	/// �t�N�H�[�^�j�I����Ԃ�
	/// </summary>
	/// <returns>�t�N�H�[�^�j�I��</returns>
	 Quaternion Inverce() const;

	 Vector3 GetDirectionX() const;

	 Vector3 GetDirectionY() const;

	 Vector3 GetDirectionZ() const;



	/// <summary>
	/// �ÓI�����o�֐�
	/// </summary>
public:
	/// <summary>
	/// �N�H�[�^�j�I���ł�DirectionToDirection
	/// </summary>
	/// <param name="from">�n�_</param>
	/// <param name="to">�I�_</param>
	/// <returns>�N�H�[�^�j�I��</returns>
	static  Quaternion DirectionToDirection(const Vector3& from, const Vector3& to);

	/// <summary>
	/// �C�ӎ���]
	/// </summary>
	/// <param name="axis">�C�ӎ��̕����x�N�g��(�P�ʃx�N�g��)</param>
	/// <param name="angle">�C�ӎ��ł̉�]��</param>
	/// <returns>�C�ӎ���]��K�p�����N�H�[�^�j�I��</returns>
	static  Quaternion MakeRotateAxisAngle(const Vector3& axis, float angle);
	/// <summary>
	/// x����]�N�H�[�^�j�I��
	/// </summary>
	/// <param name="angle">�I�C���[�p</param>
	/// <returns>x����]��K�p�����N�H�[�^�j�I��</returns>
	static  Quaternion MakeRotateXAxis(float angle);
	// <summary>
	/// y����]�N�H�[�^�j�I��
	/// </summary>
	/// <param name="angle">�I�C���[�p</param>
	/// <returns>y����]��K�p�����N�H�[�^�j�I��</returns>
	static  Quaternion MakeRotateYAxis(float angle);
	// <summary>
	/// z����]�N�H�[�^�j�I��
	/// </summary>
	/// <param name="angle">�I�C���[�p</param>
	/// <returns>z����]��K�p�����N�H�[�^�j�I��</returns>
	static  Quaternion MakeRotateZAxis(float angle);

	/// <summary>
	/// �N�H�[�^�j�I�����`�⊮�֐�(�߂����̂̕����ɉ�]����)
	/// </summary>
	/// <param name="start">�X�^�[�g���̉�]</param>
	/// <param name="end">�I���̉�]</param>
	/// <param name="t">0.0f�`1.0f</param>
	/// <returns>�⊮���ꂽ�N�H�[�^�j�I��</returns>
	static  Quaternion Slerp(Quaternion start, const Quaternion& end, float t);


	/// <summary>
	/// �ÓI�����o�萔
	/// </summary>
public:
	/// <summary>
	/// x = 0.0f, y = 0.0f, z = 0.0f w = 1.0f
	/// </summary>
	static const Quaternion kIdentity;

	/// <summary>
	/// x = 0.0f, y = 0.0f, z = 0.0f w = 0.0f
	/// </summary>
	static const Quaternion kZero;

	/// <summary>
	/// �����o�ϐ�
	/// </summary>
public:
	union
	{
		std::array<float, 4> m;
		Vector4 vector4;
		struct {
			Vector3 vector3;
			float w;
		}vector;

		struct {
			float x;
			float y;
			float z;
			float w;
		}quaternion;
	};
};
#pragma region Vector3

constexpr Vector3::Vector3() noexcept :
	x(0.0f),
	y(0.0f),
	z(0.0f)
{}

Vector3::Vector3(float x, float y, float z) noexcept :
	x(x),
	y(y),
	z(z)
{}

const Vector3 Vector3::kIdentity = { 1.0f,1.0f,1.0f };
const Vector3 Vector3::kZero = { 0.0f, 0.0f,0.0f };
const Vector3 Vector3::kXIdentity = { 1.0f,0.0f,0.0f };
const Vector3 Vector3::kYIdentity = { 0.0f,1.0f,0.0f };
const Vector3 Vector3::kZIdentity = { 0.0f,0.0f,1.0f };

Vector3 Vector3::operator+() const noexcept {
	return *this;
}
Vector3 Vector3::operator-() const noexcept {
	return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator+(const Vector3& right) const noexcept {
	Vector3 tmp(x + right.x, y + right.y, z + right.z);

	return tmp;
}
Vector3 Vector3::operator-(const Vector3& right) const noexcept {
	Vector3 tmp(x - right.x, y - right.y, z - right.z);

	return tmp;
}
Vector3& Vector3::operator+=(const Vector3& right) noexcept {
	*this = *this + right;

	return *this;
}
Vector3& Vector3::operator-=(const Vector3& right) noexcept {
	*this = *this - right;

	return *this;
}

Vector3 Vector3::operator*(float scalar) const noexcept {
	Vector3 tmp(x * scalar, y * scalar, z * scalar);

	return tmp;
}
Vector3& Vector3::operator*=(float scalar) noexcept {
	*this = *this * scalar;

	return *this;
}

Vector3 Vector3::operator/(float scalar) const noexcept {
	Vector3 tmp(x / scalar, y / scalar, z / scalar);

	return tmp;
}
Vector3& Vector3::operator/=(float scalar) noexcept {
	*this = *this / scalar;

	return *this;
}

Vector3 Vector3::operator*(const Quaternion& right) const {
	return (right * Quaternion{ *this, 0.0f } *right.Inverce()).vector.vector3;
}

Vector3& Vector3::operator*=(const Quaternion& right) {
	*this = *this * right;

	return *this;
}

bool Vector3::operator==(const Vector3& right) const noexcept {
	return x == right.x && y == right.y && z == right.z;
}
bool Vector3::operator!=(const Vector3& right) const noexcept {
	return x != right.x || y != right.y || z != right.z;
}

float& Vector3::operator[](size_t index) {
	std::array<float*, 3> tmp = { &x,&y,&z };
	return *tmp[index];
}

const float& Vector3::operator[](size_t index) const {
	std::array<const float*, 3> tmp = { &x,&y,&z };
	return *tmp[index];
}

float Vector3::Length() const noexcept {
	return std::sqrt(x * x + y * y + z * z);
}

float Vector3::Dot(const Vector3& right) const noexcept {
	return x * right.x + y * right.y + z * right.z;
}

Vector3 Vector3::Cross(const Vector3& right) const noexcept {
	Vector3 result;

	result.x = y * right.z - z * right.y;
	result.y = z * right.x - x * right.z;
	result.z = x * right.y - y * right.x;

	return result;
}

Vector3 Vector3::Normalize() const noexcept {
	if (*this == Vector3::kZero) {
		return Vector3::kZero;
	}

	return *this / this->Length();
}

#pragma endregion

#pragma region Vector4
const Vector4 Vector4::kIdentity = { 1.0f,1.0f,1.0f,1.0f };
const Vector4 Vector4::kZero = { 0.0f, 0.0f, 0.0f, 0.0f };
const Vector4 Vector4::kXIdentity = { 1.0f, 0.0f, 0.0f, 0.0f };
const Vector4 Vector4::kYIdentity = { 0.0f, 1.0f, 0.0f, 0.0f };
const Vector4 Vector4::kZIdentity = { 0.0f, 0.0f, 1.0f, 0.0f };
const Vector4 Vector4::kWIdentity = { 0.0f, 0.0f, 0.0f, 1.0f };

constexpr Vector4::Vector4() noexcept :
	m{ 0.0f }
{}

Vector4::Vector4(float x, float y, float z, float w) noexcept :
	m{ x,y,z,w }
{}

Vector4::Vector4(const Vector3& vec3, float w) noexcept :
	m{ vec3.x,vec3.y,vec3.z,w }
{}

Vector4::Vector4(const std::array<float, 4>& right) noexcept
{
	m = right;
}

Vector4 Vector4::operator+() const noexcept {
	return *this;
}
Vector4 Vector4::operator-() const noexcept {
	return { -m[0], -m[1], -m[2], -m[3] };
}

Vector4& Vector4::operator=(const Vector3& right) noexcept {
	vec.x = right.x;
	vec.y = right.y;
	vec.z = right.z;
	vec.w = 0.0f;

	return *this;
}

Vector4 Vector4::operator+(const Vector4& right) const noexcept {
	Vector4 result;

	for (size_t i = 0; i < result.m.size(); i++) {
		result.m[i] = m[i] + right.m[i];
	}

	return result;
}

Vector4& Vector4::operator+=(const Vector4& right) noexcept {
	*this = *this + right;

	return *this;
}

Vector4 Vector4::operator-(const Vector4& right) const noexcept {
	Vector4 result;

	for (size_t i = 0; i < result.m.size(); i++) {
		result.m[i] = m[i] - right.m[i];
	}

	return result;
}

Vector4& Vector4::operator-=(const Vector4& right) noexcept {
	*this = *this - right;

	return *this;
}

Vector4 Vector4::operator*(float scalar) const noexcept {
	Vector4 result;

	for (size_t i = 0; i < result.m.size(); i++) {
		result.m[i] = m[i] * scalar;
	}

	return result;
}
Vector4& Vector4::operator*=(float scalar) noexcept {
	*this = *this * scalar;

	return *this;
}

Vector4 Vector4::operator/(float scalar) const noexcept {
	Vector4 result;
	scalar = 1.0f / scalar;

	for (size_t i = 0; i < result.m.size(); i++) {
		result.m[i] = m[i] * scalar;
	}

	return result;
}
Vector4& Vector4::operator/=(float scalar) noexcept {
	*this = *this / scalar;

	return *this;
}

bool Vector4::operator==(const Vector4& right) const noexcept {
	return m == right.m;
}
bool Vector4::operator!=(const Vector4& right) const noexcept {
	return m != right.m;
}

float Vector4::Length() const noexcept {
	return std::sqrt(Dot(*this));
}

Vector4 Vector4::Normalize() const noexcept {
	if (*this == Vector4()) {
		return *this;
	}

	float nor = 1.0f / this->Length();

	return Vector4(*this) * nor;
}

float Vector4::Dot(const Vector4& right) const noexcept {
	return vec.x * right.vec.x + vec.y * right.vec.y + vec.z * right.vec.z + vec.w * right.vec.w;
}

Vector3 Vector4::GetVector3() const noexcept {
	return Vector3(vec.x, vec.y, vec.z);
}

Vector4 UintToVector4(uint32_t color) {
	static constexpr float normal = 1.0f / static_cast<float>(std::numeric_limits<uint8_t>::max());
	Vector4 result;

	result.color = {
		static_cast<float>((color & 0xff000000) >> 24) * normal,
		static_cast<float>((color & 0x00ff0000) >> 16) * normal,
		static_cast<float>((color & 0x0000ff00) >> 8) * normal,
		static_cast<float>(color & 0x000000ff) * normal
	};
	return result;
}

#pragma endregion


#pragma region Quaternion
/// ========================================================================
/// �ÓI�����o�萔
/// ========================================================================
#pragma region Constant Number
const Quaternion Quaternion::kIdentity = { 0.0f, 0.0f, 0.0f, 1.0f };
const Quaternion Quaternion::kZero = { 0.0f, 0.0f, 0.0f, 0.0f };
#pragma endregion
/// ========================================================================
/// ========================================================================
/// ========================================================================

/// ========================================================================
/// �R���X�g���N�^
/// ========================================================================
#pragma region Constructor
constexpr Quaternion::Quaternion() :
	m{ 0.0f }
{}

Quaternion::Quaternion(const Vector4& right) :
	Quaternion()
{
	*this = right;
}

Quaternion::Quaternion(const Vector3& right, float w) {
	vector.vector3 = right;
	vector.w = w;
}

Quaternion::Quaternion(const std::array<float, 4>& right) {
	m = right;
}

Quaternion::Quaternion(float x, float y, float z, float w) {
	m = { x,y,z,w };
}
#pragma endregion
/// ========================================================================
/// ========================================================================
/// ========================================================================

/// ========================================================================
/// �R�s�[���Z�q
/// ========================================================================
#pragma region Copy operator
Quaternion& Quaternion::operator=(const Vector4& right) {
	m = right.m;

	return *this;
}
#pragma endregion
/// ========================================================================
/// ========================================================================
/// ========================================================================

/// ========================================================================
/// �P�����Z�q
/// ========================================================================
#pragma region Unary operator
Quaternion Quaternion::operator+() const noexcept {
	return *this;
}
Quaternion Quaternion::operator-() const noexcept {
	return Quaternion{ -m[0],-m[1],-m[2],-m[3] };
}
#pragma endregion
/// ========================================================================
/// ========================================================================
/// ========================================================================

/// ========================================================================
/// ��Z���Z�q
/// ========================================================================
#pragma region Multiplication operator
Quaternion Quaternion::operator*(const Quaternion& right) const {
	Quaternion result;

	result = Quaternion{
		vector.vector3.Cross(right.vector.vector3) + vector.vector3 * right.vector.w + right.vector.vector3 * vector.w,
		vector.w * right.vector.w - vector.vector3.Dot(right.vector.vector3)
	};

	return result;
}
Quaternion& Quaternion::operator*=(const Quaternion& right) {
	*this = *this * right;

	return *this;
}
#pragma endregion
/// ========================================================================
/// ========================================================================
/// ========================================================================

/// ========================================================================
/// ���Z���Z�q
/// ========================================================================
#pragma region Add operator
Quaternion Quaternion::operator+(const Quaternion& right) const {
	Quaternion result;

	result = vector4 + right.vector4;

	return result;
}
Quaternion& Quaternion::operator+=(const Quaternion& right) {
	*this = *this + right;

	return *this;
}
#pragma endregion
/// ========================================================================
/// ========================================================================
/// ========================================================================

/// ========================================================================
/// ���Z���Z�q
/// ========================================================================
#pragma region Sub operator
Quaternion Quaternion::operator-(const Quaternion& right) const {
	Quaternion result;

	result = vector4 - right.vector4;

	return result;
}
Quaternion& Quaternion::operator-=(const Quaternion& right) {
	*this = *this - right;

	return *this;
}
#pragma endregion
/// ========================================================================
/// ========================================================================
/// ========================================================================

/// ========================================================================
/// �X�J���[�{���Z�q
/// ========================================================================
#pragma region Scalar operator
Quaternion Quaternion::operator*(float right) const {
	Quaternion result{ *this };

	result.vector4 *= right;

	return result;
}
Quaternion operator*(float right, const Quaternion& left) {
	return left * right;
}
Quaternion& Quaternion::operator*=(float right) {
	*this = *this * right;

	return *this;
}

Quaternion Quaternion::operator/(float right) const {
	return *this * (1.0f / right);
}
 Quaternion operator/(float right, const Quaternion& left) {
	return left / right;
}
Quaternion& Quaternion::operator/=(float right) {
	*this = *this / right;

	return *this;
}
#pragma endregion
/// ========================================================================
/// ========================================================================
/// ========================================================================

/// ========================================================================
/// ���l���Z�q
/// ========================================================================
#pragma region Equal operator
bool Quaternion::operator==(const Quaternion& right) const {
	return m == right.m;
}
bool Quaternion::operator!=(const Quaternion& right) const {
	return m != right.m;
}
#pragma endregion
/// ========================================================================
/// ========================================================================
/// ========================================================================


/// ========================================================================
/// �����o�֐�
/// ========================================================================
#pragma region Member function
Quaternion Quaternion::Conjugate() const {
	return Quaternion{ -vector.vector3, vector.w };
}

float Quaternion::Dot(const Quaternion& other) const {
	return vector4.Dot(other.vector4);
}

float Quaternion::Length() const {
	return std::sqrt(Dot(*this));
}

Quaternion Quaternion::Normalize() const {
	if (*this == Quaternion::kZero) {
		return *this;
	}

	return Quaternion{ *this } / this->Length();
}

Quaternion Quaternion::Inverce() const {
	return Conjugate() / std::pow(Length(), 2.0f);
}

Vector3 Quaternion::GetDirectionX() const {
	return Vector3(
		std::pow(quaternion.w, 2.0f) + std::pow(quaternion.x, 2.0f) - std::pow(quaternion.y, 2.0f) - std::pow(quaternion.z, 2.0f),
		2.0f * (quaternion.x * quaternion.y + quaternion.w * quaternion.z),
		2.0f * (quaternion.x * quaternion.z - quaternion.w * quaternion.y)
	);
}

Vector3 Quaternion::GetDirectionY() const
{
	return Vector3(
		2.0f * (quaternion.x * quaternion.y - quaternion.w * quaternion.z),
		std::pow(quaternion.w, 2.0f) - std::pow(quaternion.x, 2.0f) + std::pow(quaternion.y, 2.0f) - std::pow(quaternion.z, 2.0f),
		2.0f * (quaternion.y * quaternion.z + quaternion.w * quaternion.x)
	);
}

Vector3 Quaternion::GetDirectionZ() const
{
	return Vector3(
		2.0f * (quaternion.x * quaternion.z + quaternion.w * quaternion.y),
		2.0f * (quaternion.y * quaternion.z - quaternion.w * quaternion.x),
		std::pow(quaternion.w, 2.0f) - std::pow(quaternion.x, 2.0f) - std::pow(quaternion.y, 2.0f) + std::pow(quaternion.z, 2.0f)
	);
}
#pragma endregion
/// ========================================================================
/// ========================================================================
/// ========================================================================

/// ========================================================================
/// �ÓI�����o�֐�
/// ========================================================================
#pragma region Static member function
Quaternion Quaternion::DirectionToDirection(const Vector3& from, const Vector3& to) {
	Quaternion result;
	Vector3 normal;
	float theata = std::acos(from.Dot(to)) * 0.5f;

	if (from.Dot(to) == -1.0f) {
		if (from.x != 0.0f || from.y != 0.0f) {
			normal = Vector3{ from.y, -from.x, 0.0f }.Normalize();
		}
		else if (from.x != 0.0f || from.z != 0.0f) {
			normal = Vector3{ from.z, 0.0f, -from.x }.Normalize();
		}
	}
	else {
		normal = from.Cross(to).Normalize();
	}


	result.vector.w = std::cos(theata);
	result.vector.vector3 = normal * std::sin(theata);

	return result;
}

Quaternion Quaternion::MakeRotateAxisAngle(const Vector3& axis, float angle) {
	Quaternion result;
	result.vector.w = std::cos(angle * 0.5f);
	result.vector.vector3 = axis * std::sin(angle * 0.5f);

	return result;
}
Quaternion Quaternion::MakeRotateXAxis(float angle) {
	return Quaternion{ std::sin(angle * 0.5f),0.0f,0.0f,std::cos(angle * 0.5f), };
}
Quaternion Quaternion::MakeRotateYAxis(float angle) {
	return Quaternion{ 0.0f, std::sin(angle * 0.5f),0.0f,std::cos(angle * 0.5f) };
}
Quaternion Quaternion::MakeRotateZAxis(float angle) {
	return Quaternion{ 0.0f, 0.0f, std::sin(angle * 0.5f),std::cos(angle * 0.5f) };
}

Quaternion Quaternion::Slerp(Quaternion start, const Quaternion& end, float t) {
	float dot = start.Dot(end);
	if (dot < 0.0f) {
		start = -start;
		dot = -dot;
	}
	float theata = std::acos(dot);
	float sinTheata = 1.0f / std::sin(theata);

	static constexpr float kEpsilon = 0.0005f;

	Quaternion result;

	// sin�Ƃ�0.0f�ɂȂ�ꍇ�܂��͂���ɋ߂��Ȃ�ꍇ
	if (1.0f - kEpsilon <= dot) {
		result = (1.0f - t) * start + t * end;
	}
	else {
		result = (std::sin(theata * (1.0f - t)) * sinTheata) * start + (std::sin(theata * t) * sinTheata) * end;
	}

	return result;
}
#pragma endregion
/// ========================================================================
/// ========================================================================
/// ========================================================================
#pragma endregion

class Dice {
public:
	Dice():
		nums(),
		index(0llu),
		direction_()
	{
		direction_[0] = Vector3::kYIdentity;
		direction_[1] = -Vector3::kZIdentity;
		direction_[2] = Vector3::kXIdentity;
		direction_[3] = -Vector3::kXIdentity;
		direction_[4] = Vector3::kZIdentity;
		direction_[5] = -Vector3::kYIdentity;
	}
	Dice(Dice&) = default;
	Dice(Dice&&) = default;
	~Dice() = default;


	Dice& operator=(const Dice&) = default;
	Dice& operator=(Dice&&) = default;

public:
	void Move(const std::string& move) {
		for (auto& i : move) {
			Quaternion quaternion;
			if (i == 'N') {
				quaternion = Quaternion::MakeRotateXAxis(float(M_PI) * 0.5f);
			}
			else if (i == 'S') {
				quaternion = Quaternion::MakeRotateXAxis(float(-M_PI) * 0.5f);
			}
			else if (i == 'W') {
				quaternion = Quaternion::MakeRotateZAxis(float(M_PI) * 0.5f);
			}
			else if (i == 'E') {
				quaternion = Quaternion::MakeRotateZAxis(float(-M_PI) * 0.5f);
			}

			for (auto& i : direction_) {
				i *= quaternion;
			}
		}
	}

	uint32_t GetTopNum() const {
		return nums[GetCurrentTop()];
	}


private:
	size_t GetCurrentTop() const {
		size_t result = 0;

		Vector3 topDirection = Vector3::kYIdentity;

		for (auto& i : direction_) {
			if (topDirection == i) {
				break;
			}
			else {
				result++;
			}
		}

		return result;
	}

public:
	void Set(uint32_t num) {
		nums[index] = num;
		index++;
	}

private:
	std::array<uint32_t, 6> nums;
	std::array<Vector3, 6> direction_;
	size_t index;
};


int main() {
	Dice dice;

	for (size_t i = 0; i < 6; i++) {
		uint32_t input;
		cin >> input;
		dice.Set(input);
	}

	std::string move;
	cin >> move;

	dice.Move(move);

	cout << dice.GetTopNum() << endl;

	return 0;
}