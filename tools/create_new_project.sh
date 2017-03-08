#!/bin/zsh

function check_name() {
	if [[ "$1" == "" ]]; then
		echo "Project name cannot be empty"
		return 1
	else
		return 0
	fi
}

cmake_template="cmake_minimum_required(VERSION 3.2)\nproject(%s)\n\nset(CMAKE_CXX_FLAGS \"${CMAKE_CXX_FLAGS} -std=c++11\")\n\nadd_executable(%s %s.cpp)\n"
cpp_template="#include <iostream>\n#include <cstdio>\n#include <vector>\n#include <queue>\n#include <algorithm>\n#include <map>\n#include <string>\n#include <cmath>\n#include <cstring>\n\nusing namespace std;\n\nclass Solution {\npublic:\n\n};\n\nint main() {\n    Solution sol;\n    return 0;\n}"

sicily_dir="../Sicily"
leetcode_dir="../LeetCode"

mode=`echo $1 | tr '[:upper:]' '[:lower:]'`
name=$2


case $mode in
	"sicily" )
		check_name $name
		if [[ "$?" == "0" ]]; then
			printf "$cpp_template" > $sicily_dir/$name.cpp
			echo "add_executable($name $name.cpp)" >> $sicily_dir/CMakeLists.txt
		fi
		
		;;
	"leetcode" )
		check_name $name
		if [[ "$?" == "0" ]]; then
			echo "create testcase $name"
			mkdir $leetcode_dir/$name
			touch $leetcode_dir/$name/README.md
			echo "add_subdirectory($name)" >> $leetcode_dir/CMakeLists.txt
			printf "$cpp_template" > $leetcode_dir/$name/$name.cpp
			printf "$cmake_template" $name $name $name > $leetcode_dir/$name/CMakeLists.txt
		fi
		;;
	* )
		echo "Usage $0 {sicily|leetcode} name"
		;;
esac

