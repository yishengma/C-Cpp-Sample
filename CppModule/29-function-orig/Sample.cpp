//
// Created by 海盗的帽子 on 2020/6/18.
//
#include <iostream>
#include <functional>
using namespace std;


//提供一个模版
template<typename Fty>
class myfunction {};

template<typename R, typename... A>
class myfunction<R(A...)>
{
public:
	using PFUNC = R(*)(A...);
	myfunction(PFUNC pfunc) :_pfunc(pfunc) {}
	R operator()(A... arg)
	{
		return _pfunc(arg...); // hello(arg)
	}
private:
	PFUNC _pfunc;
};

int main()
{

	return 0;
}
