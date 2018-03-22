//
// meta programming exercise
//

// void type
template <typename ...Ts>
struct VoidType {};

// basic type
template <typename ...Ts>
struct BasicType { using res = VoidType<Ts...>; };

// bool type
template <typename ...Ts>
struct BoolType : BasicType<Ts...> {};
struct TrueType : BoolType<> { constexpr static const bool value = true; };
struct FalseType : BoolType<> { constexpr static const bool value = false; };

// swap(A, B)
template <typename ...Ts> struct swap;

template <typename L, typename R>
struct swap<L, R> { using res = BasicType<R, L>; };

template <typename L, typename R>
struct swap<BasicType<L, R>> { using res = BasicType<R, L>; };


// ternary operator, default in false
template <typename Condition, typename T_Res, typename F_Res>
struct TernaryOperator { using res = F_Res; };

// ternary operator, if true return T_Res
template <typename T_Res, typename F_Res>
struct TernaryOperator<TrueType, T_Res, F_Res> { using res = T_Res; };

// is same, default in false
template <typename T, typename U>
struct is_same { using res = FalseType; };

// is same, if true return TrueType
template <typename T>
struct is_same<T, T> { using res = TrueType; };

//
// Create a Container (List of Types)
//
template <typename ...Ts> struct List;

template<>
struct List<>
{
	using res = BasicType<>;
	static constexpr const int size = 0;
};

template <typename T, typename ...Us>
struct List<T, Us...> :List<Us...>
{
	using res = BasicType<T, Us...>;
	static constexpr const int size = List<Us...>::size + 1;
};

// ceate a list
template <typename ...Ts> struct MakeList { using res = List<Ts...>; };

// merge(List, List)
template<typename ...Lists> struct Merge;

template<typename... Ts, typename ...Us>
struct Merge <List<Ts...>, List<Us...> > { using res = List<Ts..., Us...>; };

template<typename... Ts, typename U>
struct Merge <List<Ts...>, U> { using res = List<Ts..., U>; };

template<typename... Ts, typename U>
struct Merge <U, List<Ts...>> { using res = List<U, Ts...>; };


// front(List)
template<typename List> struct Front;
template <typename T, typename ...Us>
struct Front<List<T, Us...>> { using res = T; };


// pop(List)
template<typename List> struct Pop;
template <typename T, typename ...Us>
struct Pop<List<T, Us...>> { using res = List<Us...>; };

// implement of find list
template<typename ...Ts> struct pFind_imp;

template<typename T>
struct pFind_imp<T> { using res = FalseType; };

template<typename ...Ts, typename U> // variadic must be at the last position
struct pFind_imp<U, U, Ts...> { using res = TrueType; };

template<typename T, typename U, typename ...Vs>
struct pFind_imp<T, U, Vs...> : pFind_imp<T, Vs...> {};


// find(List, type)
template<typename List, typename T> struct is_Find;
template<typename T, typename ...Us>
struct is_Find<List<Us...>, T> : pFind_imp<T, Us...> {};




int main()
{

	using ternary_true_float_double = typename TernaryOperator<TrueType, float, double>::res; // float
	using ternary_false_float_double = typename TernaryOperator<FalseType, float, double>::res; // double

	using swap_float_double = typename swap<float, double>::res; // BasicType<double, float>

	const auto is_same_float_double = is_same<float, double>::res::value; // false
	const auto is_same_float_float = is_same<float, float>::res::value; // true

	using my_listA = typename MakeList<float, float>::res; // List<float, float>

	using Merge_listA_double = typename Merge<my_listA, double>::res; // List<float, float, double>
	using new_list = typename Merge<List<int, int>, Merge_listA_double>::res; // List<int, int, float, float>

	const auto new_list_size = new_list::size; // 5

	using my_front = typename Front<new_list>::res; // int
	using pop_list = typename Pop<new_list>::res; // List<int, float, float, double>

	const auto is_find_bool_in_list = is_Find<pop_list, bool>::res::value; //false
	const auto is_find_int_in_list = is_Find<pop_list, int>::res::value; //true

}
