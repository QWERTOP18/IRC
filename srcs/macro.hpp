/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 06:12:34 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/15 07:50:18 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <sstream>
#include <unistd.h>
#include <sys/socket.h>
#include <vector>
#include <string.h>
#include <typeinfo>
#include <iomanip>

#include "./DTO/Error.hpp"
#include "./DTO/RequestBody.hpp"
#include "./DTO/ResponseBody.hpp"
#include "./DTO/ReplyCode.hpp"

#define MAX_CONNECT 256
typedef int ID;

// typedef std::vector<const std::string &> ARGS;

/* ************************************************************************** */
// C++ バージョン対応
/* ************************************************************************** */
#if __cplusplus >= 201103L
#define _NOEXCEPT noexcept
#else
#define _NOEXCEPT throw()
#endif

/* ************************************************************************** */
// ターミナルの色設定（ANSIエスケープコード）
/* ************************************************************************** */
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"

/* ************************************************************************** */
// デバッグ用ログマクロ
/* ************************************************************************** */
#ifdef DEBUG
#define DEBUG_FUNC() std::cerr << CYAN << "[ DEBUG ] " << std::string(typeid(*this).name()) + "->" + __func__ << RESET << std::endl
#define DEBUG_LOG(msg) std::cerr << CYAN << "[ DEBUG ] " << std::string(typeid(*this).name()) + "->" + __func__ << RESET << " " << msg << std::endl
#else
#define DEBUG_FUNC() ((void)0)
#define DEBUG_LOG(msg) ((void)0)
#endif

/* ************************************************************************** */
// LOG
/* ************************************************************************** */
static inline void LOG(const std::string &message)
{
    char buf[20];
    std::time_t t = std::time(0);
    std::strftime(buf, sizeof(buf), "%H:%M:%S> ", std::localtime(&t));
    std::cout << MAGENTA << buf << RESET << message << std::endl;
}

static inline std::string to_string(int value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

static inline std::string zero_pad3(int num)
{
    std::ostringstream oss;
    oss << std::setw(3) << std::setfill('0') << num;
    return oss.str();
}

inline ID id_hash(const std::string &name)
{
    ID hash = 0;
    for (size_t i = 0; i < name.length(); ++i)
    {
        hash = (hash * 31 + name[i]) % 1000000007;
    }
    return hash;
}

inline ID id_hash2(ID id1, ID id2)
{
    return (id1 * 31 + id2) % 1000000007;
}
