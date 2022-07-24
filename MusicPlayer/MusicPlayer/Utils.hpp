#pragma once

#include <mutex>
#include <string>
#include <iostream>
#include <sstream>
#include <functional>
#include <format>
#include <qdebug.h>
#include <qstring.h>

inline QDebug& operator <<(QDebug& qdebug, std::string str) {
	qdebug << QString::fromStdString(str);
	return qdebug;
}

namespace util {
	struct sync_print : public std::stringstream {

		static inline std::mutex cout_mutex;
		~sync_print() {
			std::lock_guard<std::mutex> lock{ cout_mutex };
			std::cout << rdbuf();
			std::cout.flush();
		}
	};

	/**
	 * `member_function_traits originally from here (PMF_traits struct):
	 * https://github.com/KonanM/CppProperties/blob/master/include/cppproperties/Signal.h
	 * `function_traits` taken from answer here:
	 * https://stackoverflow.com/questions/7943525/is-it-possible-to-figure-out-the-parameter-type-and-return-type-of-a-lambda
	 * Original code is here: https://github.com/kennytm/utils/blob/master/traits.hpp
	 */


		template <typename>
		struct member_traits {
			using member_type = void;
			using class_type = void;
		};

		template <typename T, typename U>
		struct member_traits<U T::*> {
			using member_type = U;
			using class_type = T;
		};

		template <typename C, typename R, typename... A>
		struct memfn_type {
			using type = std::conditional_t<
				std::is_const_v<C>,
				std::conditional_t<std::is_volatile_v<C>, R(C::*)(A...) const volatile, R(C::*)(A...) const>,
				std::conditional_t<std::is_volatile_v<C>, R(C::*)(A...) volatile, R(C::*)(A...)>>;
		};

		template <typename T>
		struct function_traits : public function_traits<decltype(&T::operator())> {};

		template <typename ReturnType, typename... Args>
		struct function_traits<ReturnType(Args...)> {
			/**
			.. type:: type result_type
				The type returned by calling an instance of the function object type *F*.
			*/
			using result_type = ReturnType;

			/**
			.. type:: type function_type
				The function type (``R(T...)``).
			*/
			using function_type = ReturnType(Args...);

			/**
			.. type:: type member_function_type<OwnerType>
				The member function type for an *OwnerType* (``R(OwnerType::*)(T...)``).
			*/
			template <typename OwnerType>
			using member_function_type =
				typename memfn_type<std::remove_pointer_t< std::remove_reference_t<OwnerType>>, ReturnType, Args...>::type;

			/**
			.. data:: static const size_t arity
				Number of arguments the function object will take.
			*/

			static constexpr auto arity = sizeof...(Args);

			/**
			.. type:: type arg<n>::type
				The type of the *n*-th argument.
			*/
			template <size_t i>
			struct arg {
				using type = std::tuple_element_t<i, std::tuple<Args...>>;
			};
		};

		template <typename ReturnType, typename... Args>
		struct function_traits<ReturnType(*)(Args...)> : public function_traits<ReturnType(Args...)> {};

		template <typename ClassType, typename ReturnType, typename... Args>
		struct function_traits<ReturnType(ClassType::*)(Args...)> : public function_traits<ReturnType(Args...)> {
			using owner_type = ClassType&;
		};

		template <typename ClassType, typename ReturnType, typename... Args>
		struct function_traits<ReturnType(ClassType::*)(Args...) const> : public function_traits<ReturnType(Args...)> {
			using owner_type = const ClassType&;
		};

		template <typename ClassType, typename ReturnType, typename... Args>
		struct function_traits<ReturnType(ClassType::*)(Args...) volatile> : public function_traits<ReturnType(Args...)> {
			using owner_type = volatile ClassType&;
		};

		template <typename ClassType, typename ReturnType, typename... Args>
		struct function_traits<ReturnType(ClassType::*)(Args...) const volatile> : public function_traits<ReturnType(Args...)> {
			using owner_type = const volatile ClassType&;
		};

		template <typename FunctionType>
		struct function_traits<std::function<FunctionType>> : public function_traits<FunctionType> {};

		template <typename T>
		struct function_traits<T&> : public function_traits<T> {};
		template <typename T>
		struct function_traits<const T&> : public function_traits<T> {};
		template <typename T>
		struct function_traits<volatile T&> : public function_traits<T> {};
		template <typename T>
		struct function_traits<const volatile T&> : public function_traits<T> {};
		template <typename T>
		struct function_traits<T&&> : public function_traits<T> {};
		template <typename T>
		struct function_traits<const T&&> : public function_traits<T> {};
		template <typename T>
		struct function_traits<volatile T&&> : public function_traits<T> {};
		template <typename T>
		struct function_traits<const volatile T&&> : public function_traits<T> {};
} // namespace dp
