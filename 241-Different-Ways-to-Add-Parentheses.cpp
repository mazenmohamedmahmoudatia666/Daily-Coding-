class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;

        // Base case: If the expression is a single number, return it as a single result.
        bool isNumber = true;
        for (char ch : expression) {
            if (!isdigit(ch)) {
                isNumber = false;
                break;
            }
        }
        if (isNumber) {
            result.push_back(stoi(expression));
            return result;
        }

        // Iterate through the expression to find operators.
        for (int i = 0; i < expression.size(); ++i) {
            char ch = expression[i];

            // Check if the current character is an operator.
            if (ch == '+' || ch == '-' || ch == '*') {
                // Split the expression into two parts: left and right.
                string leftPart = expression.substr(0, i);
                string rightPart = expression.substr(i + 1);

                // Recursively solve the left and right parts.
                vector<int> leftResults = diffWaysToCompute(leftPart);
                vector<int> rightResults = diffWaysToCompute(rightPart);

                // Combine the results from left and right parts based on the operator.
                for (int left : leftResults) {
                    for (int right : rightResults) {
                        if (ch == '+') {
                            result.push_back(left + right);
                        } else if (ch == '-') {
                            result.push_back(left - right);
                        } else if (ch == '*') {
                            result.push_back(left * right);
                        }
                    }
                }
            }
        }

        return result;
    }
};
