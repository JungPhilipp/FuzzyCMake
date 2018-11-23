/// To avoid name clashes within include guards, use the path of the file and the name.
/// LIBFUZZY_PATH_TO_FILE_H_
#ifndef LIBFUZZY_FOO_H_
#define LIBFUZZY_FOO_H_


namespace fuzzy {

double foo(double lhs, double rhs);

}


#endif //LIBFUZZY_FOO_H_
