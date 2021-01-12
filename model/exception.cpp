#include "exception.h"

namespace model {

path_error::path_error(const std::string& what_arg) : domain_error(what_arg) {}
path_error::path_error(const char* what_arg = "An error occurred during path building") : domain_error(what_arg) {}

state_error::state_error(const std::string& what_arg) : runtime_error(what_arg) {}
state_error::state_error(const char* what_arg = "You can't do this operation in this state") : runtime_error(what_arg) {}

}  // namespace model