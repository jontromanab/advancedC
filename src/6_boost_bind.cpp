/*
The bind class is able to bind any function object argument to a specific value or route input
arguments into arbitary positions.
works for functions , function objects and function pointers

e.g.
- You have a fucntion which accepts many arguments, and you would like to work with one variable
only, keeping the others constant

- you are given a function which you cann not modify and you would like the call the function with
the parameters being in a different, probably more intutive order.

boost bind refers to input variables by their number with a _ prefix in the order they are passed to the
fucntion. e.g _1 denotes the first argument of the function
e.g indicatorFunc

double indicatorFunc(const double& x, const double& a, const double& b)

returns 1, if x in range of a and b, 0 otherwise. suppose we want to work a lot on this function in the
interval [-1,1]. we dont want indicatorFunc(x, -1,1)

boost::function<double (double)> indPmOne;
double a = -1.0, b = 1.0l
indPmOne = boost::bind<indicatorFunc, _1,a,b) //The first param x should stay as it is. The rest param are fixed

indPmOne(x)


*/
