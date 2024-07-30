#include <string>
#include <vector>
#include <iostream>

struct S
{
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > name;
    int population;
    std::vector<int, std::allocator<int> > temperatures;
    // inline constexpr S(const S &) noexcept(false) = default;
    // inline constexpr ~S() noexcept = default;
};


std::vector<S, std::allocator<S> > data = std::vector<S, std::allocator<S> >{std::initializer_list<S>{{std::basic_string<char, std::char_traits<char>, std::allocator<char> >("Nanjing", std::allocator<char>()), 120985, std::vector<int, std::allocator<int> >{std::initializer_list<int>{-3, 0, 28, 29, 35, 34, 33, 32}, std::allocator<int>()}}, {std::basic_string<char, std::char_traits<char>, std::allocator<char> >("Shanghai", std::allocator<char>()), 283960, std::vector<int, std::allocator<int> >{std::initializer_list<int>{14, 15, 24, 34, 27, 26, 10, 11, 12}, std::allocator<int>()}}, {std::basic_string<char, std::char_traits<char>, std::allocator<char> >("Hangzhou", std::allocator<char>()), 65536, std::vector<int, std::allocator<int> >{std::initializer_list<int>{15, 17, 18, 25, 3, 31}, std::allocator<int>()}}}, std::allocator<S>()};

int sum(std::vector<int, std::allocator<int> > temperatures)
{
    int sum_up = 0;
    {
        std::vector<int, std::allocator<int> > & __range1 = temperatures;
        __gnu_cxx::__normal_iterator<int *, std::vector<int, std::allocator<int> > > __begin1 = __range1.begin();
        __gnu_cxx::__normal_iterator<int *, std::vector<int, std::allocator<int> > > __end1 = __range1.end();
        for(; !__gnu_cxx::operator==(__begin1, __end1); __begin1.operator++()) {
            int & it = __begin1.operator*();
            sum_up = sum_up + it;
        }

    }
    return static_cast<int &&>(sum_up);
}

double mean(std::vector<int, std::allocator<int> > temperatures)
{
    return static_cast<double>(sum(std::vector<int, std::allocator<int> >(temperatures))) / static_cast<double>(temperatures.size());
}

template<typename T, typename L, typename F>
requires requires(F f, S s) {
    f(s);
}
std::vector<std::vector<T> > map(const std::vector<L> data, F func, std::vector<std::vector<T> > sofar)
{
    if(sofar.size() == data.size()) {
        return static_cast<std::vector &&>(sofar);
    } 

    if constexpr(requires{
            sofar.push_back(func(data[sofar.size()]));
            }) {
        sofar.push_back(func(data[sofar.size()]));
    } else /* constexpr */ {
        std::operator<<(std::cout, "hello").operator<<(std::endl);
    } 

    return map<T>(data, func, sofar);
}

/* First instantiated from: insights.cpp:57 */
#ifdef INSIGHTS_USE_TEMPLATE
    template<>
std::vector<std::vector<double, std::allocator<double> >, std::allocator<std::vector<double, std::allocator<double> > > > map<double, S, __lambda_57_30>(const std::vector<S, std::allocator<S> > data, __lambda_57_30 func, std::vector<std::vector<double, std::allocator<double> >, std::allocator<std::vector<double, std::allocator<double> > > > sofar)
{
    if(sofar.size() == data.size()) {
        return std::vector<std::vector<double, std::allocator<double> >, std::allocator<std::vector<double, std::allocator<double> > > >(static_cast<std::vector<std::vector<double, std::allocator<double> >, std::allocator<std::vector<double, std::allocator<double> > > > &&>(sofar));
    } 

    if constexpr(true) {
        sofar.push_back(func.operator()(S(data.operator[](sofar.size()))));
    } else /* constexpr */ {
    } 

    return map<double>(std::vector<S, std::allocator<S> >(data), __lambda_57_30(func), std::vector<std::vector<double, std::allocator<double> >, std::allocator<std::vector<double, std::allocator<double> > > >(sofar));
}
#endif


/* First instantiated from: insights.cpp:66 */
#ifdef INSIGHTS_USE_TEMPLATE
    template<>
std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > map<int, std::vector<double, std::allocator<double> >, __lambda_66_29>(const std::vector<std::vector<double, std::allocator<double> >, std::allocator<std::vector<double, std::allocator<double> > > > data, __lambda_66_29 func, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > sofar)
{
    if(sofar.size() == data.size()) {
        return std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >(static_cast<std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > &&>(sofar));
    } 

    if constexpr(false) {
    } else /* constexpr */ {
        std::operator<<(std::cout, "hello").operator<<(std::endl);
    } 

    return map<int>(std::vector<std::vector<double, std::allocator<double> >, std::allocator<std::vector<double, std::allocator<double> > > >(data), __lambda_66_29(func), std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >(sofar));
}
#endif


std::vector<std::vector<double, std::allocator<double> >, std::allocator<std::vector<double, std::allocator<double> > > > extract(const std::vector<S, std::allocator<S> > & data)
{

    class __lambda_57_30
    {
        public: 
            template<class type_parameter_0_0>
                inline /*constexpr */ std::vector<double, std::allocator<double> > operator()(const type_parameter_0_0 item) const
                {
                    std::vector<double, std::allocator<double> > pop_tem = std::vector<double, std::allocator<double> >() /* NRVO variable */;
                    push_back(item.population);
                    push_back(mean(item.temperatures));
                    return pop_tem;
                }

            /* First instantiated from: insights.cpp:50 */
#ifdef INSIGHTS_USE_TEMPLATE
            template<>
                inline /*constexpr */ std::vector<double, std::allocator<double> > operator()<S>(const S item) const
                {
                    std::vector<double, std::allocator<double> > pop_tem = std::vector<double, std::allocator<double> >() /* NRVO variable */;
                    pop_tem.push_back(static_cast<double>(item.population));
                    pop_tem.push_back(mean(std::vector<int, std::allocator<int> >(item.temperatures)));
                    return pop_tem;
                }
#endif

            // inline /*constexpr */ __lambda_57_30(const __lambda_57_30 &) noexcept = default;

    };

    return map<double>(std::vector<S, std::allocator<S> >(data), __lambda_57_30{}, std::vector<std::vector<double, std::allocator<double> >, std::allocator<std::vector<double, std::allocator<double> > > >());
}

int main(const int arg_number, const char ** arg_value)
{

    class __lambda_66_29
    {
        public: 
            template<class type_parameter_0_0>
                inline /*constexpr */ auto operator()(type_parameter_0_0 it) const
                {
                    return 1;
                }

#ifdef INSIGHTS_USE_TEMPLATE
            template<>
                inline /*constexpr */ int operator()<S>(S it) const
                {
                    return 1;
                }
#endif


#ifdef INSIGHTS_USE_TEMPLATE
            template<>
                inline /*constexpr */ int operator()<std::vector<double, std::allocator<double> > >(std::vector<double, std::allocator<double> > it) const
                {
                    return 1;
                }
#endif

            // inline /*constexpr */ __lambda_66_29(const __lambda_66_29 &) noexcept = default;

    };

    map<int>(extract(data), __lambda_66_29{}, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >());
    return 0;
}

