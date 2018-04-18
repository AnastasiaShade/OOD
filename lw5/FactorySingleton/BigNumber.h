#pragma once

#pragma once
class CBigNumber
{
public:
	CBigNumber();
	CBigNumber(const std::string & strValue);
	CBigNumber(int intValue);
	CBigNumber Sqrt(const CBigNumber & value) const;
	CBigNumber Pow(const CBigNumber & value, size_t exponent) const;

	std::string GetValue() const;
	std::string GetAbsValue() const;
	bool IsNegative() const;

	~CBigNumber() = default;

private:
	void SetNegativeSign(std::string & value);

	std::string m_value;
	bool m_isNegative;
};

const CBigNumber operator+(const CBigNumber & left, const CBigNumber & right);
const std::string Add(const std::string & left, const std::string & right);

const CBigNumber operator-(const CBigNumber & left, const CBigNumber & right);
const std::string Substract(const std::string & left, const std::string & right);

const CBigNumber operator*(const CBigNumber & left, const CBigNumber & right);
const std::string Multiplication(const std::string & left, char rightValue);

const CBigNumber operator/(const CBigNumber & left, const CBigNumber & right);
const std::string Division(const std::string & left, const std::string & right);

const bool IsRightValueLarger(const std::string& left, const std::string& right);
const void AddZeros(std::string & value, size_t count);
const void EraseZeros(std::string & value);
