#include <stdexcept>
#include <iostream>
#include <string>

#include "validation.hpp"


namespace validation {
    class OptionUnavailable final : public std::exception {
    public:
        const char* what() const noexcept override {
            return "option not available";
        }
    };


    std::int16_t choiceKey(const std::string& input, const std::uint16_t choiceStartRange,
                           const std::uint16_t choiceEndRange) {
        try {
            for (const char& ch : input) {
                if (ch >= 48 && ch <= 57) {
                    continue;
                }
                throw std::invalid_argument("Invalid input");
            }
            std::int16_t key = std::stoi(input);
            if (key >= choiceStartRange && key <= choiceEndRange) {
                return key;
            }
            throw OptionUnavailable();
        } catch (std::invalid_argument& e) {
            return -1;
        } catch (std::out_of_range& e) {
            return -1;
        } catch (OptionUnavailable& e) {
            return -2;
        }
    }
}
