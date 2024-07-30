# include <string>
# include <vector>
# include <iostream>
truct S {
    std::string name;
    int population;
    std::vector<int> temperatures;
};
std::vector<S> data = {
    {
        .name = "Nanjing",
        .population = 120985,
        .temperatures = {-3, 0, 28, 29, 35, 34, 33, 32}
    },
    {
        .name = "Shanghai",
        .population = 283960,
        .temperatures = {14, 15, 24, 34, 27, 26, 10, 11, 12}
    },
    {
        .name = "Hangzhou",
        .population = 65536,
        .temperatures = {15, 17, 18, 25, 3, 31}
    }
};


int sum(std::vector<int> temperatures) {
    int sum_up = 0;
    for ( auto &it : temperatures )
    {
        sum_up += it;
    }
    return sum_up;
}

double mean(std::vector<int> temperatures) {
    return (double)sum(temperatures) / temperatures.size();
}

template <typename T, typename L, typename F>
requires requires(F f, S s) {
    f(s);
}
std::vector<std::vector<T>> map(const std::vector<L> data, F func, std::vector<std::vector<T>> sofar = std::vector<std::vector<T>>()) {
    if ( sofar.size() == data.size() )
        return sofar;
    if constexpr ( requires {sofar.push_back(func(data[sofar.size()]));} )
        sofar.push_back(func(data[sofar.size()]));
    else {
        func(data[sofar.size()]);
        sofar.push_back(std::vector<T>());
    }
    return map<T>(data, func, sofar);
}

std::vector<std::vector<double>> extract(const std::vector<S> & data) {
    return map<double>(data, [=] (const auto item) -> std::vector<double> {
            std::vector<double> pop_tem;
            pop_tem.push_back(item.population);
            pop_tem.push_back(mean(item.temperatures));
            return pop_tem;
        });
}

int main(const int arg_number, const char **arg_value) {
    map<int>(extract(data), [=] (auto it) {
            if constexpr ( !std::is_same<decltype(it), S>::value ) {
                std::cout << "(" << it[0] << ", "<< it[1] << ")\n";
            } else {
            }
            return 1;
        });
    return 0;
}
