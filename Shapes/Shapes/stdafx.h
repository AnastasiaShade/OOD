// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#define _USE_MATH_DEFINES
#define _SCL_SECURE_NO_WARNINGS
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <memory>

#include <iostream>
#include <iomanip>

#include <map>
#include <functional>
#include <boost/regex.hpp>
#include <boost/algorithm/string/regex.hpp>

static const std::string CIRCLE_TYPE = "CIRCLE";
static const std::string TRIANGLE_TYPE = "TRIANGLE";
static const std::string RECTANGLE_TYPE = "RECTANGLE";