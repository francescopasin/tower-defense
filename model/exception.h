#ifndef MODEL_EXCEPTION_H_
#define MODEL_EXCEPTION_H_

#include <exception>
#include <stdexcept>

namespace model {

class path_error : std::domain_error {
    path_error(const std::string& what_arg);
    path_error(const char* what_arg = "An error occurred during path building");
};

class state_error : std::runtime_error {
    state_error(const std::string& what_arg) : runtime_error(what_arg) {}
    state_error(const char* what_arg = "You can't do this operation in this state") : runtime_error(what_arg) {}
};

}  // namespace model

/*

*HOW 'TRY CATCH' WORKS:
try {
    throw new state_error("This is s state error");
} catch (std::Exception* e) {
    cout << e.What(); //* contains the error string
}

*/

#endif