#include "stdafx.h"
#include "BigNumber.h"

CBigNumber::CBigNumber()
	: m_value("0")
	, m_isNegative(false)
{
}

CBigNumber::CBigNumber(const std::string & strValue)
{
	std::string value = strValue;
	SetNegativeSign(value);

	EraseZeros(value);

	if (value == "0")
	{
		m_isNegative = false;
	}

	m_value = value;
}

CBigNumber::CBigNumber(int intValue)
{
	std::string value = std::to_string(intValue);
	SetNegativeSign(value);
	m_value = value;
	if (value == "0")
	{
		m_isNegative = false;
	}
}

std::string CBigNumber::GetValue() const
{
	std::string sign = (m_isNegative) ? MINUS_VALUE : "";
	return sign + m_value;
}

std::string CBigNumber::GetAbsValue() const
{
	return m_value;
}

bool CBigNumber::IsNegative() const
{
	return m_isNegative;
}

CBigNumber CBigNumber::Sqrt(const CBigNumber & value) const
{
	CBigNumber t;
	CBigNumber squareRoot = value / 2;
	CBigNumber sub;

	do
	{
		t = squareRoot;
		squareRoot = (t + (value / t)) / 2;
		sub = t - squareRoot;
	} 
	while (sub.GetAbsValue() != "0");

	return squareRoot;
}

CBigNumber CBigNumber::Pow(const CBigNumber & value, size_t exponent) const
{
	CBigNumber base = value, mult = value;

	for (size_t i = 0; i < exponent - 1; ++i)
	{
		base = base * mult;
	}

	return base;
}

void CBigNumber::SetNegativeSign(std::string & value)
{
	if (!isdigit(value[0]))
	{
		m_isNegative = true;
		value.erase(0, 1);
	}
	else
	{
		m_isNegative = false;
	}
}

const CBigNumber operator+(const CBigNumber & left, const CBigNumber & right)
{
	std::string result = "";
	CBigNumber tempLeft = left, tempRight = right;
	std::string leftValue = left.GetAbsValue();
	std::string rightValue = right.GetAbsValue();
	bool isNegative = false;

	if (std::max(leftValue, rightValue, &IsRightValueLarger) == rightValue)
	{
		if (tempRight.IsNegative() && leftValue != rightValue)
		{
			isNegative = !isNegative;
		}
		std::swap(tempLeft, tempRight);
		std::swap(leftValue, rightValue);
	}
	else if (tempLeft.IsNegative())
	{
		isNegative = !isNegative;
	}

	result = (tempLeft.IsNegative() != tempRight.IsNegative())
		? Substract(leftValue, rightValue)
		: Add(leftValue, rightValue);

	return CBigNumber((isNegative) ? MINUS_VALUE + result : result);
}

const std::string Add(const std::string & left, const std::string & right)
{
	std::string result = "";
	std::string leftValue = left;
	std::string rightValue = right;
	std::reverse(leftValue.begin(), leftValue.end());
	std::reverse(rightValue.begin(), rightValue.end());

	for (size_t i = 0; i < rightValue.size(); ++i)
	{
		int x = leftValue[i] - '0';
		int y = rightValue[i] - '0';
		int res = x + y;
		if (res >= 10)
		{
			if (i == leftValue.size() - 1)
			{
				leftValue += '0';
			}

			leftValue[i + 1] += res / 10;
			res %= 10;
		}
		result += std::to_string(res);
	}

	if (leftValue.size() > rightValue.size())
	{
		for (size_t i = rightValue.size(); i < leftValue.size(); ++i)
		{
			result.push_back(leftValue[i]);
		}
	}

	std::reverse(result.begin(), result.end());
	EraseZeros(result);

	return result;
}

const CBigNumber operator-(const CBigNumber & left, const CBigNumber & right)
{
	std::string result = "";
	CBigNumber tempLeft = left, tempRight = right;
	std::string leftValue = left.GetAbsValue();
	std::string rightValue = right.GetAbsValue();

	bool isNegative = false, swaped = false;

	if (std::max(leftValue, rightValue, &IsRightValueLarger) == rightValue)
	{
		isNegative = !isNegative;
		swaped = true;
		std::swap(leftValue, rightValue);
		std::swap(tempLeft, tempRight);
	}

	if (tempLeft.IsNegative())
	{
		isNegative = !isNegative;
	}

	result = (tempLeft.IsNegative() != tempRight.IsNegative())
		? Add(leftValue, rightValue)
		: Substract(leftValue, rightValue);

	return CBigNumber((isNegative) ? MINUS_VALUE + result : result);
}

const std::string Substract(const std::string & left, const std::string & right)
{
	std::string result = "";
	std::string leftValue = left;
	std::string rightValue = right;
	std::reverse(leftValue.begin(), leftValue.end());
	std::reverse(rightValue.begin(), rightValue.end());

	for (size_t i = 0; i < rightValue.size(); ++i)
	{
		int x = leftValue[i] - '0';
		int y = rightValue[i] - '0';
		if (y > x)
		{
			x += 10;
			leftValue[i + 1] -= 1;
		}
		result += std::to_string(x - y);
	}

	if (leftValue.size() > rightValue.size())
	{
		for (size_t i = rightValue.size(); i < leftValue.size(); ++i)
		{
			result.push_back(leftValue[i]);
		}
	}

	std::reverse(result.begin(), result.end());
	EraseZeros(result);

	return result;
}

const CBigNumber operator*(const CBigNumber & left, const CBigNumber & right)
{
	std::string result = "";
	std::string leftValue = left.GetAbsValue();
	std::string rightValue = right.GetAbsValue();
	std::string temp;
	CBigNumber bigResult;
	bool isNegative = false;

	std::reverse(rightValue.begin(), rightValue.end());

	isNegative = (left.IsNegative() != right.IsNegative());

	for (size_t i = 0; i < rightValue.size(); ++i)
	{
		temp = Multiplication(leftValue, rightValue[i]);
		if (i > 0)
		{
			AddZeros(temp, i);
		}

		bigResult = CBigNumber(temp) + bigResult;
	}

	result = bigResult.GetAbsValue();
	return CBigNumber((isNegative) ? MINUS_VALUE + result : result);
}

const std::string Multiplication(const std::string & left, char rightValue)
{
	std::string leftValue = left;
	std::string result = "", reverseRes = "";
	int temp = 0, tempRes, res, x;
	int right = rightValue - '0';
	std::reverse(leftValue.begin(), leftValue.end());

	for (size_t i = 0; i < leftValue.size(); ++i)
	{
		x = leftValue[i] - '0';
		tempRes = x * right + temp;
		res = tempRes % 10;
		temp = tempRes / 10;
		result += std::to_string(res);
	}

	if (temp > 0)
	{
		result += std::to_string(temp);
	}

	std::reverse(result.begin(), result.end());
	EraseZeros(result);

	return result;
}

const CBigNumber operator/(const CBigNumber & left, const CBigNumber & right)
{
	std::string result = "";
	std::string leftValue = left.GetAbsValue();
	std::string rightValue = right.GetAbsValue();
	std::string temp;
	bool isNegative = false;

	isNegative = (left.IsNegative() != right.IsNegative());

	result = Division(leftValue, rightValue);

	return CBigNumber((isNegative) ? MINUS_VALUE + result : result);
}

const std::string Division(const std::string & left, const std::string & right)
{
	std::string leftValue = left;
	std::string rightValue = right;

	if (rightValue == "0")
	{
		throw std::invalid_argument("Division by zero is not allowed");
	}

	if (leftValue == "0")
	{
		return "0";
	}

	std::string result = "", tmp = "", addition = "1";
	int x = 0;

	for (size_t i = 0; i < leftValue.size(); ++i)
	{
		tmp += leftValue[i];
		EraseZeros(tmp);

		if (IsRightValueLarger(tmp, rightValue))
		{
			result += "0";
		}
		else
		{
			while (!IsRightValueLarger(tmp, rightValue))
			{
				++x;
				tmp = Substract(tmp, rightValue);
				if (tmp == "0")
				{
					tmp = "";
				}
			}
			result += std::to_string(x);
			x = 0;
		}
	}

	EraseZeros(result);

	if (IsRightValueLarger(Substract(rightValue, tmp), tmp) || Substract(rightValue, tmp) == tmp)
	{
		result = Add(result, addition);
	}

	return result;
}

const bool IsRightValueLarger(const std::string& left, const std::string& right) {
	if (left.size() == right.size())
	{
		return left < right;
	}
	return left.size() < right.size();
}

const void AddZeros(std::string & value, size_t count)
{
	for (size_t i = 0; i < count; ++i)
	{
		value += "0";
	}
}

const void EraseZeros(std::string & value)
{
	while (value.size() > 1 && value[0] == '0')
	{
		value.erase(0, 1);
	}
}
