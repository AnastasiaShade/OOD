#include "stdafx.h"
#include "../BigNumbers/BigNumber.h"

void VerifyBigNumber(const CBigNumber & number, const std::string & expectedValue, const std::string & expectedAbsValue, const bool expectedNegativeState)
{
	BOOST_CHECK_EQUAL(number.GetValue(), expectedValue);
	BOOST_CHECK_EQUAL(number.GetAbsValue(), expectedAbsValue);
	BOOST_CHECK_EQUAL(number.IsNegative(), expectedNegativeState);
}

BOOST_AUTO_TEST_SUITE(Big_number)

	BOOST_AUTO_TEST_CASE(is_0_by_default)
	{
		VerifyBigNumber(CBigNumber(), "0", "0", false);
	}
	
	BOOST_AUTO_TEST_CASE(can_be_constructed_from_string)
	{
		VerifyBigNumber(CBigNumber("15"), "15", "15", false);
		VerifyBigNumber(CBigNumber("-15"), "-15", "15", true);
		VerifyBigNumber(CBigNumber("0"), "0", "0", false);
	}

	BOOST_AUTO_TEST_CASE(can_be_constructed_from_integer)
	{
		VerifyBigNumber(CBigNumber(15), "15", "15", false);
		VerifyBigNumber(CBigNumber(-15), "-15", "15", true);
		VerifyBigNumber(CBigNumber(0), "0", "0", false);
	}

	BOOST_AUTO_TEST_CASE(can_get_value)
	{
		BOOST_CHECK_EQUAL(CBigNumber(333).GetValue(), "333");
		BOOST_CHECK_EQUAL(CBigNumber(-333).GetValue(), "-333");
	}

	BOOST_AUTO_TEST_CASE(can_get_abs_value)
	{
		BOOST_CHECK_EQUAL(CBigNumber(333).GetAbsValue(), "333");
		BOOST_CHECK_EQUAL(CBigNumber(-333).GetAbsValue(), "333");
	}

	BOOST_AUTO_TEST_CASE(can_get_negative_state)
	{
		BOOST_CHECK_EQUAL(CBigNumber(333).IsNegative(), false);
		BOOST_CHECK_EQUAL(CBigNumber(-333).IsNegative(), true);
	}

	BOOST_AUTO_TEST_SUITE(has_addition_operation)

		BOOST_AUTO_TEST_CASE(with_big_number)
		{
			VerifyBigNumber(CBigNumber("22222") + CBigNumber("99999"), "122221", "122221", false);
			VerifyBigNumber(CBigNumber("-22222") + CBigNumber("-99999"), "-122221", "122221", true);
			VerifyBigNumber(CBigNumber("-22222") + CBigNumber("99999"), "77777", "77777", false);
			VerifyBigNumber(CBigNumber("22222") + CBigNumber("-99999"), "-77777", "77777", true);
			VerifyBigNumber(CBigNumber("22222") + CBigNumber("-22222"), "0", "0", false);
			VerifyBigNumber(CBigNumber("-22222") + CBigNumber("22222"), "0", "0", false);
		}

		BOOST_AUTO_TEST_CASE(with_integer)
		{
			VerifyBigNumber(CBigNumber("22222") + 99999, "122221", "122221", false);
			VerifyBigNumber(-22222 + CBigNumber("-99999"), "-122221", "122221", true);
			VerifyBigNumber(CBigNumber("-22222") + 99999, "77777", "77777", false);
			VerifyBigNumber(CBigNumber("22222") + (-99999), "-77777", "77777", true);
			VerifyBigNumber(22222 + CBigNumber("-22222"), "0", "0", false);
			VerifyBigNumber(-22222 + CBigNumber("22222"), "0", "0", false);
		}

		BOOST_AUTO_TEST_CASE(with_0)
		{
			VerifyBigNumber(-0 + CBigNumber("22222"), "22222", "22222", false);
			VerifyBigNumber(CBigNumber("22222") + 0, "22222", "22222", false);
			VerifyBigNumber(CBigNumber("-0") + CBigNumber("-22222"), "-22222", "22222", true);
			VerifyBigNumber(CBigNumber() + CBigNumber("-22222"), "-22222", "22222", true);
		}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(has_substraction_operation)

		BOOST_AUTO_TEST_CASE(with_big_number)
		{
			VerifyBigNumber(CBigNumber("22222") - CBigNumber("99999"), "-77777", "77777", true);
			VerifyBigNumber(CBigNumber("-22222") - CBigNumber("-99999"), "77777", "77777", false);
			VerifyBigNumber(CBigNumber("-22222") - CBigNumber("99999"), "-122221", "122221", true);
			VerifyBigNumber(CBigNumber("22222") - CBigNumber("-99999"), "122221", "122221", false);
			VerifyBigNumber(CBigNumber("22222") - CBigNumber("-22222"), "44444", "44444", false);
			VerifyBigNumber(CBigNumber("22222") - CBigNumber("22222"), "0", "0", false);

			VerifyBigNumber(CBigNumber("99999") - CBigNumber("-22222"), "122221", "122221", false);
			VerifyBigNumber(CBigNumber("-99999") - CBigNumber("22222"), "-122221", "122221", true);
		}

		BOOST_AUTO_TEST_CASE(with_integer)
		{
			VerifyBigNumber(CBigNumber("22222") - 99999, "-77777", "77777", true);
			VerifyBigNumber(-22222 - CBigNumber("-99999"), "77777", "77777", false);
			VerifyBigNumber(CBigNumber("-22222") - 99999, "-122221", "122221", true);
			VerifyBigNumber(CBigNumber("22222") - (-99999), "122221", "122221", false);
			VerifyBigNumber(22222 - CBigNumber("-22222"), "44444", "44444", false);
			VerifyBigNumber(22222 - CBigNumber("22222"), "0", "0", false);
		}

		BOOST_AUTO_TEST_CASE(with_0)
		{
			VerifyBigNumber(-0 - CBigNumber("22222"), "-22222", "22222", true);
			VerifyBigNumber(CBigNumber("22222") - 0, "22222", "22222", false);
			VerifyBigNumber(CBigNumber("0") - CBigNumber("-22222"), "22222", "22222", false);
		}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(has_multiplication_operation)

		BOOST_AUTO_TEST_CASE(with_big_number)
		{
			VerifyBigNumber(CBigNumber("2222222222222222222222222222222222222222222222222222222222222222222222222222222") * CBigNumber("2"), "4444444444444444444444444444444444444444444444444444444444444444444444444444444", "4444444444444444444444444444444444444444444444444444444444444444444444444444444", false);
			VerifyBigNumber(CBigNumber("2222222222222222222222222222222222222222222222222222222222222222222222222222222") * CBigNumber("22"), "48888888888888888888888888888888888888888888888888888888888888888888888888888884", "48888888888888888888888888888888888888888888888888888888888888888888888888888884", false);

			VerifyBigNumber(CBigNumber("19") * CBigNumber("19"), "361", "361", false);
			VerifyBigNumber(CBigNumber("-19") * CBigNumber("-20"), "380", "380", false);
			VerifyBigNumber(CBigNumber("1111") * CBigNumber("-4"), "-4444", "4444", true);
			VerifyBigNumber(CBigNumber("-1111") * CBigNumber("4"), "-4444", "4444", true);
		}

		BOOST_AUTO_TEST_CASE(with_integer)
		{
			VerifyBigNumber(CBigNumber("19") * 19, "361", "361", false);
			VerifyBigNumber(-19 * CBigNumber("-20"), "380", "380", false);
			VerifyBigNumber(CBigNumber("1111") * (-4), "-4444", "4444", true);
			VerifyBigNumber(CBigNumber("-1111") * 4, "-4444", "4444", true);
		}

		BOOST_AUTO_TEST_CASE(with_0)
		{
			VerifyBigNumber(CBigNumber("22222") * CBigNumber(), "0", "0", false);
			VerifyBigNumber(CBigNumber("-22222") * CBigNumber(), "0", "0", false);
		}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(has_division_operation)

		BOOST_AUTO_TEST_CASE(with_big_number)
		{
			VerifyBigNumber(CBigNumber("2222222222222222222222222222222222222222222222222222222222222222222222222222222") / CBigNumber("2"), "1111111111111111111111111111111111111111111111111111111111111111111111111111111", "1111111111111111111111111111111111111111111111111111111111111111111111111111111", false);
			VerifyBigNumber(CBigNumber("2222222222222222222222222222222222222222222222222222222222222222222222222222222") / CBigNumber("22"), "101010101010101010101010101010101010101010101010101010101010101010101010101010", "101010101010101010101010101010101010101010101010101010101010101010101010101010", false);
			VerifyBigNumber(CBigNumber("59756398587357693474") / CBigNumber("6666666666"), "8963459789", "8963459789", false);

			VerifyBigNumber(CBigNumber("25") / CBigNumber("9"), "3", "3", false);
			VerifyBigNumber(CBigNumber("-22") / CBigNumber("2"), "-11", "11", true);
			VerifyBigNumber(CBigNumber("1") / CBigNumber("5"), "0", "0", false);
			VerifyBigNumber(CBigNumber("1") / CBigNumber("-2"), "-1", "1", true);
		}

		BOOST_AUTO_TEST_CASE(with_integer)
		{
			VerifyBigNumber(25 / CBigNumber("9"), "3", "3", false);
			VerifyBigNumber((-22) / CBigNumber("2"), "-11", "11", true);
			VerifyBigNumber(CBigNumber("1") / 5, "0", "0", false);
			VerifyBigNumber(CBigNumber("1") / (-2), "-1", "1", true);
		}

		BOOST_AUTO_TEST_CASE(with_0)
		{
			VerifyBigNumber(CBigNumber() / CBigNumber("15"), "0", "0", false);
			VerifyBigNumber(CBigNumber("-0") / CBigNumber("111111111111"), "0", "0", false);
		}

		BOOST_AUTO_TEST_CASE(cant_divide_by_zero)
		{
			BOOST_REQUIRE_THROW(CBigNumber("2") / CBigNumber("0"), std::invalid_argument);
		}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
