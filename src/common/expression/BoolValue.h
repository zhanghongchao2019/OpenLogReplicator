/* Header for BoolValue class
   Copyright (C) 2018-2024 Adam Leszczynski (aleszczynski@bersler.com)

This file is part of OpenLogReplicator.

OpenLogReplicator is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as published
by the Free Software Foundation; either version 3, or (at your option)
any later version.

OpenLogReplicator is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
Public License for more details.

You should have received a copy of the GNU General Public License
along with OpenLogReplicator; see the file LICENSE;  If not see
<http://www.gnu.org/licenses/>.  */

#include "Expression.h"

#ifndef EXPRESSION_BOOL_H_
#define EXPRESSION_BOOL_H_

#define BOOL_VALUE_FALSE         0
#define BOOL_VALUE_TRUE          1
#define BOOL_OPERATOR_AND        2
#define BOOL_OPERATOR_OR         3
#define BOOL_OPERATOR_NOT        4
#define BOOL_OPERATOR_EQUAL      5
#define BOOL_OPERATOR_NOT_EQUAL  6

namespace OpenLogReplicator {
    class BoolValue : public Expression {
    protected:
        uint64_t boolType;
        Expression* left;
        Expression* right;

    public:
        BoolValue(uint64_t newBoolType, Expression* newLeft, Expression* newRight);
        virtual ~BoolValue();

        virtual bool isBool() { return true; }

        virtual bool evaluateToBool(char op, const std::unordered_map<std::string, std::string>* attributes);
        virtual std::string evaluateToString(char op, const std::unordered_map<std::string, std::string>* attributes);
    };
}

#endif
